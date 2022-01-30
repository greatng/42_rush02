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
void	search(unsigned int n, char **dict);
void	spliter(unsigned int input, char **dict);
void	ft_putchar(char c);
/*int	ft_atoi(char *str);*/

void	check_input(unsigned int input, char **dict)
{
	if (input < 0 || input > 4294967295)
		write(1, "Error\n", 6);
	else
		spliter(input, dict);
}

void	converter(char *str, char **dict)
{
	unsigned int	input;

	input = atoi(str);
	check_input(input, dict);
}

void	spliter(unsigned int input, char **dict)
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
			search(out, dict);
			search(tmp, dict);
			input = input % tmp;
			tmp = tmp / 10;
		}
		else if (input <= 99)
		{
			outb = input % 10;
			if (input <= 20)
			{
				out = input;
				search(out, dict);
			}
			else
			{
				out = input - outb;
				search(out, dict);
				if (outb != 0)
				       search(outb, dict);
			}
			tmp = 0;	
		}	
	}
}

int	main(void)
{
	char	*str;
	char	**dict;

	dict = dict_init("numbers.dict");
	str = "100000";
	converter(str, dict);
	setfree(dict);
}
