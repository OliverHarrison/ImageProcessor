#include "Image.h"

/* Constructors */

// default constructor
Image::Image() : width(0), height(0), pixels(0) {

}

// file constructor
Image::Image(string filename) {
	vector<unsigned char> image; //the raw pixels,  4 bytes per pixel, ordered RGBARGBA
  unsigned error = lodepng::decode(image, width, height, filename); //decode

  if(error) {
		cout << "Error when reading file. " << error << ": " << lodepng_error_text(error) << endl;
	}
	else {	//the pixels are now in the vector "image"
		for (int i=0; i<image.size(); i+=4) {
			pixels.push_back(Pixel(image[i], image[i+1], image[i+2], image[i+3]));
		}
	}
}

// char data constructor
Image::Image(int w, int h, vector<unsigned char> image) : width(w), height(h) {
	for (int i=0; i<image.size(); i+=4) {
		pixels.push_back(Pixel(image[i], image[i+1], image[i+2], image[i+3]));
	}
}

// pixel data contructor
Image::Image(int w, int h, vector<Pixel> image) : width(w), height(h), pixels(image) {

}

// move constructor
Image::Image(Image && other){
	width = other.width;
	height = other.height;
	pixels = std::move(other.pixels);
}
// copy constructor
Image::Image(const Image & other) {
	width = other.width;
	height = other.height;
	pixels = other.pixels;
}

/* Operator Overloads */

// assignment operator
Image & Image::operator = (const Image & other) {
	width = other.width;
	height = other.height;
	pixels = other.pixels;
	return *this;
}
// move assignment operator
Image & Image::operator = (Image && other) {
	width = other.width;
	height = other.height;
	pixels = std::move(other.pixels);
	return *this;
}

// destructor
Image::~Image() {
	width = 0;
	height = 0;
	pixels.clear();
}