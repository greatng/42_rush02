/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboonint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:54:02 by sboonint          #+#    #+#             */
/*   Updated: 2022/01/30 11:46:44 by sboonint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	checkerror(int argc);
int	checkargv(char *argv);
void	toconverter(char *nbr, char *path);

int	main(int argc, char **argv)
{
	char	*path;

	path = "numbers.dict";
	if (checkerror(argc))
	{
		if (argc == 2)
		{
			if(checkargv(argv[1]))
				toconverter(argv[1], path);
		}
		if (argc == 3)
		{
			if (checkargv(argv[2]))
			{
				path = argv[1];
				toconverter(argv[2], path);
			}
		}
	}
	return (0);
}
