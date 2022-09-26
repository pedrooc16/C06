/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:38:05 by rreis-de          #+#    #+#             */
/*   Updated: 2022/09/25 15:54:19 by pecosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**ft_order(int argc, char **argv)
{
	int		i;
	int		k;
	char	*swap;

	i = 1;
	while (i < argc - 1)
	{
		k = i + 1;
		while (k < argc)
		{
			if (ft_strcmp(argv[i], argv[k]) > 0)
			{
				swap = argv[i];
				argv[i] = argv[k];
				argv[k] = swap;
			}
			k++;
		}
		i++;
	}
	return (argv);
}

int	main(int argc, char	**argv)
{
	int	i;
	int	k;

	ft_order(argc, argv);
	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			write(1, &argv[i][k], 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
