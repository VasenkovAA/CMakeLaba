// Copirite 2023 Vasenkov Andrey
#ifndef _STRING_PARSER_H_
#define _STRING_PARSER_H_
#include <iostream>
#include <string>
#include "../stack_on_list/stack.h"
using namespace std;


bool isNumber(std::string input) {
	int num_decimals = std::count(input.begin(), input.end(), '.');
	int num_underscores = std::count(input.begin(), input.end(), '_');
	if (num_decimals > 1 || num_underscores > 0) {
		// Input contains more than one decimal point or any underscores, so it is likely a variable
		if (!std::isalpha(input[0])) {
			// First character is not a letter, so it is an invalid variable name
			throw std::invalid_argument("Invalid variable name");
		}
		for (char c : input) {
			if (!std::isalnum(c) && c != '_') {
				return false;
			}
		}
		return true;
	}
	else {
		// Input contains at most one decimal point, so it is likely a number
		for (char c : input) {
			if (!std::isdigit(c) && c != '.') {
				return false;
			}
		}
		return true;
	}
}

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
				if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
					return &c - &str[0] + 1;
				}

			}


		}
	}
	if (stack.empty()) { return -1; }
	else { return str.size(); }
	
};

enum VariableType { Const, Variable, OperationResult };

class CVariable {
	VariableType type;
	double data;
	string name;
	
public:
	//static int getID() {}
	CVariable(double _data, std::string _name = "", VariableType _type = Const) {
		data = _data;
		name = _name;
		type = _type;

	}
	CVariable(string str) {
		if (isNumber(str) ) {
			data = std::stod(str);
			name = "";
			type = Const;
		}
		else {

			type = Variable;
			name = str;
			data = 0;
		}
	}
	CVariable() {
		data = 0;
		name = "result";
		type = OperationResult;
	}
	void setName(std::string _name) {
		name = _name;
	}
	bool operator==(const CVariable& value) {
		return(name == value.name);
	}

	friend ostream& operator<<(ostream& os, const CVariable& d) {
		return os << d.data << ';' << d.name
			<< ';' << d.type << endl;
	}
};


enum OperationType {Sum,Mult,Sin,Cos};
class COperation {
	CVariable* pOperator1;
	CVariable* pOperator2;
	CVariable* pRes;
	OperationType operation;
public:
	COperation(CVariable* op1, CVariable* op2, CVariable* res, OperationType type) {
		pOperator1 = op1;
		pOperator2 = op2;
		pRes = res;
		operation = type;
	}
	void Run() {
		*pRes = 1;
	}
	friend ostream& operator<<(ostream& os, const COperation& d) {
		return os << *d.pOperator1 << ';' << *d.pOperator2
			<< ';' << d.operation<< endl;
	}
};





//
//void stringParser(std::string str) {
//	stackOnList<int> stack;
//	stackOnList<CVariable> stack1;
//
//
//	for (int i = 0; i < str.length(); i++) {
//		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
//			stack.push(i);
//		}
//		if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
//			if (str[stack.top()] == reversParenthesis(str[i])) {
//				string substr = str.substr(stack.top() + 1, i - 1);
//				int index = substr.find(';');
//				/*stack1.push(substr.substr(stack.top() + 1, index - 1));
//				stack1.push(substr.substr(index+1,i-1));*/
//
//				stack1.push(CVariable(substr.substr(stack.top() + 1, index - 1),stack1));
//				stack1.push(CVariable(substr.substr(stack.top() + 1, index - 1), stack1));
//
//
//				stack.pop();
//			}
//			else throw std::logic_error("string has error in char namber "+i);
//		}
//	}
//
//
//}


class StringCalc {
public:
	std::string InputString;
	std::string PolishString;
	TList<CVariable> VariabalsList;
	stackOnList<COperation> OperationStack;

	void ParsePolishString() {
		stackOnList<int> charStack;
		std::string str = PolishString;
		for (int i = 0; i < str.length(); i++) {
			if (str.length() < 3) { break; }
			if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
				charStack.push(i);
			}
			if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
				if (str[charStack.top()] == reversParenthesis(str[i])) {
					string substr = str.substr(charStack.top() + 1, i - 1);
					if (str[i + 1] == '+') {
						int Index = substr.find(';');
						CVariable var1(substr.substr(0, Index));
						CVariable var2(substr.substr(Index+1, substr.length()));
						CVariable var3;
						CVariable* pVar1 = &VariabalsList.Tail();
						if (VariabalsList.getCount()>0&&VariabalsList.getIndex(var1) == -1) { VariabalsList.push_back(var1); }
						else {
							pVar1 = &VariabalsList.getData(VariabalsList.getIndex(var1));
						}
						var3.setName("result"+VariabalsList.getCount()+2);
						//VariabalsList.push_back(var1);

						VariabalsList.push_back(var2);
						CVariable* pVar2 = &VariabalsList.Tail();
						VariabalsList.push_back(var3);
						CVariable* pRes = &VariabalsList.Tail();
						COperation* operation = new COperation(pVar1, pVar2, pRes, Sum);
						str = str.substr(0, charStack.top())+"&result" + (to_string(VariabalsList.getCount()))+"&" + str.substr(i+2,str.length());
						cout << str << endl;
						i = -1;
					}
					//if (str[i + 1] == '*') {}




					/*size_t index = substr.find(';');
					if (index != std::string::npos) {

					}
					else {

					}*/



				}
				else throw std::logic_error("string has error in char namber " + i);
			}
		}
		cout << OperationStack.top() <<endl;
	}

	void Run() {}

};


#endif //_STRING_PARSER_H_