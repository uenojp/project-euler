#include <iostream>
typedef long long int64;

int main() {
    int64 ans = 0;
    for (int i = 1; i < 1000; i++)
        if (i % 3 == 0 || i % 5 == 0)
            ans += i;
    std::cout << ans << '\n';
    return 0;
}