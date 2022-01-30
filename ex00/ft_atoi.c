/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:07:13 by pngamcha          #+#    #+#             */
/*   Updated: 2022/01/30 16:01:38 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkspace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	nbr;
	int				i;

	nbr = 0;
	i = ft_checkspace(str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i++] - 48);
	}
	return (nbr);
}
