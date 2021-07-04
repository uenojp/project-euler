#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
typedef long long int64;

int main() {
    int64 ans = 0;
    for (int64 p1 = 0; p1 <= 200 / 1; p1++)
        for (int64 p2 = 0; p2 <= 200 / 2; p2++)
            for (int64 p5 = 0; p5 <= 200 / 5; p5++)
                for (int64 p10 = 0; p10 <= 200 / 10; p10++)
                    for (int64 p20 = 0; p20 <= 200 / 20; p20++)
                        for (int64 p50 = 0; p50 <= 200 / 50; p50++)
                            for (int64 p100 = 0; p100 <= 200 / 100; p100++)
                                if (1 * p1 + 2 * p2 + 5 * p5 + 10 * p10 + 20 * p20 + 50 * p50 + 100 * p100 == 200) ans++;

    ans++;  // 200poundコイン1枚の分++
    std::cout << ans << '\n';
    return 0;
}