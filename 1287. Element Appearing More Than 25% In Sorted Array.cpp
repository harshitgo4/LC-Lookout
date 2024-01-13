class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int n=nums.size();
        int target=n/4;
        int prev=nums[0];
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(prev==nums[i])
            {
            count++;
            if(count>target)
            return nums[i];
            }
            else
            {
                count=1;
                prev=nums[i];
            }
        }
        return 0;
    }
};