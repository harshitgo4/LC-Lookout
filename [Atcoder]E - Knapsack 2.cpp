#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>

using namespace std;
#define mod 1000000007
#define ll long long 

ll n, w, a[100009], b[100009];
ll dp[109][100009];  // Memoization array

// Recursive function to solve the 0/1 Knapsack problem
ll solve(int r, int idx) {
    // Base case: If all items are considered
    if(idx == n)
        return r == 0 ? 0 : INT_MAX;  // Return 0 if remaining weight is 0, else INT_MAX

    // If result for current state is already computed, return it
    if(dp[idx][r] != -1)
        return dp[idx][r];

    // Calculate minimum value by either excluding or including the current item
    ll ans = solve(r, idx + 1);  // Exclude the current item
    if(b[idx] <= r)
        ans = min(ans, a[idx] + solve(r - b[idx], idx + 1));  // Include the current item if weight allows
    
    // Memoize the result and return
    return dp[idx][r] = ans;
}

// Function to find the maximum weight that can be accommodated in the knapsack
int s(int v_max) {
    for(int i = v_max; i >= 0; i--) {
        // Check if the maximum value achievable with remaining weight is less than or equal to total weight limit
        if(solve(i, 0) <= w)
            return i;  // Return the maximum weight that can be accommodated
    }
    return 0;  // If no valid weight is found, return 0
}

int main() {
    // Input the number of items (n) and maximum weight (w)
    cin >> n >> w;
    
    // Initialize memoization array with -1 values
    memset(dp, -1, sizeof(dp));

    int v_max = 0;  // Initialize maximum possible total weight

    // Input values and weights of the items
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        v_max += b[i];  // Update maximum possible total weight
    }

    // Call the function to find and print the maximum weight that can be accommodated
    cout << s(v_max) << endl;

    return 0;
}
