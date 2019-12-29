#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
	if(argc != 1)
	{
		printf(2, "Usage: barrier\n");
		exit();
	}

	int i;
	int pid = 0;
	init_barrier(7);

	for (i = 0; i < 6; ++i)
	{
		pid = fork();
		double counter;

		for (counter = 0; counter < 300000; counter += 0.1)
			continue;

		if (!pid)
			break;
	}

	printf(1, "%d reached behind of barrier\n", getpid());
	barrier();
	printf(1, "%d passed the barrier\n", getpid());

	for (i = 0; i < 6; ++i)
	{
		if (pid)
		{
			printf(1, "free: %d\n", wait());
		}
	}

	printf(1, "%d finished\n", getpid());
	exit();
}