#include "catch.hpp"
#include "pixel.h"
#include "image.h"

#include <vector>

TEST_CASE ("Image Contructor", "[image.constructors]") {

	// some test data - read only
	vector<unsigned char> data;
	for (int i=0; i<9; ++i) {			// 3x3 image
		for (int j=0; j<4; ++j) {		// rgba
			data.push_back(i*20);
		}
	}

	vector<Pixel> pixels;
	for (int i=0; i<9; ++i) {
		pixels.push_back(Pixel(i*20, i*20, i*20, i*20));
	}

	SECTION("Default Constructor") {
		Image image;
		REQUIRE(image.getWidth() == 0);
		REQUIRE(image.getHeight() == 0);
		REQUIRE(image.getPixels().size() == 0);
	}

	SECTION("File Constructor") {
		Image image("test-images/t1.png");
		REQUIRE(image.getWidth() == 5);
		REQUIRE(image.getHeight() == 5);
		REQUIRE(image.getPixels().size() == 25);
		for (Pixel & p :image.getPixels()) {
			REQUIRE((int)p.getR() == 255);
			REQUIRE((int)p.getG() == 255);
			REQUIRE((int)p.getB() == 255);
		}
	}

	SECTION("Char Data Constructor") {
		Image image(3, 3, data);
		REQUIRE(image.getWidth() == 3);
		REQUIRE(image.getHeight() == 3);
		REQUIRE(image.getPixels().size() == 9);
		for (int i=0; i<9; ++i) {			// 3x3 image
			REQUIRE((int)image.getPixel(i).getR() == i*20);
			REQUIRE((int)image.getPixel(i).getG() == i*20);
			REQUIRE((int)image.getPixel(i).getB() == i*20);
			REQUIRE((int)image.getPixel(i).getA() == i*20);
		}
	}

	SECTION("Pixel Data Contructor") {
		// contruct vector of pixels
		Image image(3, 3, pixels);
		for (int i=0; i<9; ++i) {
			REQUIRE((int)image.getPixel(i).getR() == i*20);
			REQUIRE((int)image.getPixel(i).getG() == i*20);
			REQUIRE((int)image.getPixel(i).getB() == i*20);
			REQUIRE((int)image.getPixel(i).getA() == i*20);
		}
	}
}