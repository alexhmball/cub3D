#include "cub3d.h"

unsigned int hash_key(char *str)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		hash += str[i];
		i++;
	}
	hash = hash % SIZE;
	return (hash);
}

t_hex	**create_table(void)
{
	t_hex **hash_table;
	int i;

	i = 0;
	hash_table = (t_hex **)malloc(sizeof(t_hex *) * SIZE);
	while (i < SIZE)
	{
		hash_table[i] = (t_hex *)malloc(sizeof(t_hex));
		hash_table[i]->key = NULL;
		hash_table[i]->next = NULL;
		i++;
	}
	return (hash_table);
}

t_hex	*create_hex(char *key, char *colour, t_hex *new)
{
	new->key = ft_strdup(key);
	new->colour = hextoi(colour);
	new->next = NULL;
	return (new);
}

t_hex	**insert_hex(t_hex **hash_table, char *key, char *colour)
{
	int index;
	t_hex *head;
	t_hex *new;
	t_hex *temp;

	index = hash_key(key);
	head = hash_table[index];
	if (head->key == NULL)
	{
		hash_table[index] = create_hex(key, colour, hash_table[index]);
		return (hash_table);
	}
	new = (t_hex *)malloc(sizeof(t_hex));
	new = create_hex(key, colour, new);
	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (hash_table);
}

int	find_hex_colour(char *key, t_hex **hash_table, int size)
{
	int index;
	t_hex *head;
	t_hex *temp;

	index = hash_key(key);
	head = hash_table[index];
	if (!key)
		return (0);
	if (!ft_strncmp(head->key, key, size))
		return (head->colour);
	temp = head->next;
	while (temp)
	{
		if (!ft_strncmp(temp->key, key, size))
			return (temp->colour);
		temp = temp->next;
	}
	return (0);
}