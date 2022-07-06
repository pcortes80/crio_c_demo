#----------------------------------------------------------------------------
# Macros
#----------------------------------------------------------------------------

# Compiler to use
CC := gcc

#----------------------------------------------------------------------------
# Setting of target
#----------------------------------------------------------------------------

# Source file directories
SRCDIR := ./src

# Directory of executable
BINDIR := ./bin

LDFLAGS = -ldl
EXECUTABLE = crio
OBJECTS = crioMain.o NiFpga.o

# Include header file directories
INC := -I ./include

all: $(OBJECTS)
	$(CC) $(SRCDIR)/crioMain.o include/NiFpga.o $(LDFLAGS) -o $(EXECUTABLE)

crioMain.o:
	$(CC) -c $(SRCDIR)/crioMain.c -o $(SRCDIR)/crioMain.o

NiFpga.o:
	$(CC) -c include/NiFpga.c -o include/NiFpga.o

clean:
	rm -f $(EXECUTABLE) include/NiFpga.o $(SRCDIR)/crioMain.o
