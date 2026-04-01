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
    ArrayStack<string> stack;
    bool expectOperand = true;

    for (const auto& t : tokens) {
        if (isdigit(t.value[0])) {
            if (!expectOperand) return false;
            expectOperand = false;
        }
        else if (t.value == "(") {
            stack.push("(");
            expectOperand = true;
        }
        else if (t.value == ")") {
            if (stack.empty()) return false;
            stack.pop();
            expectOperand = false;
        }
        else if (isOperator(t.value)) {
            if (expectOperand) return false;
            expectOperand = true;
        }
        else {
            return false;
        }
    }

    return !expectOperand && stack.empty();
}

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    ArrayStack<string> ops;

    for (const auto& t : tokens) {
        if (isdigit(t.value[0])) {
            output.push_back(t);
        }
        else if (t.value == "(") {
            ops.push(t.value);
        }
        else if (t.value == ")") {
            while (!ops.empty() && ops.top() != "(") {
                output.push_back({ops.top()});
                ops.pop();
            }
            ops.pop();
        }
        else if (isOperator(t.value)) {
            while (!ops.empty() &&
                   precedence(ops.top()) >= precedence(t.value)) {
                output.push_back({ops.top()});
                ops.pop();
            }
            ops.push(t.value);
        }
    }

    while (!ops.empty()) {
        output.push_back({ops.top()});
        ops.pop();
    }

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

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);

        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";

        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}
