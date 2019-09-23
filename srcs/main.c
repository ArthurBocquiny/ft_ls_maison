#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	int		flags;
	int		i;
	t_file	*file;

	i = 0;
	i = ft_parsing(ac, av, &flags);
	ac -= i;
	av += i;
	file = ft_add_file(ac, av);
	if (!file)
		return (0);
	ft_show(file, flags, -1);
	return (0);
}
