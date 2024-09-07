#include <iostream>
using namespace std;

int main()
{
    int a = 7;
    cout << (a > 0 && a < 10) << endl;
    cout << (a < 0 && a < 10) << endl;
    cout << (a < 0 || a < 10) << endl;
    cout << !(a > 0 && a < 10) << endl;

    a++;
    cout << a <<"\n";

    int x = 1;
    int y = 2;
    int z = x ++ - ++y +1;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    return 0;




}