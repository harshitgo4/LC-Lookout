class Solution {
public:
    /*int helper(vector<int> &nums,bool taken,ind index,int n)
    {
        if(n==index)
        {
            return 0;
        }
        int take=0;
        int nottake=0;
        take=helper(nums,true,index+1,n);
        nottake=helper(nums,false,index+1,n);
    }*/
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
        return 0;
        int ans=0;
      /*  bool taken=false;
        int index=0;
        */
        int n=nums.size();
        int d=0;
        int temp=0;
       // return helper(nums,taken,index,n);
        int prev=-1;

        for(int i=0;i<n-2;i++)
        {
                prev=nums[i];
                d=nums[i+1]-prev;
                temp=d;
                prev=nums[i+1];
            for(int j=i+2;j<n;j++)
            {
               d=nums[j]-prev;
               if(d==temp)
                ans++;
                else
                break;
                prev=nums[j];
            }
        }
        return ans;
    }
};