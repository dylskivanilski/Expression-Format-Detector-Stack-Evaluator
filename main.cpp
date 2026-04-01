#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "ArrayStack.h"

using namespace std;

struct Token {
    string value;
};

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    string current = "";

    for (char c : line) {
        if (isdigit(c)) {
            current += c;
        }
        else {
            if (!current.empty()) {
                tokens.push_back({current});
                current = "";
            }
            if (!isspace(c)) {
                tokens.push_back({string(1, c)});
            }
        }
    }

    if (!current.empty()) tokens.push_back({current});
    return tokens;
    }

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
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
