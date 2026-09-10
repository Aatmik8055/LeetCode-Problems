class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i:nums)sum+=i;
        if(sum%2!=0)return 0;
        int target=sum/2;
        vector<int>prev(target+1,0),curr(target+1,0);
        if(nums[0]<=target)prev[nums[0]]=1;
        prev[0]=1;
        for(int i=1;i<n;i++)
        {
            curr[0]=1;
            for(int j=1;j<=target;j++)
            {
                int take=0;
                if(j>=nums[i])
                take=prev[j-nums[i]];
                int nottake=prev[j];
                curr[j]=take||nottake;
            }
            prev=curr;
        }
        return prev[target];
    }
};