#include<unistd.h>
int	write_me(int nb, int i)
{
	char	r;
	int		e;

	e = 1;
	while ((i--) > 0)
		e = e * 10;
	r = (nb / e) + '0';
	write(1, &r, 1);
	return (nb = (nb %e));
}

void	ft_putnbr(int nb)
{
	int	size;
	int	i;

	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * (-1));
	}
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		i = nb;
		size = 0;
		while ((i % 10) > 0)
		{
			size++;
			i = i / 10;
		}
		while ((size--) > 0)
		{
			i = size;
			nb = write_me(nb, i);
		}
	}
}
int	main()
{
	ft_putnbr(12345);

	ft_putnbr(0);

	ft_putnbr(42);

	ft_putnbr(-1);

	ft_putnbr(-12345);
}
