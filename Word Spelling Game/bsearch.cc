#include <vector>
#include <iostream>
using namespace std;

const int SIZE = 10;
const int VAL = 99;

/*  Binary Search requires that the data be sorted. It checks the middle
element in the collecton and narrows the search space based on the diff-
erence between the middle element and the target. We plan to discuss the
details of Binary Search in class.*/

bool
binary_search(const int data[], int size, const int target)
{
    int start = 0, mid, elem;
    do {
        mid = (start + size) / 2;
        elem = data[mid];
        if (elem < target)
            start = mid + 1;
        else if (elem > target)
            size = mid;
        else
            return true;
    } while (start < size);
    return false;
}

int
main()
{
    int data[SIZE] = {10, 23, 25, 50, 75, 87, 90, 95, 99, 100};
    cout << binary_search(data, SIZE, VAL) << endl;
    return 0;
}
