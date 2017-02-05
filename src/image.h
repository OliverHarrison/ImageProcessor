#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

#include "Pixel.h"

using namespace std;

class Image {

private:
	int width; int height;
	vector<Pixel> pixels;
public:
	// constructors
	Image() : width(0), height(0), pixels(0) {}

	// operator overloads

	// getters
	int getWidth()	const	{ return width; }
	int getHeight()	const	{ return height; }
	vector<Pixel> & getPixels() { return pixels; }

	// functions
};

#endif