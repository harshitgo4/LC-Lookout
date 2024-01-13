class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length(), ans = 0;
        vector<int> arr(26, 0);
        
        for (int i = 0; i < n; i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                ans += arr[i];
            }
        }
        
        return ans;
    }
};