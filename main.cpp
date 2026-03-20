#include <iostream>
#include <vector>
#include <string>
#include "ArrayStack.h"

using namespace std;

struct Token {
    string value;
};

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    return tokens;
}

bool isValidPostfix(const vector<Token>& tokens) {
    return false;
}

bool isValidInfix(const vector<Token>& tokens) {
    return false;
}

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    return output;
}

double evalPostfix(const vector<Token>& tokens) {
    return 0.0;
}

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    return 0;
}
