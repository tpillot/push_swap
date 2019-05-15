#include "push_swap.h"

static	void	exect_option_a(t_stack *stack)
{
	ft_putnbr(stack->ra);
	ft_putstr("   commande rb : ");
	ft_putnbr(stack->rb);
	ft_putstr("   commande rr : ");
	ft_putnbr(stack->rr);
	ft_putendl("");
	ft_putstr("commande rra : ");
	ft_putnbr(stack->rra);
	ft_putstr("   commande rrb : ");
	ft_putnbr(stack->rrb);
	ft_putstr("   commande rrr : ");
	ft_putnbr(stack->rrr);
	ft_putendl("");
	ft_putstr("commande sa : ");
	ft_putnbr(stack->sa);
	ft_putstr("   commande sb : ");
	ft_putnbr(stack->sb);
	ft_putstr("   commande ss : ");
	ft_putnbr(stack->ss);
	ft_putendl("");
	ft_putstr("commande pa : ");
	ft_putnbr(stack->pa);
	ft_putstr("   commande pb : ");
	ft_putnbr(stack->pb);
	ft_putendl("");
}

static	void	exect_option_v_c(t_stack *stack, char *str)
{
	if (stack->c)
		ft_putstr("\033[31m");
	ft_putstr("commande : ");
	ft_putendl(str);
	if (stack->c)
		ft_putstr("\033[0m");
	if (stack->c)
		ft_putstr("\033[32m");
	print_list(stack->list_a, 0, 'a');
	print_list(stack->list_b, 0, 'b');
	if (stack->c)
		ft_putstr("\033[0m");
}

void			exect_option(t_stack *stack, char *str, int i)
{
	if (str)
	{
		exect_option_v_c(stack, str);
		return ;
	}
	if (stack->a)
	{
		ft_putstr("commande ra : ");
		exect_option_a(stack);
	}
	if (stack->n)
	{
		ft_putstr("nombre de commande total : ");
		ft_putnbr(i);
		ft_putendl("");
	}
}
