#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> vec{2, 4, 6, 8, 10, 12};

    bool any =
        std::any_of(vec.begin(), vec.end(), [](auto i) { return i % 2 == 1; });

    if (any)
        std::cerr << "Van paratlan" << '\n';
    else
        std::cerr << "NIncs" << '\n';

    for (auto i : vec)
        std::cerr << i << ' ';
    std::cerr << "" << '\n';

    std::transform(vec.begin(), vec.end(), vec.begin(),
                   [](auto i) { return 2 * i; });

    for (auto i : vec)
        std::cerr << i << ' ';
    std::cerr << "" << '\n';

    std::vector<int> vec2;
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(vec2),
                 [](auto i) { return i < 10; });

    for (auto i : vec2)
        std::cerr << i << ' ';
    std::cerr << "" << '\n';

    int i = std::accumulate(vec2.begin(), vec2.end(), vec2[0],
                            [](auto i, auto j) { return std::max(i, j); });

    std::cerr << *std::max_element(vec2.begin(), vec2.end()) << '\n';
}