/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:19:11 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/18 09:25:30 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

size_t	ftpf_strlen(const char *str);
char	*ftpf_strdup(const char *s);
char	*ftpf_itoa(int n);
int		ftpf_putnbr(int n);
int		ftpf_putnbru(unsigned int u);
size_t	ftpf_strlcpy(char *dst, const char *src, size_t size);

int		ft_printf(const char *str, ...);
char	*ftpf_itoahex(size_t n);
char	*ftpf_strupcase(char *str);

int		manage_char(int c);
int		manage_str(char *str);
int		manage_hex(unsigned int num, char c);
int		manage_dir(size_t num);

#endif
