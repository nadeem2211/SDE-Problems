#include <iostream>
#include <unordered_set>
using namespace std;
bool isSubset(int arr1[], int m, int arr2[], int n)
{
    unordered_set<int> hashSet;
    // insert the arr1 element into a set
    for (int i = 0; i < m; i++)
    {
        hashSet.insert(arr1[i]);
    }
    // read if arr2 elements present in set, if not then return false
    for (int i = 0; i < n; i++)
    {
        if (hashSet.find(arr2[i]) == hashSet.end())
            return false; // when nothing found then find returns end() place iterator
    }
    return true;
}
int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 2};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout << isSubset(arr1, m, arr2, n) << endl;
    return 0;
}