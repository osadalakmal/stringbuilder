#include "StringBuilder.h"
#include "gtest/gtest.h"

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
