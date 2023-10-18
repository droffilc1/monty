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
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		fprintf(stderr, "Error: memory allocation failed\n");
		free(new);
		exit(EXIT_FAILURE);
	}
	new->n = n;

	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}
	return (new);
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
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: memory allocation failed\n");
		free(new);
		exit(EXIT_FAILURE);
	}
	new->n = n;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
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

	if (stack)
	{
		next_node = stack->next;
		while (current)
		{
			free(current);
			current = next_node;
			if (next_node)
				next_node = next_node->next;
		}
	}
}
