#include <stdio.h>
#include <stdlib.h>


struct node {
	int value; // Data
	struct node *next; // Next node
};


/// Inserts a node into a linked list
struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		fprintf(stderr, "Could not allocate memory for a node\n");
		return NULL;
	}
	new_node->value = n;
	new_node->next = list;
	return new_node;
}


/// Searches a node into a linked list
struct node *search_list(struct node *list, int n)
{
	for (; list != NULL && list->value != n; list = list->next) {}
	return list;
}


/// Deletes a node from a linked list
void delete_from_list(struct node **list, int n)
{
	struct node *curr = *list;
	if (curr->value == n) { // Test head
		*list = (*list)->next;
		printf("Freeing %d\n", curr->value);
		free(curr);
	}
	else {
		while (curr->next != NULL && curr->next->value != n) {
			curr = curr->next;
		}
		if (curr->next == NULL) { // Node not found
			printf("Could not find %d\n", n);
		}
		else { // Found
			struct node *temp = curr->next;
			curr->next = curr->next->next;
			printf("Freeing %d\n", temp->value);
			free(temp);
		}
	}
}


/// Clears the linked list
void clear_list(struct node *list)
{
	for (struct node *iter = list, *next; iter != NULL; iter = next) {
		next = iter->next;
		printf("Freeing %d\n", iter->value);
		free(iter);
	}
}


/// Returns the number of times that n appears in the list
int count_occurrencies(struct node *list, int n)
{
	int occurrencies = 0;
	while(list != NULL) {
		if (list->value == n) { ++occurrencies; }
		list = list->next;
	}
	return occurrencies;
}


/// Returns a pointer to the last node that contains n
struct node *find_last(struct node *list, int n)
{
	struct node *last = NULL;
	while (list != NULL) {
		if (list->value == n) { last = list; }
		list = list->next;
	}
	return last;
}

