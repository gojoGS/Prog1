#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto i : vec)
        std::cerr << i << ' ';
    std::cerr << "" << '\n';

    // std::any_of
    bool isany =
        std::any_of(vec.begin(), vec.end(), [](auto i) { return i % 2 == 1; });

    if (isany)
        std::cerr << "van paratlan" << '\n';
    else
        std::cerr << "nincs paratlan" << '\n';

    // std::transform
    std::transform(vec.begin(), vec.end(), vec.begin(),
                   [](auto i) { return i * 2; });

    for (auto i : vec)
        std::cerr << i << ' ';

    std::cerr << "" << '\n';

    std::vector<int> filtered;

    // std::copy_if
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(filtered),
                 [](auto i) { return i < 10; });

    for (auto i : filtered)
        std::cerr << i << ' ';

    std::cerr << "" << '\n';

    // std::accumulate
    int sum = std::accumulate(filtered.begin(), filtered.end(), filtered[0],
                              [](auto i, auto j) { return i < j ? j : i; });

    std::cerr << sum << '\n';

    std::string s("ABBA");
    std::string s2("BABA");

    // std::is_permutation

    bool isit = std::is_permutation(s.begin(), s.end(), s2.begin());

    if (isit)
        std::cerr << "indeed it is" << '\n';
    else
        std::cerr << "no its not" << '\n';

    // std::max(_element)
    std::cerr << *std::max_element(vec.begin(), vec.end()) << '\n';
    std::cerr << std::max(2, 3) << '\n';
}