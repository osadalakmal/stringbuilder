#include "StringBuilder.h"
#include "gtest/gtest.h"
#include "hayai/src/hayai.hpp"
#include <fstream>
#include <sstream>

using namespace ::testing;

TEST(Strbld,Constructor) {
    StringBuilder<char> stringBuilder;
    ASSERT_EQ(stringBuilder.getString(), "");
    StringBuilder<char> stringBuilder_2("Test");
    ASSERT_EQ(stringBuilder_2.getString(), "Test");
}

TEST(Strbld,EXCEPTION_SAFE) {
    StringBuilder<char> strBld;
    ASSERT_NO_THROW(strBld.Append("Hello"));
    ASSERT_NO_THROW(strBld.getString());
}

TEST(Strbld,Concatanation) {
    StringBuilder<char> strBld;
    strBld.Append("Hello");
    strBld.Append(" World");
    strBld.Append(" How");
    strBld.Append(" Are You");
    strBld.Append(" Doing ?");
    std::string mystr = strBld.getString();
    ASSERT_STREQ(mystr.c_str(),"Hello World How Are You Doing ?");
}

TEST(Strbld,Appendline) {
    StringBuilder<char> strBld;
    strBld.Append("Hello");
    strBld.AppendLine(" World");
    strBld.Append(" How");
    strBld.Append(" Are You");
    strBld.AppendLine();
    strBld.Append(" Doing ?");
    std::string mystr = strBld.getString();
    ASSERT_STREQ(mystr.c_str(),"Hello World\n How Are You\n Doing ?");
}

void benchMarkStrBuilder() {
    StringBuilder<char> strBld;
    std::ifstream infile("test.txt");
    std::string line;
    while (std::getline(infile, line)) {
        strBld.Append(line);
    }
    std::cout << "Final string is:\n" << strBld.getString() << std::endl;
}

void benchMarkStringstream() {
    std::ostringstream os;
    std::ifstream infile("test.txt");
    std::string line;
    while (std::getline(infile, line)) {
        os << (line);
    }
    std::cout << "Final string is:\n" << os.str() << std::endl;
}

BENCHMARK(Strings,StrBuilder,10,100){
    benchMarkStrBuilder();
}

BENCHMARK(Strings,StrStream,10,100){
    benchMarkStringstream();
}
