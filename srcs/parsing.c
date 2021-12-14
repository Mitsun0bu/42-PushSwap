/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:49:59 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/14 12:45:43 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_arg(int argc, char **argv)
{
	if (arg_is_nbr(argc, argv) == 0)
		return (-1);
	if (arg_is_int(argc, argv) == 0)
		return (-1);
	if (check_dub(argc, argv) == 1)
		return (-1);
	return (0);
}

int	arg_is_nbr(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][0] == '-' && ft_strlen(argv[i]) < 2)
				return (0);
			if (argv[i][j] == '-' && j != 0)
				return (0);
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_is_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
			return (0);
		if (ft_strlen(argv[i]) == 11)
		{
			if (argv[i][0] != '-')
				return (0);
			if (ft_strncmp(argv[i], "-2147483648", 11) > 0)
				return (0);
		}
		if (ft_strlen(argv[i]) == 10)
		{
			if (ft_strncmp(argv[i], "2147483647", 10) > 0)
				return (0);
		}
		i ++;
	}
	return (1);
}

int	check_dub(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strlen(argv[i]) > ft_strlen(argv[j]))
				len = ft_strlen(argv[i]);
			else
				len = ft_strlen(argv[j]);
			if (ft_strncmp(argv[i], argv[j], len) == 0)
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

void	stack_init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i_tab;
	int	i_arg;

	a->size = argc - 1;
	b->size = 0;
	a->tab = ft_calloc(a->size, sizeof(int));
	b->tab = ft_calloc(a->size, sizeof(int));
	i_tab = 0;
	i_arg = 1;
	while (i_arg < argc)
	{
		a->tab[i_tab] = ft_atoi(argv[i_arg]);
		i_tab++;
		i_arg++;
	}
}
