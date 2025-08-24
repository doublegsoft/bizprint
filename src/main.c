/*
**  _     _                _       _
** | |   (_)              (_)     | |
** | |__  _ _____ __  _ __ _ _ __ | |_
** | '_ \| |_  / '_ \| '__| | '_ \| __|
** | |_) | |/ /| |_) | |  | | | | | |_
** |_.__/|_/___| .__/|_|  |_|_| |_|\__|
**             | |
**             |_|
*/
#include <windows.h>
#include <libwebsockets.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <tchar.h>
#include <cJSON.h>

#include "http-client.h"

static int process_request(struct lws *wsi,
                           enum lws_callback_reasons reason,
                           void *user,
                           void *in,
                           size_t len);

/*
** printers.
*/
static PPRINTER_INFO_2    g_printers;
static DWORD              g_printer_count;

static int  interrupted = 0;

static const struct lws_protocols echo_protocols[] =
{
  {
    "print-protocol",          /* name (client identifies with it) */
    process_request,           /* callback */
    0,                         /* per session data size */
    1024,                      /* receive buffer size */
    1, NULL, 0
  },
  { NULL, NULL, 0, 0, 2, NULL, 0 }
};

static void sigint_handler(int sig)
{
  interrupted = 1;
}

static int process_request(struct lws *wsi,
                           enum lws_callback_reasons reason,
                           void *user,
                           void *in,
                           size_t len)
{
  switch (reason)
  {
    case LWS_CALLBACK_ESTABLISHED:
      lwsl_info("Connection established\n");
      break;
    case LWS_CALLBACK_RECEIVE:
    {
      char* cmd = (char*)in;
      cmd[len] = '\0';
      if (strstr(cmd, "printers") == cmd)
      {
        cJSON* printers = cJSON_CreateArray();
        for (DWORD i = 0; i < g_printer_count; ++i)
        {
          cJSON* printer = cJSON_CreateObject();
          cJSON* name = cJSON_CreateString(g_printers[i].pPrinterName);
          cJSON_AddItemToObject(printer, "name", name);
          cJSON_AddItemToArray(printers, printer);
        }
        const char* str = cJSON_Print(printers);
        cJSON_Delete(printers);
        lws_write(wsi, (unsigned char *)str, strlen(str), LWS_WRITE_TEXT);
      }
      break;
    }
    case LWS_CALLBACK_CLOSED:
      lwsl_info("Connection closed\n");
      break;
    default:
      break;
  }
  return 0;
}

int main()
{
  DWORD needed = 0;
  EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS,
               NULL,
               2,
               NULL,
               0,
               &needed,
               &g_printer_count);

  if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
  {
    fprintf(stderr, "EnumPrinters failed (no printers?)\n");
    return 1;
  }
  
  g_printers = calloc(needed, sizeof(char));
  if (!g_printers)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  if (!EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS,
                    NULL,
                    2,
                    (LPBYTE)g_printers,
                    needed,
                    &needed,
                    &g_printer_count))
  {
    fprintf(stderr, "EnumPrinters failed on second call\n");
    free(g_printers);
    return 1;
  }
  
  struct lws_context_creation_info info;
  struct lws_context *context;

  signal(SIGINT, sigint_handler);

  memset(&info, 0, sizeof info);
  info.port = 54321;                     /* listen on port 9000 */
  info.protocols = echo_protocols;      /* protocol list */
  info.gid = -1;
  info.uid = -1;

  lws_set_log_level(LLL_ERR | LLL_WARN | LLL_NOTICE | LLL_INFO | LLL_DEBUG, NULL);

  context = lws_create_context(&info);
  if (!context)
  {
    fprintf(stderr, "lws_create_context failed\n");
    return 1;
  }

  while (!interrupted)
    lws_service(context, 1000);   /* 1000 ms timeout */

  lws_context_destroy(context);
  return 0;
}
