class Solution {
public:
    int helper(vector<int> &nums,int index,int n,vector<int> &dp)
    {   if(index>=n)
        return 1e5;
        if(index==n-1)
        return 0;
        if(dp[index]!=-1)
        return dp[index];
        int ans=1e5;
        int jump=nums[index];
        for(int i=1;i<=jump;i++)
        {
            ans=min(ans,1+helper(nums,index+i,n,dp));
        }
        dp[index]= ans;
        return dp[index];
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
       // return helper(nums,0,n,dp);
       dp[n-1]=0;
       dp[0]=0;
       for(int i=0;i<n;i++)
       {
           int jump=nums[i];
           int ans=1e5;
           for(int j=1;j<=jump && i+j<n;j++)
           {
               dp[i+j]=min(dp[i+j],1+dp[i+j]);
           }
       }
       return dp[n-1];

       
    }
};