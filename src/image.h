#ifndef IMAGE_H
#define IMAGE_H

#include <cmath>
#include <iostream>
#include <random>
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
		/* Constructors */
		Image();
		Image(string filename);
		Image(int w, int h, vector<unsigned char> image);
		Image(int w, int h, vector<Pixel> image);

		Image(Image && other);                      // move constructor
		Image(const Image & other);                 // copy constructor
		~Image();                                   // destructor

		/* Operator Overloads */
		Image & operator = (const Image & other);   // assignment operator
		Image & operator = (Image && other);        // move assignment operator

		/* Getters */
		int getWidth()	const	{ return width; }
		int getHeight()	const	{ return height; }
		vector<Pixel> & getPixels() { return pixels; }
		Pixel & getPixel (int index) { return pixels[index]; }

		/* Utility  */
		static bool isValidKernel(const vector<float> & k);

		/* Image Functions */
		void save(string filename);

		// local (per-pixel) functions
		void invert();
		void toGreyscale();
		void threshold(int t);
		void modifyColour(int deltaR, int deltaG, int deltaB, int deltaA);

		// global functions
		void quantize(int k);                           // colour quantization by K-Means
		void convolve(const vector<float> & kernel);    // apply a kernel
		void blur();
		void sharpen();
		void detectEdges();
};

#endif
