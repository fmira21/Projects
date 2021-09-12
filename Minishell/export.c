#include "includes/minishell.h"

void	export_with_no_arg(t_list **envp_list)
{
	char	**export;
	t_list	*tmp_list;
	size_t	qty_exist_elem;

	tmp_list = *envp_list;
	export = NULL;
	qty_exist_elem = count_elem_in_list(envp_list);
	export = malloc_dubble_mass_or_exit(qty_exist_elem);
	export = fill_double_mas_from_list(envp_list, qty_exist_elem, export);
	export = sort_bubble_double_massive_char(export);
	check_empty_elems_and_join_dec_x(tmp_list, export, qty_exist_elem);
	print_double_massive_char(export, qty_exist_elem);
	free_double_massive(export);
}

void	export(t_list **envp_list, char *arg)
{
	if (!arg)
		export_with_no_arg(envp_list);
	else
	{
		if (check_arg(arg) == KEY_SEP_VALUE)
			push_key_sep_value(envp_list, arg);
		else if (check_arg(arg) == KEY_SEP)
			push_key_sep(envp_list, arg);
		else if (check_arg(arg) == KEY)
			push_key(envp_list, arg);
		else if (check_arg(arg) == 0)
			return ;
		else
			perror("Error: Invalid a valid identifier\n");
	}
}