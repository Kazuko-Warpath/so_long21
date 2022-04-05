/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:34:49 by kwarpath          #+#    #+#             */
/*   Updated: 2021/11/30 14:47:55 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_nbr(int nbr, int *prnt_sym)
{
	char	c;

	if (nbr == 0)
		return (0);
	else
	{
		c = nbr % 10;
		if (c < 0)
			c = -c;
		c = c + '0';
		nbr = nbr / 10;
		ft_print_nbr(nbr, prnt_sym);
		*prnt_sym += write(1, &c, 1);
	}
	return (0);
}

static int	ft_nbr_len(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

static void	ft_flag_zero(int *tabs, int *nulls, t_struct *s, int n)
{
	s->w_len = ft_nbr_len(n);
	*tabs = s->width - s->accur;
	if (s->accur < s->w_len)
		*tabs = s->width - s->w_len;
	if (n < 0)
		(*tabs)--;
	if (n < 0 && s->zeroflag == 1)
		s->accur--;
	*nulls = s->accur - s->w_len;
}

static void	ft_zero_print(int n, t_struct *s, int *prnt_sym)
{
	if (n == 0)
	{
		if (s->accur != 0)
			*prnt_sym += write(1, "0", 1);
		else if (s->width != 0)
			*prnt_sym += write(1, " ", 1);
	}
}

int	ft_printf_d_i(int n, t_struct *s)
{
	int	prnt_sym;
	int	tabs;
	int	nulls;

	prnt_sym = 0;
	ft_flag_zero(&tabs, &nulls, s, n);
	if (s->left_align == 0)
		ft_print_sym(tabs, &prnt_sym);
	if (n < 0)
		prnt_sym += write(1, "-", 1);
	if (s->plus == 1 && n >= 0)
		prnt_sym += write(1, "+", 1);
	else if (s->space == 1 && n >= 0)
		prnt_sym += write(1, " ", 1);
	while (nulls-- > 0)
		prnt_sym += write(1, "0", 1);
	ft_zero_print(n, s, &prnt_sym);
	ft_print_nbr(n, &prnt_sym);
	if (s->left_align == 1)
		ft_print_sym(tabs, &prnt_sym);
	return (prnt_sym);
}
