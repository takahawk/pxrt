#include <stdint.h> 

typedef struct PxrtImage PxrtImage;
typedef struct PxrtLayer PxrtLayer;

struct PxrtImage;
struct PxrtLayer;

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
} PxrtRgba;


/**
* Adds new layer to image
* @param image receiver
* @param width width in pixels of the new layer
* @param height height in pixels of the new layer
* @return new layer
*/
PxrtLayer *
pxrt_image_add_layer(PxrtImage *image, int width, int height);

/**
* Disposes image and frees memory
* @param image image to be disposed
*/
void
pxrt_image_free(PxrtImage **image);

/**
* Returns color value in a given position
* @param image receiver
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
* Removes layer from image
* @param layer layer to be removed
*/
void
pxrt_layer_remove(PxrtLayer **layer);

/**
* Sets color value at a given position
* @param x x-coordinata top to bottom
* @param y y-coordinate left to right
*/
void
pxrt_layer_set_pixel(
		PxrtLayer *layer,
		int x,
		int y,
		uint8_t red,
		uint8_t green,
		uint8_t blue,
		uint8_t alpha);
