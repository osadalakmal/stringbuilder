#include "gtest/gtest.h"
#include "hayai/src/hayai.hpp"
#include <iostream>// for std::cout, std::endl
#include <string>  // for std::string
#include <vector>  // for std::vector
#include <numeric> // for std::accumulate


int main(int argc, char* argv[])
{
    if (argc > 1 && strncmp(argv[1],"bench",strlen("bench")) == 0) {
        Hayai::Benchmarker::RunAllTests();
        return 0;
    } else {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}
