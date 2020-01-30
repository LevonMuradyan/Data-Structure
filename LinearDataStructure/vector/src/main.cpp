#include <iostream>
#include "vector.hpp"
#include "test.hpp"

int main() {
    int value = 595;
    int index = 4;
 
    std::cout << "After vector<int> f = {1,2,3,4,5,6,7,8,9,10} :" << std::endl;
    DS::vector<int> f = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    print(f);
    TEST(f, value, index);

    /*std::cout << "After vector<int> q((1, 2, 3), 3) :" << std::endl;
    DS::vector<int> q((1, 2, 3), 3);
    print(q);
    TEST(q, value, index);*/

    /*std::cout << "After vector<int> a :" << std::endl;
    DS::vector<int> a;
    print(a);
    TEST(a, value, index);*/

    /*std::cout << "After vector<int> b(0) :" << std::endl;
    DS::vector<int> b(0);
    print(b);
    TEST(b, value, index);*/

    /*std::cout << "After vector<int> c(10) :" << std::endl;
    DS::vector<int> c(10);
    print(c);
    TEST(c, value, index);*/

    /*std::cout << "After vector<int> d(10, 0) :" << std::endl;
    DS::vector<int> d(10, 0);
    print(d);
    TEST(d, value, index);*/

    /*std::cout << "After vector<int> e(5, 10) :" << std::endl;
    DS::vector<int> e(5, 10);
    print(e);
    TEST(e, value, index);*/

   
    /*std::cout << "After vector<int> g = {0} :" << std::endl;
    DS::vector<int> g = { 0 };
    print(g);
    TEST(g, value, index);*/

    /*std::cout << "After g = {5, 4, 6} :" << std::endl;
    g = { 5,4,6 };
    print(g);*/

    /*std::cout<< "After a = b" << std::endl;
    a = b;
    print(a);*/

    /*std::cout << "After vector<int> k(ptr,10) :" << std::endl;
    int *ptr = new int[5];
    DS::vector<int> k(ptr,10);
    print(k);
    TEST(k, value, index);*/
    
    return 0;
}


