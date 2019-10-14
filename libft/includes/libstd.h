/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:27:02 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/09/04 16:31:29 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_LIBSTD_H
#define LIBFT_LIBSTD_H
#include <unistd.h>
#include <stdlib.h>
# define IN_RNGII(a, b, c) ((a) <= (b) && (b) <= (c))
# define IN_RANGE_CI(a, b, c) ((a) < (b) && (b) <= (c))
# define IN_RANGE_IC(a, b, c) ((a) <= (b) && (b) < (c))
# define IN_RANGE_CC(a, b, c) ((a) < (b) && (b) < (c))
# define FT_ABS(x) (((x) > 0) ? (x) : -(x))
# define FT_SIGN(x) (((x) > 0) ? 1 : -1)
# define FT_MAX2(x, y) ((x) > (y) ? (x) : (y))
# define FT_MIN2(x, y) ((x) < (y) ? (x) : (y))

void				*ft_memset(void *b, int c, size_t len);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_itoa(long n);
char				*ft_strncpy(char *dst, char const *src, size_t len);
char				**ft_strsplit(char const *s, char c);
int					ft_tolower(int c);
char				*ft_tolower_str(char *str);
int					ft_toupper(int c);
char				*ft_toupper_str(char *str);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isnumeric(char *line);
char				*ft_int_to_unicode(int n, char *bytes);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *st);
char				ft_atoi_safe(const char *str, int *ans);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
int					ft_abs(int a);
int					ft_isspace(int c);
void				ft_foreachint(int **arr, size_t len, void (*f)(int *n));
int					*ft_foreachintm(const int *arr, size_t len, int (*f)(int));
int					ft_sqrt(int c);
int					ft_atoi_m(const char **str);
char				*ft_itoa_base(__int128_t n, int rad);
void				*ft_realloc(void *old_data, size_t prev_size,
								size_t new_size);
size_t				ft_strlen_u(const int *s, char f);
char				ft_unilen(int u);
int					ft_intlen(long int n);
char				*ft_itoa_buf(long n, char *res);
void				*ft_replace_pointer(void *old, void *new);
#endif