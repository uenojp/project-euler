#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
typedef long long int64;

// v.push_back(リテラル)をどうやるか
int main() {
    std::vector<std::vector<int64>> v;
    v.push_back({1, 3, 56, 9999});  // 単にこれでおｋ
    for (auto& e : v) {
        for (auto elm : e) {
            std::cout << elm << '\n';
        }
    }
    return 0;
}