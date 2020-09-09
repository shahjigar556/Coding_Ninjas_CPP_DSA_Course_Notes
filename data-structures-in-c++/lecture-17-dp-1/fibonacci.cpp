#include <iostream>
using namespace std;

/*
Use DP whenever there are results that are repeating or if we need to find the most optimised[Maximum or Minimum] Solution to a problem.
*/

/*
Always first make a brute force solution then make a MEMOIZATION solution (This should be enough :)).
Then make a Tabulation (DP) solution (If you are feeling fancy ;)).
*/

// inefficient fibonaccci -> BRUTE-FORCE[Basic implementation] => O(2^n) <- Worst Solution
int fibo(int n) {
    if(n <= 1) {
        return n;
    }
    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;    
}


// fibonacci with MEMOIZATION [Top-down appoarch -> recursive] => O(n) <- Better Solution [Space complexity is worse than DP because ofrecursion]
/*
In this algorithms, there are n + 1 unique cases. [0 to n - 1]
To stop our algorithm from repeating the same cases we will store the values in an array and directly pick the required value.
This will save time of the unnecessary calculation.
We will store ith fibonacci number in the array.
ans[i] => ith fibonacci number
ans[n] => final output

From now on, before starting any calculation, first check if the answer already exists. 
If yes, then pick the answer from the array and return.
If no, then calculate, save for future use and return.

Memoization is a top-down approach.
In memorization, we save our current output, so that we can use them in the future and improve our complexity drastically

definition:- In computing, memoization or memoisation is an optimization technique used primarily to speed up computer programs
 by storing the results of expensive function calls and returning the cached result when the same inputs occur again.
*/
int fibo_helper(int n, int *ans) {
    if(n <= 1) {
        return n;
    }

    // check if output already exists
    if(ans[n] != -1) {
        return ans[n];
    }
    // calculate if output does not exist
    int a = fibo_helper(n - 1, ans);
    int b = fibo_helper(n - 2, ans);
    // store the output for future use
    ans[n] = a + b;
    // return the output
    return ans[n];
}

int fibo_2(int n) {
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        ans[i] = -1;
    }
    return fibo_helper(n, ans);
}

// fibonacci with DYNAMIC PROGRAMMING [Bottom-up approach -> Iterative] => O(n) <- Best solution
/*
First find the smallest problem's output and put it in the array and return the output
Basic concept of Memoization and DP is to store the somplest calculation's approach so, that we don't need to calculate it again.
In case of Memoization we move from the bigger problem to the smaller problem.
In case of DP we move from the smaller problem to the bigger problem.
*/

int fibo_3(int n) {
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2; i <= n; i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}