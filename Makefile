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

# Directories
SRCDIR   := src
BUILDDIR := build
TARGET   := hello.exe

# Flags
CFLAGS := -Wall -Wextra -O2 -I/usr/x86_64-w64-mingw32/include
LDFLAGS  := -L/usr/x86_64-w64-mingw32/include -lwsock32 -lws2_32

# Sources & objects
SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# ----------------------------------------------
#  Targets
# ----------------------------------------------
.PHONY: all clean debug release

all: $(BUILDDIR) $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

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

