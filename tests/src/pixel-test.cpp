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