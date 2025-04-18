/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:26:26 by jrocha-v          #+#    #+#             */
/*   Updated: 2024/06/05 16:18:56 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

# define ERROR 1
# define SUCCESS 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *big, const char *little, \
						size_t len);
int					ft_atoi(const char *nstr);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *dest, int c, size_t len);
void				*ft_memchr(const void *b, int c, size_t len);
int					ft_memcmp(const void *b1, const void *b2, size_t len);
void				ft_bzero(void *b, size_t len);
void				*ft_calloc(size_t number, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strdup(const char *str);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_itoa(int n);

// New functions
int					ft_iswhitespace(char c);
int					ft_isdelimiter(char s, char c);
char				*ft_firstword(char *str);
void				ft_free_matrix(void **matrix);
void				ft_error(char *msg, int exit_code);
int					ft_count_words(char const *s);
int					ft_count_words_del(char const *s, char c);
void				ft_print_imatrix(int **matrix, int height, int width);
void				ft_print_smatrix(char **matrix, int height, int width);
int					ft_isinbase(char c, int str_base, char *base);
int					ft_atoi_base(const char *str, int str_base);
int					ft_int_max(int x, int y);
int					ft_check_ext(char *str, char *ext);
int					ft_nbrlen(long n);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strpbrk(const char *s1, const char *s2);
char				*ft_strldup(const char *s, size_t l);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strupdate(char *s1, char const *s2);
long				ft_atol(const char *nstr);
unsigned long long	ft_atoll(const char *nstr);
int					*ft_split_ints(char const *s, char c);
long				*ft_split_longs(char const *s, char c);
void				*ft_safe_malloc(size_t bytes);
void				ft_safe_free(void *memory);
void				ft_perror_exit(char *str, int error);

// List manipulation
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
						void (*del)(void *));

#endif
