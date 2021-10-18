#include <iostream>
using namespace std;
int sonarray(int left, int right, int array[], int* max)
{
    if (left == right)
        return array[left];
    int left2, right2;

    left2 = sonarray(left + 1, right, array, max);
    right2 = sonarray(left, right - 1, array, max);

    if (left2 > right2)
    {
        left2 = left2 + array[left];
        if (left2 > * max)
        {
            *max = left2;
            array[16] = left;
            array[17] = right;
        }
        return left2;
    }
    else
    {
        right2 = right2 + array[right];
        if (right2 > * max)
        {
            *max = right2;
            array[16] = left;
            array[17] = right;
        }
        return right2;
    }

}

int main()
{
    int array[18] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 ,0,0 };
    int* max, b = 13, temp;
    max = &b;
    for (int i = 0; i < 16; i++)
        printf("%d,", array[i]);
    sonarray(0, 15, array, max);
    printf("\nmax sonarray=%d from %d to %d", *max, array[16], array[17]);
}
