#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "readline.h"

#define INSERT_COMMAND 'i'
#define SEARCH_COMMAND 's'
#define UPDATE_COMMAND 'u'
#define PRINT_COMMAND 'p'
#define QUIT_COMMAND 'q'

#define NAME_LEN 25
#define PARTS_MAX 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[PARTS_MAX];

int parts_count = 0; // number of parts currently stored

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/// Prompts the user to enter an operation code, then calls a function to perform the requested action.
// Repeats until the user enters 'q'. Prints an error message if the user enters an illegal code
int main(void)
{
	
	while (true) {
		char command = 0;
		printf("Enter operation code: ");
		scanf(" %c", &command); // prompt user to enter command code

		switch (command) {
		  case INSERT_COMMAND:
			insert();
			break;
		  case SEARCH_COMMAND:
			search();
			break;
		  case UPDATE_COMMAND:
			update();
			break;
		  case PRINT_COMMAND:
			print();
			break;
		  case QUIT_COMMAND:
			goto EXIT;
		  default: // Error
			fprintf(stderr, "Invalid command: %c\n", command);
		}

	}

EXIT:
	return EXIT_SUCCESS;
}


/// Looks up a part number in the inventory array.
// Returns the array index if the part number is found; otherwise return -1.
int find_part(int number)
{
	for (int i = 0; i < parts_count; ++i) {
		if (inventory[i].number == number) { return i; }
	}
	return -1;
}

/// Prompts the user for information about a new part and then inserts the part into the database.
// Prints an error message and returns prematurely if the part already exists or the database is full.
void insert(void)
{
	int part_number;

	if (parts_count == PARTS_MAX) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);
	if (find_part(part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	inventory[parts_count].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[parts_count].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[parts_count].on_hand);
	++parts_count;
}


/// Prompts the user to enter a part number, then looks up the part in the database.
// If the part exists, prints the name and quantity on hand; if not, prints an error message.
void search(void)
{
	int i, number;
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else {
		fprintf(stderr, "Part not fount.\n");
	}
}


/// Prompts the user to enter a part number. Prints an error message if the part desn't exist;
// otherwise, prompts the user to enter change in quantity on hand and updates the database.
void update(void)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else {
		printf("Part not found.\n");
	}
}


/// Prints a listing of all parts in the database, showing the part number, part name, and quantity on hand.
//Parts are printed in the order in which they were entered into the database.
void print(void)
{
	printf("Part Number\tPart Name\tQuantity on Hand\n");
	for (int i = 0; i < parts_count; ++i) {
		printf("%7d\t%-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
	}
}
