#include<stdio.h>
#include<string.h>
int	chek(char *base)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (base[++i])
	{
		if (base[i] <= 32 || base[i] == 43 || base[i] == 45)
			return (0);
	}
	if (i == 0 || i == 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[++j])
			if (i != j)
				if (base[i] == base[j])
					return (0);
	}
	return (1);
}

int	search_in_base(char i, char *base)
{
	int	e;

	e = -1;
	while (base[++e])
		if (i == base[e])
			return (1);
	return (0);
}

int	base_to_int(char i, char *base)
{
	int	e;

	e = 0;
	while (base[e] != i)
		e++;
	return (e);
}

int	pre_transform(char *str, char *base, int i)
{
	int	size;
	int	num;
	int	e;

	size = 0;
	e = -1;
	while (base[size])
		size++;
	num = 0;
	i--;
	while (search_in_base(str[++i], base))
		num = num * size +(base_to_int(str[i], base));
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	negativ;

	if (chek(base) == 0)
		return (0);
	i = -1;
	negativ = 1;
	while (str[++i])
	{
		if ((str[i] == 45) || (str[i] == 43) || (str[i] <= 32)
			|| (str[i] >= 127))
		{
			if (str[i] == 45)
				negativ *= (-1);
		}
		else if (search_in_base(str[i], base))
		{
			return (negativ * pre_transform(str, base, i));
		}
		else
			return (0);
	}
	return (0);
}

int	main()
{
	printf("%d\n", ft_atoi_base ("123", "01"));
	printf("%d\n", ft_atoi_base("-+\n\t-+--12345A 12fef3", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("-+-+-12345 12fefe23","01234567"));
	printf("%d\n", ft_atoi_base("   ---+--+1234ab567", "01234"));
	printf("%d\n", ft_atoi_base("  \n ---+--+01fefe","01f"));
	return (0);
}

