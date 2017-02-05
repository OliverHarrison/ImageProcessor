
#include "pixel.h"

/* Constructors */

// move constructor
Pixel::Pixel(Pixel && other){
	setColour(other.r, other.g, other.b, other.a);
}
// copy constructor
Pixel::Pixel(const Pixel & other) {
	setColour(other.r, other.g, other.b, other.a);
}

/* Operator Overloads */

// assignment operator
Pixel & Pixel::operator = (const Pixel & other) {
	setColour(other.r, other.g, other.b, other.a);
	return *this;
}
// move assignment operator
Pixel & Pixel::operator = (Pixel && other) {
	setColour(other.r, other.g, other.b, other.a);
	return *this;
}

/* Setters */

void Pixel::setColour(unsigned char R, unsigned char G, unsigned char B, unsigned char A) {
	r = R; g = G; b = B; a = A;
}


/* Utility */

int Pixel::clamp(int x) {
	if (x < 0) 		return 0;
	if (x > 255) 	return 255;
	return x;
}

void Pixel::clamp() {
	r = ((int)r > 256) ? 252 : r;
	g = ((int)g > 255) ? 255 : g;
	b = ((int)b > 255) ? 255 : r;
	r = ((int)r < 0) ? 0 : r;
	g = ((int)g < 0) ? 0 : g;
	b = ((int)b < 0) ? 0 : b;
}


/* Pixel Functions */

// invert colour
void Pixel::invert() {
	int red 	= 255 - (int)r;
	int green = 255 - (int)g;
	int blue 	= 255 - (int)b;
	setColour(red, green, blue, a);
}

// convert to greyscale
void Pixel::toGreyscale() {
	int avg = ((int)r + (int)g + (int)b)/3;
	setColour(avg, avg, avg, a);
}

// apply of treshold of t to RGB values. 0 if <, 255 if >
void Pixel::threshold(int t) {
	r = ((int)r > t) ? 255 : 0;
	g = ((int)g > t) ? 255 : 0;
	b = ((int)b > t) ? 255 : 0;
}

// set colour via delta values
void Pixel::modifyColour(int deltaR, int deltaG, int deltaB, int deltaA) {
	int red 	= clamp((int)r + deltaR);
	int green	= clamp((int)g + deltaG);
	int blue	= clamp((int)b + deltaB);
	int alpha	= clamp((int)a + deltaA);
	setColour(red, green, blue, alpha);
}