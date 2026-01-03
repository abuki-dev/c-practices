#include <iostream>
using namespace std;
void max_finder(int *a, int &size)
{
    int max = *a;
    int sec = *a;
    for (int i = 0; i < size; i++)
    {
        if (max < *a)
        {
            sec = max;
            max = *a;
        }
        else if (*a > sec && *a != max)
        {

            sec = *a;
        }

        *a++;
    }
    cout << "the maximum value from the give array is " << max;
    cout << "\nthe second maximum value from the give array is " << sec;
}
int main()
{
    int size = 10;
    int array[size] = {20, 201, 1, 35, 43, 26, 65, 34, 54, 1000};
    max_finder(array, size);
    return 0;
}