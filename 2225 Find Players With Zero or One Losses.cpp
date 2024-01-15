class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp;
        for(auto it:matches)
        {
            int val1=it[0];
            int val2=it[1];
            if(mp.find(val1)==mp.end())
            {
                mp[val1]=0;
            }
                mp[val2]++;
        }
        vector<int> ans1;
        vector<int> ans2;
        for(auto it:mp)
        {
            if(it.second==0)
            ans1.push_back(it.first);
            if(it.second==1)
            ans2.push_back(it.first);
        }
        vector<vector<int>> v;
        sort(ans1.begin(),ans1.end());
        sort(ans2.begin(),ans2.end());
        v.push_back(ans1);
        v.push_back(ans2);
        return v;
    }
};