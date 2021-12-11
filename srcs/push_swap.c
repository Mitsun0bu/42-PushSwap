/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:42:53 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/11 14:56:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	if (argc < 2 || check_arg(argc, argv) == -1)
	{
		ft_putstr_fd("Error", 1);
		return (0);
	}
	stack_init(&a, &b, argc, argv);
	push_swap(&a, &b);

	// // START DISPLAY STACKS TEST //

	// int i_tab = 0;
	// int i_arg = 0;
	// printf("=== STACK A ===\n");
	// while (i_arg < a.size)
	// {
	// 	printf("element %d = %d\n", i_tab, a.tab[i_tab]);
	// 	i_tab++;
	// 	i_arg++;
	// }
	// i_tab = 0;
	// i_arg = 0;
	// printf("=== STACK B ===\n");
	// while (i_arg < b.size)
	// {
	// 	printf("element %d = %d\n", i_tab, b.tab[i_tab]);
	// 	i_tab++;
	// 	i_arg++;
	// }

	// // END DISPLAY TEST //
	return (0);
}

void push_swap(t_stack *a, t_stack *b)
{
	if (a->size < 2 || check_if_sorted(a) == 1)
		return ;
	else if (a->size < 4)
		sort_xs_stack(a);
	else if (a->size < 6)
		sort_s_stack(a, b);
	// else if (a-> size < 101)
	// 	sort_l_stack(a, b);
	// else
	// 	sort_xl_stack(a, b);
	return ;
}
