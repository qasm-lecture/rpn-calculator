#include "lib.hpp"
#include <stdexcept>
#include <stack>
#include <iostream>
#include <sstream>
#include <iterator>

int plus(int a, int b) { return a + b; }

int minus(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

int divide(int a, int b) {
    if(b == 0)
        throw std::invalid_argument("division by zero is not allowed");
    return a / b;
}

int pop_stack(stack_type &stack) {
    if(stack.empty())
        throw std::invalid_argument("invalid input");
    const auto ret{stack.top()};
    stack.pop();
    return ret;
}

void change_stack_state(const binary_int_function &operation, stack_type &stack) {
    const auto op_b{pop_stack(stack)};
    const auto op_a{pop_stack(stack)};
    stack.push(operation(op_a, op_b));
}

std::vector<std::string> splitStringBySpace(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> result{std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{}};
    return result;
}


bool isStringNumber(const std::string& input) {
    std::istringstream iss(input);
    double d;
    iss >> d;
    // Check if the entire string has been consumed by the stream
    return iss.eof() && !iss.fail();
}

int evaluate(const std::string &s) {
    stack_type stack;
    for (const char c: s) {
        switch (c) {
            case '+':
                change_stack_state(plus, stack);
                break;
            case '-':
                change_stack_state(minus, stack);
                break;
            case '*':
                change_stack_state(multiply, stack);
                break;
            case '/':
                change_stack_state(divide, stack);
                break;
            case '0'...'9':
                stack.push(c - '0');
                break;
            default:
                throw std::invalid_argument("invalid input");
        }
    }
    if(stack.empty())
        throw std::invalid_argument("invalid input");


    return {stack.top()};
}
