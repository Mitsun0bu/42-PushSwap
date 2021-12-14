/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:39:39 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/14 12:57:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *x, char c)
{
	int	temp;

	if (x->size < 2)
		return ;
	temp = x->tab[0];
	x->tab[0] = x->tab[1];
	x->tab[1] = temp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	push(t_stack *dest, t_stack *src, char c)
{
	int	i;

	if (src->size == 0)
		return ;
	dest->size++;
	i = -1;
	while (++i < dest->size)
		dest->tab[dest->size - i - 1] = dest->tab[dest->size - i - 2];
	dest->tab[0] = src->tab[0];
	i = -1;
	while (++i < src->size)
		src->tab[i] = src->tab[i + 1];
	src->size --;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

void	rotate(t_stack *x, char c)
{
	int	buffer;
	int	i;

	if (x->size < 2)
		return ;
	buffer = x->tab[0];
	i = -1;
	while (++i < x->size)
		x->tab[i] = x->tab[i + 1];
	x->tab[x->size - 1] = buffer;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rev_rotate(t_stack *x, char c)
{
	int	buffer;
	int	i;

	if (x->size < 2)
		return ;
	buffer = x->tab[x->size - 1];
	i = -1;
	while (++i < x->size)
		x->tab[x->size - i - 1] = x->tab[x->size - i - 2];
	x->tab[0] = buffer;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	swap_table(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
