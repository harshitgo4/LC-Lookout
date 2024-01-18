#include <iostream>
#include<vector>
#include<string>
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                int a = -1;
                int b = -1;
                if (text1[i - 1] == text2[j - 1]) {
                    a = 1 + dp[i - 1][j - 1];
                } else
                    b = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(a, b);
            }
        }

        i = n1;
        j = n2;
        string s = "";
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                s += text1[i - 1];
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }
        reverse(s.begin(), s.end());
         cout << s << endl;

        return dp[n1][n2];
    }


int main() {
    string text1;
    string text2;
    cin>>text1>>text2;
    int result = longestCommonSubsequence(text1, text2);

    return 0;
}
