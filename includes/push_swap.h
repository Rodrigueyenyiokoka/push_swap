/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:01:47 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/09/18 15:01:51 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef	enum		e_optype
{
	sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr, nothing
}					t_optype;

typedef	enum		e_onum
{
	SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR, NOTHING
}					t_onum;

typedef	struct		s_stack
{
	int				v;
	struct s_stack	*pv;
	struct s_stack	*nx;
	int				g;
	int				maf;
	int				mar;
	int				mbf;
	int				mbr;
	int				moves;
	int				dir;
}					t_stack;

typedef	struct		s_op
{
	t_optype		op;
	void			(*call)(t_stack **stacka, t_stack **stackb);
	struct s_op		*next;
}					t_op;

typedef struct		s_out
{
	t_onum			num;
	struct s_out	*nx;
}					t_out;

typedef struct		s_tmps
{
	int				tmp1;
	int				tmp2;
	int				flag;
}					t_tmps;

void				ft_free(t_stack **sa, t_stack **sb, t_out **ret);
void				ft_print_2(t_stack **sa,\
		t_stack **sb, t_op *oplist, int debug);
void				ft_print_1(t_out *ret);
int					ft_position(t_stack *sb, int j);
int					ft_is_ordered(t_stack *stacka, t_stack *stackb);
void				stacks_debug(t_stack *stacka, t_stack *stackb);
int					op_debug(t_op *begin);
int					find_lagest(t_stack *sb);
int					find_smallest(t_stack *sb);
void				b_move(t_stack *sa, t_stack *sb);
void				ft_move(t_stack *sa);
void				a_move(t_stack *sa);
int					help_m1(t_stack *sa, t_stack *tmpb);
int					help_m2(t_stack *tmpb, t_stack *sa);
void				ft_help_m3(t_stack *sa, int *ar);
int					b_move_largest(t_stack *tmpb, t_stack *sb);
int					b_move_smallest(t_stack *tmpb, t_stack *sb);
void				ft_rot(t_out *ret, t_stack **sa,\
		t_stack **sb, int descending);
void				op_updating(t_stack *target,\
		t_stack **sa, t_stack **sb, t_out *ret);
void				ft_algo(t_stack **sa, t_stack **sb, t_out *ret);
t_stack				*stack_initializer();
t_op				*get_next_op();
t_stack				*ft_is_integer(int argc, char **argv, t_stack *stacka);
int					ft_ordered(t_stack *stackb);
int					ft_half_ordered(t_stack *stackb);
int					ft_half_ordered_2(t_stack *stackb, int tmp, int tmp2);
t_out				*ft_out_initialize();
int					ft_length(t_stack *stack);
t_stack				*ft_end(t_stack **stack);
void				op(t_out *ret, t_onum op,\
		t_stack **sa, t_stack **sb);
void				printelement(t_optype num);
void				printelement2(t_onum num);
void				ft_do_op(t_onum num, t_stack **sa, t_stack **sb);
void				sa_op(t_stack **stacka, t_stack **stackb);
void				sb_op(t_stack **stacka, t_stack **stackb);
void				pa_op(t_stack **stacka, t_stack **stackb);
void				pb_op(t_stack **stacka, t_stack **stackb);
void				ss_op(t_stack **stacka, t_stack **stackb);
void				ra_op(t_stack **stacka, t_stack **stackb);
void				rb_op(t_stack **stacka, t_stack **stackb);
void				rr_op(t_stack **stacka, t_stack **stackb);
void				rra_op(t_stack **stacka, t_stack **stackb);
void				rrb_op(t_stack **stacka, t_stack **stackb);
void				rrr_op(t_stack **stacka, t_stack **stackb);
#endif
