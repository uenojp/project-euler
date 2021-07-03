#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
typedef long long int64;

std::vector<int64> divisor(int64 n) {
    std::vector<int64> v;
    for (int64 i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (n / i != i) v.push_back(n / i);
        }
    }
    return v;
}

int64 proper_divisors(int64 n) {
    auto v = divisor(n);
    auto sum_divisors = std::accumulate(v.begin(), v.end(), 0LL);
    return sum_divisors - n;
}

int main() {
    int64 ans = 0;
    for (int64 a = 1; a <= 10000; a++) {
        int64 b = proper_divisors(a);
        if (proper_divisors(b) == a && a != b) ans += a;
    }
    std::cout << ans << '\n';
    return 0;
}