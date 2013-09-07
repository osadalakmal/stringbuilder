#include "StringBuilder.h"
#include "gtest/gtest.h"

using namespace ::testing;

TEST(Strbld,Constructor) {
    StringBuilder stringBuilder;
    ASSERT_EQ(stringBuilder.getString(), "");
    StringBuilder stringBuilder_2("Test");
    ASSERT_EQ(stringBuilder_2.getString(), "Test");

}
