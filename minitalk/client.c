/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/26 16:33:37 by jalcim            #+#    #+#             */
/*   Updated: 2014/08/26 19:20:07 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_object t_object;

struct s_object
{
	int pid;
	char *string;
}

char*balance(char **buffer, char **tmp, int *compt, int fd);
char*ft_fd_in_str(int fd);
t_object *carbu(t_object *save);
void error(char *strerr);
void ok();

int main()
{
	t_object *object;

	signal(SIGUSR1, ok);
	signal(SIGUSR2, err_transmit);

	object = (t_object *)malloc(sizeof(t_object));

	printf("server pid : ");
	scanf("%d", &object->pid);

	printf("entrez la chaine\n");
	object->string = ft_fd_in_str(0);
	carbu(object);
	kill(pid, SIGUSR1);
	sleep(1000);
	error("connection error :");
}

void error(char *strerr)
{
	perror();
}


void ok()
{
	t_object *object;

	object = carbu(NULL);
	printf("pid = %d string = :%s:\n", object->pid, object->string);
}

t_object *carbu(t_object *save)
{
	static t_object *object = NULL;
	char c;

	if (save)
		object = save;
	else if (object)
		return (object);
	return (NULL);
}

char *ft_fd_in_str(int fd)
{
	char*tmp;
	char*buffer;
	intcompt;

	compt = 0;
	tmp = (char *)malloc(2 * sizeof(char));
	bzero(tmp, 2);
	buffer = NULL;
	read(fd, tmp, 1);
	tmp[++compt] = '\0';
	while (42)
	{
		if (!buffer)
		{
			if (balance(&buffer, &tmp, &compt, fd))
				return (buffer);
		}
		else if (balance(&tmp, &buffer, &compt, fd))
			return (tmp);
	}
}

char *balance(char **buffer, char **tmp, int *compt, int fd)
{
	(*buffer) = (char *)malloc(*compt + 2 * sizeof(char));
	strcpy((*buffer), (*tmp));
	free((*tmp));
	(*tmp) = NULL;
	read(fd, &(*buffer)[*compt], 1);
	if (!((*buffer)[*compt]))
		return ((*buffer));
	(*buffer)[++*compt] = '\0';
	return (NULL);
}
