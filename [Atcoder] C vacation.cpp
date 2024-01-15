#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

int main() {
    // Write C++ code here
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
    vector<vector<int>> dp(n+1,vector<int>(4,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=2;j>=-1;j--)
        {
            if(j==-1)
            {
                dp[i][j+1]=max(dp[i][j+2],max(dp[i][j+3],dp[i][j+4]));
            }
            else if(j==0)
            {
                dp[i][j+1]=v[i][j]+max(dp[i+1][2],dp[i+1][3]);
            }
            else if(j==1)
            {
                 dp[i][j+1]=v[i][j]+max(dp[i+1][1],dp[i+1][3]);
            }
            else{
                 dp[i][j+1]=v[i][j]+max(dp[i+1][1],dp[i+1][2]);
            }
        }
    }
    cout<< dp[0][0]<<endl;
    return 0;
}