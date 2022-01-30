/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvachira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:12:17 by nvachira          #+#    #+#             */
/*   Updated: 2022/01/30 11:17:23 by nvachira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
void    setfree(char **dict);
char 	**dict_init(char *dictpath);
void	search(unsigned int n, char **dict, int *init);
void	spliter(unsigned int input, char **dict, int *init);
void	ft_putchar(char c);
/*int	ft_atoi(char *str);*/

void	check_input(unsigned int input, char **dict)
{
	int	init;

	init = 0;
	if (input < 0 || input > 4294967295)
		write(1, "Error\n", 6);
	else
		spliter(input, dict, &init);
}

void	converter(char *str, char **dict)
{
	unsigned int	input;

	input = atoi(str);
	check_input(input, dict);
}

void	spliter(unsigned int input, char **dict, int *init)
{
	unsigned int	tmp;
	unsigned int	out;
	unsigned int	outb;

	tmp = 1000000000;
	while (tmp != 0)
	{
		if (input < tmp)
		       tmp = tmp / 10;
		else if (input >= tmp&& input >= 100)
		{	
			out = input / tmp;
			search(out, dict, init);
			search(tmp, dict, init);
			input = input % tmp;
			tmp = tmp / 10;
		}
		else if (input <= 99)
		{
			outb = input % 10;
			if (input <= 20)
			{
				out = input;
				search(out, dict, init);
			}
			else
			{
				out = input - outb;
				search(out, dict, init);
				if (outb != 0)
				       search(outb, dict, init);
			}
			tmp = 0;	
		}	
	}
}

void	toconverter(char *nbr, char *path)
{
	char	**dict;

	dict = dict_init(path);
	converter(nbr, dict);
	setfree(dict);
	write(1, "\n", 1);
}
