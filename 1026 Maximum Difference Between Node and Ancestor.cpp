class Solution {
public:
    bool helper(string s,unordered_map<string ,int> mp,int n,unordered_map<string ,bool> &dp)
    {   if(s.size()==0)
        return true;
        if(mp.find(s)!=mp.end())
        return true;
         if(dp.find(s)!=dp.end())
        return dp[s];

        bool ans=false;
        for(int i=1;i<=n;i++)
        {
            string temp=s.substr(0,i);
           // cout<<temp<<endl;
            if(mp.find(temp)!=mp.end())
            {  // cout<<temp<<endl;
                string h=s.substr(i,n-i);
              //  cout<<h<<endl;
                ans=helper(h,mp,h.size(),dp);
                if(ans==true)
                return true;
            }
        }
        dp[s]=ans;
        return dp[s];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans=false;
        unordered_map<string ,int> mp;
        for(auto it:wordDict)
        {
            mp[it]++;
        }
        int n=s.size();
         unordered_map<string ,bool> dp;
        ans=helper(s,mp,n,dp);
        return ans;
    }
};