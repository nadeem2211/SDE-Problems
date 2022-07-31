#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), k, l;
        // finding first index where arr[k] < arr[k+1]
        for (k = n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
            {
                break;
            }
        }
        // reversing to get first permutation, if it is largest permutation
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            // finding smallest greater element from arr[k] in remaining array
            for (l = n - 1; l > k; l--)
            {
                if (nums[l] > nums[k])
                {

                    break;
                }
            }
            // swap kth and lth element
            swap(nums[k], nums[l]);
            // reverse array begining from k=1 to end for the next smallest permutation
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
int main()
{
    vector<int> arr;
    int n, a;
    cout << "enter vector size :" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << "enter value at index:" << i << endl;
        cin >> a;
        arr.push_back(a);
    };
    Solution s;
    s.nextPermutation(arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}