#include "foo.h"
#include <iostream>
template<typename T>
void foo(T value) {
std::cout << "Value: " << value;
}