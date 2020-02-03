#include <iostream>
#include <algorithm>
#include "vector.hpp"
#include "test.hpp"

int main() {

    TEST_DEFAULT_CONSTRUCTOR();
    TEST_SIZE_CONSTRUCTOR();
    TEST_SIZE_VALUE_CONSTRUCTOR();
    TEST_SEQ_SIZE_CONSTRUCTOR();
    TEST_COPY_CONSTRUCTOR();
    TEST_INITIALIZATION_CONSTRUCTOR();
    TEST_OPERATOR_EQUAL();
    TEST_PUSH_BACK();
    TEST_POP_BACK();
    TEST_INSERT();
    TEST_ERASE();
    TEST_STL_FIND();
    TEST_STL_SORT();

    return 0;
}

