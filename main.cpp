#include <iostream>
#include <optional>
#include <stack>
#include <stdexcept>

int plus(    int a, int b) { return a + b; }
int minus(   int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(  int a, int b) { return a / b; }

int pop_stack(auto &stack) {
  const auto ret{stack.top()};
  stack.pop();
  return ret;
}

void change_stack_state(auto &operation, auto &stack) {
  const auto op_b{pop_stack(stack)};
  const auto op_a{pop_stack(stack)};
  stack.push(operation(op_a, op_b));
}

int evaluate(const std::string &s) {
  std::stack<int> stack;

  for (const char c : s) {
    switch (c) {
    case '+': change_stack_state(plus,     stack); break;
    case '-': change_stack_state(minus,    stack); break;
    case '*': change_stack_state(multiply, stack); break;
    case '/': change_stack_state(divide,   stack); break;
    case '0'...'9': stack.push(c - '0'); break;
    }
  }

  return {stack.top()};
}
int main() {
  std::string user_input;
  std::cin >> user_input;

  if (user_input.empty()) { std::cout << "Empty input\n"; return 1; }

  std::cout << "User input is \"" << user_input << "\"\n";

  const int result{evaluate(user_input)};
  std::cout << "Result is: " << result << '\n';
}
