/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:21:00 by pngamcha          #+#    #+#             */
/*   Updated: 2022/01/30 16:23:54 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

unsigned int	ft_atoi(char *str);

void			printvalue(char *dict);

void	search(unsigned int n, char **dict, int *init)
{
	int	line;
	int	found;

	line = 0;
	found = 0;
	if (*init != 0)
		write(1, " ", 1);
	while (dict[line++])
	{
		if (ft_atoi(dict[line - 1]) == n)
		{
			found = 1;
			*init = *init + 1;
			printvalue(dict[line - 1]);
			break ;
		}
	}
	if (!found)
		write(1, "Dict Error\n", 11);
}
