// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<vector>
int main() {
    // Write C++ code here
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
  vector<int> dp(n+1,0);
  for(int i=1;i<n;i++)
  {
      int first1=abs(v[i]-v[i-1])+dp[i-1];
      int first2=1e4;
      if(i-2>=0)
      {
          first2=abs(v[i]-v[i-2])+dp[i-2];
      }
      dp[i]=min(first1,first2);
      
  }
  cout<<dp[n-1]<<endl;

    return 0;
}