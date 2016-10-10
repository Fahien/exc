# Each group is known as a rule

# The first line in each rule gives a target file,
# followed by the files on which it depends

# The second line is a command to be executed if the target should 
# be to be rebuilt because of a change to one of its dependent files


parts-database: parts-database.o readline.o
	gcc -o parts-database parts-database.o readline.o

parts-database.o: parts-database.c
	gcc -c parts-database.c

readline.o: readline.c readline.h
	gcc -c readline.c
