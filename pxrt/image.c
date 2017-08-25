#include "image.h"

#include <stdlib.h>
#include <stdint.h>

static const int INITIAL_LAYER_CAPACITY = 10;
static const double CAPACITY_INCREMENT = 0.5;

struct PxrtImage {
	int layer_count;
	int layers_capacity;
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
	PxrtImage *image;
};


static PxrtLayer *
alloc_layer(int width, int height);

static void
dealloc_layer(PxrtLayer **layer);

static void
update_pixel(PxrtImage *image, int x, int y);


PxrtLayer *
pxrt_image_add_layer(PxrtImage *image, int width, int height)
{
	PxrtLayer *layer = alloc_layer(width, height);
	layer->image = image;

	if (image->layers_capacity == image->layer_count) {
		image->layers_capacity *= CAPACITY_INCREMENT;
		image->layers = realloc(image->layers, sizeof (PxrtLayer *) * image->layers_capacity);
	}

	layer->number = image->layer_count;
	image->layers[image->layer_count++] = layer;

	return layer;
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

PxrtRgba
pxrt_image_get_pixel(PxrtImage *image, int x, int y)
{
	return image->pixels[image->height * y + x]; // FIXME: stub
}

PxrtImage *
pxrt_image_new(int width, int height)
{
	int x, y;
	PxrtImage *image = (PxrtImage *) malloc(sizeof (PxrtImage));
	image->width = width;
	image->height = height;
	image->layer_count = 0;
	image->pixels = (PxrtRgba *) malloc(sizeof (PxrtRgba) * width * height);

	for (x = 0; x < width; x++)
		for (y = 0; y < height; y++)
			update_pixel(image, x, y);
	
	return image;
}

void
pxrt_layer_remove(PxrtLayer **layer)
{
	int i;
	int number = (*layer)->number;
	PxrtImage *image = (*layer)->image;

	for (i = number; i < image->layer_count - 1; i++)
		image->layers[i] = image->layers[i + 1];

	dealloc_layer(layer);
}

void
pxrt_layer_set_pixel(
		PxrtLayer *layer,
		int x,
		int y,
		uint8_t red,
		uint8_t green,
		uint8_t blue,
		uint8_t alpha)
{
	PxrtRgba value = { red, green, blue, alpha };
	x += layer->x;
	y += layer->y;
	layer->pixels[y * layer->width + x] = value;

	update_pixel(layer->image, x, y);
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

static void
update_pixel(PxrtImage *image, int x, int y)
{
	// TODO: implement
}
