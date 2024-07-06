/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:25:19 by lteng             #+#    #+#             */
/*   Updated: 2024/02/08 18:25:10 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, char **cmd, char *cmdpath)
{
	if (cmd != NULL)
		free_all(cmd);
	if (cmdpath != NULL)
		free(cmdpath);
	perror(str);
	exit(1);
}

char	*ft_path(char *cmd, char *envp[])
{
	char	**path;
	char	*testpath;
	char	*temp;
	int		i;

	i = 0;
	if (envp == NULL || envp[i] == NULL)
		return (NULL);
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		testpath = ft_strjoin(temp, cmd);
		free(temp);
		if (access(testpath, F_OK) == 0)
			return (free_all(path), testpath);
		free(testpath);
		i++;
	}
	return (free_all(path), NULL);
}

void	child_process(int pipefd[], char *cmd1, char *file1, char *envp[])
{
	int		fd;
	char	*cmdpath;
	char	**cmd;

	close(pipefd[0]);
	cmd = ft_split(cmd1, ' ');
	cmdpath = ft_path(cmd[0], envp);
	fd = open(file1, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening file child", NULL, NULL);
	dup2(fd, STDIN_FILENO);
	close(fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		ft_error("Error redirecting standard output\n", cmd, cmdpath);
	if (execve(cmdpath, cmd, envp) == -1)
		ft_error("Error executing command1\n", cmd, cmdpath);
}

void	parent_process(int pipefd[], char *cmd2, char *file2, char *envp[])
{
	int		fd;
	char	*cmdpath;
	char	**cmd;

	close(pipefd[1]);
	cmd = ft_split(cmd2, ' ');
	cmdpath = ft_path(cmd[0], envp);
	fd = open(file2, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		ft_error("Error opening file parent", NULL, NULL);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		ft_error("Error redirecting standard input\n", cmd, cmdpath);
	if (execve(cmdpath, cmd, envp) == -1)
		ft_error("Error executing command2\n", cmd, cmdpath);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipefd[2];
	pid_t	process_id;

	if (argc != 5)
		ft_error("Expecting ./pipex infile cmd cmd outfile\n", NULL, NULL);
	if (pipe(pipefd) == -1)
		ft_error("Pipe\n", NULL, NULL);
	process_id = fork();
	if (process_id == -1)
		ft_error("Fork\n", NULL, NULL);
	if (process_id == 0)
		child_process(pipefd, argv[2], argv[1], envp);
	else
		parent_process(pipefd, argv[3], argv[4], envp);
	return (0);
}
