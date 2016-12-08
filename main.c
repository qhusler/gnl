#include "get_next_line.h"

int		main(int ac, char **av)
{
	(void)ac;
	char	*line;
	int 	fd = open(av[1], O_RDONLY);
	char	s[] = "this string is not empty";
	char	*ptr;

	ptr = ft_strchr(s, 's');
//	ft_memmove();
//	while (get_next_line(fd, &line) != 0)
//		printf("%s\n", line);
	get_next_line(fd, &line);
	printf("line->%s\n", line);
	get_next_line(fd, &line);
	printf("line->%s\n", line);
	get_next_line(fd, &line);
	printf("line->%s\n", line);
	get_next_line(fd, &line);
	printf("line->%s\n", line);
	get_next_line(fd, &line);
	printf("line->%s\n", line);
	get_next_line(fd, &line);
	printf("line->%s\n", line);
/*	get_next_line(fd, &line);
	printf("line->%s\n", line);
	get_next_line(fd, &line);
	printf("line->%s\n", line);
	printf("---->%ld\n", ptr - s + 1);
*/	return (0);
}
