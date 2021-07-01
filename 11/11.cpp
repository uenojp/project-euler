#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
typedef long long int64;

std::vector<std::string> split(const std::string& s, char sep) {
    std::vector<std::string> res;
    std::stringstream ss(s);
    std::string line;
    while (std::getline(ss, line, sep))
        res.push_back(line);
    return res;
}

int main() {
    std::ifstream file("20x20");
    std::string line;

    std::vector<std::vector<int64>> grid;
    while (std::getline(file, line)) {
        auto l = split(line, ' ');
        std::vector<int64> v;
        for (auto& e : l)
            v.push_back(std::stoi(e));
        grid.push_back(v);
    }

    int64 ans = 0;
    const int64 N = 20;
    const int64 dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    const int64 dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    for (int64 x = 0; x < N; x++)
        for (int64 y = 0; y < N; y++) {
            for (int64 i = 0; i < 8; i++) {
                int64 x0 = x + 0 * dx[i], x1 = x + 1 * dx[i], x2 = x + 2 * dx[i], x3 = x + 3 * dx[i];
                int64 y0 = y + 0 * dy[i], y1 = y + 1 * dy[i], y2 = y + 2 * dy[i], y3 = y + 3 * dy[i];
                if (0 <= x0 && x0 < N && 0 <= x1 && x1 < N && 0 <= x2 && x2 < N && 0 <= x3 && x3 < N)
                    if (0 <= y0 && y0 < N && 0 <= y1 && y1 < N && 0 <= y2 && y2 < N && 0 <= y3 && y3 < N)
                        ans = std::max(ans, grid[x0][y0] * grid[x1][y1] * grid[x2][y2] * grid[x3][y3]);
            }
        }
    std::cout << ans << '\n';
    return 0;
}