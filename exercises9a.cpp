#include <iostream>
using namespace std;

int main()
{
    float dtb;
    cout <<"Hãy nhập điểm trung bình của bạn: ";
    cin >> dtb;
    if (dtb <=10 && dtb >=8)
    {
        cout <<"Bạn là học sinh giỏi";
    }
    else if (dtb >= 6.5)
    {
        cout <<"Bạn là học sinh khá";
    }
    else if (dtb >= 5)
    {
        cout <<"Bạn là học sinh trung bình";
    }
    else
        cout <<"Bạn là học sinh yếu";
    return 0;
}