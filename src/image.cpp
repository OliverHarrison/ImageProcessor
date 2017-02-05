#include "Image.h"

/* Default Constructor */
Image::Image() : width(0), height(0), pixels(0) {

}

/* File Constructor */
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

/* Char Data Constructor */
Image::Image(int w, int h, vector<unsigned char> image) : width(w), height(h) {
	for (int i=0; i<image.size(); i+=4) {
		pixels.push_back(Pixel(image[i], image[i+1], image[i+2], image[i+3]));
	}
}

/* Pixel Data Contructor */
Image::Image(int w, int h, vector<Pixel> image) : width(w), height(h), pixels(image) {

}