#include <iostream>

using namespace std;

int main(){


    int x=10;

    int cpy_x = x;

    int &ref = x;
    x=30;
    

    cout << x << endl;
    cout << cpy_x << endl;
    cout << ref << endl;
    cout << &x << endl;
    cout << &ref << endl;

    int *p = &ref;

    cout << *p << endl;

    cout << "x = " << x << ", ref = " << ref << ", *p = " << *p << ", cpy_x = " << cpy_x << endl;

    *p = 50;

    cout << "x = " << x << ", ref = " << ref << ", *p = " << *p << ", cpy_x = " << cpy_x << endl;

return 0;
}