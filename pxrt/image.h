#include <stdint.h> 

typedef struct PxrtImage PxrtImage;

struct PxrtImage;

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
} PxrtRgba;

/**
* Returns color value in a given position
* @param x x-coordinate from left to right
* @param y y-coordinate from top to bottom
* @return color in RGBA format
*/
PxrtRgba
pxrt_image_get_pixel(PxrtImage *image, int x, int y);

/**
* Creating new image with specified measurments
* @param width width in pixels
* @param height height in pixels
* @return new image instance
*/
PxrtImage *
pxrt_image_new(int width, int height);

/**
* Disposes image and frees memory
* @param image image to be disposed
*/
void
pxrt_image_free(PxrtImage *image);
