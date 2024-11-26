#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int MCM_Recursive(int index1, int index2, vector<int> &dim, vector<vector<int>> &dp)
{
    if (index1 == index2)
        return 0;

    if (dp[index1][index2] != -1)
        return dp[index1][index2];

    int min_oper = INT_MAX;
    for (int i = index1; i < index2; i++)
    {
        int left_oper = MCM_Recursive(index1, i, dim, dp);
        int right_oper = MCM_Recursive(i + 1, index2, dim, dp);
        int curr_oper = dim[index1 - 1] * dim[i] * dim[index2];
        int total_oper = left_oper + right_oper + curr_oper;
        min_oper = min(min_oper, total_oper);
    }

    return dp[index1][index2] = min_oper;
}

void printOrder(int i, int j, vector<vector<int>> &bracket, char &name)
{
    if (j-i==1)
    {
        cout << name++;
        return;
    }

    cout << "(";

    printOrder(i, bracket[i][j], bracket, name);
    printOrder(bracket[i][j], j, bracket, name);

    cout << ")";
}

void MCM_iterative_with_order(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++)
    {
        for (int i = 0; i < n - len; i++)
        {
            int j = i + len;
            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++)
            {
                int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    cout << "Optimal Parenthesization is: ";
    printOrder(0, n-1, bracket, name);
    cout << "\nMinimum number of operations needed for chain multiplication is: " << dp[0][n - 1] << endl;
}

int main()
{

    int n = 8;

    vector<int> mat_dim(n);

    for (int i = 0; i < n; i++)
    {
        cin >> mat_dim[i];
    }

    // vector<vector<int>> dp(n, vector<int>(n, -1)); // for recursive solution
    // cout << "Minimum number of operations needed for chain multiplication is: " << MCM_Recursive(1, n - 1, mat_dim, dp);
     MCM_iterative_with_order(mat_dim);
    // cout << "Minimum number of operations needed for chain multiplication is: " <<;

    return 0;
}
