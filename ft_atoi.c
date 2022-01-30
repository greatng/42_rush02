/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:07:13 by pngamcha          #+#    #+#             */
/*   Updated: 2022/01/25 14:37:41 by pngamcha         ###   ########.fr       */
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
	int	i;
	unsigned int	nbr;

	nbr = 0;
	i = ft_checkspace(str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i++] - 48);
	}
	return (nbr);
}
