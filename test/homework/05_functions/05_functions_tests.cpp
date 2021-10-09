#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify GC content"){
	REQUIRE(get_gc_content("AGCTATAG")==.375);
	REQUIRE(get_gc_content("CGCTATAG")==.5);
}


TEST_CASE("Verify Reverse String"){
	REQUIRE(get_reverse_string("AGCTATAG") == "GATATCGA");
	REQUIRE(get_reverse_string("CGCTATAG" )== "GATATCGC");
}




TEST_CASE("Verify dna complement"){
	REQUIRE(get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT");
	REQUIRE(get_dna_complement("CCCGGAAAAT") == "ATTTTCCGGG");

}