/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:50:19 by seheo             #+#    #+#             */
/*   Updated: 2022/07/02 20:55:53 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     TEST_H
# define    TEST_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *str, int c);
char	*s1_init(char *s1);
char	*ft_strjoin(char *s1, char const *s2);
char	*file_save(char *result);
char	*get_line(char *file_text);


#endif 