#include <iostream>
using namespace std;
void sumer_av(int *ar, int size)
{
    ar = &ar[size - 1];
    int sum = 0;
    float x = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + *ar;
        ar--;
    }
    x = (float)sum / size;
    cout << "the sum of your array is " << sum;
    cout << "\nand the average is " << x;
}
void doubler(int *ar, int size)
{
    for (int i = 0; i < size; i++)
    {
        ar[i] *= 2;
    }

    for (int j = 0; j < size; j++)
    {
        cout << ar[j] << " ";
    }
}
int main()
{
    int size;
    cout << "pleas tell me how many arrays you wnat to store";
    cin >> size;
    int *srr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << " array " << i + 1;
        cin >> srr[i];
    }
    sumer_av(srr, size);
    cout << "\n also theis doubled value is ";
    doubler(srr, size);
    // srr=nullptr;
    return 0;
}