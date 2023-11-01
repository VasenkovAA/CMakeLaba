#include"../string_parser/string_parser.h"
#include "../gtest/gtest.h"
//
TEST(StringParserFunction, CorrectTest) {
	string str = "()((()))";
	int i = -1;
	
	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, ErrorIsFirst) {
	string str = ")((()))";
	int i = 1;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, InvalidParenthesesCount) {
	string str = "(((()))";
	int i = 7;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, OpeningParenthesisEnd) {
	string str = "()(";
	int i = 3;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, DifferentParenthesesMiddle) {
	string str = "()(((}))";
	int i = 6;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, CorrectTestVithAllParenthesis) {
	string str = "()({})[]([{()}])";
	int i = -1;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, DifferentParentheses) {
	string str = "()(((}))()}";
	int i = 6;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, DifferentParenthesesMiddleVithVariables) {
	string str = "(x*y)(((}))()}";
	int i = 6+3;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, DifferentParenthesesVithVariables) {
	string str = "(xy)(((}))()}";
	int i = 6+2;

	EXPECT_EQ(i, checkCorrectString(str));
}
TEST(StringParserFunction, test10) {
	string str = "()(((}))(1*5)}";
	int i = 6;

	EXPECT_EQ(i, checkCorrectString(str));
}