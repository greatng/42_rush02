/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:03:26 by pngamcha          #+#    #+#             */
/*   Updated: 2022/01/30 16:23:03 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

unsigned int	ft_atoi(char *str);

char	**assigndict(char **dict, char *dictpath, int line)
{
	int		fd;
	int		i;
	int		j;
	char	buff;

	fd = open(dictpath, O_RDONLY, 0);
	i = 0;
	j = 0;
	while (read(fd, &buff, 1) == 1 && i < line)
	{
		if (buff == '\n')
		{
			dict[i][j] = '\0';
			j = 0;
			i++;
			continue ;
		}
		dict[i][j] = buff;
		j++;
	}
	dict[i] = 0;
	close(fd);
	return (dict);
}

char	**memalloc(int count, int line)
{
	char	**dict;
	int		i;

	dict = (char **)malloc(sizeof(char *) * (line + 1));
	i = 0;
	while (i < line - 1)
	{
		dict[i] = (char *)malloc(sizeof(char) * count);
		i++;
	}
	return (dict);
}

char	**dict_init(char *dictpath)
{
	int		i;
	int		count;
	int		fd;
	int		line;
	char	buff;

	i = 0;
	count = 0;
	line = 0;
	fd = open(dictpath, O_RDONLY, 0);
	while (1)
	{
		i = read(fd, &buff, 1);
		count = count + i;
		if (buff == '\n')
			line = line + 1;
		if (i < 1)
			break ;
	}
	close(fd);
	return (assigndict(memalloc(count, line), dictpath, line));
}

void	printvalue(char *dict)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (dict[i] != ':')
		i++;
	i = i + 1;
	while (dict[i])
	{
		if (dict[i] == ' ' && space == 0)
		{
			i++;
			continue ;
		}
		else
			space = 1;
		write(1, &dict[i++], 1);
	}
}

void	setfree(char **dict)
{
	int	i;

	i = 0;
	if (!dict)
		return ;
	while (dict[i])
	{
		free(dict[i]);
		dict[i] = NULL;
		i++;
	}
	free(dict);
	dict = NULL;
}
