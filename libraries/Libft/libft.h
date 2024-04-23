/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:38:53 by ssteveli          #+#    #+#             */
/*   Updated: 2024/01/30 14:41:41 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen(const char *str);
int		ft_isdigit(char *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlenint(const int *str);
int		ft_strchr(int *a, int c, int j);
int		ft_atoi(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_printf(const char *a, ...);
void	*ft_bzero(void *a, size_t len);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		is_chr(char s);
int		is_str(char *s);
int		is_p(unsigned long s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		is_d(int nb);
int		is_u(unsigned int nb);
int		is_x(unsigned int s);
int		is_xup(unsigned int s);
int		len_s(unsigned long s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_toupper(int c);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *stack);
void	ft_lstadd_back(t_list **lst, t_list *news);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int content, int index);
t_list	*ft_lstlast(t_list *lst);
#endif