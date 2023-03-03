#ifndef __OXFIELD_C__
#define __OXFIELD_C__

/* Defines and Macros ....... */
#define WIDTH	16
#define HEIGHT	9
#define ox_sub(a, b)	(a) > (b) ? (a) - (b) : (b) - (a)
#define ox_min(a, b)	(a) < (b) ? (a) : (b)
#define ox_max(a, b)	(a) > (b) ? (a) : (b)
/* Global Variables ......... */
static uint8_t buffer[HEIGHT * WIDTH];
/* Procedures ............... */
void oxFill(uint8_t * buffer, size_t w, size_t h, uint8_t c)
{
	for (size_t i = 0; i < w * h; ++i)
		buffer[i] = c;
}
void oxDrawFillRect(uint8_t * buffer, size_t x1, size_t y1,
					size_t x2, size_t y2, uint8_t c)
{
	size_t w = ox_sub(x2, x1);
	size_t h = ox_sub(y2, y1);
	size_t sx = ox_min(x1, x2);
	size_t sy = ox_min(y1, y2);
	for (size_t i = 0; i < h; ++i)
		for (size_t j = 0; j < w; ++j)
			buffer[(sy + i) * WIDTH + (sx + j)] = c;
}
void oxSetChar(uint8_t * buffer, size_t x, size_t y, uint8_t c)
{
	buffer[y * WIDTH + x] = c;
}
uint8_t oxGetChar(uint8_t * buffer, size_t x, size_t y)
{
	return buffer[y * WIDTH + x];
}
// TODO: Bresenham's Line Algorithm
void oxDrawLine(uint8_t * buffer, size_t x1, size_t y1,
				size_t x2, size_t y2, uint8_t c)
{
	size_t w = ox_sub(x2, x1);
	size_t h = ox_sub(y2, y1);
	size_t sx = ox_min(x1, x2);
	size_t sy = ox_min(y1, y2);
	for (size_t y = 0; y < h; ++y) {
		for (size_t x = 0; x < (w / h); ++x) {
			buffer[(sy + y) * WIDTH + sx] = c;
			++sx;
		}
	}
}
void oxRender(uint8_t * buffer, size_t w, size_t h)
{
	for (size_t y = 0; y < h; ++y) {
		for (size_t x = 0; x < w; ++x)
			printf("%c ", buffer[y * w + x]);
		putc('\n', stdout);
	}
}

#endif // __OXFIELD_C__
