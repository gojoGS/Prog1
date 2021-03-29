#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

bool is_valid(std::string expr) {
    std::string parens;

    auto contains = [](std::string str, char c) {
        for (auto i : str) {
            if (c == i)
                return true;
        }
        return false;
    };

    auto pair = [](char c) {
        switch (c) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
        };

        return '!';
    };

    std::copy_if(
        expr.begin(), expr.end(), std::back_inserter(parens),
        [contains](auto i) { return contains(std::string("({[]})"), i); });

    std::stack<char> lparen;
    for (auto i : parens) {
        if (contains(std::string("[({"), i)) {
            lparen.push(i);
        } else {
            if (lparen.top() == pair(i))
                lparen.pop();
            else
                return false;
        }
    }

    return lparen.empty();
}

int main() {
    std::vector<std::pair<std::string, bool>> tests;
    tests.push_back({"(3+2)", true});
    tests.push_back({"(3+(2 * 4))", true});
    tests.push_back({"(3+{2 + 3})", true});
    tests.push_back({"([3]+{2})", true});
    tests.push_back({"{(2+3)*(3+2)}", true});
    tests.push_back({"{(2+3)*{3+2)}", false});
    tests.push_back({"{(2+3]*(3+2)}", false});
    tests.push_back({"[(]", false});

    for (auto i : tests) {
        if (is_valid(i.first) == i.second)
            std::cerr << "Test Successful" << '\n';
        else
            std::cerr << "Test Unsuccessful" << '\n';
    }
}