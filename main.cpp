#include "lib.hpp"

#include <iostream>

int main() {
  std::string user_input;
  std::cin >> user_input;

  if (user_input.empty()) { std::cout << "Empty input\n"; return 1; }

  std::cout << "Hello world.\nUser input is \"" << user_input << "\"\n";

  int counter = 1;
  try {
    const float result{evaluate(user_input, counter)};
    std::cout << "Result is: " << result << '\n';
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n' << "At Position " + std::to_string(counter);
  }
}
