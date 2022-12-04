// squarer_test.cpp  FINISHED
// Brandon Forsythe
// 12/3/22
//
// For CS 311 Fall 2022
// Test program for class Squarer
// For Assignment 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.h

// Includes for code to be tested
#include "squarer.h"         // For class Squarer

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                             // doctest writes main for us
#include "doctest.h"         // For doctest framework


// *********************************************************************
// Test Cases
// NOTE: THESE WORK, SEE COMMENTED BELOW FOR TEST CASES THAT DON'T.
// *********************************************************************


TEST_CASE("Squarer: 7")
{
    Squarer sq;

    SUBCASE("7 Squared") {
        int arg = 7;
        int result = 49;  // WRONG!!!
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
    SUBCASE("1337 Squared") {
        int arg = 1337;
        int result = 1787569;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
}

TEST_CASE("Squarer: Negative Integers")

{
    Squarer squared;

    SUBCASE("-1 Squared") {
        INFO("-1 Squared should be 1");
        REQUIRE(squared(-1) == 1);
    }
    SUBCASE("-50 Squared") {
        INFO("-50 Squared should be 2500");
        REQUIRE(squared(-50) == 2500);
    }
    SUBCASE("-1337 Squared") {
        INFO("-1337 Squared should be 178759");
        REQUIRE(squared(-1337) == 1787569);
    }
}

TEST_CASE("Squarer: Negative Doubles") {
    Squarer squared;

    SUBCASE("-1.1 Squared") {
        INFO("-1.1 Squared should be 1.21");
        REQUIRE(squared(-1.1) == doctest::Approx(1.21));

    }
    SUBCASE("-2.2 Squared") {
        INFO("-2.2 Squared should be 1.21");
        REQUIRE(squared(-2.2) == doctest::Approx(4.84));

    }
    SUBCASE("-5.533 Squared") {
        INFO("-5.533 Squared should be 1.21");
        REQUIRE(squared(-5.533) == doctest::Approx(30.614089));

    }

}

TEST_CASE("Squarer: Positive Doubles") {
    Squarer squared;

    SUBCASE("1.1 Squared") {
        INFO("1.1 Squared should be 1.21");
        REQUIRE(squared(1.1) == doctest::Approx(1.21));

    }
    SUBCASE("2.2 Squared") {
        INFO("2.2 Squared should be 1.21");
        REQUIRE(squared(2.2) == doctest::Approx(4.84));

    }
    SUBCASE("5.533 Squared") {
        INFO("5.533 Squared should be 1.21");
        REQUIRE(squared(5.533) == doctest::Approx(30.614089));

    }

}

TEST_CASE("Squarer: Special Cases") {
    Squarer squared;

    SUBCASE("0 Squared") {
        INFO("0 Squared should be 0");
        REQUIRE(squared(0) == 0);
    }
    SUBCASE("1 Squared") {
        INFO("1 Squared should be 1");
        REQUIRE(squared(1) == 1);
    }
    SUBCASE("-1 Squared") {
        INFO("-1 Squared should be 1");
        REQUIRE(squared(-1) == 1);
    }
}



// ****************************************************************
// * Bad Functions for Bad Programmers who can't compute squares  *
// ****************************************************************


/*  ****Uncomment me to release the beasts****

TEST_CASE("Squarer: count-on-fingers") {
    Squarer squared;
    SUBCASE("11 Squared") {
        INFO("11 Squared SHOULD be 121, but I counted wrong");
        REQUIRE(squared(11) == 111);
    }
    SUBCASE("10010101 Squared") {
        INFO("10010101 Squared should be... something");
        REQUIRE(squared(10010101) == 4);
    }
} */
