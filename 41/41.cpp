#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
typedef long long int64;

bool is_prime(int64 n) {
    if (n <= 1) return false;
    for (int64 i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

std::vector<int64> panditigal(int64 n) {
    std::vector<int64> res, one_to_n;
    for (int64 i = 1; i <= n; i++) one_to_n.push_back(i);
    do {
        std::string s;
        for (auto& d : one_to_n) s += std::to_string(d);
        res.push_back(std::stoi(s));
    } while (std::next_permutation(one_to_n.begin(), one_to_n.end()));
    return res;
}

int main() {
    int64 ans = 0;
    for (int64 n = 1; n <= 9; n++) {
        auto v = panditigal(n);
        decltype(v) primes;
        std::copy_if(v.begin(), v.end(), std::back_inserter(primes), [](int64 i) { return is_prime(i); });
        std::sort(primes.rbegin(), primes.rend());
        if (primes.size() > 0 && primes[0] > ans) ans = primes[0];
    }
    std::cout << ans << '\n';
    return 0;
}