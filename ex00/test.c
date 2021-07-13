#include<stdio.h>
#include<string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int main()
{
	char e1[1024]="Stingray sand lance golden shiner trout-perch:\0 frfjfirfjrifri";
	printf("%d\n",ft_strlen(e1));
	//char e1[1024]="Stingray sand lance golden shiner trout-perch:\0 frfjfirfjrifri";
	printf("%d\n",ft_strlen(" "));
	//char e1[1024]="Stingray sand lance golden shiner trout-perch:\0 frfjfirfjrifri";
	printf("%d\n",ft_strlen(""));
	printf("%d",ft_strlen("\0"));
}
