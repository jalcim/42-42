/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/26 17:14:49 by jalcim            #+#    #+#             */
/*   Updated: 2014/08/27 17:55:53 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <signal.h>

typedef struct s_object t_object;

struct s_object
{
	int compt;
	int byte_index;
	char car;
};

t_object *compt(t_object *save);
void one();
void null();
int save_pid(int spid);
void connect(int sig, siginfo_t *info, void * X);

void one()
{
	t_object *object;

	object = compt(NULL);
}

void null()
{
	
}

t_object *compt(t_object *save)
{
	static t_object *object = NULL;

	if (save)
		object = save;
	else
		return (object);
	return (NULL);
}

int save_pid(int spid)
{
	static int pid = 0;

	if (spid)
		pid = spid;
	else
		return (pid);
}

void connect(int sig, siginfo_t *info, void * X)
{
	int pid;

	pid = info->si_pid;
	kill(pid, SIGUSR1);
	save_pid(pid);
	printf("connect\n");
}

int main()
{
	struct sigaction act;

	printf("mon pid = %d\n", getpid());
    act.sa_sigaction = connect;
    sigaction(SIGUSR1, &act, NULL);
	sleep(500);
	printf("sig error\n");
}
