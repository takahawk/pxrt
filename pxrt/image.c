#include "image.h"
#include "layer.h"

struct PxrtImage {
	int layer_count;
	PxrtLayer *layers;
};

PxrtRgba
pxrt_image_get_pixel(PxrtImage *image, int x, int y)
{
	PxrtRgba pixel = { 0, 0, 0, 0};
	if (image->layer_count == 0)
		return pixel; // fully transparent

	return pixel; // FIXME: stub
}

PxrtImage *
pxrt_image_new(int width, int height)
{
	return 0; // FIXME: stub
}

void
pxrt_image_free(PxrtImage *image)
{
	// FIXME: implement
}

