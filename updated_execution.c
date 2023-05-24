#include "shell.h"

/**
 * updated_process - create new process
 * @argv: array of string
 *
 * Return: 1 or 0 if failed
 */
int updated_process(char **argv)
{
	pid_t pid;
	int condition;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("error in updated_process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in updated_process: forking");
	}
	else
	{
		do {
			waitpid(pid, &condition, WUNTRACED);
		} while (!WIFEXITED(condition) && !WIFSIGNALED(condition));
	}
	return (-1);
}
