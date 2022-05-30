#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;

/*
Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1


Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution
{
public:
    /*void setZeroesBrute(vector<vector<int> > &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col0;
        //
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // check if found zero on i,j
                if (matrix[i][j] == 0)
                {
                    // traverse the rows for given j
                    ind = i + 1; // traverse forward
                    while (ind < rows)
                    {
                        if (matrix[ind][j] != 0)
                            matrix[ind][j] = -1;
                        ind++;
                    }
                    ind = i - 1; // traverese backward
                    while (ind >= 0 && ind < rows)
                    {
                        if (matrix[ind][j] != 0)
                            matrix[ind][j] = -1;

                        ind--;
                    }
                    // traverse  through columns
                    ind = j + 1; // traverse forward
                    while (ind < cols)
                    {
                        if (matrix[i][ind] != 0)
                            matrix[i][ind] = -1;
                        ind++;
                    }
                    ind = j - 1; // traverese backward
                    while (ind >= 0 && ind < cols)
                    {
                        if (matrix[i][ind] != 0)
                            matrix[i][ind] = -1;
                        ind--;
                    }
                }
            }
        }
        // change all -1 to 0
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    } */
    // optimized approch
    void setZeroes(vector<vector<int> > &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col0 = -1;
        //
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // check if found zero on i,j
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // to track zeros in row
                    if (j == 0)
                        col0 = 0; // to track zeros oth column position
                    else
                        matrix[0][j] = 0; // track zero on colmn other than 0th position
                }
            }
        }
        // traverse backward to avoid 0th row and 0th column modification at last
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};
int main()
{
    vector<vector<int> > arr;
    arr = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    Solution s;
    s.setZeroes(arr);
    // display
    for (int k = 0; k < 3; k++)
    {
        cout << arr[k] << endl;
    }
    return 0;
}