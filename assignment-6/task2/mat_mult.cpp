#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int MCM(int index1, int index2, vector<int> &dim){
    if(index1 == index2) return 0;
    if(index2 == index1 + 1){
        return dim[index1-1]*dim[index1]*dim[index2];
    }

    int min_oper = INT_MAX;
    for(int i = index1; i<index2; i++){
        int oper = MCM(index1, i, dim) + MCM(i+1, index2, dim) + dim[index1 - 1]*dim[i]*dim[index2];
        min_oper = min(oper,min_oper);
    }

    return min_oper;

}

int main()
{

    int n = 8;

    vector<int> mat_dim(n);

    for (int i = 0; i < n; i++)
    {
        cin >> mat_dim[i];
    }

    cout << "Minimum number of operations needed for chain multiplication is: " << MCM(1, n-1, mat_dim);
    
    return 0;
}