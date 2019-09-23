#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"

# include <dirent.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>

typedef	struct	dirent		t_dirent;
typedef	struct	stat		t_stat;
typedef	struct	group		t_group;
typedef	struct	passwd		t_passwd;
typedef	struct	tm			t_time;

# define LS_L				1
# define LS_RR				2
# define LS_A				4
# define LS_R				8
# define LS_T				16

# define PATH_MAX			4096

void						ft_print_rep(char **av);
int							ft_parsing(int ac, char **av, int *flags);

typedef struct				s_file
{
	mode_t					st_mode;
	nlink_t					st_nlink;
	uid_t					st_uid;
	gid_t					st_gid;
	dev_t					st_rdev;
	off_t					st_size;
	blkcnt_t				st_blocks;
	time_t					time;
	int						ntime;
	char					*name;
	char					*path;
	struct s_file			*next;
}							t_file;

void						ft_error_flags(char name);
void						ft_error_files(char *name);
t_file						*ft_add_file(int nbr_file, char **files);
void						ft_sort_file(char **name, int nbr_files);
char						**ft_sort_file_r(char **name, int nbr_files);
int							ft_show(t_file *file, int flags, int i);
int							ft_created_file(char *f_name, t_file **lst_files,
		t_file **start, char *path);
t_file						*ft_sort_lst_r(t_file *list);
t_file						*ft_sort_lst_t(t_file *list);
void						check_file_mode(t_file *file);
void						check_file_perm_user(t_file *file);
void						check_file_perm_grp(t_file *file);
void						check_file_perm_other(t_file *file);
void						ft_show_long_list(t_file *file);
t_file						*ft_sort_lst_alpha(t_file *list);

#endif
