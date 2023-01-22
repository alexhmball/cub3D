#include "cub3d.h"

static int find_hex_val(char c)
{
	int i;
	char *compare;

	i = 0;
	compare = "ABCDEF";
	while (i < 6)
	{
		if (c == compare[i])
			return (i + 10);
		i++;
	}
	return (0);
}

int hextoi(char *hex)
{
	int i;
	int ret;
	int power;

	i = 0;
	ret = 0;
	power = 5;
	while (hex[i])
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			ret += (ft_atoi(&hex[i]) * (int)pow(16, power));
		else
			ret += (find_hex_val(hex[i]) * (int)pow(16, power));
		i++;
		power--;
	}
	return (ret);
}