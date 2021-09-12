#include "includes/minishell.h"

int	qty_symbol(const char *string, char symbol, char symbol_to_stop_condition)
{
	int	i;
	int	qty_symbol;

	i = 0;
	qty_symbol = 0;
	while (string[i] != '\0' && string[i] != symbol_to_stop_condition)
	{
		if (string[i] == symbol)
			qty_symbol++;
		i++;
	}
	return (qty_symbol);
}

void	ft_create_pars_data(t_pars *data)
{
	data->move = 0;
	data->stop = 0;
	data->size = 0;
}

char	*parse_if_one_hook(char **line, t_pars *data)
{
	char	*chunk;
	int		size;
	int		index;

	index = -1;
	chunk = NULL;
	data->stop = ++data->move;
	while ((*line)[data->move] != '\0' && (*line)[data->move] != '\'')
		data->move++;
	if ((*line)[data->move] == '\0')
		return (NULL);
	size = data->move - data->stop;
	chunk = malloc(sizeof (char) * size + 1);
	if (chunk == NULL)
		return (NULL);
	while (++index != size)
		chunk[index] = (*line)[data->stop++];
	chunk[size] = '\0';
	index = -1;
	while (index++ != data->move)
		(*line)++;
	return (chunk);
}

char	*pars_of_command(char **cmd)
{
	char		**cmd_value;
	struct stat	buf;
	int			index;

	index = 0;
	cmd[index] = ignore_spaces(cmd[index]);
	if (stat(cmd[index], &buf) != -1)
	{
		cmd_value = ft_split(cmd[index], '/');
		index = 0;
		while (cmd_value[index] != NULL)
			index++;
		return (cmd_value[--index]);
	}
	return (NULL);
}
