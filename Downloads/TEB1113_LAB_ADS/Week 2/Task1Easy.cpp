// This is the print in zig-zag pattern problem. The task is to print the elements of a 2D matrix in a zig-zag pattern.

#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int>>& mat)
{
    int m = mat.size();  
    int n = mat[0].size(); 

    // Traverse through all rows
    for (int i = 0; i < m; i++) {
        
        // If current row is even, print from left to right
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
        }
        
        // If current row is odd, print from right to left
        else {
            for (int j = n - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
    }
}

int main()
{
    vector<vector<int>> mat = {
        {23, 63, 12},
        {34, 45, 85},
        {52, 96, 77}
    };

    print(mat);
    return 0;
}