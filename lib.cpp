#include "lib.hpp"

#include <stack>
#include <iostream>
#include <sstream>
#include <iterator>
#include <cmath>

int plus(    int a, int b) { return a + b; }
int minus(   int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(  int a, int b) { return a / b; }
int ln(      int a) { return log(a); }
int exp(     int a) { return exp(a); }
int square(  int a) { return a * a; }
int sqrt(    int a) { return sqrt(a); }

int pop_stack(stack_type &stack) {
  const auto ret{stack.top()};
  stack.pop();
  return ret;
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

int evaluate(const std::string &s) {
  stack_type stack;

  for (const char c : s) {
    switch (c) {
    case '+': apply_binary_function(plus,     stack); break;
    case '-': apply_binary_function(minus,    stack); break;
    case '*': apply_binary_function(multiply, stack); break;
    case '/': apply_binary_function(divide,   stack); break;
    case 'l': apply_unary_function(ln, stack); break;
    case 'e': apply_unary_function(exp, stack); break;
    case 's': apply_unary_function(square, stack); break;
    case 'q': apply_unary_function(sqrt, stack); break;
    case '0'...'9': stack.push(c - '0'); break;
    }
  }

  return {stack.top()};
}
