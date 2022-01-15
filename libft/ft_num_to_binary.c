



#include "libft.h"
#include <stdlib.h>

int	ft_num_to_binary(int num)
{
	char	 	*str;
	int		i;
	int		content;

	i = 1;
	content = num;
	while (content / 2 != 0 || content / 2 != 1)
	{
		if (content / 2 == 0 || content / 2 == 1)
		{
			i++;
			break ;
		}
		content = content / 2;
		i++;
	}
	str = (char *)malloc(sizeof(char) * i);
	content = num;
	while (i--)
	{
		str[i] = content % 2 + 48;
		content = content / 2;
	}
	return (ft_atoi(str));
}


