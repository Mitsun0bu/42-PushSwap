/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:42:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/12 14:27:31 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (check_arg(argc, argv) == -1)
	{
		ft_putstr_fd("Error", 1);
		return (0);
	}
	stack_init(&a, &b, argc, argv);
	push_swap(&a, &b);
	free(a.tab);
	free(b.tab);
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

void	push_swap(t_stack *a, t_stack *b)
{
	int	*tab;

	tab = 0;
	if (a->size <= 1 || check_if_sorted(a) == 1)
		return ;
	else if (a->size <= 3)
		sort_xs_stack(a);
	else if (a->size <= 5)
		sort_s_stack(a, b);
	else
	{
		tab = copy_stack(a, tab);
		if (!tab)
		{
			error_handler(a, b);
			return ;
		}
		quicksort_tab(tab, 0, a->size - 1);
		convert_val_to_index(a, tab);
		if (a->size <= 100)
			sort_l_stack(a, b, 20);
		else if (a->size > 100)
			sort_xl_stack(a, b, 40);
		free(tab);
	}
}
