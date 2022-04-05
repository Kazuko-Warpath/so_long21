/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:59:51 by kwarpath          #+#    #+#             */
/*   Updated: 2021/11/30 14:42:30 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_width_size(char **text)
{
	int	a;

	a = ft_atoi(*text);
	if (a < 0)
		a = -a;
	while (ft_isdigit(**text))
		(*text)++;
	(*text)--;
	return (a);
}

static void	ft_options_flag(char **text, t_struct *s)
{
	if ((char)**text == '-')
		s->left_align = 1;
	else if ((char)**text == '0')
	{
		s->left_align = 0;
		s->zeroflag = 1;
	}
	else if ((char)**text == '#')
		s->sharp = 1;
	else if ((char)**text == ' ')
		s->space = 1;
	else if ((char)**text == '+')
		s->plus = 1;
}

void	ft_find_flag(char **text, t_struct *s)
{
	ft_flag_struct(s);
	while (ft_strchr(FLAGBASE, (int)**text) || ft_isdigit(**text))
	{
		ft_options_flag(text, s);
		if (ft_isdigit(**text) && (**text) != '0')
			s->width = ft_width_size(text);
		if ((char)**text == '.')
		{
			(*text)++;
			s->accur = ft_width_size(text);
			s->zeroflag = 0;
		}
		(*text)++;
	}
	if (s->zeroflag == 1)
		s->accur = s->width;
}

int	ft_parser(const char *text, va_list args, t_struct *s, int prnt_sym)
{
	if (ft_strchr(FLAGSYM, (int)*text))
	{
		if ((char)*text == 'c')
			prnt_sym += ft_printf_char(va_arg(args, int), s);
		if ((char)*text == 's')
			prnt_sym += ft_printf_str(va_arg(args, char *), s);
		if ((char)*text == 'd' || (char)*text == 'i')
			prnt_sym += ft_printf_d_i(va_arg(args, int), s);
		if ((char)*text == 'u')
			prnt_sym += ft_printf_un_d(va_arg(args, unsigned int), s);
		if ((char)*text == 'p')
			prnt_sym += ft_printf_pointer(va_arg(args, unsigned long), s);
		if ((char)*text == 'x')
			prnt_sym += ft_printf_hex(va_arg(args, unsigned int), s, 'x');
		if ((char)*text == 'X')
			prnt_sym += ft_printf_hex(va_arg(args, unsigned int), s, 'X');
		if ((char)*text == '%')
			prnt_sym += write(1, "%", 1);
	}
	return (prnt_sym);
}

int	ft_printf(const char *text, ...)
{
	va_list		args;
	int			prnt_sym;
	t_struct	s;

	prnt_sym = 0;
	if (!text[0])
	{
		write(1, "", 0);
		return (0);
	}
	va_start(args, text);
	while (*text)
	{
		if (*text == '%')
		{
			text++;
			ft_find_flag((char **)&(text), &s);
			prnt_sym = ft_parser(text, args, &s, prnt_sym);
		}
		else
			prnt_sym += write(1, text, 1);
		text++;
	}
	va_end(args);
	return (prnt_sym);
}
