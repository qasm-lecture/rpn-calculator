#include "lib.hpp"
#include <stdexcept>
#include <stack>
#include <iostream>
#include <sstream>
#include <iterator>
#include <cmath>

float plus(float a, float b) { return a + b; }

float minus(float a, float b) { return a - b; }

float multiply(float a, float b) { return a * b; }

float divide(float a, float b) {
    if(b == 0)
        throw std::invalid_argument("division by zero is not allowed");
    return a / b;
}
float ln(         float a) { return std::log(a); }
float exponential(float a) { return std::exp(a); }
float square(     float a) { return a * a; }
float squareroot( float a) { return std::sqrt(a); }

float pop_stack(stack_type &stack) {
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
void apply_binary_function(const binary_int_function &operation, stack_type &stack) {
    const auto op_b{pop_stack(stack)};
    const auto op_a{pop_stack(stack)};
    stack.push(operation(op_a, op_b));
}

void apply_unary_function(const unary_int_function &operation, stack_type &stack) {
    const auto op_a{pop_stack(stack)};
    stack.push(operation(op_a));
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

void processOperator(const char op, stack_type &stack) {
    switch (op) {
        case '+': change_stack_state(plus,     stack); break;
        case '-': change_stack_state(minus,    stack); break;
        case '*': change_stack_state(multiply, stack); break;
        case '/': change_stack_state(divide,   stack); break;
    }
}

float evaluate(const std::string &s) {
    stack_type stack;

    for (const char c : s) {
        switch (c) {
            case '+': apply_binary_function(plus,     stack); break;
            case '-': apply_binary_function(minus,    stack); break;
            case '*': apply_binary_function(multiply, stack); break;
            case '/': apply_binary_function(divide,   stack); break;
            case 'l': apply_unary_function(ln, stack); break;
            case 'e': apply_unary_function(exponential, stack); break;
            case 's': apply_unary_function(square, stack); break;
            case 'q': apply_unary_function(squareroot, stack); break;
            case '0'...'9': stack.push(c - '0'); break;
            default:
                throw std::invalid_argument("invalid input");
        }
    }
    if(stack.empty())
        throw std::invalid_argument("invalid input");

    return {stack.top()};
}
