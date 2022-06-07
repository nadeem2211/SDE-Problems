// { Driver Code Starts
#include <stdlib.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
 *  arr[]: input array
 *  n: size of array
 */
class Solution
{
public:
    // Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {
        // sort the array
        sort(arr, arr + n);
        // run the loop for possible triplets
        for (int i = 0; i < n; i++)
        {
            int lower = i + 1;
            int higher = n - 1;
            // run loop for combinations
            while (lower < higher)
            {
                if (arr[i] + arr[lower] + arr[higher] == 0)
                    return true;
                else if (arr[i] + arr[lower] + arr[higher] < 0)
                    lower++;
                else
                    higher--;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cout << "enter t=1" << endl;
    cin >> t;
    while (t--)
    {
        int n;
        cout << "enter length of array" << endl;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cout << "enter " << i + 1 << "th element" << endl;
            cin >> arr[i];
            cout << endl;
        }
        Solution obj;
        if (obj.findTriplets(arr, n))
            cout << "triplet found" << endl;
        else
            cout << "no triplet" << endl;
    }
    return 0;
} // } Driver Code Ends