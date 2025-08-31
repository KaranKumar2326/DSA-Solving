class Solution {
public:

    int fibans(int n,vector<int> &dp){
        
        if(n<2) return n;
        if(dp[n]!=-1) return dp[n];
        dp[n] = fibans(n-1,dp)+fibans(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int > dp(n+1,-1);
        return fibans(n,dp);
    }
};