#include "main.h"

/**
 * _isalpha  - Checks if a character is alphabetic
 * @c: Character to check
 *
 * Return: 1 if alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
