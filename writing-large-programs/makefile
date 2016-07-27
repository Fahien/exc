# Each group is known as a rule

# The first line in each rule gives a target file,
# followed by the files on which it depends

# The second line is a command to be executed if the target should 
# be to be rebuilt because of a change to one of its dependent files


justify: justify.o word.o line.o
	gcc -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h
	gcc -c justify.c

word.o: word.c word.h
	gcc -c word.c

line.o: line.c line.h
	gcc -c line.c
