class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        unordered_set<int> s;
        for(auto it:mp)
        {
            if(s.find(it.second)==s.end())
            {
                s.insert(it.second);
            }
            else
            {
                return false;
            }

        }
        return true;
    }
};