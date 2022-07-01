CC=gcc
LDFLAGS=-ldl
#VPATH=./src/crio/
CFLAGS = -g -Wall
OBJECTS=crioMain.o NiFpga.o
EXECUTABLE=crioMain

include Makefile.inc

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)

crioMain.o: NiFpga_FPGA_code.h NiFpga.h

NiFpga.o: NiFpga.h

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
