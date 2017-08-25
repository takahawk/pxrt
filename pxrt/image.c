#include "image.h"

#include <stdlib.h>
#include <stdint.h>

struct PxrtImage {
	int layer_count;
	int width;
	int height;
	PxrtLayer **layers;
	PxrtRgba *pixels;
};

struct PxrtLayer {
	// TODO: add transparency
	int number;
	int x;
	int y;
	int width;
	int height;
	PxrtRgba *pixels;
};


static PxrtLayer *
alloc_layer(int width, int height);

static void
dealloc_layer(PxrtLayer **layer);


PxrtRgba
pxrt_image_get_pixel(PxrtImage *image, int x, int y)
{
	return image->pixels[image->height * y + x]; // FIXME: stub
}

PxrtImage *
pxrt_image_new(int width, int height)
{
	PxrtImage *image = (PxrtImage *) malloc(sizeof (PxrtImage));
	image->width = width;
	image->height = height;
	image->layer_count = 0;
	image->pixels = (PxrtRgba *) malloc(sizeof (PxrtRgba) * width * height);
	return image; // FIXME: stub
}

void
pxrt_image_free(PxrtImage **image)
{
	int i;
	for (i = 0; i < (*image)->layer_count; i++)
		dealloc_layer(&(*image)->layers[i]);
	free((*image)->pixels);
	free((*image));
	*image = NULL;
}


static PxrtLayer *
alloc_layer(int width, int height)
{
	PxrtLayer *layer = (PxrtLayer *) malloc(sizeof (PxrtLayer));
	layer->x = 0;
	layer->y = 0;
	layer->width = width;
	layer->height = height;
	layer->pixels = (PxrtRgba *) malloc(sizeof (PxrtRgba) * width * height);

	return layer;
}


static void
dealloc_layer(PxrtLayer **layer)
{
	free((*layer)->pixels);
	free(*layer);
	*layer = NULL;
}
