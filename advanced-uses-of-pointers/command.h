#include <string.h>
#include <stdio.h>

#define COMMAND_COUNT 9


typedef struct {
	char *name;
	void (*handler)();
} command;


void new_cmd() { printf("Invoked new command\n"); }
void open_cmd() { printf("Invoked open command\n"); }
void close_cmd() { printf("Invoked close command\n"); }
void close_all_cmd() { printf("Invoked close all command\n"); }
void save_cmd() { printf("Invoked save command\n"); }
void save_as_cmd() { printf("Invoked save as command\n"); }
void save_all_cmd() { printf("Invoked save all command\n"); }
void print_cmd() { printf("Invoked print command\n"); }
void exit_cmd() { printf("Invoked exit command\n"); }


command commands[COMMAND_COUNT] = {
	{"new", new_cmd},
	{"open", open_cmd},
	{"close", close_cmd},
	{"close all", close_all_cmd},
	{"save", save_cmd},
	{"save as", save_as_cmd},
	{"save all", save_all_cmd},
	{"print", print_cmd},
	{"exit", exit_cmd}
};


/// Searches the commands array for a matching command name,
// then calls the function associated with that name
void invoke(const char *command_name)
{
	for (int i = 0; i < COMMAND_COUNT; ++i) {
		if (strcmp(command_name, commands[i].name) == 0) {
			(*(commands[i].handler))();
			return;
		}
	}
	fprintf(stderr, "Command %s not found\n", command_name);
}

