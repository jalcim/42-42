/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/26 17:14:49 by jalcim            #+#    #+#             */
/*   Updated: 2014/08/26 19:19:45 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_object t_object;

struct s_object
{
	int compt;
	char car;
}

void one()
{
	int decal;

	decal = compt(0);
	
}

void null()
{
	
}

int compt(t_object *save)
{
	static t_object *object = NULL;

	if (save)
		object = save;
	else
		return (object);
	return (NULL);
}

int main()
{
	signal(SIGUSR1, one);
	signal(SIGUSR2, null);

}
