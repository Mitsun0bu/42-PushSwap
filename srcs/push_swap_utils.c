/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:41:28 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/11 16:13:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_if_sorted(t_stack *x)
{
	int	i;

	i = 0;
	while(i < x->size - 1)
	{
		if (x->tab[i] > x->tab[i + 1])
			return (0);
		i ++;
	}
	return (1);
}

int	high_val_index(t_stack *x)
{
	int	i_high;
	int	i;

	i_high = 0;
	i = - 1;
	while (++i != x->size)
	{
		if (x->tab[i] > x->tab[i_high])
			i_high = i;
	}
	return (i_high);
}

int	low_val_index(t_stack *x)
{
	int	i_low;
	int	i;

	i_low = 0;
	i = - 1;
	while (++i != x->size)
	{
		if (x->tab[i] < x->tab[i_low])
			i_low = i;
	}
	return (i_low);
}

void	copy_stack(t_stack *x, int *tab)
{
	int	i;

	i = 0;
	while(i < x->size)
	{
		tab[i] = x->tab[i];
		i ++;
	}
}