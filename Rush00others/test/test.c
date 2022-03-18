#include <unistd.h>

void test_putchar(char c)
{
	write(1, &c, 1);
}
