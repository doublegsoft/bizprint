##
##  _     _                _       _
## | |   (_)              (_)     | |
## | |__  _ _____ __  _ __ _ _ __ | |_
## | '_ \| |_  / '_ \| '__| | '_ \| __|
## | |_) | |/ /| |_) | |  | | | | | |_
## |_.__/|_/___| .__/|_|  |_|_| |_|\__|
##             | |
##             |_|
##

CC   := x86_64-w64-mingw32-gcc
LD   := $(CC)

SRCDIR   := src
BUILDDIR := build
TARGET   := bizprint.exe

CFLAGS := -Wall -Wextra -O2 -std=gnu11 												\
					-Wno-unused-parameter -Wno-unknown-pragmas 					\
					-Wno-cpp 																						\
          -I/usr/x86_64-w64-mingw32/include 									\
					-I./3rd/libwebsockets/include 											\
					-I./3rd/libwebsockets/build/mingw64 								\
					-I./3rd/cJSON
LDFLAGS := -L/usr/x86_64-w64-mingw32/lib 											\
           -L./3rd/libwebsockets/build/mingw64/lib 						\
					 -L./3rd/cJSON/build/mingw64 												\
					 -lcjson.dll -lcjson_utils.dll											\
					 -lwsock32 -lws2_32 -lwebsockets.dll 								\
					 -lkernel32 -luser32 -lwinspool -lssp

# Sources & objects
SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# ----------------------------------------------
#  Targets
# ----------------------------------------------
.PHONY: all clean debug release

all: $(BUILDDIR) $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $(BUILDDIR)/$@ $^ $(CFLAGS) $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(BUILDDIR):
	@mkdir -p $@

clean:
	rm -rf $(BUILDDIR) $(TARGET)

debug: CFLAGS += -g -O0
debug: all

release: CFLAGS = -O3 -DNDEBUG
release: all

