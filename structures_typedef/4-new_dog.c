#include <stdlib.h>
#include "dog.h"

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
	int i = 0;

	dog = malloc(sizeof(*dog));

	if (dog == NULL)
		return (NULL);

	while (name[i] != '\0')
		i++;

	dog->name = malloc(sizeof(char) * (i + 1));

	if (dog->name == NULL)
		return (NULL);

	for (i = 0; name[i] != '\0'; i++)
		dog->name[i] = name[i];

	dog->name[i] = '\0';
	i = 0;

	while (owner[i] != '\0')
		i++;

	dog->owner = malloc(sizeof(char) * (i + 1));

	if (dog->owner == NULL)
		return (NULL);

	for (i = 0; owner[i] != '\0'; i++)
		dog->owner[i] = owner[i];

	dog->owner[i] = '\0';
	dog->age = age;

	return (dog);
}
