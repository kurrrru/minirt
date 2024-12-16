/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:24:56 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/17 01:00:20 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set.h"

static int	process_element(t_data *data, char **elements);
static int	handle_elements(t_data *data, char *next_line, int fd);

int	read_file(t_data *data, char **argv)
{
	int			fd;
	char		*next_line;
	t_list		*current;
	t_object	*obj;

	fd = xopen(argv[1], O_RDONLY);
	next_line = get_next_line(fd);
	while (next_line)
	{
		if (next_line[ft_strlen(next_line) - 1] == '\n')
			next_line[ft_strlen(next_line) - 1] = '\0';
		handle_elements(data, next_line, fd);
		free(next_line);
		next_line = get_next_line(fd);
	}
	xclose(fd);
	current = data->objects;
	while (current)
	{
		obj = (t_object *)current->content;
		current = current->next;
	}
	return (0);
}

static int	process_element(t_data *data, char **elements)
{
	if (ft_strcmp(elements[0], "A") == 0)
		return (set_ambient(data, elements + 1));
	else if (ft_strcmp(elements[0], "C") == 0)
		return (set_camera(data, elements + 1));
	else if (ft_strcmp(elements[0], "L") == 0)
		return (set_light(data, elements + 1));
	else if (ft_strcmp(elements[0], "pl") == 0)
		return (set_plane(data, elements + 1));
	else if (ft_strcmp(elements[0], "sp") == 0)
		return (set_sphere(data, elements + 1));
	else if (ft_strcmp(elements[0], "cy") == 0)
		return (set_cylinder(data, elements + 1));
	return (-1);
}

static int	handle_elements(t_data *data, char *next_line, int fd)
{
	char	**elements;

	elements = xsplit(next_line, ' ');
	if (process_element(data, elements) == -1)
	{
		free_ptrarr((void **)elements);
		xclose(fd);
		msg_exit("Invalid or error processing element in file");
	}
	free_ptrarr((void **)elements);
	return (1);
}
