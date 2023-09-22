/**
 * fork_cmd - fork Child pRocess and execute command. dd.
 * @inform: structure for parameter and return . dd.
 */
void my_fork_cmd(info_t *inform)
{
	pid_t ch_pid; /*The child PID*/

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (ch_pid == 0)
	{
		if (execve(inform->path, inform->argv, my_get_environ(inform)) == -1)
		{
			my_free_info(inform, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(inform->status));
		if (WIFEXITED(inform->status))
		{
			inform->status = WEXITSTATUS(inform->status);
			if (inform->status == 126)
				my_print_error(inform, "Permission denied\n");
		}
	}
}
