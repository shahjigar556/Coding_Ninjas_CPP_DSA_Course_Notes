/*
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}.
Output will be 1, as 1 is the minimum count of numbers required.
*/

#include <bits/stdc++.h>
using namespace std;

int minCountHelper(int *ans,int n){
    if(n-int(pow(int(sqrt(n)),2))==0){
        ans[n]=1;
        return ans[n];
    }
    if(ans[n]!=INT_MAX){
        return ans[n];
    }
    for(int i=1;i<=int(sqrt(n));i++){
        int val=minCountHelper(ans,n-int(pow(i,2)))+1;
        ans[n]=min(val,ans[n]);
    }
    return ans[n];
}

int minCount(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
        ans[i]=INT_MAX;
    return minCountHelper(ans,n);    
}

int main(){
    int n;
	cin >> n;
	cout << minCount(n);
}