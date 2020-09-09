/*
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Brute Force: Time Complexity -> O(3 ^ n)
int editDistance(string s, string t) {
    if(s.empty() || t.empty()) {
        return s.size() + t.size();
    }
    if(s[0] == t[0]) {
        return editDistance(s.substr(1), t.substr(1));
    }else {
        // Insert
        int x = editDistance(s.substr(1), t) + 1;
        // Delete
        int y = editDistance(s, t.substr(1)) + 1;
        // Replace
        int z = editDistance(s.substr(1), t.substr(1)) + 1;
        return min(x, min(y, z));
    }
}

// Memoization
int editDistance_mem_helper(string s, string t, int **output) {
    int m = s.size();
    int n = t.size();
    if(s.empty() || t.empty()) {
        output[m][n] = s.size() + t.size(); 
        return output[m][n];
    }
    if(output[m][n]!=-1) {
        return output[m][n];
    }

    if(s[0] == t[0]) {
        return editDistance_mem_helper(s.substr(1), t.substr(1), output);
    }else {
        // Insert
        int x = editDistance_mem_helper(s.substr(1), t, output) + 1;
        // Delete
        int y = editDistance_mem_helper(s, t.substr(1), output) + 1;
        // Replace
        int z = editDistance_mem_helper(s.substr(1), t.substr(1), output) + 1;
        output[m][n] = min(x, min(y, z));
        return output[m][n];
    }
}
int editDistance_mem(string s, string t) {
    int m = s.size();
    int n = t.size();
    int **output = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            output[i][j] = -1;
        }
    }
    int ans = editDistance_mem_helper(s, t, output);
    for(int i = 0; i <= m; i++) {
        delete[] output[i];
    }
    delete[] output;
    return ans;
}

// Tabulation
int editDistance_DP(string s, string t) {
    int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}

	// Fill 1st row
	for(int j = 0; j <= n; j++) {
		output[0][j] = j;
	}

	// Fill 1st col
	for(int i = 1; i <= m; i++) {
		output[i][0] = i;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[i - 1] == t[j - 1]) {
				output[i][j] = output[i-1][j-1];
			}
			else {
				int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = min(a, min(b, c)) + 1;
			}
		}
	}

	return output[m][n];
}

int main(){
    string s, t;
    cin >> s >> t;
    cout << editDistance(s, t) << endl;
    cout << editDistance_mem(s, t) << endl;
    cout << editDistance_DP(s, t) << endl;
}