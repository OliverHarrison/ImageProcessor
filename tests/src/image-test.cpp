#include "catch.hpp"
#include "pixel.h"
#include "image.h"

#include <vector>

void checkPixelColour(Pixel & p, int c) {
	REQUIRE((int)p.getR() == c);
	REQUIRE((int)p.getG() == c);
	REQUIRE((int)p.getB() == c);
	REQUIRE((int)p.getA() == c);
}

void checkSize(Image & image, int w, int h, int size) {
	REQUIRE(image.getWidth() == w);
	REQUIRE(image.getHeight() == h);
	REQUIRE(image.getPixels().size() == size);
}

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

	SECTION("default constructor") {
		Image image;
		checkSize(image, 0, 0, 0);
	}

	SECTION("file constructor") {
		Image image("test-images/t1.png");
		checkSize(image, 5, 5, 25);
		for (Pixel & p :image.getPixels()) {
			REQUIRE((int)p.getR() == 255);
			REQUIRE((int)p.getG() == 255);
			REQUIRE((int)p.getB() == 255);
		}
	}

	SECTION("char data constructor") {
		Image image(3, 3, data);
		checkSize(image, 3, 3, 9);
		for (int i=0; i<9; ++i) {
			checkPixelColour(image.getPixel(i), i*20);
		}
	}

	SECTION("pixel data contructor") {
		// contruct vector of pixels
		Image image(3, 3, pixels);
		for (int i=0; i<9; ++i) {
			checkPixelColour(image.getPixel(i), i*20);
		}
	}

	SECTION("copy constructor") {
		Image image2(3, 3, data);
		Image image(image2);
		checkSize(image, 3, 3, 9);
		for (int i=0; i<9; ++i) {
			checkPixelColour(image.getPixel(i), i*20);
		}
	}

	SECTION("move constructor") {
		Image image2(3, 3, data);
		Image image = move(image2);
		checkSize(image, 3, 3, 9);
		for (int i=0; i<9; ++i) {
			checkPixelColour(image.getPixel(i), i*20);
		}
	}
}

TEST_CASE ("Image Operators", "[image.operators]") {
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

	SECTION("copy assignment") {
		Image image("test-images/t1.png");
		Image image2(3, 3, data);
		image = image2;
		checkSize(image, 3, 3, 9);
		for (int i=0; i<9; ++i) {
			checkPixelColour(image.getPixel(i), i*20);
		}
	}

	SECTION("move assignment") {
		Image image("test-images/t1.png");
		Image image2(3, 3, data);
		image = move(image2);
		checkSize(image, 3, 3, 9);
		for (int i=0; i<9; ++i) {
			checkPixelColour(image.getPixel(i), i*20);
		}
	}
}