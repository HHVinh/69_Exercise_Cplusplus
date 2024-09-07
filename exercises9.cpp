#include <iostream>
using namespace std;

int main()
{
    float dtb;
    cout << "Hãy nhập điểm trung bình của bạn: ";
    cin >> dtb;

    if (dtb>5.0)
    {
        cout <<"Bạn đã thi đạt";
    }
    else
        cout <<"Bạn đã thi trượt";
    
    return 0;
}