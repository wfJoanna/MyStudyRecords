/*509.斐波那契数*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*1.暴力递归
    int fib(int N)
    {
        if (N == 1 || N == 2)
            return 1;
        if (N < 1)
            return 0;
        return fib(N - 1) + fib(N - 2);
    }
    */

    /*2.带备忘录的递归解法
    int fib(int N)
    {
        if (N < 1)
            return 0;
        vector<int> memo(N + 1, 0);
        return helper(memo, N);
    }
    int helper(vector<int> &memo, int N) //记得要用引用
    {
        if (N == 1 || N == 2)
            return 1;
        if (memo[N] != 0)
            return memo[N];
        memo[N] = helper(memo, N - 1) + helper(memo, N - 2);
        return memo[N];
    }
    */

    /*3.dp数组的迭代解法
    int fib(int N)
    {
        if (N < 1)
            return 0;
        if (N == 1 || N == 2) //之所以要在这儿判断，是因为怕后面访问越界
            return 1;
        vector<int> dp(N + 1, 0); //dp:dynamic programming动态规划
        dp[1] = dp[2] = 1;
        for (int i = 3; i < N + 1; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[N];
    }
    */

    /*4.最优化*/
    int fib(int N)
    {
        if (N < 1)
            return 0;
        if (N == 1 || N == 2)
            return 1;
        int prev = 1, curr = 1;
        for (int i = 3; i < N + 1; i++)
        {
            int sum = prev + curr;
            prev = curr;
            curr = sum;
        }
        return curr;
    }
};

int main()
{
    Solution solution;
    cout << solution.fib(1);
    return 0;
}