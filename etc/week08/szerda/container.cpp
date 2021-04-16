#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

void vector() {
    std::vector<int> vec1;
    std::vector<int> vec2(10);
    std::vector<int> vec3(10, 3);

    for (auto i : vec1)
        std::cerr << i << ' ';

    std::cerr << "" << '\n';

    for (auto i : vec2)
        std::cerr << i << ' ';

    std::cerr << "" << '\n';

    for (auto i : vec3)
        std::cerr << i << ' ';

    std::cerr << "" << '\n';

    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(6);

    for (auto i : vec1)
        std::cerr << i << ' ';

    std::cerr << "" << '\n';

    std::cerr << vec1.size() << ' ' << vec1.capacity() << '\n';

    std::vector<int> vec4;
    std::cerr << vec4.size() << ' ' << vec4.capacity() << '\n';

    for (int i = 0; i < 10; ++i) {
        std::cerr << "Before: " << vec4.size() << ' ' << vec4.capacity()
                  << '\n';

        vec4.push_back(i);
        std::cerr << "After: " << vec4.size() << ' ' << vec4.capacity() << '\n';
    }

    // while (!vec4.empty()) {
    //     std::cerr << "Before: ";
    //     for (auto i : vec4)
    //         std::cerr << i << ' ';
    //     std::cerr << "" << '\n';

    //     vec4.pop_back();

    //     std::cerr << "After: ";
    //     for (auto i : vec4)
    //         std::cerr << i << ' ';
    //     std::cerr << "" << '\n';
    // }

    // std::cerr << vec4.size() << " " << vec4.capacity() << '\n';

    std::cerr << vec4.back() << '\n';
    std::cerr << vec4.front() << '\n';

    for (auto i : vec4)
        std::cerr << i << ' ';
    std::cerr << "" << '\n';

    vec4.back()  = 99;
    vec4.front() = 99;

    for (auto i : vec4)
        std::cerr << i << ' ';
    std::cerr << "" << '\n';

    std::vector<int> vec5{6};

    // auto i = vec5.begin();

    // std::cerr << *i << '\n';

    for (int i = 0; i < 5; ++i) {
        vec5.push_back(i);
    }

    // std::cerr << *i << '\n';

    for (auto i = vec5.begin(); i != vec5.end(); ++i) {
        std::cerr << *i << ' ';
    }

    std::cerr << "" << '\n';

    for (auto i = vec5.rbegin(); i != vec5.rend(); ++i) {
        std::cerr << *i << ' ';
    }
}

void map() {
    // std::map<int, std::string> map;
    // map.insert(std::pair<int, std::string>(1, "Lolka"));
    // map.insert({2, "Bolka"});

    // for (auto i : map)
    //     std::cerr << i.first << ' ' << i.second << '\n';

    // std::cerr << map[1] << '\n';

    std::map<std::string, std::string> map2;
    map2.insert({"Lolek", "Lolka"});
    map2.insert({"Bolek", "Bolka"});
    map2.insert({"Bolek", "Bolka"});

    for (auto i : map2)
        std::cerr << i.first << ": " << i.second << '\n';

    map2["Lolek"] = "Jenő";

    for (auto i : map2)
        std::cerr << i.first << ": " << i.second << '\n';

    map2["Jani"];

    for (auto i : map2)
        std::cerr << i.first << ": " << i.second << '\n';
}

void set() {
    std::set<int> set;
    set.insert(4);
    set.insert(3);
    set.insert(2);
    set.insert(4);

    for (auto i : set)
        std::cerr << i << ' ';
}

void stack() {
    std::stack<int> stack;
    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cerr << stack.top() << '\n';

    while (!stack.empty()) {
        std::cerr << "Before: " << stack.top() << '\n';
        stack.pop();
    }
}

void queue() {
    std::queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    while (!q.empty()) {
        std::cerr << "front: " << q.front() << " back:" << q.back() << '\n';
        q.pop();
    }
}

void list() {
    std::list<int> lst;
    lst.push_back(3);
    lst.push_back(34);
    lst.push_front(-1);
    lst.push_front(-567891);

    for (auto i : lst)
        std::cerr << i << ' ';
    std::cerr << "" << '\n';

    lst.pop_back();

    for (auto i : lst)
        std::cerr << i << ' ';
    std::cerr << "" << '\n';

    lst.pop_front();

    for (auto i : lst)
        std::cerr << i << ' ';
    std::cerr << "" << '\n';

    lst.front() = 4;
    lst.back()  = 727;

    for (auto i : lst)
        std::cerr << i << ' ';
    std::cerr << "" << '\n';
}

int main() {
    // vector();
    // map();
    // set();
    // stack();
    // queue();
    list();
}