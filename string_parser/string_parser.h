
// Copirite 2023 Vasenkov Andrey
#ifndef _STRING_PARSER_H_
#define _STRING_PARSER_H_
#include <iostream>
#include "../stack/stack.h"

char reversParenthesis(char char_) {
	if (char_ == '(') { return')'; }
	if (char_ == '[') { return']'; }
	if (char_ == '{') { return'}'; }
	if (char_ == ')') { return'('; }
	if (char_ == ']') { return'['; }
	if (char_ == '}') { return'{'; }
	return char_;
}

int checkCorrectString(std::string str) {
	stackOnList<char>stack;
	for (char& c : str) {
		if ((c == '(') || (c == '[') || (c == '{') || (c == ')') || (c == ']') || (c == '}')) {
			if (c == '(' || c == '[' || c == '{') {
				stack.push(c);
			}
			else {
				if (c == ')' || c == ']' || c == '}') {
					if (stack.empty() || reversParenthesis(stack.top()) != c) { return &c - &str[0] + 1; }
				}
				char top = stack.top();
				stack.pop();
				if ((c == ')' && top != '(') || (c == ']' && top != '[') || 0(c == '}' && top != '{')) {
					return &c - &str[0] + 1;
				}

			}

		}
	}
	if (stack.empty()) { return -1; }
	else { return str.size(); }
	
};
#endif //_STRING_PARSER_H_