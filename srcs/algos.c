/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:22:05 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/11 11:29:30 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_xs_stack(t_stack *a)
{
	if (a->size == 3)
	{
		if (high_val_index(a) ==  0)
			rotate(a, 'a');
		else if (high_val_index(a) ==  1)
			rev_rotate(a, 'a');
	}
	if (a->tab[0] > a->tab[1])
		swap(a, 'a');
}

void sort_s_stack(t_stack *a, t_stack *b)
{
	while(a->size > 3)
	{
		if(low_val_index(a) == 1)
			swap(a, 'a');
		while (low_val_index(a) != 0)
			rev_rotate(a, 'a');
		push(b, a, 'b');
	}
	sort_xs_stack(a);
	push(a, b, 'a');
	push(a, b, 'a');
}

void sort_l_stack(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
	return ;
}