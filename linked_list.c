#include "monty.h"

/**
* queue_node - adds a node to a stack_t stack in queue node
* @stack: stack head
* @n: number of the node
*
* Return: address of the new node. Otherwise NULL
*/
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *current;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
		return (new_node);
	}

	current = *stack;

	while (current->next)
	{
		current = current->next;
	}
	current->next = new_node;
	new_node->prev = current;
	new_node->next = NULL;

	return (new_node);
}

/**
 * add_node - adds a node to the start of a stack_t stack
 * @stack: stack head
 * @n: number for the new node
 *
 * Return: address of the new node. Otherwise NULL
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;

	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}

/**
 * print_stack - prints the contents of a stack_t stack
 * @stack: stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t n = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		n++;
	}

	return (n);
}

/**
 * free_stack - frees a dlistint_t linked list
 * @stack: list head
 *
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next_node;

	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
