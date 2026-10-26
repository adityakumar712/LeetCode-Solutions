class Solution {
    unordered_map<int , int>dp;
public:
    int fib(int n) {
        if(n==0){return 0;}

        if(n==1){return 1;}

        if(dp.find(n) != dp.end()){
            return dp[n];
        }

        int a = fib(n-1);
        int b = fib(n-2);

        int ans = a+b;
        dp[n] = ans;

        return ans;
    }
};