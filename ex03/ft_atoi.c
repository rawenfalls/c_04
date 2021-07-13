int	number(char *nb, int start, int end)
{
	int	a;
	int	e;
	int	e1;
	int	number;

	number = 0;
	start--;
	while (++start < end)
	{
		a = 1;
		e = -1;
		e1 = start;
		while (end - (++e1) > 0)
			a *= 10;
		number = number + ((nb[start] - 48) * a);
	}
	return (number);
}

int	ft_atoi(char *str)
{
	int	i;
	int	r;
	int	negativ;

	i = -1;
	r = 0;
	negativ = 1;
	while (str[++i])
	{
		if ((str[i] == 45) || (str[i] == 43) || (str[i] <= 32)
			|| (str[i] >= 127))
		{
			if (str[i] == 45)
				negativ = negativ * (-1);
		}
		else if ((str[i] >= '0') && (str[i] <= '9'))
		{
			while (str[i + r] >= '0' && str[i + r] <= '9')
				r++;
			return (negativ * number(str, i, r + i));
		}
		else
			return (0);
	}
	return (0);
}
