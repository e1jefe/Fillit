

// t_position *coord;
// coord = ft_create_list(buffer);
// //ft_left_corner(coord);
// ft_push(coord);
// coord = coord->next;
void		ft_fillit(coord, map, map_size)
{
	ft_left_corner(coord);
	while (coord)
	{
		if (ft_small_push_check(coord, map, map_size) == 1) // move + push
		{
			ft_push(coord, map);
			coord = coord->next;
		}
		else
		{
			ft_clear(сoord,map);
			coord = coord->prev;
			if (ft_push_check(coord, map, map_size) == 1) // move -> can push? move:exit;
			{
				ft_push(coord);
				coord = coord->next;
			}
			else
			{
			//	if (coord == head)
			//		ft_fillit(coord, map_size++);
			//	else
					coord = coord->prev;
			}
		}
	}
}
#include "libft.h"
#include "f.h"

int	main()
{
	int i;
	char **pos;
	char **map;
	t_position *coord;
	coord = ft_create_list(buffer);
	map = ft_create_map(4);
	ft_fillit(coord, map, 4);re
//	ft_left_corner(coord);
//	ft_push(coord);
//	coord = coord->next;
//	pos = ft_strsplit("...#\n...#\n...#\n...#\n\n.##.\n.##.\n....\n....\n\n...#\n...#\n...#\n...#\n\n....\n..##\n..##\n....\n\n", '\n');
//	i = 1;
//	head = ft_create_list(pos, 10);
//	ft_left_corner(head);
	// while (head->next)
	// {
	// 	printf("tetrim # :%d", i);
	// 	//ft_left_corner(head);
	// 	printf(" %d%d\n" ,head->xy[0][0], head->xy[0][1]);
	// 	printf(" %d%d\n" ,head->xy[1][0], head->xy[1][1]);
	// 	printf(" %d%d\n" ,head->xy[2][0], head->xy[2][1]);
	// 	printf(" %d%d\n" ,head->xy[3][0], head->xy[3][1]);
	// 	head = head->next;
	// 	i++;
	// }

	return (0);
}












