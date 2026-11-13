#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - Prints information about a dog
 * @d: Pointer to the dog structure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(*dog));

	if (dog == NULL)
		return (NULL);

	dog->name = name;
	dog->age = age;
	dog->owner = owner;

	return (dog);
}
