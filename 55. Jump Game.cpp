class Solution {
public:
    bool helper(vector<int>& nums,int index,int n,vector<int>& dp)
    {   bool ans=false;
        if(index==n-1)
        return true;
        if(dp[index]!=-1)
        return dp[index];
        for(int j=1;j<=nums[index]&& index+j<n ;j++)
        {
            ans=helper(nums,index+j,n,dp);
            if(ans==true)
            return true;
        }

        dp[index]= ans;
        return dp[index];
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,nums.size(),dp);
    }
};