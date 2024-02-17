/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:05:01 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:05:02 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					nb;
	int					index;
	int					push_cost;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void			exit_error(void);
void			free_stack(t_stack_node **stack);
void			display_stack(t_stack_node *stack);
bool			ft_issort(t_stack_node **stack);
void			display_stack_details(t_stack_node *stack);
// ft_split
char			**ft_split(char const *s, char c);
size_t			ft_strlen(char *s);
char			*addtoreaded(char *s, int c);
int				ft_countword(char const *s, char c);
char			*ft_allocword(char const *s, char c, int const i);
// ft_printf
int				ft_printf(const char *format, ...);
int				ft_choice(const char *format, size_t i, va_list arg_list);
int				ft_printfchar(int c);
int				ft_printfhex(unsigned long long n, char *basehex);
int				ft_printfnbr(int n);
int				ft_printfpointer(unsigned long long n, char *basehex);
int				ft_printfstr(char *s);
int				ft_printfunbr(unsigned int n);
void			ft_putchar(int c);
void			ft_puthex(unsigned long long n, char *basehex);
void			ft_putnbr(unsigned int n);
void			ft_putstr(char *str);
// check_errors
void			check_errors(char **argv);
int				ft_issame(char *s1, char *s2);
int				check_double(char **argv);
long long		ft_atoll(char *s);
int				ft_isdigit(char *s);
int				ft_isint(char *s);
// init_stack
void			init_stack_a(t_stack_node **a, char **argv);
t_stack_node	*find_bottom(t_stack_node *stack);
void			append_node(t_stack_node **stack, int nb);
// commands
void			swap(t_stack_node **top);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			push(t_stack_node **src, t_stack_node **dest);
void			pa(t_stack_node **b, t_stack_node **a);
void			pb(t_stack_node **a, t_stack_node **b);
void			rotate(t_stack_node **top);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rev_rotate(t_stack_node **top);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
// sort
void			sort_three(t_stack_node **a);
void			sort_turk(t_stack_node **a, t_stack_node **b);
size_t			count_node(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_closest_smaller(int nb, t_stack_node *stack);
t_stack_node	*find_closest_bigger(int nb, t_stack_node *stack);
void			set_index(t_stack_node **top);
void			set_median(t_stack_node **top);
void			set_stack_a_to_b(t_stack_node **a, t_stack_node **b);
t_stack_node	*find_cheapest(t_stack_node *stack);
void			sort_turk_move_a_to_b(t_stack_node **a, t_stack_node **b);

#endif
