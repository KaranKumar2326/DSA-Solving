class Solution {
public:

    int fibans(int n,vector<int> &dp, int k){
        
        if(n<2) return n;
        if(dp[k]!=-1) return dp[k];
        dp[k] = fibans(n-1,dp,k+1)+fibans(n-2,dp,k+2);
        return dp[k];
    }
    int fib(int n) {
        vector<int > dp(n,-1);
        return fibans(n,dp,0);
    }
};