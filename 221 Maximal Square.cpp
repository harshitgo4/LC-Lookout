class Solution {
public:
    int helper(vector<vector<char>>& matrix,int m,int n,int i,int j,int &maxi,vector<vector<int>> &dp)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        int right=helper(matrix,m,n,i,j+1,maxi,dp);
        int down=helper(matrix,m,n,i+1,j+1,maxi,dp);
        int diag=helper(matrix,m,n,i+1,j,maxi,dp);
        if(matrix[i][j]=='1')
        {
            ans=1+min(right,min(down,diag));
            maxi=max(maxi,ans);
            dp[i][j]= ans;
            return ans;
        }
        else
        return 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxi=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans= helper(matrix,m,n,0,0,maxi,dp);
        return maxi*maxi;
    }
};