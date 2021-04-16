#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

struct Item {
    Item() : name(""), id(0), value(0.0) {}
    Item(std::string n, int i, double v) : name(n), id(i), value(v) {}

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
        item = Item{n, i, v};

    return is;
}

std::ostream& operator<<(std::ostream& os, Item const& item) {
    os << item.name << ' ' << item.id << ' ' << item.value;

    return os;
}

bool pred_id(Item i) {
    return i.id == 7 || i.id == 96;
}

int main() {
    std::fstream      input("items.in", std::ios_base::in);
    std::vector<Item> vi;

    // most vexing parse
    // Item vp();

    for (Item tmp; input >> tmp;)
        vi.push_back(tmp);

    std::sort(vi.begin(), vi.end(),
              [](Item lhs, Item rhs) { return lhs.name < rhs.name; });

    for (auto i : vi)
        std::cout << i << '\n';
    std::cout << std::endl;

    std::sort(vi.begin(), vi.end(),
              [](auto lhs, auto rhs) { return lhs.id < rhs.id; });

    for (auto i : vi)
        std::cout << i << '\n';
    std::cout << std::endl;

    std::sort(vi.begin(), vi.end(),
              [](auto lhs, auto rhs) { return lhs.value < rhs.value; });

    for (auto i : vi)
        std::cout << i << '\n';
    std::cout << std::endl;

    for (auto it = vi.rbegin(); it != vi.rend(); ++it)
        std::cout << *it << '\n';
    std::cout << std::endl;

    vi.push_back(Item("Lulu", 93, 3552.286381));
    vi.push_back(Item("Belle", 96, 32.81));

    for (auto i : vi)
        std::cout << i << '\n';
    std::cout << std::endl;

    vi.erase(std::find_if(vi.begin(), vi.end(),
                          [](Item i) { return i.name == "Lulu"; }));

    for (auto i : vi)
        std::cout << i << '\n';
    std::cout << std::endl;

    vi.erase(std::remove_if(vi.begin(), vi.end(),
                            [](Item i) { return i.name == "Klaus"; }),
             vi.end());

    for (auto i : vi)
        std::cout << i << '\n';
    std::cout << std::endl;

    vi.erase(std::remove_if(vi.begin(), vi.end(), pred_id), vi.end());

    for (auto i : vi)
        std::cout << i << '\n';
    std::cout << std::endl;

    std::list<Item> lst;
    lst.push_back(Item("name", 1, 23.23));
    lst.push_back(Item("namene", 2, 322.2332));

    for (auto i : lst)
        std::cout << i << '\n';
    std::cout << std::endl;

    lst.remove_if([](Item i) { return i.id == 1; });

    for (auto i : lst)
        std::cout << i << '\n';
    std::cout << std::endl;
}