#include <iostream>
#include "vector.hpp"
#include <cassert>


void TEST_DEFAULT_CONSTRUCTOR() {
    DS::vector<int> v;
    assert(v.capacity() == 4  && v.size() == 0);

}

void TEST_SIZE_CONSTRUCTOR() {
    DS::vector<int> v(10);
    assert(v.capacity() == 10 && v.size() == 10);

}

void TEST_COPY_CONSTRUCTOR() {
    DS::vector<int> v(10);
    DS::vector<int> v_copy = v;
    assert(v_copy.capacity() == 10 && v_copy.size() == 10);

}

void TEST_SIZE_VALUE_CONSTRUCTOR() {
    DS::vector<int> v(8,7);
    assert(v.capacity() == 8 && v.size() == 8);
    for (auto t : v) {
        assert(t == 7);
    }

}

void TEST_SEQ_SIZE_CONSTRUCTOR() {
    int* p = new int[12];
    for (int i = 0; i < 12; i++) {
        p[i] = i;
    }
    DS::vector<int> v(p,12);
    assert(v.capacity() == 12 && v.size() == 12);
    for (int i = 0; i < 12; i++) {
        assert(v[i] == i);
    }
}

void TEST_INITIALIZATION_CONSTRUCTOR() {
    DS::vector<int> v = { 2,2,2,2,2,2 };
    assert(v.capacity() == 6 && v.size() == 6);
    for (int i = 0; i < 6; i++) {
        assert(v[i] == 2);
    }
}

void TEST_OPERATOR_EQUAL() {
    DS::vector<int> v = { 2,2,2,2,2,2 };
    DS::vector<int> v1 = { 3,4,5 };
    v1 = v;
    assert(v1.capacity() == 6 && v1.size() == 6);
    for (int i = 0; i < 6; i++) {
        assert(v1[i] == 2);
    }
}

void TEST_PUSH_BACK() {
    DS::vector<int> v = { 2,2,2,2,2,2 };
    v.push_back(139);
    assert(v.capacity() == 12 && v.size() == 7);
    assert(v[6] == 139);
}

void TEST_POP_BACK() {
    DS::vector<int> v = { 2,2,2,2,29,85 };
    v.pop_back();
    assert(v.capacity() == 6 && v.size() == 5);
}

void TEST_INSERT() {
    DS::vector<int> v = { 2,2,2,2,29,85 };
    v.insert(898, 2);
    assert(v.capacity() == 12);
    assert(v.size() == 7);
    assert(v[2] == 898);

}

void TEST_ERASE() {
    DS::vector<int> v = { 2,2,2,2,29,85 };
    v.erase(4);
    assert(v.capacity() == 6);
    assert(v.size() == 5);
    assert(v[4] == 85);

}

void TEST_STL_FIND() {
    DS::vector<int> v = { 9,5,7,10,12,8,48 };
    DS::vector<int>::iterator it = std::find(v.begin(), v.end(), 12);
    assert(it != nullptr);

}

void TEST_STL_SORT() {
    DS::vector<int> v = { 9,5,7,10,12,8,48 };
    std::sort(v.begin(), v.end());
    assert(std::is_sorted(v.begin(), v.end()));
}

template < typename T >
void print(const DS::vector<T>& vec) {


    std::cout << "      size = " << vec.size() << std::endl;
    std::cout << "      capacity = " << vec.capacity() << std::endl;
    std::cout << "      elements = " << vec;
    std::cout << std::endl << std::endl;
}

