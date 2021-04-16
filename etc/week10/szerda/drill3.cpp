#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
    std::vector<double> vd{1.4253, 34.232, 4.0, 238.23, 2382.93, 94.2836};

    std::vector<int> vi(vd.size());
    std::vector<int> vi2;

    std::transform(vd.begin(), vd.end(), vi.begin(),
                   [](double d) { return int(d); });

    std::copy(vd.begin(), vd.end(), std::back_inserter(vi2));

    for (auto i : vi)
        std::cout << i << ' ';
    std::cout << std::endl;

    for (auto i : vi2)
        std::cout << i << ' ';
    std::cout << std::endl;

    double mean = std::accumulate(vd.begin(), vd.end(), 0.0) / vd.size();

    std::vector<double> vd2;
    std::copy_if(vd.begin(), vd.end(), std::back_inserter(vd2),
                 [mean](double d) { return d < mean; });

    for (auto i : vd2)
        std::cout << i << ' ';
    std::cout << std::endl;
}