#include <stack>
#include <string>
#include <vector>


using binary_int_function = float (*)(float, float);

using unary_int_function = float (*)(float);

float plus(       float a, float b);
float minus(      float a, float b);
float multiply(   float a, float b);
float divide(     float a, float b);
float ln(         float a);
float exponential(float a);
float square(     float a);
float squareroot( float a);

using stack_type = std::stack<float>;

float pop_stack(stack_type &stack);

void apply_binary_function(const binary_int_function &operation, stack_type &stack);
void apply_unary_function(const unary_int_function &operation, stack_type &stack);

std::vector<std::string> splitStringBySpace(const std::string& input);

bool isStringNumber(const std::string& input);

void processOperator(const char op, stack_type &stack);

float evaluate(const std::string &s, int &counter);
