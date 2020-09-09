/*LCS: Longest Common Substring*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Brute Force
int lcs(string s, string t) {
    if(s.empty() || t.empty()) {
        return 0;
    }
    if(s[0] == t[0]) 
        return 1 + lcs(s.substr(1), t.substr(1));
    int a = lcs(s.substr(1), t);
    int b = lcs(s, t.substr(1));
    int c = lcs(s.substr(1), t.substr(1));
    return max(a, max(b, c));
}

// Memoization: Time and Space Complexity -> O(m * n)
int lcs_mem_helper(string s, string t, int **output) {
    if(s.empty() || t.empty()) {
        return 0;
    }
    int m = s.size();
    int n = t.size();
    int ans;
    if(output[m][n] != -1) {
        return output[m][n];
    }
    if(s[0] == t[0]) {
        ans = 1 + lcs_mem_helper(s.substr(1), t.substr(1), output);
    } else {
        int a = lcs_mem_helper(s.substr(1), t, output);
        int b = lcs_mem_helper(s, t.substr(1), output);
        int c = lcs_mem_helper(s.substr(1), t.substr(1), output);
        ans = max(a, max(b, c));
    }
    output[m][n] = ans;
    return output[m][n];
}
int lcs_mem(string s, string t) {
    int m = s.size();
    int n = t.size();
    int **output = new int*[m + 1]; // m + 1 Rows
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n + 1]; // n + 1 Columns
        for(int j = 0; j <= n; j++) {
            output[i][j] = -1;
        }
    }
    int ans = lcs_mem_helper(s, t, output);
    for(int i = 0; i <= m; i++) {
        delete[] output[i];
    }
    delete[] output;
    return ans;
}

// Tabulation
int lcs_DP(string s, string t) {
    int m = s.size();
    int n = t.size();
    int **output = new int*[m + 1]; // m + 1 Rows
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n + 1]; // n + 1 Columns
        for(int j = 0; j <= n; j++) {
            output[i][j] = -1;
        }
    }
    output[0][0] = 0;
    // Fill first row
    for(int j = 1; j <= n; j++) {
        output[0][j] = 0;
    }
    // FIll first column
    for(int i = 1; i <= m; i++) {
        output[i][0] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            // Check if first character matches
            if(s[i - 1] == t[j - 1]) {
                output[i][j] = 1 + output[i - 1][j - 1];
            }else {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];
                output[i][j] = max(a, max(b, c));
            }
        }
    }
    int ans = output[m][n];
    for(int i = 0; i <= m; i++) {
        delete[] output[i];
    }
    delete[] output;
    return ans;
}

int main(){
    string s, t;
    cin >> s >> t;
    cout<< lcs(s, t) << endl;
    cout << lcs_mem(s, t) << endl;
    cout << lcs_DP(s, t) << endl;
}