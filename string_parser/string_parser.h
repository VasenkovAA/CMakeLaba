
// Copirite 2023 Vasenkov Andrey
#ifndef _STRING_PARSER_H_
#define _STRING_PARSER_H_
#include <iostream>
#include "../stack/stack.h"

int checkCorrectString(std::string str) {
	stackOnList<char>stack;
	for (char& c : str) {
		if (c == '(' || c == '[' || c == '{') {
			stack.push(c);
		}
		else {
			if (c == ')' || c == ']' || c == '}') {
				if (stack.empty()) { return &c - &str[0]; }
			}
			char top = stack.top();
			stack.pop();
			if ((c == ')' && top != '(') || (c == ']' && top != '[') || 0(c == '}' && top != '{')) {
			    return &c - &str[0];
			}

		}
	
	
	
	}
	if (stack.empty()) { return -1; }
	else { return str.size(); }


};
#endif //_STRING_PARSER_H_