#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>
#include <vector>

#include "Pixel.h"
#include "lodepng.h"

using namespace std;

class Image {

private:
	unsigned int width, height;
	vector<Pixel> pixels;
public:
	// constructors
	Image();
	Image(string filename);
	Image(int w, int h, vector<unsigned char> image);
	Image(int w, int h, vector<Pixel> image);

	// operator overloads

	// getters
	int getWidth()	const	{ return width; }
	int getHeight()	const	{ return height; }
	vector<Pixel> & getPixels() { return pixels; }
	Pixel & getPixel (int index) { return pixels[index]; }
	// Pixel & getPixel (int x, int y) { }
	// functions
};

#endif