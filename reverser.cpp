#include <iostream>
using namespace std;
void rev(int *a, int &size)
{
    a = &a[size - 1];
    for (int i = 0; i < size; i++)
    {
        cout << *a << " ";
        a--;
    }
}
int main()
{
    int size = 10;
    int array[size] = {20, 201, 1, 35, 43, 26, 65, 34, 54, 1000};
    rev(array, size);
    return 0;
}