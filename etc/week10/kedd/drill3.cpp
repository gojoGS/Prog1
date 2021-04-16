#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
    std::vector<double> vd{1.0, 4.33, 5.66, 7.17, 12.21, 6.8};
    std::vector<int>    vi(vd.size());

    std::transform(vd.begin(), vd.end(), vi.begin(),
                   [](double d) { return int(d); });

    for (auto i : vd)
        std::cout << i << ' ';
    std::cout << '\n';
    for (auto i : vi)
        std::cout << i << ' ';
    std::cout << '\n';

    std::cout << std::accumulate(vi.begin(), vi.end(), 0) << '\n';
}