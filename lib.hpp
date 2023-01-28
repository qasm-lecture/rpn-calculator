#include <stack>
#include <string>
#include <vector>


using binary_int_function = int (*)(int, int);

using unary_int_function = int (*)(int);

int plus(       int a, int b);
int minus(      int a, int b);
int multiply(   int a, int b);
int divide(     int a, int b);
int ln(         int a);
int exponential(int a);
int square(     int a);
int squareroot( int a);

using stack_type = std::stack<int>;

int pop_stack(stack_type &stack);

void apply_binary_function(const binary_int_function &operation, stack_type &stack);
void apply_unary_function(const unary_int_function &operation, stack_type &stack);

std::vector<std::string> splitStringBySpace(const std::string& input);

bool isStringNumber(const std::string& input);

int evaluate(const std::string &s);
