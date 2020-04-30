#include "doctest.h"
#include "solver.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace solver;

TEST_CASE("Test 1") { 
    RealVariable x;
    CHECK(solve(x*2 == 10) == 5);
    CHECK(solve(x+3 == 5) == 2);
    CHECK(solve(x*2 + x*5 == 14) == 2);
    CHECK(solve(x-3 == 3) == 6);
    CHECK(solve(x+3-(3-x) == 2) == 1);
    CHECK(solve(4*(x-2) == 8) == 4);
    CHECK(solve(x*5 + x*5 - x*8 == 2) == 1);
    CHECK(solve(x/2 == 2) == 4);
    CHECK(solve(x + x/2 == 9) == 6);
    CHECK(solve(2*x - x/2 == 15) == 10);
    CHECK(solve((x^2) == 4) == 2);
    CHECK(solve(2*x==9)==4.5);
    CHECK(solve(2*x==18)==9);
    CHECK(solve(4*x==36)==9);
    CHECK(solve(2*x==100)==50);
    CHECK(solve((x^2)/2 == 8) == 4);
}

TEST_CASE("Test 2") { 
    ComplexVariable x;
    CHECK(solve(x*3 == 6) == std::complex<double>(2,0));
    CHECK(solve(x+5 == 7) == std::complex<double>(2,0));
    CHECK(solve(x*2 + x*5 == 7) == std::complex<double>(1,0));
    CHECK(solve(x-4 == 2) == std::complex<double>(6,0));
    CHECK(solve(x+2-(2-x) == 2) == std::complex<double>(1,0));
    CHECK(solve(2*(x-2) == 2) == std::complex<double>(3,0));
    CHECK(solve(x*2 + x*5 - x*6 == 7) == std::complex<double>(7,0));
    CHECK(solve(x/2 == 2) == std::complex<double>(4,0));
    CHECK(solve(x + x/2 == 6) == std::complex<double>(4,0));
    CHECK(solve(2*x - x/2 == 6) == std::complex<double>(4,0));
    CHECK(solve(x-4 == 10)==std::complex<double>(14,0)); 
    CHECK(solve((x^2)== 9)==std::complex<double>(3,0)); 
    CHECK(solve((x^2)== 81)==std::complex<double>(9,0)); 
    CHECK(solve((x^2) == 4) == std::complex<double>(2,0));
}


TEST_CASE("Test 3") { 
    RealVariable x;
    CHECK(solve((x*2)*2 == 4) == 1);
    CHECK(solve(x+1+2+3-1-2 == 10) == 7);
    CHECK(solve(x+1+1+1+1+1 == 5) == 0);
    CHECK(solve((x*2)*2 + (x*5)*5 == 29) == 1);
    CHECK(solve(x-5-5-5-5-5-5 == 35) == 65);
    CHECK(solve(x+3-(4-x)+(x+8)-(3-x)-x == 1) == -1);
    CHECK(solve(2*(2*(x-2)) == 2) == 2.5);
    CHECK(solve((x*3)*2 + (x*3)*2 - (x*3)*2 == 12) == 2);
    CHECK(solve(((x/4)/2)*2 == 10) == 40);
    CHECK(solve(x + x/2 + x/4 + x/8 == 30) == 16);
    CHECK(solve(4*(2*x) - (x/2) == 5*12) == 8);
    CHECK(solve(((x^2)*2)*7 == 14) == 1);
    CHECK(solve((((2*x)^2) + (3*(2*x)^2) + 16) == 16) == 0);
}


TEST_CASE("Test 4") {
    ComplexVariable x;
    CHECK(solve((x*2)*2 == 4) == std::complex<double>(1,0));
    CHECK(solve(x+2+2+2+2+2 == 10) == std::complex<double>(0,0));
    CHECK(solve((x*2)*2 + (x*5)*5 == 29) == std::complex<double>(1,0));
    CHECK(solve(x-2-2-2-2-2-2 == -2) == std::complex<double>(10,0));
    CHECK(solve(x+2-(2-x)+(x+7)-(3-x)-x == 1) == std::complex<double>(-1,0));
    CHECK(solve(2*(2*(x-2)) == 2) == std::complex<double>(2.5,0));
    CHECK(solve((x*2)*2 + (x*5)*5 - (x*6)*3 == 11) == std::complex<double>(1,0));
    CHECK(solve(((x/2)/2)/2 == 2) == std::complex<double>(16,0));
    CHECK(solve(x + x/2 + x/4 + x/8 == 30) == std::complex<double>(16,0));
    CHECK(solve(4*(2*x) - (x/2) == 5*15) == std::complex<double>(10,0));
    CHECK(solve(((x^2)*2)*7 == 0) == std::complex<double>(0,0));
    CHECK(solve((x^2) + 2*x - 2 == -3) == std::complex<double>(-1,0));
    CHECK(solve((((2*x)/3)^2) == 144) == std::complex<double>(18,0));
    CHECK(solve((((2*x)^2)/4) == -1) == std::complex<double>(0,1));
    CHECK(solve((((2*x)^2)/2)/4 == -8) == std::complex<double>(0,4));
}


TEST_CASE("Test 5") {
    RealVariable x;
    CHECK(solve(x+2+3 == 5) == 0);
    CHECK(solve(x*3 + x*3 == 6) == 1);
    CHECK(solve(x-99 == 99) == 198);
    CHECK(solve(x+3-(4-x) == 2) == 1.5);
    CHECK(solve(2*(x-2) == 2) == 3);
    CHECK(solve(x*2 + x*5 - x*5 == 6) == 3);
    CHECK(solve(x/2 == 2) == 4);
    CHECK(solve(x + x/2 == 6) == 4);
    CHECK(solve(2*x - x/2 == 6) == 4);
    CHECK(solve((x^2) == 4) == 2);
    CHECK(solve((x^2) + 2*x - 2 == -3) == -1);
    CHECK(solve((x^2) + 2*x - 5 == -6) == -1);
    CHECK(solve((x^2)/2 == 8) == 4);
    CHECK(solve(x+2 == 4) == 2);
    CHECK(solve(x*2 + x*5 == 7) == 1);
    CHECK(solve(x-2 == 2) == 4);
    CHECK(solve(x+2-(2-x) == 2) == 1);
    CHECK(solve(2*(x-2) == 2) == 3);
    CHECK(solve(x*2 + x*5 - x*6 == 7) == 7);
    CHECK(solve(x/2 == 2) == 4);
    CHECK(solve(x + x/2 == 6) == 4);
    CHECK(solve(2*x - x/2 == 6) == 4);
    CHECK(solve(x-3 == 3) == 6);
    CHECK(solve(x+3-(3-x) == 2) == 1);
    CHECK(solve(4*(x-2) == 8) == 4);
    CHECK(solve(x*5 + x*5 - x*8 == 2) == 1);
    CHECK(solve(x/2 == 2) == 4);
    CHECK(solve(x + x/2 == 9) == 6);
    CHECK(solve(2*x - x/2 == 15) == 10);
    CHECK(solve((x^2) == 4) == 2);
    CHECK(solve(2*x==9)==4.5);
    CHECK(solve(2*x==18)==9);
    CHECK(solve(3*x==18)==6);
    CHECK(solve(4*x==36)==9);
    CHECK(solve(x + x/2 == 6) == 4);
    CHECK(solve(2*x - x/2 == 6) == 4);
    CHECK(solve((x^2) == 4) == 2);
    CHECK(solve((x^2) + 2*x - 2 == -3) == -1);
    CHECK(solve((x^2)/2 == 8) == 4);
    CHECK(solve(x+2 == 4) == 2);
    CHECK(solve(x*2 + x*5 == 7) == 1);
    CHECK(solve(x-2-2 == 4) == 8);
    CHECK(solve(x+2-(2-x) == 2) == 1);
    CHECK(solve(2*(x-2) == 2) == 3);
    CHECK(solve(x + x*3 - x*2 +x*4 +x == 7) == 1);
}
