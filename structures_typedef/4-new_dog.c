#include <stdlib.h>
#include "dog.h"

/**
 * copy_str - Creates a copy of a string
 * @str: String to copy
 *
 * Return: Pointer to the copy, or NULL on failure
 */
char *copy_str(char *str)
{
	char *p;
	int i = 0;

	while (str[i] != '\0')
		i++;

	p = malloc(sizeof(char) * (i + 1));

	if (p == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		p[i] = str[i];

	p[i] = '\0';

	return (p);
}

/**
 * new_dog - Creates a new dog with copies of its strings
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Name of the dog's owner
 *
 * Return: Pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(*dog));

	if (dog == NULL)
		return (NULL);

	dog->name = copy_str(name);

	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = copy_str(owner);

	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	dog->age = age;

	return (dog);
}
