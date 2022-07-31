#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums, vector<int> &subArr)
    {
        int sum, max, start, end, s;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > max)
            {
                max = sum;
                start = s;
                end = i;
            }
            if (sum < 0)
            {
                sum = 0;
                s = i + 1;
            }
        }
        subArr.push_back(start);
        subArr.push_back(end);
        return max;
    }
};

int main()
{
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> subarray;
    Solution s;
    int lon = s.maxSubArray(arr, subarray);
    cout << "The maximum sum is " << lon << endl;
    cout << "The subarray is " << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++)
    {
        cout << arr[i] << " ";
    }
}