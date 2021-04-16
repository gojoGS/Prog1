#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <ostream>
#include <vector>

struct Item {
    Item(std::string n = "", int i = 0, double v = 0.0)
        : name(n), id(i), value(v) {}

    // Item() : name(""), id(0), value(0.0) {}

    friend std::ostream& operator<<(std::ostream& os, Item const& item);
    friend std::istream& operator>>(std::istream& is, Item& item);

    std::string name;
    int         id;
    double      value;
};

std::istream& operator>>(std::istream& is, Item& item) {
    std::string n;
    int         i;
    double      v;

    if (is >> n >> i >> v)
        item = Item(n, i, v);

    return is;
}

std::ostream& operator<<(std::ostream& os, Item const& item) {
    os << "(" << item.name << ", " << item.id << ", " << item.value << ")";

    return os;
}

void print(std::vector<Item> vec) {
    for (auto i : vec)
        std::cout << i << '\n';
}

bool pred_name(Item i) {
    return i.name == "Buksi";
}

bool pred_id(Item i) {
    return i.id == 1 || i.id == 2;
}

int main() {
    std::vector<Item> vi;

    std::fstream f("items.in", std::ios_base::in);

    // most vexing parse
    // Item tmp{};

    for (Item tmp; f >> tmp;)
        vi.push_back(tmp);

    std::cout << "Before:\n";
    print(vi);

    std::sort(vi.begin(), vi.end(),
              [](Item lhs, Item rhs) { return lhs.name < rhs.name; });

    std::cout << "After name:\n";
    print(vi);

    std::sort(vi.begin(), vi.end(),
              [](Item lhs, Item rhs) { return lhs.id < rhs.id; });

    std::cout << "After id:\n";
    print(vi);

    std::sort(vi.begin(), vi.end(),
              [](Item lhs, Item rhs) { return lhs.value < rhs.value; });

    std::cout << "After value:\n";
    print(vi);

    std::cout << "After value (reverse):\n";
    for (auto it = vi.rbegin(); it != vi.rend(); ++it)
        std::cout << *it << '\n';

    vi.push_back(Item{"Buksi", 11, 9.87});
    vi.push_back(Item{"Zsoca", 13, 4.5});

    std::cout << "After insert:\n";
    print(vi);

    vi.erase(std::find_if(vi.begin(), vi.end(), pred_name));
    vi.erase(std::find_if(vi.begin(), vi.end(),
                          [](Item i) { return i.name == "Zsoca"; }));

    std::cout << "After erase:\n";
    print(vi);

    vi.erase(std::remove_if(vi.begin(), vi.end(), pred_id), vi.end());

    std::cout << "After remove_if+erase:\n";
    print(vi);
}