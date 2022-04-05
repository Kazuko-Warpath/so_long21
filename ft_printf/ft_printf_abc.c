/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_abc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:41:02 by kwarpath          #+#    #+#             */
/*   Updated: 2021/11/30 14:43:20 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c, t_struct *s)
{
	int	prnt_sym;
	int	tabs;

	tabs = 0;
	prnt_sym = 0;
	s->w_len = 1;
	tabs = s->width - s->w_len;
	if (s->left_align == 0)
		ft_print_sym(tabs, &prnt_sym);
	prnt_sym += write(1, &c, 1);
	if (s->left_align == 1)
		ft_print_sym(tabs, &prnt_sym);
	return (prnt_sym);
}

static void	strnull(char *str, int *toprint)
{
	if (str == NULL)
		*toprint = 6;
}

int	ft_printf_str(char *str, t_struct *s)
{
	int	prnt_sym;
	int	tabs;
	int	toprint;

	tabs = 0;
	prnt_sym = 0;
	toprint = s->accur;
	s->w_len = ft_strlen(str);
	if (s->w_len < s->accur || s->accur == -1)
		toprint = s->w_len;
	strnull(str, &toprint);
	tabs = s->width - toprint;
	if (s->left_align == 0)
		ft_print_sym(tabs, &prnt_sym);
	if (str == NULL)
		prnt_sym += write(1, "(null)", toprint);
	else
		prnt_sym += write(1, str, toprint);
	if (s->left_align == 1)
		ft_print_sym(tabs, &prnt_sym);
	return (prnt_sym);
}
