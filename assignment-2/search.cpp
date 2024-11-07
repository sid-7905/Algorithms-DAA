#include <bits/stdc++.h>
using namespace std;

int linear_search(vector<int> v,int target){
    for(int i=0;i<v.size();i++){
         if(v[i]==target){
             return i;
         }
    }
    return -1;
}

int binary_search(vector<int> v, int target,int left=0,int right=-1){
    if(right==-1){
        right=v.size()-1;
    }
    if(left>right){
         return -1;
    }
    int mid=left+(right-left)/2;
    if(v[mid]==target){
         return mid;
    }
    else if(v[mid]<target){
         return binary_search(v,target,mid+1,right);
    }
    else{
         return binary_search(v,target,left,mid-1);
    }
}

int main()
{
    vector<int> v={1,2,3,4,5,6,7};
    int index=binary_search(v,1);
    if(index!=-1){
        cout<<"Target is found at index "<<index<<endl;
    }
    else{
        cout<<"target not found "<<endl;
    }
    
    return 0;
}