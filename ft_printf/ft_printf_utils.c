/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:44:55 by kwarpath          #+#    #+#             */
/*   Updated: 2021/11/30 13:33:27 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_struct(t_struct *s)
{
	s->width = 0;
	s->accur = -1;
	s->w_len = 0;
	s->left_align = 0;
	s->zeroflag = 0;
	s->sharp = 0;
	s->space = 0;
	s->plus = 0;
}

void	ft_print_sym(int tabs, int *prnt_sym)
{
	while (tabs-- > 0)
		*prnt_sym += write(1, " ", 1);
}
