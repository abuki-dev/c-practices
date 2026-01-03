#include <iostream>
using namespace std;
void swaper(int *x, int *b)
{
    *x = *x + *b;
    *b = *x - *b;
    *x = *x - *b;
}
int main()
{
    int a = 70;
    int y = 129;
    cout << " a before swaap " << a << " and the addres is " << &a << endl;
    cout << " y before swaap " << y << " and the addres is " << &y << endl;
    swaper(&a, &y);
    // only the valus changed but the address reamins un changed
    cout << "the value of a after swaap " << a << " and the addres is " << &a << endl;
    cout << "the value of y after swaap " << y << " and the addres is " << &y << endl;
    return 0;
}