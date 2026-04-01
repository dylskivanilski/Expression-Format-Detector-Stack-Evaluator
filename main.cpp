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
    int depth = 0;

    for (const auto& t : tokens) {
        if (isdigit(t.value[0])) {
            depth++;
        }
        else if (isOperator(t.value)) {
            if (depth < 2) return false;
            depth--;
        }
        else {
            return false;
        }
    }

    return depth == 1;
}

bool isValidInfix(const vector<Token>& tokens) {
    return false;
}

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    return output;
}

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;

    for (const auto& t : tokens) {
        if (isdigit(t.value[0])) {
            stack.push(stod(t.value));
        }
        else {
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();

            if (t.value == "+") stack.push(a + b);
            else if (t.value == "-") stack.push(a - b);
            else if (t.value == "*") stack.push(a * b);
            else if (t.value == "/") stack.push(a / b);
        }
    }

    return stack.top();
}

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    return 0;
}
