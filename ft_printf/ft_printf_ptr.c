/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:27:52 by kwarpath          #+#    #+#             */
/*   Updated: 2021/11/30 14:53:33 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr_len(unsigned long n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static int	ft_print_nbr(char **base, unsigned long nbr, int *prnt_sym)
{
	char	c;

	if (nbr == 0)
		return (0);
	else
	{
		c = (*base)[nbr % 16];
		nbr = nbr / 16;
		ft_print_nbr(base, nbr, prnt_sym);
		*prnt_sym += write(1, &c, 1);
	}
	return (0);
}

static void	ft_change_flag(int *tabs, t_struct *s, unsigned long n)
{
	s->w_len = ft_nbr_len(n);
	*tabs = s->width - s->accur - 2;
	if (s->accur < s->w_len)
		*tabs = s->width - s->w_len - 3;
	if (n != 0)
		(*tabs)++;
}

int	ft_printf_pointer(unsigned long n, t_struct *s)
{
	int		prnt_sym;
	char	*base;
	int		tabs;

	base = "0123456789abcdef";
	prnt_sym = 0;
	ft_change_flag(&tabs, s, n);
	if (s->left_align == 0)
		ft_print_sym(tabs, &prnt_sym);
	prnt_sym += write(1, "0x", 2);
	if (n == 0 && s->accur == -1)
		prnt_sym += write(1, "0", 1);
	ft_print_nbr(&base, n, &prnt_sym);
	if (s->left_align == 1)
		ft_print_sym(tabs, &prnt_sym);
	return (prnt_sym);
}
