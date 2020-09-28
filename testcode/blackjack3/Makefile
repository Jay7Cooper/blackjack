# define the C compiler to use
CC       = gcc
# define compiler flags
CFLAGS   = -std=c11 -Wall -fmax-errors=10 -Wextra -pedantic
# define library paths in addition to /usr/lib
LFLAGS   = 
# define libraries to use
LIBS     = 
# define the object files that this project needs
OBJFILES = 
# define the name of the executable file
MAIN     = blackjack

# all of the below is generic - one typically only adjusts the above

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES) 
        
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJFILES) $(MAIN)
