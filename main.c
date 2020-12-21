#include <sys/stat.h>
#include <fcntl.h>
#include "include/get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int fd2;
	int ret;
	int ret2;
	char **line;
	char **line2;

	if (argc == 0)
		return (0);
	line = (char**)ft_memalloc(sizeof(char*));
	fd = open(argv[1], O_RDONLY);
	ret = get_next_line(fd, line);
	fd2 = 0;
	if (argc == 3)
	{
		line2 = (char**)ft_memalloc(sizeof(char*));
		fd2 = open(argv[2], O_RDONLY);
		ret2 = get_next_line(fd2, line2);
	}
	while (ret > 0 || (argc == 3 && ret2 > 0))
	{
		if (ret > 0)
		{
			ft_putstr(*line);
			free(*line);
			ret = get_next_line(fd, line);
		}
		if (ret2 > 0)
		{
			ft_putstr(*line2);
			free(*line2);
			ret2 = get_next_line(fd2, line2);
		}
	}
	return (1);
}