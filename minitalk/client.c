/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/26 16:33:37 by jalcim            #+#    #+#             */
/*   Updated: 2014/08/27 18:17:45 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_object t_object;

struct s_object
{
	int pid;
	int index;
	char *string;
};

char *balance(char **buffer, char **tmp, int *compt, int fd);
char *ft_fd_in_str(int fd);
t_object *carbu(t_object *save);
void error(char *strerr);
void connect();
void err_transmit();

int main()
{
	t_object *object;

	signal(SIGUSR1, connect);
	signal(SIGUSR2, err_transmit);

	object = (t_object *)malloc(sizeof(t_object));

	printf("server pid : ");
	scanf("%d", &object->pid);

	printf("entrez la chaine\n");

	object->string = ft_fd_in_str(0);

	object->index = 0;
	carbu(object);

	printf("signal sended\n");
	kill(object->pid, SIGUSR1);
	sleep(500);
	error("connection error :");
}

void err_transmit()
{
	printf("erreur de transmition\n");
}

void error(char *strerr)
{
	perror(strerr);
}


void connect()
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
