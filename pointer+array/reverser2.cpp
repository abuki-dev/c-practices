#include <iostream>
using namespace std;
void reverser(int *a, int &size)
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
    int size;
    cout << "how many do you wnt to store ";
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "enter your " << i + 1 << "array ";
        cin >> arr[i];
    }
    reverser(arr, size);
    arr = nullptr;
}