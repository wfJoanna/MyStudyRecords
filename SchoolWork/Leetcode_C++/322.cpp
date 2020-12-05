/*322.零钱兑换*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /*1.暴力递归
    int coinChange(vector<int> &coins, int amount)
    {
        return dp(coins, amount);
    }
    int dp(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        int res = amount + 1;

        for (int coin : coins)
        {
            int subproblem = dp(coins, amount - coin);
            if (subproblem == -1)
                continue;
            res = min(res, 1 + subproblem);
        }

        if (res != amount + 1)
            return res;
        else
            return -1;
    }
    */
    /*2.带备忘录的递归
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> memo(amount + 1, amount + 1);
        return dp(memo, coins, amount, amount);
    }
    int dp(vector<int> &memo, vector<int> &coins, int amount, int n)
    {
        if (n == 0)
            return 0;
        if (n < 0)
            return -1;
        if (memo[n] != amount + 1)
            return memo[n];

        int res = amount + 1;

        for (int coin : coins)
        {
            int subproblem = dp(memo, coins, amount, n - coin);
            if (subproblem == -1)
                continue;
            res = min(res, 1 + subproblem);
        }

        if (res != amount + 1)
        {
            memo[n] = res;
        }
        else
        {
            memo[n] = -1;
        }

        return memo[n];
    }
    */
    /*3.dp数组的迭代解法*/
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount < 0)
            return -1;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++)
        {
            for (int coin : coins)
            {
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};

int main()
{
    Solution solution;
    int a[3] = {1, 2, 5};
    vector<int> coins(a, a + 3);
    cout << solution.coinChange(coins, 11);
    return 0;
}