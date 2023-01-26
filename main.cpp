#include "lib.hpp"

#include <iostream>

int main() {
  std::string user_input;
  std::cin >> user_input;

  if (user_input.empty()) { std::cout << "Empty input\n"; return 1; }

  std::cout << "User input is \"" << user_input << "\"\n";

  const int result{evaluate(user_input)};
  std::cout << "Result is: " << result << '\n';
}
