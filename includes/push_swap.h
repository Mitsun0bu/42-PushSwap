/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:21:40 by llethuil          #+#    #+#             */
/*   Updated: 2021/12/14 17:17:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <stdio.h> // DEBUG

/* ************************************************************************** */
/*                                                                            */
/*                                  TYPEDEFS                                  */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
	int	size;
	int	*tab;
}	t_stack;

/* ************************************************************************** */
/*                                                                            */
/*                                  PROTOTYPES                                */
/*                                                                            */
/* ************************************************************************** */

/* algos.c */
void	sort_xs_stack(t_stack *a);
void	sort_s_stack(t_stack *a, t_stack *b);
void	sort_l_stack(t_stack *a, t_stack *b, int chunk_max);
void	sort_xl_stack(t_stack *a, t_stack *b, int chunk_max);
void	quicksort_tab(int *tab, int first, int last);

/* double_operations.c */
void	swap_both(t_stack *a, t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);
void	rev_rotate_both(t_stack *a, t_stack *b);

/* parsing.c */
int		check_arg(int argc, char **argv);
int		arg_is_nbr(int argc, char **argv);
int		arg_is_int(int argc, char **argv);
int		check_dub(int argc, char **argv);
void	stack_init(t_stack *a, t_stack *b, int argc, char **argv);

/* push_swap.c */
int		main(int argc, char**argv);
void	push_swap(t_stack *stack_a, t_stack *stack_b);

/* simple_operations.c */
void	swap(t_stack *x, char c);
void	push(t_stack *dest, t_stack *src, char c);
void	rotate(t_stack *x, char c);
void	rev_rotate(t_stack *x, char c);
void	swap_table(int *a, int *b);

/* utils_1.c */
int		check_if_sorted(t_stack *x);
int		high_val_index(t_stack *x);
int		low_val_index(t_stack *x);
int		*copy_stack(t_stack *x, int *tab);
void	convert_val_to_index(t_stack *x, int *tab);

/* utils_2.c */
int		chunk_member_index(t_stack *x, int chunk_max);
void	push_chunk(t_stack *a, t_stack *b, int chunk_max);
void	push_back_chunk(t_stack *a, t_stack *b);
void	error_handler(t_stack *a, t_stack *b);

#endif