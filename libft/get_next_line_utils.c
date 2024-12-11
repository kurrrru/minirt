/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:02:34 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/06/28 00:25:18 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// buf_init: Initialize buf if it is not initialized.
// After memory allocation, initialize the memory with '\0'.
// Return: whether the initialization is successful. (1: success, -1: error)
int	buf_init(char **buf)
{
	if (*buf)
		return (1);
	*buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (*buf == NULL)
		return (-1);
	gnl_bzero(*buf, BUFFER_SIZE + 1);
	return (1);
}

// gnl_realloc: Reallocate memory with new_size.
// If the reallocation fails, free the original pointer and return NULL.
// If the reallocation succeeds, copy the original data to the new pointer.
// Return: the new pointer.
void	*gnl_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*new_ptr;
	size_t	i;

	if (new_size == 0)
		while (new_size == 0 || ((char *)ptr)[new_size - 1])
			new_size++;
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (free(ptr), NULL);
	i = 0;
	while (i < old_size && i < new_size)
	{
		((char *)new_ptr)[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}

// gnl_strncat: Concatenate src to dst.
// If the new_size of dst is not enough, it is reallocated in gnl_realloc.
// The size of the concatenated string of src is stored in cat_size.
// Return: the size of the concatenated string of src.
int	gnl_strncat(char **dst, const char *src, int *line_size, int *cat_size)
{
	int	i;
	int	j;

	i = -1;
	while ((*dst)[++i])
		;
	j = 0;
	while (src[j] && (j == 0 || src[j - 1] != '\n'))
	{
		if (i + j + 1 >= *line_size)
		{
			*dst = gnl_realloc(*dst, *line_size * 2, *line_size);
			if (*dst == NULL)
			{
				*cat_size = -1;
				return (-1);
			}
			*line_size *= 2;
		}
		(*dst)[i + j] = src[j];
		j++;
	}
	(*dst)[i + j] = '\0';
	*cat_size = j;
	return (j);
}

// gnl_bzero: Initialize buf with '\0'.
// Return: None
void	gnl_bzero(void *buf, size_t size)
{
	while (size)
		((char *)buf)[--size] = '\0';
}

// gnl_read: Read from fd to buf and concatenate buf to line.
// If line is not empty, concatenate buf to line.
// If '\n' is not found in buf, read until '\n' is found or EOF is reached.
// Move the characters after first '\n' to the beginning of buf.
// Return: whether the reading is successful. (1: success, 0: EOF, -1: error)
int	gnl_read(int fd, char **line, int *line_size, char *buf)
{
	int			read_size;
	int			cat_size;
	int			i;

	cat_size = 0;
	if (line[0] && gnl_strncat(line, buf, line_size, &cat_size) == -1)
		return (-1);
	if (!buf[cat_size] && (cat_size == 0 || buf[cat_size - 1] != '\n'))
	{
		while (1)
		{
			read_size = read(fd, buf, BUFFER_SIZE);
			if (read_size == -1 || read_size == 0)
				return (read_size);
			buf[read_size] = '\0';
			if (gnl_strncat(line, buf, line_size, &cat_size) <= 0)
				return (cat_size);
			if (buf[cat_size - 1] == '\n')
				break ;
		}
	}
	i = -1;
	while (++i <= BUFFER_SIZE - cat_size)
		buf[i] = buf[cat_size + i];
	return (1);
}
