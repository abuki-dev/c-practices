#include <iostream>
using namespace std;

void ptrmax(int *ar, int size)
{
    int max = *ar;
    int min = *ar;
    for (int i = 0; i < size; i++)
    {
        if (max < *ar)
        {
            max = *ar;
        }
        if (min > *ar)
        {
            min = *ar;
        }
        ar++;
    }
    cout << "the max is " << max << endl;
    cout << "the minimum is" << min << endl;
}
void reverser(int *ar, int size)
{
    int start = 0;
    int end = size - 1;
    int temp;
    while (end > start)
    {
        temp = ar[end];
        ar[end] = ar[start];
        ar[start] = temp;
        end--;
        start++;
    }
    cout << "reversed array";
    for (int i = 0; i < size; i++)
    {
        cout << *ar << " ";
        ar++;
    }
}
int main()
{
    int size;
    cout << "tell the size of the array ";
    cin >> size;
    int *ab = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "element[" << i + 1 << "] ";
        cin >> ab[i];
    }
    ptrmax(ab, size);
    reverser(ab, size);
    ab = nullptr;
    return 0;
}