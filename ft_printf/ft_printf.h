/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:30:59 by kwarpath          #+#    #+#             */
/*   Updated: 2022/03/31 18:01:00 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define FLAGSYM "cspdiuxX%"
# define FLAGBASE "+- #0."

typedef struct s_struct
{			
	int	width;
	int	accur;
	int	w_len;
	int	left_align;
	int	zeroflag;
	int	sharp;
	int	space;
	int	plus;
}	t_struct;

int		ft_printf(const char *text, ...);
int		ft_printf_d_i(int n, t_struct *s);
int		ft_printf_un_d(unsigned int n, t_struct *s);
int		ft_printf_pointer(unsigned long n, t_struct *s);
int		ft_printf_hex(unsigned int n, t_struct *s, char cs);
int		ft_printf_char(char c, t_struct *s);
int		ft_printf_str(char *str, t_struct *s);
void	ft_flag_struct(t_struct *s);
void	ft_print_sym(int tabs, int *prnt_sym);
void	ft_find_flag(char **text, t_struct *s);
int		ft_parser(const char *text, va_list ap, t_struct *s, int prnt_sym);

#endif
