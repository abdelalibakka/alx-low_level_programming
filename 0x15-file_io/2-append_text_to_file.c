#include "main.h"
#include <fcntl.h>

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: namet number of file to which text content needs to be appended
 * @text_content: the text content that needs to be appended to the file
 * Return: 1 on success . -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd_append;

	ssize_t len = 0;

	ssize_t n_written;

	if (filename == NULL)
		return (-1);

	fd_append = open(filename, O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd_append == 0)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
		{
			len++;
		}
	}
	n_written = write(fd_append, text_content, len);
	if (n_written == -1 || n_written != len)
		return (-1);

	close(fd_append);

	return (1);

}
