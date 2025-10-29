/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:22:35 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/29 11:21:59 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> // for write
# include <stdlib.h> // for malloc

# define BUFFER_SIZE 32

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(const char *s);

#endif