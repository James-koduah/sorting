#include "sort.h"


void swap_nodes(listint_t *current, listint_t *last, listint_t **list);
/**
 * insertion_sort_list - Implements the insertion sorting algorithm
 * @list: A Doubly linked list to be sorted
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = (*list)->next;
	listint_t *node;

	while (head != NULL)
	{
		node = head;
		while (node->prev != NULL && (node->prev)->n > node->n)
		{
			swap_nodes(node, node->prev, list);
			print_list(*list);
		}
		head = head->next;
	}
}

/**
 * swap_nodes - Function to swap in place two nodes
 * @current: The node with a greater index in the list
 * @last: The node with the smaller index in the list
 * @list: the head of the original list
 * when we swap nodes we need to get the new head of the list os as to print
 * it out
 * Return: Nothing
 */
void swap_nodes(listint_t *current, listint_t *last, listint_t **list)
{
	if (last->prev != NULL)
	{
		(last->prev)->next = current;
		current->prev = last->prev;
	}
	else
	{
		current->prev = NULL;
		*list = current;
	}
	if (current->next != NULL)
	{
		(current->next)->prev = last;
		last->next = current->next;
	}
	else
	{
		last->next = NULL;
	}
	current->next = last;
	last->prev = current;
}
