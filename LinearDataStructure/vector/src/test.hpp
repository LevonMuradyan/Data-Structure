#include <iostream>
#include "vector.hpp"

template < typename T >
void print(const DS::vector<T>& vec) {


    std::cout << "      size = " << vec.size() << std::endl;
    std::cout << "      capacity = " << vec.capacity() << std::endl;
    std::cout << "      elements = " << vec;
    std::cout << std::endl << std::endl;
}

template < typename T >
void TEST(DS::vector<T>& vector, T value, int index) {
    std::cout << "Before push_back(" << value << ") :" << std::endl;
    print(vector);
    std::cout << "After push_back(" << value << ") :" << std::endl;
    vector.push_back(value);
    print(vector);
    
    std::cout << "After find(" << value << ") :" << std::endl;
    if (vector.find(value)) {
        std::cout << "The value " << value << " was found" << "\n\n";
    }
    else {
        std::cout << "The value " << value << " was not found" << "\n\n";
    }
    
    std::cout << "Before pop_back() :" << std::endl;
    print(vector);
    std::cout << "After pop_back() :" << std::endl;
    vector.pop_back();
    print(vector);
 
    std::cout << "After find(" << value << ") :" << std::endl;
    if (vector.find(value)) {
        std::cout << "The value " << value << " was found" << "\n\n";
    }
    else {
        std::cout << "The value " << value << " was not found" << "\n\n";
    }

    std::cout << "Before front() :" << std::endl;
    print(vector);
    std::cout << "After front() :" << std::endl;
    std::cout << "      First element is = " << vector.front() << "\n\n";

    std::cout << "Before back() :" << std::endl;
    print(vector);
    std::cout << "After back() :" << std::endl;
    std::cout << "      Last element is = " << vector.back() << "\n\n";

    std::cout << "Before insert(" << value << ", " << index << ") :" << std::endl;
    print(vector);
    std::cout << "After insert(" << value << ", " << index << ") :" << std::endl;
    vector.insert(value, index);
    print(vector);

    std::cout << "Before erase(" << index << ") :" << std::endl;
    print(vector);
    std::cout << "After erase(" << index << ") :" << std::endl;
    vector.erase(index);
    print(vector);

    std::cout << "Before clear() :" << std::endl;
    print(vector);
    std::cout << "After clear() :" << std::endl;
    vector.clear();
    print(vector);

}
