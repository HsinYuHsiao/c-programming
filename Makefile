CC=gcc
CFLAGS=-std=gnu99 -pedantic -Wall   
# gnu99: C99 standard with gnu extension
# -Wall: request compiler issue warnings for a wide range of questionable behavior 
# -Werror: treat all warnings as errors
# $(wildcard pattern): generate the list of .c files in the current directory
# $(patsubst pattern, replacement, text): replace .c endings with .o endings  
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRCS))
myProgram: $(OBJS) 
	gcc -o $@ $(OBJS) 
# $@ name of the current target

# built-in $< will set to the name of the first prerequisite of the rule
#%.o : %.c -> default rule: cc -c -o file.o file.c  
	#gcc $(CFLAGS) -c $< 

.PHONY:clean depend
clean:
	rm -rf myProgram *.o *.c~ *.h~ 
depend:
	makedepend $(SRCS)
# Add dependency information to avoid re-compiling every file
file1.o: header1.h header2.h 
file2.o: header3.h header4.h 
