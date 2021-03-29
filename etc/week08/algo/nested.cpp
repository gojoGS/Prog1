#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

int depth(std::string expr) {
    std::vector<int> a;

    auto mapping = [](char c) {
        if (c == '(')
            return 1;
        else if (c == ')')
            return -1;
        else
            return 0;
    };
    std::transform(expr.begin(), expr.end(), std::back_inserter(a), mapping);

    std::partial_sum(a.begin(), a.end(), a.begin());

    return *std::max_element(a.begin(), a.end());
}

int main() {
    std::vector<std::pair<std::string, int>> tests;
    tests.push_back({"(3+2)", 1});
    tests.push_back({"1", 0});
    tests.push_back({"3+2", 0});
    tests.push_back({"(3+(2+2))", 2});
    tests.push_back({"((3+2) + ((2 + 4) * 4))", 3});
    tests.push_back({"(((((|)))))", 5});

    for (auto i : tests) {
        if (depth(i.first) == i.second)
            std::cerr << "Test Successful" << '\n';
        else
            std::cerr << "Test Unsuccessful" << '\n';
    }
}