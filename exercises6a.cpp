#include <iostream>
using namespace std;

int main()
{
    int i1 = 2;
    int i2 = 5;
    int i3 = -3;
    float d1 = 2.0f;
    float d2 = 5.0f;
    float d3 = -0.5f;

    cout << i1 + (i2*i3) << endl;
    cout << i1 * (i2+i3) << endl;
    cout << i1 / (i2+i3) << endl;
    cout << d1 + (d2*d3) << endl;
    cout << d1 / d2-d3 << endl;
    cout << d1 / (d2-d3) << endl;
}