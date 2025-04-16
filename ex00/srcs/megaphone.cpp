#include <cctype>
#include <cstdio>
#include <iostream>

int main(int ac, char **av)
{
	int i = 1;
	int j = 0;

	if (ac <= 1)
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE";
	else
	{
		while(i < ac)
		{
			while(av[i][j] != '\0')
			{
				std::cout << (char )toupper(av[i][j]);
				j++;
			}
			j^=j;
			i++;
		}
	}
	std::cout << '\n';
	return 0;
}
