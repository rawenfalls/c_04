#include<stdio.h>
#include<string.h>
#include<unistd.h>
int	chek(char *base)
{
	int	i;
	int	j;
	int	size;

	size = -1;
	i = -1;
	j = -1;
	while (base[++size])
	{
		if (base[size] == 43 || base[size] == 45)
			return (0);
	}
	if (size == 0 || size == 1)
		return (0);
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

void	write_me(int nbr, char *base, int size)
{
	char	r;

	r = base[nbr % size];
	if (nbr / size > 0)
		write_me(nbr / size, base, size);
	write(1, &r, 1);
	nbr = nbr / size;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	char	r;

	if (chek(base) == 0)
		return ;
	r = '0';
	size = 0;
	while (base[size])
		size++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base((-1) * nbr, base);
	}
	else if (nbr > 0)
		write_me(nbr, base, size);
	else if (nbr == 0)
		write(1, &r, 1);
}
int	main()
{
	ft_putnbr_base (123, "01");
	write(1, "\n", 1);
	ft_putnbr_base (1234, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base (1234, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base (0, "01");
	write(1, "\n", 1);
	ft_putnbr_base (-1234, "gfa");
	write(1, "\n", 1);
	ft_putnbr_base (-2, "012345");
	return (0);
}
