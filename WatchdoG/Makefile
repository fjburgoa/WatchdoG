# MAKEFILE DE JAVIER B.

# define the C compiler to use
CXX = g++

# define any compile-time flags
CFLAGS = -Wall -g

# includes
INCLUDES = -I/usr/local/include

# define the C source files
SRCS = main.cpp

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = -L/usr/local/lib

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibna
LIBS = -lwiringPi

# define the CPP object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
OBJS = $(SRCS:.cpp=.o)

# define the executable file
MAIN = WatchdoG

all:    $(MAIN)
	@echo  Simple compiler named WatchdoG has been compiled
$(MAIN): $(OBJS) 
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

clean:
	$(RM) *.o *~ $(MAIN)



