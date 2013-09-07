#include "gtest/gtest.h"
#include <iostream>// for std::cout, std::endl
#include <string>  // for std::string
#include <vector>  // for std::vector
#include <numeric> // for std::accumulate


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
