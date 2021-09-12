#include "includes/minishell.h"

char	*parse_if_double_hook(char **line, t_pars *data)
{
	char	*chunk;
	int		size;
	int		index;

	index = -1;
	chunk = NULL;
	data->stop = ++data->move;
	while ((*line)[data->move] != '\0' && (*line)[data->move] != '\"')
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

char	*create_chunk(char **line, t_pars *data)
{
	char	*chunk;
	int		size;
	int		index;

	index = -1;
	chunk = NULL;
	data->stop = data->move;
	while ((*line)[data->move] != '\0' && (*line)[data->move] != '\''
		&& (*line)[data->move] != '\"' && (*line)[data->move] != ' ')
		data->move++;
	size = data->move - data->stop;
	chunk = malloc(sizeof (char) * size + 1);
	if (chunk == NULL)
		return (NULL);
	while (++index != size)
		chunk[index] = (*line)[data->stop++];
	chunk[size] = '\0';
	index = -1;
	while (++index != size)
		(*line)++;
	return (chunk);
}

char	*check_create_cmd(char **line, t_pars *data, char *chunk, char *token)
{
	char	*tmp;

	while ((*line)[data->move] && (*line)[data->move] != ' ')
	{
		if ((*line)[data->move] == '\'')
			chunk = parse_if_one_hook(line, data);
		else if ((*line)[data->move] == '\"')
			chunk = parse_if_double_hook(line, data);
		else
			chunk = create_chunk(line, data);
		if (chunk != NULL && token == NULL)
			token = chunk;
		else if (token != NULL)
		{
			tmp = token;
			token = ft_strjoin(token, chunk);
			free(tmp);
			free(chunk);
		}
		else
			return (NULL);
		ft_create_pars_data(data);
	}
	return (token);
}

char	*check_and_create_arg(char **line, t_pars *d, char *chunk, char *token)
{
	char	*tmp;

	while ((*line)[d->move] && (*line)[d->move] != ' ')
	{
		if ((*line)[d->move] == '\'')
			chunk = parse_if_one_hook(line, d);
		else if ((*line)[d->move] == '\"')
			chunk = parse_if_double_hook(line, d);
		else
			chunk = create_chunk(line, d);
		if (chunk != NULL && token == NULL)
			token = chunk;
		else if (token != NULL)
		{
			tmp = token;
			token = ft_strjoin(token, chunk);
			free(tmp);
			free(chunk);
		}
		else
			return (NULL);
		ft_create_pars_data(d);
	}
	return (token);
}

char	**split_comands_by_token_without_quotes(char *line, int index)
{
	t_pars	data;
	char	**tokens;

	ft_create_pars_data(&data);
	data.size = qty_symbol(line, ' ', '\0') + 1;
	tokens = malloc_dubble_mass_or_exit(data.size + 1);
	while (*line == ' ')
		line++;
	while (*line != '\0')
	{
		if (index == 0)
			tokens[index++] = check_create_cmd(&line, &data, NULL, NULL);
		else
		{
			while (*line == ' ')
				line++;
			tokens[index++] = check_and_create_arg(&line, &data, NULL, NULL);
		}
		line++;
	}
	while (tokens[index] != NULL)
		tokens[index++] = NULL;
	return (tokens);
}
