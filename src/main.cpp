#include <iostream>
#include "vector.hpp"
using namespace DS;
using namespace std;

void print(const vector<int>& vec) {


    cout << "size = " << vec.size() << endl;
    cout << "capacity = " << vec.capacity() << endl;
    cout << "elements = " << " ";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";

    }
    cout << endl << endl;
}


int main() {

    vector<int> q((1, 2, 3), 3);
    cout << "q:" << endl;
    print(q);

    vector<int> a;
    cout << "a:" << endl;
    print(a);

    vector<int> b(0);
    cout << "b:" << endl;
    print(b);

    vector<int> c(10);
    cout << "c:" << endl;
    print(c);

    vector<int> d(10, 0);
    cout << "d:" << endl;
    print(d);

    vector<int> e(5, 10);
    cout << "e:" << endl;
    print(e);

    vector<int> f = { 1,2,3 };
    cout << "f:" << endl;
    print(f);

    vector<int> g = { 0 };
    cout << "g:" << endl;
    print(g);

    g = { 5,4,6 };
    cout << "g:" << endl;
    print(g);

    a = b;
    std::cout<< "a = b" << std::endl;
   
    return 0;
}


