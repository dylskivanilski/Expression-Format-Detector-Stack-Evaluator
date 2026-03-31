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

    if (!current.empty()) {
        tokens.push_back({current});
    }

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
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (data.empty()) {
            throw std::runtime_error("Stack underflow");
        }
        data.pop_back();
    }

    T top() const {
        if (data.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    int size() const {
        return data.size();
    }
};

#endif
