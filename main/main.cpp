// Copyright 2022 Marina Usova

#include <iostream>
#include "../string_parser/string_parser.h"

int main() {
	StringCalc c;
	c.PolishString = "((x;2)+;5)+";
	c.ParsePolishString();
	return 0;
}
