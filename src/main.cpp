#include <iostream>
#include "vector.h"
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
    vector<int> a;
    vector<int> b(0);
    vector<int> c(10);
    vector<int> d(10, 0);
    vector<int> e(5, 10);
    vector<int> f = { 1,2,3 };
    vector<int> g = { 0 };
    g = { 5,4,6 };
    a = b;


    vector<int> aa = vector<int>();
    vector<int> bb = vector<int>(0);
    vector<int> cc = vector<int>(10);
    vector<int> dd = vector<int>(10, 0);
    vector<int> ee = vector<int>(5, 10);
    vector<int> ff = vector<int>{ 1,2,3 };
    vector<int> gg = vector<int>{ 0 };
    g = { 5,4,6 };



    cout << "q:" << endl;
    print(q);

    cout << "a:" << endl;
    print(a);

    cout << "b:" << endl;
    print(b);

    cout << "c:" << endl;
    print(c);

    cout << "d:" << endl;
    print(d);

    cout << "e:" << endl;
    print(e);

    cout << "f:" << endl;
    print(f);

    cout << "g:" << endl;
    print(g);




    cout << "aa:" << endl;
    print(aa);

    cout << "bb:" << endl;
    print(bb);

    cout << "cc:" << endl;
    print(cc);

    cout << "dd:" << endl;
    print(dd);

    cout << "ee:" << endl;
    print(ee);

    cout << "ff:" << endl;
    print(ff);

    cout << "gg:" << endl;
    print(gg);
    
    return 0;
}


