
/*
Given an integer h, find the possible number of balanced binary trees of height h.
You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.

Time complexity should be O(h).
1 <= h <= 10^7
*/

#include <bits/stdc++.h>
using namespace std;

const int mod=(int)(pow(10,9))+7;

// Brute force
int  balancedBTs(int h){
    if(h<=1){
        return 1;
    }
    int x=balancedBTs(h-1);
    int y=balancedBTs(h-2);
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)(((long)(y)*y)%mod);
    int ans=(temp1+temp2)%mod;
    return ans;
}

// DP: Memoization
int binaryTreesOfHeightHHelper(int *ans,int h) {
    if(h<=1){
        return 1;        
    }else if(h==2){
        return 3;
    }
    if(ans[h]!=0){
        return ans[h];
    }
    if(h>2)
        ans[h]=(
        		int((2*long(binaryTreesOfHeightHHelper(ans,h-1))*(binaryTreesOfHeightHHelper(ans,h-2)))%mod)
               	+int((long(binaryTreesOfHeightHHelper(ans,h-1))*(binaryTreesOfHeightHHelper(ans,h-1)))%mod)
    			)%mod;
    return ans[h];
}

int binaryTreesOfHeightH(int h){
    int *ans=new int[41];
    memset(ans,0,sizeof(ans));
    return binaryTreesOfHeightHHelper(ans,h);
}


int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
