/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:21:45 by npaturzo          #+#    #+#             */
/*   Updated: 2023/10/04 16:40:05 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char conv);
int		ft_printpercent(void);

void	ft_putstr(char *str);
void	ft_put_ptr(unsigned long long num);
int		ft_ptr_len(unsigned long long num);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned int num);
void	ft_put_hex(unsigned int num, const char conv);
int		ft_hex_len(unsigned int num);

#endif
