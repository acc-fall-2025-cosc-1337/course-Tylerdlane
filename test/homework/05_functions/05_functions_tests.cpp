#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>

// Function declarations (assume these are implemented elsewhere)
double get_gc_content(const std::string& dna);
std::string get_reverse_string(std::string dna);
std::string get_dna_complement(std::string dna);

TEST_CASE("Test get_gc_content") {
	REQUIRE(get_gc_content("AGCTATAG") == Approx(0.375));
	REQUIRE(get_gc_content("CCGG") == Approx(1.0));
	REQUIRE(get_gc_content("ATAT") == Approx(0.0));
}

TEST_CASE("Test get_reverse_string") {
	REQUIRE(get_reverse_string("AGCT") == "TCGA");
	REQUIRE(get_reverse_string("A") == "A");
	REQUIRE(get_reverse_string("") == "");
	REQUIRE(get_reverse_string("GATTACA") == "ACATTAG");
}

TEST_CASE("Test get_dna_complement") {
	REQUIRE(get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT");
	REQUIRE(get_dna_complement("CCGTA") == "TACGG");
	REQUIRE(get_dna_complement("A") == "T");
	REQUIRE(get_dna_complement("") == "");
}
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

