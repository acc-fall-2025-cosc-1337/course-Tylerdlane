#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "repetition.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify get_factorial function")
{
	REQUIRE(get_factorial(5) == 120);
	REQUIRE(get_factorial(3) == 6);
	REQUIRE(get_factorial(1) == 1);
	REQUIRE(get_factorial(0) == 1);
	REQUIRE(get_factorial(4) == 24);
}

TEST_CASE("Verify sum_odd_numbers function")
{
	REQUIRE(sum_odd_numbers(10) == 25);  // 1+3+5+7+9 = 25
	REQUIRE(sum_odd_numbers(5) == 9);    // 1+3+5 = 9
	REQUIRE(sum_odd_numbers(1) == 1);    // 1 = 1
	REQUIRE(sum_odd_numbers(15) == 64);  // 1+3+5+7+9+11+13+15 = 64
	REQUIRE(sum_odd_numbers(20) == 100); // 1+3+5+...+19 = 100
}

