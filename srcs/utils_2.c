/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:45:21 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/14 17:17:32 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_chunk(t_stack *a, t_stack *b, int chunk_max)
{
	while (chunk_member_index(a, chunk_max) != -1)
	{
		if (chunk_member_index(a, chunk_max) < a->size / 2)
			while (chunk_member_index(a, chunk_max) != 0)
				rotate(a, 'a');
		if (chunk_member_index(a, chunk_max) >= a->size / 2)
			while (chunk_member_index(a, chunk_max) != 0)
				rev_rotate(a, 'a');
		push(b, a, 'b');
	}
}

int	chunk_member_index(t_stack *x, int chunk_max)
{
	int	i;

	i = -1;
	while (++i < x->size)
	{
		if (x->tab[i] < chunk_max)
			return (i);
		i ++;
	}
	return (-1);
}

void	push_back_chunk(t_stack *a, t_stack *b)
{
	if (high_val_index(b) < b->size / 2)
		while (high_val_index(b) != 0)
			rotate(b, 'b');
	if (high_val_index(b) >= b->size / 2)
		while (high_val_index(b) != 0)
			rev_rotate(b, 'b');
	push(a, b, 'a');
}

void	error_handler(t_stack *a, t_stack *b)
{
	free(a->tab);
	free(b->tab);
	ft_putstr_fd("Error", 1);
}
