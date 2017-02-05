#include "catch.hpp"
#include "pixel.h"
#include "image.h"

TEST_CASE ("Image Contructor", "[image.constructors]") {

	SECTION("default") {
		Image i;
		REQUIRE(i.getWidth() == 0);
		REQUIRE(i.getHeight() == 0);
		REQUIRE(i.getPixels().size() == 0);
	}

}