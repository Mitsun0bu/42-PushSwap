/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:40:22 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/12 14:43:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a, 'x');
	swap(b, 'x');
	ft_putstr_fd("ss\n", 1);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a, 'x');
	rotate(b, 'x');
	ft_putstr_fd("rr\n", 1);
}

void	rev_rotate_both(t_stack *a, t_stack *b)
{
	rev_rotate(a, 'x');
	rev_rotate(b, 'x');
	ft_putstr_fd("rrr\n", 1);
}
