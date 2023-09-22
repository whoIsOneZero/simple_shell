#include "myshell.h"

/**
 * my_print_list - echo all the Linked List list_t elements
 * @head: a pointer to the head of the linked list
 * Return: The size of the linked list printed. dd.
 */
size_t my_print_list(const list_t *head)
{
	size_t size;

	size = 0;

	while (head != NULL)
	{
		/*Convert to string representation*/
		my_puts(my_convert_number(head->num, 10, 0));
		my_putchar(':'); /*Separate num and string*/
		my_putchar(' '); /*Line separator*/

		/*Print all strings stored in current node*/
		my_puts(head->str ? head->str : "(nil)");
		my_puts("\n");

		/*For the next iteration*/
		head = head->next;
		size++;
	}

	return (size);
}
