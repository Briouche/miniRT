/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:22:35 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/08 11:13:58 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> // for write
# include <stdlib.h> // for malloc

# define BUFFER_SIZE 32

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isupper(int c);

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free_array(void **arr);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void	*s, int c, size_t n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);

char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(const char *s);
char	*ft_strndup(const char *src, int n);

char	*ft_gnl(int fd);

#endif
