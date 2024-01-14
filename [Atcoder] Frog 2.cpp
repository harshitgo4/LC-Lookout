#include <algorithm>
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> height(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }
    vector<int> dp (n+1,1e9);
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=k&&j+i<n;j++)
        {
            dp[i+j]=min(dp[i]+abs(height[i]-height[i+j]),dp[i+j]);
        }
    }
    cout<< dp[n-1]<<endl;
   
    
    return 0;
}