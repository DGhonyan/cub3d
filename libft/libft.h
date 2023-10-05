/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:54:23 by mtiesha           #+#    #+#             */
/*   Updated: 2022/06/24 12:40:42 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

/* get_next_line */
int		ft_gnl_sh(char **line, int memory, int fd);
/* get "min" or "max" value */
int		ft_get_minmax(int a, int b, char *min_or_max);
/* free undo 3ptr (NULL if argument d't need)*/
void	ft_multifree(void *m1, void *m2, void *m3);
/* find str in spl before c (\0 to full search) */
char	*ft_get_strnspl(char **spl, char *str, char c);
/* array an arrays function */
char	**ft_split(char const *s, char c);
char	**ft_spldup(char **split);
int		ft_spllen(char **split);
void	ft_splfree(char **split);
void	ft_splarrfree(char ***a_spl);
/* swap 2 ptr */
void	ft_swap_ptr(char **p1, char **p2);
/* delete all double char, after c */
char	*ft_deldoublec(char **str, char c);
/* is function */
int		ft_isalnum(int c);
/* find char in string */
int		ft_iscinstr(const char *str, char c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
/* put function */
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
/* put str to fd, before (position)n character */
int		ft_putnstr_fd(char *str, int n, int fd);
size_t	ft_putspl_fd(char **split, int fd);
/* malloc/calloc functions */
void	*ft_calloc(size_t number, size_t size);
char	*ft_strdup(const char *str);
/* return copy of string, before (position)n character */
char	*ft_strndup(char *str, int n);
char	*ft_strjoin(char const *str1, char const *str2);
/* add char, after str1 */
char	*ft_strjoinchar(char const *str1, char const *str2, char c);
/* 0 - free str1, 1 - free str2, 2 - free both */
char	*ft_strjoinfree(char **str1, char **str2, int free_flag);
size_t	ft_strlcat(char *dest, const char *src, size_t dest_size);
/* find function */
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
/* find needle in haystack revers, undo (position)n */
char	*ft_strrnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
/* add char to string on index */
char	*ft_charadd(char **str, int index, char c);
/* delete char from string on index */
char	*ft_chardel(char **str, int index);
/* count how many char in str */
size_t	ft_count_char(const char *str, char c);
/* count char before c, revers */
size_t	ft_strrnlen(const char *str, char c);
size_t	ft_strnlen(const char *str, char c);
size_t	ft_strlen(const char *s);

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *destination, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *destination, int c, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *string1, const char *string2, size_t num);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

t_list	*ft_lstnew(void *content);
int		ft_strcmp(char *s1, char *s2);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
char	*ft_charadd_end(char *s, char c);
char	*ft_strjoinfree_v2(char *s1, char *s2);
char	**ft_split_str(char const *s, char *c);

#endif
