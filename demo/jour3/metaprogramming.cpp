#include <iostream>

int factorial(unsigned int n) {
   if (n == 0)
     return 1;
   return n * factorial(n - 1);
}

template <unsigned int N>
struct Factorial {
   enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0> {
   enum { value = 1 };
};

int main() {
    int result = Factorial<4>::value;
    std::cout << result << std::endl;
}