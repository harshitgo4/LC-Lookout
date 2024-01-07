class Solution {
public:
    long numberOfArithmeticSlices(vector<int>& nums) {
        long n = nums.size();
        vector<unordered_map<long, long>> mp(n);
        long res = 0;

        for (long i = 0; i < n; i++) {
            for (long j = 0; j < i; j++) {
                long diff = static_cast<long>(nums[i]) - static_cast<long>(nums[j]);
                auto it = mp[j].find(diff);
                long put = 0;
                if (it != mp[j].end())
                    put = it->second;
                mp[i][diff] += put + 1;
                res += put;
            }
        }

        return res;
    }
};
