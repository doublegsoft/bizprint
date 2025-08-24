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

const char* ps = 
  "%%!PS-Adobe-1.0\n"
  "%%Creator: CGMGEN\n"
  "%%Title: CGMGEN\n"
  "%%Pages: 1\n"
  "%%DocumentFonts: Times-Roman\n"
  "%%CreationDate: Fri Feb 23 09:32:25 1996\n"
  "%%BoundingBox: 0 0 576 576 \n"
  "%%EndComments\n"
  "%%BeginProlog\n"
  "%%EndProlog\n"
  "\n"
  "c language multi-line string\n"
  "\n"
  "%%Page: 1 1\n"
  "save\n"
  "72 300 div dup scale % scale co-ordinate system\n"
  "/ln {lineto} def /mv {moveto} def /np {newpath} def /st {stroke} def\n"
  "/s {show} def /cp {closepath} def /sd {setdash} def /sl {setlinewidth} def\n"
  "/ch { dup stringwidth pop 2 div neg 0 rmoveto } def /mch {ch show} def\n"
  "/rh { dup stringwidth pop neg 0 rmoveto } def /fl {fill} def\n"
  "/rp {show 1 0 rmoveto} def /rm {show -1 0 rmoveto} def /rpn {1 0 rmoveto} def\n"
  "/rmn {-1 0 rmoveto} def /ah {av moveto} def /sf {findfont setfont} def\n"
  "/mh {dup /av exch def moveto} def /tr {translate} def \n"
  "/gs {gsave} def /gr {grestore} def \n"
  "/Times-Roman findfont 40 scalefont setfont save [] 0 sd 2 sl \n"
  "0.0000 0.0000 0.0000 setrgbcolor np 595 543 mv 902 747 ln st np 902 747 mv 1175 \n"
  "961 ln st np 1175 961 mv 1394 1145 ln st np 1394 1145 mv 1560 1286 ln st np 1560\n"
  "1286 mv 1550 1277 ln st np 1550 1277 mv 1658 1367 ln st np 1658 1367 mv 1848 \n"
  "1522 ln st np 595 543 mv 902 747 ln st np 902 747 mv 902 747 ln st np 902 747 \n"
  "mv 595 543 ln st np 595 543 mv 595 543 ln st np 902 747 mv 1175 961 ln st np \n"
  "1175 961 mv 1175 961 ln st np 1175 961 mv 902 747 ln st np 902 747 mv 902 747 \n"
  "ln st np 1175 961 mv 1394 1145 ln st np 1394 1145 mv 1394 1145 ln st np 1394 \n"
  "1145 mv 1175 961 ln st np 1175 961 mv 1175 961 ln st np 1394 1145 mv 1560 1286 \n"
  "ln st np 1560 1286 mv 1560 1286 ln st np 1560 1286 mv 1394 1145 ln st np 1394 \n"
  "1145 mv 1394 1145 ln st np 1560 1286 mv 1550 1277 ln st np 1550 1277 mv 1550 \n"
  "1277 ln st np 1550 1277 mv 1560 1286 ln st np 1560 1286 mv 1560 1286 ln st np \n"
  "1550 1277 mv 1658 1367 ln st np 1658 1367 mv 1658 1367 ln st np 1658 1367 mv \n"
  "1550 1277 ln st np 1550 1277 mv 1550 1277 ln st np 1658 1367 mv 1848 1522 ln st \n"
  "np 1848 1522 mv 1848 1522 ln st np 1848 1522 mv 1658 1367 ln st np 1658 1367 mv \n"
  "1658 1367 ln st np 595 543 mv 902 747 ln st np 902 747 mv 902 747 ln st np 902 \n"
  "747 mv 595 605 ln st np 595 605 mv 595 543 ln st np 902 747 mv 1175 961 ln st \n"
  "np 1175 961 mv 1175 961 ln st np 1175 961 mv 902 747 ln st np 902 747 mv 902 747\n"
  "ln st np 1175 961 mv 1394 1145 ln st np 1394 1145 mv 1394 1145 ln st np 1394 \n"
  "1145 mv 1175 961 ln st np 1175 961 mv 1175 961 ln st np 1394 1145 mv 1560 1286 \n"
  "ln st np 1560 1286 mv 1560 1286 ln st np 1560 1286 mv 1394 1145 ln st np 1394 \n"
  "1145 mv 1394 1145 ln st np 1560 1286 mv 1550 1277 ln st np 1550 1277 mv 1550 \n"
  "1436 ln st np 1550 1436 mv 1560 1286 ln st np 1560 1286 mv 1560 1286 ln st np \n"
  "1550 1277 mv 1658 1367 ln st np 1658 1367 mv 1658 1454 ln st np 1658 1454 mv \n"
  "1550 1436 ln st np 1550 1436 mv 1550 1277 ln st np 1658 1367 mv 1848 1522 ln st \n"
  "np 1848 1522 mv 1848 1578 ln st np 1848 1578 mv 1658 1454 ln st np 1658 1454 mv \n"
  "1658 1367 ln st np 595 605 mv 902 747 ln st np 902 747 mv 896 808 ln st np 896 \n"
  "808 mv 606 674 ln st np 606 674 mv 595 605 ln st np 902 747 mv 1175 961 ln st \n"
  "np 1175 961 mv 1155 1007 ln st np 1155 1007 mv 896 808 ln st np 896 808 mv 902 \n"
  "747 ln st np 1175 961 mv 1394 1145 ln st np 1394 1145 mv 1367 1191 ln st np 1367\n"
  "1191 mv 1155 1007 ln st np 1155 1007 mv 1175 961 ln st np 1394 1145 mv 1560 1286\n"
  "ln st np 1560 1286 mv 1508 1340 ln st np 1508 1340 mv 1367 1191 ln st np 1367 \n"
  "1191 mv 1394 1145 ln st np 1560 1286 mv 1550 1436 ln st np 1550 1436 mv 1550 \n"
  "1540 ln st np 1550 1540 mv 1508 1340 ln st np 1508 1340 mv 1560 1286 ln st np \n"
  "1550 1436 mv 1658 1454 ln st np 1658 1454 mv 1677 1547 ln st np 1677 1547 mv \n"
  "1550 1540 ln st np 1550 1540 mv 1550 1436 ln st np 1658 1454 mv 1848 1578 ln st \n"
  "np 1848 1578 mv 1859 1642 ln st np 1859 1642 mv 1677 1547 ln st np 1677 1547 mv \n"
  "1658 1454 ln st np 606 674 mv 896 808 ln st np 896 808 mv 889 873 ln st np 889 \n"
  "873 mv 611 745 ln st np 611 745 mv 606 674 ln st np 896 808 mv 1155 1007 ln st \n"
  "np 1155 1007 mv 1135 1059 ln st np 1135 1059 mv 889 873 ln st np 889 873 mv 896 \n"
  "808 ln st np 1155 1007 mv 1367 1191 ln st np 1367 1191 mv 1337 1240 ln st np \n"
  "1337 1240 mv 1135 1059 ln st np 1135 1059 mv 1155 1007 ln st np 1367 1191 mv \n"
  "1508 1340 ln st np 1508 1340 mv 1472 1401 ln st np 1472 1401 mv 1337 1240 ln st \n"
  "np 1337 1240 mv 1367 1191 ln st np 1508 1340 mv 1550 1540 ln st np 1550 1540 mv \n"
  "1550 1619 ln st np 1550 1619 mv 1472 1401 ln st np 1472 1401 mv 1508 1340 ln st \n"
  "np 1550 1540 mv 1677 1547 ln st np 1677 1547 mv 1698 1632 ln st np 1698 1632 mv \n"
  "1550 1619 ln st np 1550 1619 mv 1550 1540 ln st np 1677 1547 mv 1859 1642 ln st \n"
  "np 1859 1642 mv 1877 1713 ln st np 1877 1713 mv 1698 1632 ln st np 1698 1632 mv \n"
  "1677 1547 ln st np 611 745 mv 889 873 ln st np 889 873 mv 881 943 ln st np 881 \n"
  "943 mv 612 818 ln st np 612 818 mv 611 745 ln st np 889 873 mv 1135 1059 ln st \n"
  "np 1135 1059 mv 1115 1116 ln st np 1115 1116 mv 881 943 ln st np 881 943 mv 889 \n"
  "873 ln st np 1135 1059 mv 1337 1240 ln st np 1337 1240 mv 1308 1294 ln st np \n"

  // ... and so on for the rest of the file ...
  
  "np 1757 2249 mv 1550 2160 ln st \n"
  "np 1550 2160 mv 1550 2080 ln st np 543 1577 mv 783 1704 ln st np 783 1704 mv 772 1836 ln st \n"
  "np 772 1836 mv 530 1710 ln st np 530 1710 mv 543 1577 ln st np 783 1704 mv 991 \n"
  "1835 ln st np 991 1835 mv 983 1964 ln st np 983 1964 mv 772 1836 ln st np 772 \n"

  // ... imagine the rest of the lines are here ...

  "1836 mv 783 1704 ln st np 991 1835 mv 1180 1971 ln st np 1180 1971 mv 1176 2092 \n"
  "ln st np 1176 2092 mv 983 1964 ln st np 983 1964 mv 991 1835 ln st np 1180 1971 \n"
  "mv 1363 2110 ln st np 1363 2110 mv 1362 2221 ln st np 1362 2221 mv 1176 2092 ln \n"
  "st np 1176 2092 mv 1180 1971 ln st np 530 1710 mv 772 1836 ln st np 772 1836 mv \n"
  "762 1983 ln st np 762 1983 mv 518 1858 ln st np 518 1858 mv 530 1710 ln st np \n"
  "772 1836 mv 983 1964 ln st np 983 1964 mv 976 2106 ln st np 976 2106 mv 762 1983\n"
  "ln st np 762 1983 mv 772 1836 ln st np 983 1964 mv 1176 2092 ln st np 1176 2092 \n"
  "mv 1174 2227 ln st np 1174 2227 mv 976 2106 ln st np 976 2106 mv 983 1964 ln st \n"
  "np 518 1858 mv 762 1983 ln st np 762 1983 mv 752 2146 ln st np 752 2146 mv 505 \n"
  "2024 ln st np 505 2024 mv 518 1858 ln st np 762 1983 mv 976 2106 ln st np 976 \n"
  "2106 mv 970 2264 ln st np 970 2264 mv 752 2146 ln st np 752 2146 mv 762 1983 ln \n"
  "st showpage restore\n"
  "\n"
  "restore\n"
  "%%Trailer\n"
  "%%Pages:      1\n"
  "%%EOF\n";

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

unsigned char* 
read_file(const char* path)
{
  FILE *fp = fopen(path, "rb");
  if (!fp)
  {
    perror("fopen");
    return NULL;
  }

  /* seek to end to find the size */
  if (fseek(fp, 0, SEEK_END) != 0)
  {
    perror("fseek");
    fclose(fp);
    return NULL;
  }

  long size = ftell(fp);
  if (size < 0)
  {
    perror("ftell");
    fclose(fp);
    return NULL;
  }

  rewind(fp);                     /* go back to the beginning */

  /* allocate buffer */
  unsigned char *buf = malloc((size_t)size);
  if (!buf)
  {
    perror("malloc");
    fclose(fp);
    return NULL;
  }

  /* read the whole file */
  size_t read = fread(buf, 1, (size_t)size, fp);
  if (read != (size_t)size)
  {
    perror("fread");
    free(buf);
    fclose(fp);
    return NULL;
  }

  fclose(fp);
  return buf;
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

  unsigned char* textToPrint = 
      read_file("Z:\\export\\local\\works\\doublegsoft.biz\\bizprint\\03.Development\\bizprint\\test\\test.ps");


  HANDLE hPrinter;
  PRINTER_DEFAULTS pd = {0};
  pd.pDatatype      = NULL;// "RAW";
  pd.DesiredAccess  = PRINTER_ALL_ACCESS;

  if (!OpenPrinterA("Canon_TS5380_series", &hPrinter, &pd)) {
    fprintf(stderr, "OpenPrinter failed: %lu\n", GetLastError());
    return 1;
  }

  /* 2. Start a document */
  DOC_INFO_1 docInfo = {0};
  docInfo.pDocName = "MinGW C Print Job";
  docInfo.pOutputFile = NULL;
  docInfo.pDatatype = NULL;// "RAW";

  DWORD docHandle = StartDocPrinter(hPrinter, 1, (LPBYTE)&docInfo);
  if (docHandle == 0) {
    fprintf(stderr, "StartDocPrinter failed: %lu\n", GetLastError());
    ClosePrinter(hPrinter);
    return 1;
  }

  /* 3. Start a page */
  DWORD pageHandle = StartPagePrinter(hPrinter);
  if (pageHandle == 0) {
    fprintf(stderr, "StartPagePrinter failed: %lu\n", GetLastError());
    EndDocPrinter(hPrinter);
    ClosePrinter(hPrinter);
    return 1;
  }

  /* 4. Write the data */
  DWORD written = 0;
  if (!WritePrinter(hPrinter,
                    (BYTE*)textToPrint,
                    (DWORD)strlen(textToPrint),
                    &written)) {
    fprintf(stderr, "WritePrinter failed: %lu\n", GetLastError());
  }

  /* 5. End page / document / close */
  EndPagePrinter(hPrinter);
  EndDocPrinter(hPrinter);
  ClosePrinter(hPrinter);

  printf("ok\n");
  
  // struct lws_context_creation_info info;
  // struct lws_context *context;

  // signal(SIGINT, sigint_handler);

  // memset(&info, 0, sizeof info);
  // info.port = 54321; 
  // info.protocols = echo_protocols;
  // info.gid = -1;
  // info.uid = -1;

  // lws_set_log_level(LLL_ERR | LLL_WARN | LLL_NOTICE | LLL_INFO | LLL_DEBUG, NULL);

  // context = lws_create_context(&info);
  // if (!context)
  // {
  //   fprintf(stderr, "lws_create_context failed\n");
  //   return 1;
  // }

  // while (!interrupted)
  //   lws_service(context, 1000);   /* 1000 ms timeout */

  // lws_context_destroy(context);
  return 0;
}
