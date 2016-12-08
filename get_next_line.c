/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:05:06 by qhusler           #+#    #+#             */
/*   Updated: 2016/12/08 18:18:42 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_sstrlen(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static char		*s = NULL;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*ptrn;

	if (fd < 0 || !line)
		return (-1);

	if (s)
		ft_putendl(s);

	if (s && (ptrn = ft_strchr(s, '\n')))
	{
		*line = ft_strsub(s, 0, ptrn - s);
		tmp = ft_strsub(s, (ptrn - s + 1), ft_strlen(s));
		ft_strdel(&s);
		s = ft_strdup(tmp);
		return (1);
	}
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0/* && (!(ft_strchr(s, '\n')))*/)
	{
		buf[ret] = '\0';
		s = (!s) ? ft_strdup(buf) : ft_strjoin(s, buf);
		if ((ptrn = ft_strchr(s, '\n')))
			break ;
	}
//	ptrn = ft_strchr(s, '\n');
	*line = ft_strsub(s, 0, ptrn - s);
	tmp = ft_strsub(s, (ptrn - s + 1), ft_strlen(s));
	ft_strdel(&s);
	s = ft_strdup(tmp);
	return (1);
}
//		printf("%d\n", BUFF_SIZE - ft_sstrlen(ptrn));
