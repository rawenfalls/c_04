#include<stdio.h>
#include<string.h>
#include<unistd.h>
int	number_int(char *nb)
{
	int	i;
	int	a;
	int	e;
	int	e1;
	int	number;

	number = 0;
	i = 0;
	while (nb[i])
		i++;
	if (nb[0] == '0' && i == 1)
		return (0);
	else
	{
		e = -1;
		while (nb[++e])
		{
			a = 1;
			e1 = e;
			while (i - (++e1) > 0)
				a = a * 10;
			number = number + (((int)(nb[e]) - 48) * a);
		}
	}
	return (number);
}

int	number_char(char *str, int i)
{
	char	e[1024];
	int		r;

	r = 0;
	while (str[i + r] >= '0' && str[i + r] <= '9')
	{
		e[r] = str[i + r];
		r++;
	}
	e[r] = '\0';
	return (number_int(e));
}

int	ft_atoi(char *str)
{
	int	i;
	int	negativ;

	i = -1;
	negativ = 1;
	while (str[++i])
	{
		if ((str[i] == 45) || (str[i] == 43) || (str[i] == 32))
		{
			if (str[i] == 45)
				negativ = negativ * (-1);
		}
		else if ((str[i] >= '0') && (str[i] <= '9'))
			return (negativ * number_char(str, i));
		else
			return (0);
	}
	return (0);
}
int	main()
{
	 ft_atoi("-+-+--12345");
	 ft_atoi("-+-+-12345");
	 ft_atoi("   ---+--+1234ab567");
	return (0);
}
