class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>cur(n),prev(n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)cur[j]=1;
                else {
                    cur[j]=prev[j]+cur[j-1];
                }
            }
            prev=cur;
        }
        return cur[n-1];
    }
};