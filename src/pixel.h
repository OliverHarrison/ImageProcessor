#ifndef PIXEL_H
#define PIXEL_H

using namespace std;

class Pixel {

	private:
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;

	public:
		// constructors
		Pixel() : Pixel(0, 0, 0, 0) {}
		Pixel(unsigned char r, unsigned char g, unsigned char b) : Pixel(r, g, b, 255) {}
		Pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a) {}

		Pixel(Pixel && other);                         // move constructor
		Pixel(const Pixel & other);                    // copy constructor

		// operator overloads
		Pixel & operator = (const Pixel & other);      // assignment operator
		Pixel & operator = (Pixel && other);           // move assignment operator



		// getters
		unsigned char getR() { return r; }
		unsigned char getG() { return g; }
		unsigned char getB() { return b; }
		unsigned char getA() { return a; }

		// setters



		// functions


};

#endif