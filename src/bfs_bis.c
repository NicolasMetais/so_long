#include "../include/so_long.h"

void	locatepos(t_locate *locate, size_t actualpos, size_t **pathtab)
{
	size_t			i;
	size_t			j;

	i = 0;
	while (pathtab[i])
	{
		j = 0;
		while (pathtab[i][j])
		{
			if (actualpos == pathtab[i][j])
			{
				locate->x = j;
				locate->y = i;
			}
			j++;
		}
	i++;
	}
}