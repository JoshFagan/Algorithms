# Usage: just run make, it will pick up this Makefile as the default

SRCS = select.cpp

CC = /usr/bin/g++
LD = /usr/bin/g++

# Compiler options
# The -g option in CPPFLAGS will generate debug information,
CPPFLAGS = -g

IFLAGS = 
LDFLAGS =

# Using extra libraries
# If u are using any extra libraries u will have to update the LIBS =
LIBS = 

# Output of the make
# The Makefile produces your final binary as lab1
PROGRAM = select

OBJS = $(SRCS:.cc=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)


# Recompiling all sources
# If u want to recompile all your sourses run 
# 	make clean
# and then make
clean:
	rm -f $(PROGRAM)

