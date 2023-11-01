#include"../string_parser/string_parser.h"
#include "../gtest/gtest.h"

TEST(StringParserFunction, test1) {
	string str = "()((()))";
	int i = -1;
	
	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, test2) {
	string str = ")((()))";
	int i = 0;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, test3) {
	string str = "(((()))";
	int i = 7;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, test4) {
	string str = "()(";
	int i = 3;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, test5) {
	string str = "()(((}))";
	int i = 6;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, test6) {
	string str = "()({})[]([{()}])";
	int i = -1;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, test7) {
	string str = "()(((}))()}";
	int i = 6;

	EXPECT_EQ(i, checkCorrectString(str));
}