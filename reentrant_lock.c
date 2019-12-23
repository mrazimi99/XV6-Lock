#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char* argv[])
{
	write(1, "Testing reentrant lock!\n", 33);
	recursive_lock_test(10);
	exit();
}