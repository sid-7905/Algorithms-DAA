#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int MCM(int index1, int index2, vector<int> &dim, vector<vector<int>> &dp)
{
    if (index1 == index2)
        return 0;

    if (dp[index1][index2] != -1)
        return dp[index1][index2];

    int min_oper = INT_MAX;
    for (int i = index1; i < index2; i++)
    {
        int left_oper = MCM(index1, i, dim, dp);                                    
        int right_oper = MCM(i + 1, index2, dim, dp);
        int curr_oper =  dim[index1 - 1] * dim[i] * dim[index2];
        int total_oper =  left_oper + right_oper + curr_oper;
        min_oper = min(min_oper, total_oper);
    }

    return dp[index1][index2] = min_oper;
}

int main()
{

    int n = 8;

    vector<int> mat_dim(n);

    for (int i = 0; i < n; i++)
    {
        cin >> mat_dim[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << "Minimum number of operations needed for chain multiplication is: " << MCM(1, n-1, mat_dim, dp);

    return 0;
}
