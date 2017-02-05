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

	Image(Image && other);												// move constructor
	Image(const Image & other);                   // copy constructor
	~Image();																		 	// destructor

	// operator overloads
	Image & operator = (const Image & other);			// assignment operator
	Image & operator = (Image && other);					// move assignment operator

	// getters
	int getWidth()	const	{ return width; }
	int getHeight()	const	{ return height; }
	vector<Pixel> & getPixels() { return pixels; }
	Pixel & getPixel (int index) { return pixels[index]; }

	/* Image Functions */

	void save(string filename);

	// local (per-pixel) functions
	void invert();
	void toGreyscale();
	void threshold(int t);
	void modifyColour(int deltaR, int deltaG, int deltaB, int deltaA);

	// global functions
	// kmeans
	// convolution - blur, sharpen, detect edges

};

#endif