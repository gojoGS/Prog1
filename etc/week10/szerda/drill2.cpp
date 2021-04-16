#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> msi;
    msi.insert({"string", 3});
    msi["masik"]      = 2244;
    msi["masikmasik"] = 224;

    std::map<int, std::string> mis;

    // for (auto i : msi)
    //     mis[i.second] = i.first;
    for (auto i : msi)
        std::cout << i.first << ' ' << i.second << '\n';
    std::cout << std::endl;

    // for (auto [k, v] : msi)
    //     mis[v] = k;

    for (auto i : msi)
        mis[i.second] = i.first;

    for (auto i : mis)
        std::cout << i.first << ' ' << i.second << '\n';
    std::cout << std::endl;
}