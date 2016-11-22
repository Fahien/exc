#include "linked-list.h"

int main()
{
	// Initialize a list
	struct node *head = malloc(sizeof(struct node));
	head->value = 7;
	for (int i = 7; i > 0; --i) {
		head = add_to_list(head, i);
		if (head == NULL) { return EXIT_FAILURE; }
	}

	// Delete 1 and 4
	delete_from_list(&head, 1);
	delete_from_list(&head, 4);

	// Write out the list
	for (struct node *iter = head; iter != NULL; iter = iter->next) { printf("%d ", iter->value); }
	printf("\b\n");

	// Search 5
	struct node *found = search_list(head, 5);
	if (found != NULL) { printf("%d found\n", found->value); }

	// Search 10
	found = search_list(head, 10);
	if (found == NULL) { printf("10 not found\n"); }

	// Count 7 and 2
	printf("The list contains %d seven\n", count_occurrencies(head, 7));
	printf("The list contains %d two\n", count_occurrencies(head, 2));

	// Find last 7
	struct node *last = find_last(head, 7);
	if (last->next != NULL) { fprintf(stderr, "That seven is not the last one\n"); }
	else { printf("Found %d\n", last->value); }

	// Find 1
	last = find_last(head, 1);
	if (last != NULL) { fprintf(stderr, "Found an inexistent element?!\n"); }
	else { printf("1 not found\n"); }

	// Free memory
	clear_list(head);
	return EXIT_SUCCESS;
}

