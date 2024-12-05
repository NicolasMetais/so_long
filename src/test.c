#include "../include/so_long.h"

void	getcheckpoints(t_checkpoint *checkpoint, size_t collect)
{
	size_t			i;
	t_checkpoint	*new;

	i = 0;
	while (i < collect)
	{
		checkpoint->x = i;
		checkpoint->y = i + 10;
		new = malloc(sizeof(*new));
		checkpoint->next = new;
		checkpoint = new;
		i++;
	}
	checkpoint->next = NULL;
}

void	dupboard(t_checkpoint *checkpoint)
{

	while (checkpoint)
	{
		printf("\nx:%zu\n", checkpoint->x);
		printf("y:%zu\n", checkpoint->y);
		checkpoint = checkpoint->next;
	}
}

int	main(void)
{
	t_checkpoint	*checkpoint;

	checkpoint = malloc(sizeof(checkpoint));
	getcheckpoints(checkpoint, 4);
	dupboard(checkpoint);
}