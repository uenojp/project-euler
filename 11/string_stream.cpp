#include <iostream>
#include <sstream>
#include <string>
#include <vector>
typedef long long int64;

// splitを実装するために使った
std::vector<std::string> split(const std::string& s, char sep) {
    std::vector<std::string> res;
    std::stringstream ss(s);
    std::string line;
    while (std::getline(ss, line, sep))
        res.push_back(line);
    return res;
}

int main() {
    std::stringstream ss;
    ss << "hello sstream!";  // ストリームに流して

    std::string s;
    ss >> s;  // もらってきたら空白区切りで帰ってくる

    std::cout << ss.eof() << '\n';  // 0

    std::cout << s << '\n';
    ss >> s;
    std::cout << s << '\n';
    ss >> s;
    std::cout << s << '\n';

    std::cout << ss.eof() << '\n';  // 1
    return 0;
}