#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long knapsack(int N, long long W, vector<long long>& weights, vector<long long>& values) {
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (long long w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][W];
}

int main() {
    int N;
    long long W;
    cin >> N >> W;

    vector<long long> weights(N);
    vector<long long> values(N);

    for (int i = 0; i < N; ++i) {
        cin >> weights[i] >> values[i];
    }

    long long result = knapsack(N, W, weights, values);
    cout << result << endl;

    return 0;
}
