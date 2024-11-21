/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:12:04 by msalim            #+#    #+#             */
/*   Updated: 2024/11/21 18:06:18 by msalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * function to protect the process id if its fails to fork;
 * main function just create the child processes and pass it to
 * their respective function;
  */
static void	protect(pid_t pid, int pipefd[])
{
	if (pid == -1)
	{
		perror("fork failed");
    close(pipefd[0]);
    close(pipefd[1]);
		exit(-1);
	}
}

int	main(int argc, char **argv)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		exit(-1);
	if (pipe(pipefd) == -1)
	{
    close(pipefd[0]);
    close(pipefd[1]);
		perror("pipe creation failed");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	protect(pid1, pipefd);
	if (pid1 == 0)
		first_child(pipefd, argv);
	pid2 = fork();
	protect(pid2, pipefd);
	if (pid2 == 0)
		second_child(pipefd, argv);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
/*we set up the enviornment today
 now i should know how to create uni-directional communication between procesess
 using fork and pipe to shit at the same time
 and using the helpers to redirect input and output by dup2
 keep tracking and knowing how many file descreptors are there (actually)
and then try to come up with solution to solve all of the	project;
*/