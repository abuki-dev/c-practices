#include <iostream>
using namespace std;

int main()
{
    int x = 100;
    cout << "the original valuye of x=" << x << endl;
    int *y = &x;
    int **z = &y;
    **z = 130; // x is updated to 130;
    cout << "the addres of 1st pointer " << y << endl;
    cout << "the adrees of the 2nd pointer" << *z << endl;
    cout << "the updated value of x " << x;
    return 0;
}