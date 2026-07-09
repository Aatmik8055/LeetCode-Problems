class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int d=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)c++;
            if(c>d)d=c;
            if(nums[i]==0)c=0;
        }
        return d;
    }
};
