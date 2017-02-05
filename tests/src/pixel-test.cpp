#include "catch.hpp"
#include "pixel.h"

TEST_CASE ("Pixel Contructor", "[pixel.constructors]") {

	SECTION( "default" ) {
		Pixel p;
		REQUIRE((int)p.getR() == 0);
		REQUIRE((int)p.getG() == 0);
		REQUIRE((int)p.getB() == 0);
		REQUIRE((int)p.getA() == 0);
	}

	SECTION( "rgb" ) {
		Pixel p(1,2,3);
		REQUIRE((int)p.getR() == 1);
		REQUIRE((int)p.getG() == 2);
		REQUIRE((int)p.getB() == 3);
		REQUIRE((int)p.getA() == 255);
	}

	SECTION("rgba") {
		Pixel p(1,2,3, 4);
		REQUIRE((int)p.getR() == 1);
		REQUIRE((int)p.getG() == 2);
		REQUIRE((int)p.getB() == 3);
		REQUIRE((int)p.getA() == 4);
	}
}