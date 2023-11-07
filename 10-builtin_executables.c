#include "shell.h"

void exec_exit(char **cmd, int status)
{
	free2d(cmd);
	exit(status);
}
