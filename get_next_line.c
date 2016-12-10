/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:05:06 by qhusler           #+#    #+#             */
/*   Updated: 2016/12/10 16:24:16 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freejoin(char *s1, char *s2)
{
	char	*s;

	if (!(s = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(s, s1);
	ft_strdel(&s1);
	ft_strncat(s, s2, ft_strlen(s2));
	ft_strclr(s2);
	return (s);
}

int		line_load(char **line, char **s)
{
	char *tmp;
	char *ptrn;

	ptrn = ft_strchr(*s, '\n');
	if (ptrn)
	{
		*line = ft_strsub(*s, 0, ptrn - *s);
		tmp = ft_strsub(*s, (ptrn - *s + 1), ft_strlen(*s));
		ft_strdel(&*s);
		*s = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	if (ft_strlen(*s) > 0)
	{
		*line = ft_strsub(*s, 0, ft_strlen(*s));
		ft_strdel(&*s);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*s = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	
	if (fd < 0 || !line)
		return (-1);
	if (!s)
		s = ft_strnew(1);
	while (!ft_strchr(s, '\n'))
	{
		ret = read(fd, &buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (line_load(&*line, &s));
		buf[ret] = '\0';
		s = ft_freejoin(s, buf);
	}
	return (line_load(&*line, &s));
}
