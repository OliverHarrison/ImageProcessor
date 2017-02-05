#include "catch.hpp"
#include "pixel.h"

void checkColour(Pixel & p, int r, int g, int b, int a) {
	REQUIRE((int)p.getR() == r);
	REQUIRE((int)p.getG() == g);
	REQUIRE((int)p.getB() == b);
	REQUIRE((int)p.getA() == a);
}

TEST_CASE ("Pixel Contructor", "[pixel.constructors]") {

	SECTION( "default" ) {
		Pixel p;
		checkColour(p, 0, 0, 0, 0);
	}

	SECTION( "rgb" ) {
		Pixel p(1,2,3);
		checkColour(p, 1, 2, 3, 255);
	}

	SECTION("rgba") {
		Pixel p(1,2,3, 4);
		checkColour(p, 1, 2, 3, 4);
	}

	SECTION("copy constructor") {
		Pixel p2(1, 2, 3, 4);
		Pixel p = p2;
		checkColour(p, 1, 2, 3, 4);
	}

	SECTION("move constructor") {
		Pixel p2(1, 2, 3, 4);
		Pixel p = p2;
		checkColour(p, 1, 2, 3, 4);
	}
}

TEST_CASE("Pixel Setters", "[pixel.setters]") {
	SECTION("setColour") {
		Pixel p;
		p.setColour(1, 2, 3, 4);
		checkColour(p, 1, 2, 3, 4);
	}
}

TEST_CASE("Pixel Utility", "[pixel.utility]") {
	SECTION("faltten") {
		REQUIRE(Pixel::flatten(-300) == 0);
		REQUIRE(Pixel::flatten(-1) == 0);
		REQUIRE(Pixel::flatten(0) == 0);
		REQUIRE(Pixel::flatten(1) == 1);
		REQUIRE(Pixel::flatten(128) == 128);
		REQUIRE(Pixel::flatten(255) == 255);
		REQUIRE(Pixel::flatten(256) == 255);
		REQUIRE(Pixel::flatten(300) == 255);
	}
}

TEST_CASE ("Pixel Operators", "[pixel.operators]") {
	SECTION("copy assignment") {
		Pixel p(20, 50, 80, 110);
		Pixel p2(1, 2, 3, 4);
		p = p2;
		checkColour(p, 1, 2, 3, 4);
	}

	SECTION("move assignment") {
		Pixel p(20, 50, 80, 110);
		Pixel p2(1, 2, 3, 4);
		p = move(p2);
		checkColour(p, 1, 2, 3, 4);
	}
}

TEST_CASE("Pixel Functions", "[pixel.functions]") {
	SECTION("invert") {
		Pixel p(20, 50, 80, 110);
		p.invert();
		checkColour(p, 235, 205, 175, 110);
	}
	SECTION("toGreyscale") {
		Pixel p(2, 4, 6, 10);
		p.toGreyscale();
		checkColour(p, 4, 4, 4, 10);
	}
	SECTION("threshold") {
		Pixel p(20, 40, 60, 100);
		p.threshold(30);
		checkColour(p, 0, 255, 255, 100);
	}
	SECTION("modifyColour") {
		Pixel p(20, 40, 60, 100);
		p.modifyColour(-10, 5, 3, 2);
		checkColour(p, 10, 45, 63, 102);
		p.modifyColour(-20, 50, 0, 200);
		checkColour(p, 0, 95, 63, 255);
	}
}

