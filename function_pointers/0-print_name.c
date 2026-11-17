#include "function_pointers.h"

/**
 * print_name - Calls a function to print a name
 * @name: Name to print
 * @f: Pointer to the function
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
