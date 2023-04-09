#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
/**
 * create_file - Creates a file
 * @filename: the name of the ffile to create
 * @text_content: the content of the filename
 * Return: 1 (success) . -1 failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd_create;

	ssize_t len = 0;

	ssize_t n_written;

	if (filename == NULL)
		return (-1);

	fd_create = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd_create == -1)
		return (-1);


	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
	}

	n_written = write(fd_create, text_content, len);
	if (n_written == -1 || n_written != len)
	{
		close(fd_create);
		return (-1);
	}

	close(fd_create);

	return (1);
}
