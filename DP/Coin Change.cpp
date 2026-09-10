class Solution {
public:
int solve(int ind,vector<int>& coins, int amount,vector<vector<int>>&dp)
{
    if(dp[ind][amount]!=-1)return dp[ind][amount];
    if(ind==0)
    {
        if(amount%coins[ind]==0)return amount/coins[ind];
        else return 1e9;
    }
    int take=1e9;
    if(coins[ind]<=amount)
     take=1+solve(ind,coins,amount-coins[ind],dp);
    int nottake=solve(ind-1,coins,amount,dp);
    return dp[ind][amount]=min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        if (amount ==0)return 0;
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,1e9));
        for(int i=0;i<=amount;i++)if(i%coins[0]==0)dp[0][i]=i/coins[0];
        for(int i=0;i<coins.size();i++)dp[i][0]=0;
        for(int i=1;i<coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                int take=1e9;
                if(coins[i]<=j)
                take=1+dp[i][j-coins[i]];
                int nottake=dp[i-1][j];
                dp[i][j]=min(take,nottake);
            }
        }
       return dp[coins.size()-1][amount]!=1e9?dp[coins.size()-1][amount]:-1;
       }
};