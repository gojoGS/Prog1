#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> msi;
    msi["Bib"]   = 0;
    msi["Bup"]   = 2;
    msi["Győzi"] = 23;

    std::map<int, std::string> mis;

    // for (auto [str, integer] : msi)
    //     mis[integer] = str;

    for (auto i : msi)
        mis[i.second] = i.first;

    std::cout << "Before\n";
    for (auto i : msi)
        std::cout << i.first << '\n';

    msi.erase("Bup");

    std::cout << "After\n";
    for (auto i : msi)
        std::cout << i.first << '\n';
}