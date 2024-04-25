/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:49:28 by guilrodr          #+#    #+#             */
/*   Updated: 2023/10/14 20:49:43 by guilrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_args_control(char c, va_list params);
int		ft_get_string(va_list param);
int		ft_get_int(va_list param);
int		ft_get_unsigned_int(va_list param);
int		ft_get_address(va_list param, char *base_array);
int		ft_get_base(va_list param, char *base);

int		ft_putnbr_fd(int n, int fd);
int		ft_put_unsigned_nbr_fd(unsigned int n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_base(unsigned long number, int b_number, char b_array[], int value);

#endif
