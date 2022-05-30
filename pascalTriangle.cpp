#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > arr(numRows);
        for (int i = 0; i < numRows; i++)
        {
            // inner array size
            arr[i].resize(i + 1);
            // on edge's index
            // arr[i][0] = arr[i][i] = 1;
            //

            // for (int j = 1;j < i; j++){
            for (int j = 0; j <= i; j++)
            {
                // on edge's index
                if (j == 0)
                    arr[i][0] = 1;
                else if (j == i)
                    arr[i][i] = 1;
                // on inner indexes
                else
                    arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
                // arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
        // return
        return arr;
    }
};

int main()
{
    int num;
    vector<vector<int> > vec(num);
    cout << "enter rows: " << endl;
    cin >> num;
    Solution s;
    vec = s.generate(num);
    // display
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}