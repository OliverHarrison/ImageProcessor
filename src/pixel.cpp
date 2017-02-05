
#include "pixel.h"

// move constructor
Pixel::Pixel(Pixel && other){
	r = other.r;
	g = other.g;
	b = other.b;
	a = other.a;
}
// copy constructor
Pixel::Pixel(const Pixel & other) {
	r = other.r;
	g = other.g;
	b = other.b;
	a = other.a;
}

// assignment operator
Pixel & Pixel::operator = (const Pixel & other) {
	r = other.r;
	g = other.g;
	b = other.b;
	a = other.a;
	return *this;
}
// move assignment operator
Pixel & Pixel::operator = (Pixel && other) {
	r = other.r;
	g = other.g;
	b = other.b;
	a = other.a;
	return *this;
}