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

void		search(unsigned int n);
void	spliter(unsigned int input);
void	ft_putchar(char c);
/*int	ft_atoi(char *str);*/

void	check_input(unsigned int input)
{
	if (input < 0 || input > 4294967295)
		write(1, "Error\n", 6);
	else
		spliter(input);
}

void	converter(char *str)
{
	unsigned int	input;

	input = atoi(str);
	check_input(input);
}

void	spliter(unsigned int input)
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
			search(out);
			search(tmp);
			input = input % tmp;
			tmp = tmp / 10;
		}
		else if (input <= 99)
		{
			outb = input % 10;
			if (input <= 20)
			{
				out = input;
				search(out);
			}
			else
			{
				out = input - outb;
				search(out);
				if (outb != 0)
				       search(outb);
			}
			tmp = 0;	
		}	
	}
}

int	main(void)
{
	char	*str;

	str = "100000";
	converter(str);
}
