#include<unistd.h>
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		write(1, &str[i], 1);
}

int main()
{
	char e1[1024]="Stingray sand lance golden shiner trout-perch: \0   привет";
	ft_putstr(e1);
	//printf("%d",ft_strlen(e1));
}
