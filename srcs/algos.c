/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:22:05 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/14 17:19:43 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_xs_stack(t_stack *a)
{
	if (a->size == 3)
	{
		if (high_val_index(a) == 0)
			rotate(a, 'a');
		else if (high_val_index(a) == 1)
			rev_rotate(a, 'a');
	}
	if (a->tab[0] > a->tab[1])
		swap(a, 'a');
}

void	sort_s_stack(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (low_val_index(a) == 1)
			swap(a, 'a');
		while (low_val_index(a) != 0)
			rev_rotate(a, 'a');
		push(b, a, 'b');
	}
	sort_xs_stack(a);
	push(a, b, 'a');
	push(a, b, 'a');
}

void	sort_l_stack(t_stack *a, t_stack *b, int chunk_max)
{
	while (a->size != 0)
	{
		push_chunk(a, b, chunk_max);
		chunk_max += 20;
	}
	while (b->size != 0)
		push_back_chunk(a, b);
	return ;
}

void	sort_xl_stack(t_stack *a, t_stack *b, int chunk_max)
{
	while (a->size != 0)
	{
		push_chunk(a, b, chunk_max);
		chunk_max += 40;
	}
	while (b->size != 0)
		push_back_chunk(a, b);
	return ;
}

void	quicksort_tab(int *tab, int first, int last)
{
	int	pivot;
	int	i;
	int	j;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (tab[i] <= tab[pivot] && i < last)
				i++;
			while (tab[j] > tab[pivot])
				j--;
			if (i < j)
				swap_table(&tab[i], &tab[j]);
		}
		swap_table(&tab[pivot], &tab[j]);
		quicksort_tab(tab, first, j - 1);
		quicksort_tab(tab, j + 1, last);
	}
}
