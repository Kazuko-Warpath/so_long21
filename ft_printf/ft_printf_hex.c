/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:05:15 by kwarpath          #+#    #+#             */
/*   Updated: 2021/11/30 14:57:45 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_nbr(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

static int	ft_print_nbr(char **base, unsigned int nbr, int *prnt_sym)
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

static void	ft_flag_zero(int *tabs, int *nulls, t_struct *s, unsigned int n)
{
	s->w_len = ft_len_nbr(n);
	*tabs = s->width - s->accur;
	if (s->accur < s->w_len)
		*tabs = s->width - s->w_len;
	*nulls = s->accur - s->w_len;
}

static void	ft_print_zero(unsigned int n, t_struct *s, int *prnt_sym, char cs)
{
	if (n == 0)
	{
		if (s->accur != 0)
			*prnt_sym += write(1, "0", 1);
		else if (s->width != 0)
			*prnt_sym += write(1, " ", 1);
	}
	if (n != 0 && s->sharp == 1)
	{
		if (cs == 'x')
			*prnt_sym += write(1, "0x", 2);
		if (cs == 'X')
			*prnt_sym += write(1, "0X", 2);
	}
}

int	ft_printf_hex(unsigned int n, t_struct *s, char cs)
{
	int		prnt_sym;
	char	*base;
	int		tabs;
	int		nulls;

	if (cs == 'x')
		base = "0123456789abcdef";
	if (cs == 'X')
		base = "0123456789ABCDEF";
	prnt_sym = 0;
	ft_flag_zero(&tabs, &nulls, s, n);
	if (s->left_align == 0)
		ft_print_sym(tabs, &prnt_sym);
	while (nulls-- > 0)
		prnt_sym += write(1, "0", 1);
	ft_print_zero(n, s, &prnt_sym, cs);
	ft_print_nbr(&base, n, &prnt_sym);
	if (s->left_align == 1)
		ft_print_sym(tabs, &prnt_sym);
	return (prnt_sym);
}
