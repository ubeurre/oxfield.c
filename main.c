/* Include Standard Libraries */
#include <stdio.h>
#include <stdint.h>
/* Include Custom Libraries . */
#include "oxfield.c"
/* Entry Point .............. */
int main(void)
{
	oxFill(buffer, WIDTH, HEIGHT, '.');
	oxDrawFillRect(buffer, 0, 0, 8, 4,	':');
	oxDrawFillRect(buffer, 16, 0, 8, 4,	'-');
	oxDrawFillRect(buffer, 0, 4, 8, 9,	'=');
	oxDrawFillRect(buffer, 16, 4, 8, 9, '+');
	oxSetChar(buffer, 4, 2, '@');
	oxSetChar(buffer, 11, 2, oxGetChar(buffer, 4, 2));
	oxDrawLine(buffer, 2, 4, 14, 7, '@');
	oxRender(buffer, WIDTH, HEIGHT);
	return 0;
}
/* .......................... */
