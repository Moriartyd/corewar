#include <stdio.h>
#include <stdint.h>

int main()
{
	uint16_t x;
	x = 1;
	printf(((uint8_t)1 & x) == 0 ? "big-indian" : "lil-indian\n");
	return(0);
}
