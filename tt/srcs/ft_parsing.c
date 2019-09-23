#include "../includes/ft_ls.h"

int		ft_strschr(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_stock_flags(int *flags, char *options)
{
	int		i;
	int		j;

	j = 1;
	i = 0;
	while (options[j])
	{
		if ((i = ft_strschr("lRart", options[j])) == -1)
			ft_error_flags(options[j]);
		*flags |= (1 << i);
		j++;
	}
}

int		ft_parsing(int ac, char **f_names, int *flags)
{
	int		i;

	i = 0;
	while (++i < ac && f_names[i][0] == '-' && f_names[i][1])
	{
		if (f_names[i][1] == '-')
			return (i + 1);
		ft_stock_flags(flags, f_names[i]);
	}
	return (i);
}
