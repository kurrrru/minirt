/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimiyahara <marimiyahara@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:24:56 by marimiyahar       #+#    #+#             */
/*   Updated: 2024/12/13 23:59:07 by marimiyahar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set.h"

static int	process_element(t_data *data, char **elements);
static int	handle_elements(t_data *data, char *next_line, int fd);

int	read_file(t_data *data, char **argv)
{
	int		fd;
	char	*next_line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		msg_exit("failed to open file\n");
	next_line = get_next_line(fd);
	while (next_line)
	{
		if (!handle_elements(data, next_line, fd))
		{
			free(next_line);
			next_line = get_next_line(fd);
			continue ;
		}
		free(next_line);
		next_line = get_next_line(fd);
	}
	free(next_line);
	close(fd);
	return (0);
}

static int	process_element(t_data *data, char **elements)
{
	if (ft_strlen(elements[0]) == 1 && elements[0][0] == 'A')
		return (set_ambient(data, elements + 1));
	else if (ft_strlen(elements[0]) == 1 && elements[0][0] == 'C')
		return (set_camera(data, elements + 1));
	else if (ft_strlen(elements[0]) == 1 && elements[0][0] == 'L')
		return (set_light(data, elements + 1));
	else if (ft_strncmp(elements[0], "pl", 2) == 0 && elements[0][2] == '\0')
		return (set_plane(data, elements + 1));
	else if (ft_strncmp(elements[0], "sp", 2) == 0 && elements[0][2] == '\0')
		return (set_sphere(data, elements + 1));
	else if (ft_strncmp(elements[0], "cy", 2) == 0 && elements[0][2] == '\0')
		return (set_cylinder(data, elements + 1));
	return (-1);
}

static int	handle_elements(t_data *data, char *next_line, int fd)
{
	char	**elements;
	int		status;

	elements = ft_split(next_line, ' ');
	if (!elements)
		return (0);
	status = process_element(data, elements);
	if (status == -1)
	{
		free_ptrarr((void **)elements);
		close(fd);
		msg_exit("Invalid or error processing element in file\n");
	}
	free_ptrarr((void **)elements);
	return (1);
}
