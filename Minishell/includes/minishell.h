#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <curses.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>

# define SAME 0
# define CHANGE 1
# define BEFORE 0
# define AFTHER 1
# define KEY 1
# define KEY_SEP 2
# define KEY_SEP_VALUE 3
# define SIGINT 2
# define SIGQUIT 3
# define ERR1 "ERROR"
# define SIGTSTP 18

typedef struct s_data
{
	int			is_pipe;
	int			is_inter;
	int			proc_status;
	int			redir_flag;
	int			*redir_mass;
	int			parent;
	int			current;
	char		**envp_mass;
	char		**path_value;
	int			statint;
	int			pipefds[2];
	int			redirfds[2];
	int			wait;
	int			pipe_length;
	int			redir_length;
	int			input;
	struct stat	buf;
	int 		pipe_status;
	int			redir_status;
	pid_t		*pipe_pids;
	pid_t		*redir_pids;
	char 		**redir_toks;
	char		*str_buf;
	int			j;
}				t_data;

typedef struct s_list
{
	char			*key;
	char			*sep;
	char			*value;
	struct s_list	*next;
}					t_list;

typedef struct s_pars
{
	int		move;
	int		stop;
	int		size;
}				t_pars;

t_data	g_lobal;

int		cmd_parser(t_list **envp_list, char **command);
void	free_double_massive(char **double_massive);
void	print_double_massive_char(char **double_massive, size_t size);
char	**sort_bubble_double_massive_char(char **keys);
char	**join_str_to_each_str_double_mass(char **keys, const char *s, int pos);
char	*malloc_getcwd(void);
void	just_cd(char **cmd, t_list **envp_list);
void	cd_with_arg(t_list **envp_list);
void	cd(char **cmd, t_list **envp_list);
int		is_env(char *s);
int		parse_env(char *s, t_list **envp_list);
void	echo_n(char **command);
void	check_envs(char *s, t_list **envp_list);
void	echo_conv(char **command, t_list **envp_list);
void	msh_echo(char **command, t_list **envp_list);
int		check_spaces(char *str);
int		checker(char *line);
void	init_vars(void);
int		parse_entrypoint(t_list **envp_list, char **pipeline);
int		msh_loop(t_list **envp_list);
void	check_empty_elems_and_join_ksv(t_list *tmp_list, char **exp, size_t i);
void	check_empty_elems_and_join_ks(t_list *tmp_list, char **exp, size_t i);
void	check_empty_elems_and_join_dec_x(t_list *unused, char **exp, size_t qty);
char	**malloc_dubble_mass_or_exit(size_t size);
char	**fill_double_mas_from_list(t_list **envp, size_t qty, char **export);
void	get_envp(char **envp, t_list **envp_list, int index);
void	env(t_list **envp_list);
int		exec_command(int status, char **commands);
void	init_exec_commands(t_list *path, char *command, t_list **envp_list);
int		parent_exec(int status, int pid);
int		search_of_command(char **cmd, t_list **envp_list);
int		check_arg(char *arg);
void	push_key_sep_value(t_list **envp_list, char *arg);
void	push_key_sep(t_list **envp_list, char *arg);
void	push_key(t_list **envp_list, char *arg);
void	export_with_no_arg(t_list **envp_list);
void	export(t_list **envp_list, char *arg);
char	*get_key(char *envp);
char	*get_value(char *envp);
char	*get_sep(char *envp);
t_list	*search_key_list(t_list **begin_list, const char *key);
size_t	count_elem_in_list(t_list **envp_list);
void	clean_envp_list(t_list **begin_list);
t_list	*ft_create_elem(char *key, char *sep, char *value);
void	ft_push_back_list(t_list **list, char *key, char *sep, char *value);
void	ft_push_next_list(t_list **list, char *key, char *sep, char *value);
char	**split_sa(char *line, char sa);
int		cmd_compare(char *s1, char *s2);
void	exec_unset(char **command, t_list **envp_list, int i);
char	*ignore_spaces(char const *s);
char	*parse_if_double_hook(char **line, t_pars *data);
char	*create_chunk(char **line, t_pars *data);
char	*check_create_cmd(char **line, t_pars *data, char *chunk, char *token);
char	*check_and_create_arg(char **line, t_pars *d, char *chunk, char *token);
char	**split_comands_by_token_without_quotes(char *line, int index);
int		qty_symbol(const char *string, char symbol, char symbol_to_stop_condition);
void	ft_create_pars_data(t_pars *data);
char	*parse_if_one_hook(char **line, t_pars *data);
char	*pars_of_command(char **cmd);
int		ignore_quotes(char c);
void	single_command(char **cmds, char *command, t_list **envp_list);
void	operate_pipefds(int i);
void	pipe_children(char **cmds, char **pipeline, t_list **envp_list);
void	wait_children(void);
void	pwd(t_list **envp_list);
void	unset(t_list **envp_list, const char *key);
char	**ft_split2(char const *s, char c[2]);;
void	exec_double_right(char **str, t_list **envp_list, int i);
void	exec_single_left(char **str, t_list **envp_list, int i);
void	exec_double_left(char *buf, char **str, t_list **envp_list);
void	exec_nonempty(char **str, char *buf, t_list **envp_list, int i);
int		check_invalid(char *str, int i);
void	fill_right(char *str, int i, int j);
void	fill_redirs(int numredir, char *str);
int		find_redir(char *str);
void	read_empty(char *buf);
char	**split_sa2(char *line, char sa[2]);
int		check_extra(char *str, int i);
void	wait_redir_children(void);
void	exec_redir_children(char **str, char *buf, t_list **envp_list);
void	redir_parse(char **cmds, t_list **envp_list);
int		redir_detect(char **cmd);
void	sig_handler(int sig);
void	exec_export(char **command, t_list **envp_list, int i);
void	rl_replace_line();

char	*dvs_strdup(const char *string, size_t size_string);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
int	ft_strcmp(const char *str1, const char *str2);
char	*ft_strchr(const char *s, int c);
int		ft_isalpha(int c);


#endif