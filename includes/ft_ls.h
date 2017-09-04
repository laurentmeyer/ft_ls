#ifndef FT_LS_H

# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <stdio.h>
# include <dirent.h>

#define _DARWIN_NO_64_BIT_INODE
#define	FALSE 0
#define	TRUE !FALSE
#define SUCCESS 0
#define ERROR -1
#define NOT_DIRECTORY -2
#define STDERR 2

typedef struct			s_options {
	int 				sort_reverse : 1;
	int					sort_timemod : 1;
	int					display_dots : 1;
	int					display_long : 1;
	int					recursive : 1;
} 						t_options;

typedef struct			s_file {
	char				*dirname;
	char				*basename;
	struct stat			stat;
} 						t_file;

typedef void			(t_listdisplay)(t_list *elem);

t_file					*t_file_new(char *path, char *name, struct stat *stat);
t_listcmp				*select_sort_function(t_options *options);
t_options				get_options(int *argc_ptr, char ***argv_ptr);
char					*make_full_path(char *dirname, char *basename);
void					display_dir_contents(char *dirpath, t_options *options);
int						list_contents(char *path, t_list **alst);
int						insert_ordered(t_file *file,
												t_list **alst, t_options opt);
void					exit_msg(char *str);
void					exit_perror(char *str);

#endif
//
//struct stat { /* when _DARWIN_FEATURE_64_BIT_INODE is NOT defined */
//	dev_t    st_dev;    /* device inode resides on */
//	ino_t    st_ino;    /* inode's number */
//	mode_t   st_mode;   /* inode protection mode */
//	nlink_t  st_nlink;  /* number of hard links to the file */
//	uid_t    st_uid;    /* user-id of owner */
//	gid_t    st_gid;    /* group-id of owner */
//	dev_t    st_rdev;   /* device type, for special file inode */
//	struct timespec st_atimespec;  /* time of last access */
//	struct timespec st_mtimespec;  /* time of last data modification */
//	struct timespec st_ctimespec;  /* time of last file status change */
//	off_t    st_size;   /* file size, in bytes */
//	quad_t   st_blocks; /* blocks allocated for file */
//	u_long   st_blksize;/* optimal file sys I/O ops blocksize */
//	u_long   st_flags;  /* user defined flags for file */
//	u_long   st_gen;    /* file generation number */
//};
