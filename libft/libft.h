/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:22:35 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/09 18:30:03 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> // for write
# include <stdlib.h> // for malloc

# define BUFFER_SIZE 32
# define MAX_SIGNIFICANT_DIGITS 17

double	ft_atod(const char *str);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		parse_sign(const char **s);
void	process_integer(const char c, double *res, int *state);
void	process_fraction(const char c, double *frac_part,
			double *frac_div, int *state);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isupper(int c);

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free_array(void **arr);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void	*s, int c, size_t n);

void	ft_putchar_fd(const char c, int fd);
void	ft_putstr_fd(const char *s, int fd);

char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(const char *s);
char	*ft_strndup(const char *src, int n);

char	*get_next_line(int fd);

#endif
