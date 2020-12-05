/*509.쳲�������*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*1.�����ݹ�
    int fib(int N)
    {
        if (N == 1 || N == 2)
            return 1;
        if (N < 1)
            return 0;
        return fib(N - 1) + fib(N - 2);
    }
    */

    /*2.������¼�ĵݹ�ⷨ
    int fib(int N)
    {
        if (N < 1)
            return 0;
        vector<int> memo(N + 1, 0);
        return helper(memo, N);
    }
    int helper(vector<int> &memo, int N) //�ǵ�Ҫ������
    {
        if (N == 1 || N == 2)
            return 1;
        if (memo[N] != 0)
            return memo[N];
        memo[N] = helper(memo, N - 1) + helper(memo, N - 2);
        return memo[N];
    }
    */

    /*3.dp����ĵ����ⷨ
    int fib(int N)
    {
        if (N < 1)
            return 0;
        if (N == 1 || N == 2) //֮����Ҫ������жϣ�����Ϊ�º������Խ��
            return 1;
        vector<int> dp(N + 1, 0); //dp:dynamic programming��̬�滮
        dp[1] = dp[2] = 1;
        for (int i = 3; i < N + 1; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[N];
    }
    */

    /*4.���Ż�*/
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