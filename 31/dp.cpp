#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
typedef long long int64;

int main() {
    const std::vector<int64> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    const int64 n = coins.size(), m = 200;
    int64 dp[m + 1][n];
    // dp[i][j] := j番目までのコインを使ってよいとき、ちょうどi円を作る通りの数
    // dp[i][j] = dp[i][j - 1] + dp[i - coins[j]][j - 1]
    // j番目のコインを   使わない           使う
    // 使えない場合は dp[i][j] = dp[i][j - 1]

    // 1pence硬貨だけ使っていいときは何円でも1通り
    for (int64 i = 0; i <= m; i++) dp[i][0] = 1;
    // 0円を作るにはどれだけ硬貨の択があっても全く選ばないの1通り
    for (int64 j = 0; j < n; j++) dp[0][j] = 1;
    for (int64 i = 0; i <= m; i++) {
        for (int64 j = 1; j < n; j++) {
            if (i - coins[j] >= 0)
                dp[i][j] = dp[i][j - 1] + dp[i - coins[j]][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    std::cout << dp[m][n - 1] << '\n';
    return 0;
}