#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

void vector() {
    std::cout << "/***** std::vector *****/\n\n";

    std::vector<int> vec1;
    std::vector<int> vec2(10);
    std::vector<int> vec3(10, 0);

    if (vec1.empty())
        std::cout << "meg ures\n";
    std::cout << std::endl;

    std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
    std::cout << vec2.size() << ' ' << vec2.capacity() << '\n';
    std::cout << vec2.size() << ' ' << vec3.capacity() << '\n';
    std::cout << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
        vec1.push_back(i);
        std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
    }
    std::cout << std::endl;

    auto it = vec1.begin();
    std::cout << *it << '\n';

    for (int i = 0; i < 10; ++i)
        vec1.push_back(i);

    std::cout << *it << '\n';

    for (auto i : vec1)
        std::cout << i << ' ';
    std::cout << std::endl;

    vec1.pop_back();

    for (auto i : vec1)
        std::cout << i << ' ';
    std::cout << std::endl;
}

void map() {
    std::cout << "/***** std::map *****/\n\n";
    std::map<int, std::string> map;
    map.insert(std::pair<int, std::string>(3, "three"));
    map.insert({4, "four"});
    map[5] = "five";

    for (auto i : map)
        std::cout << i.first << ": " << i.second << '\n';

    std::cout << map[404];
}
void set() {
    std::cout << "/***** std::set *****/\n\n";

    std::set<int> set;
    set.insert(3);
    set.insert(6);
    set.insert(11);
    set.insert(11);

    for (auto i : set)
        std::cout << i << ' ';
    std::cout << std::endl;
}
void stack() {
    std::cout << "/***** std::stack *****/\n\n";
    std::stack<int> stack;
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(-3);

    std::cout << stack.top() << '\n';
    stack.pop();
    std::cout << stack.top() << '\n';

    while (!stack.empty()) {
        std::cout << stack.top();
        stack.pop();
    }
    std::cout << std::endl;
}
void queue() {
    std::cout << "/***** std::queue *****/\n\n";
    std::queue<int> q;
    q.push(31);
    q.push(2);
    q.push(-31);
    q.push(27);

    std::cout << q.front() << ' ' << q.back() << '\n';
    q.pop();
    std::cout << q.front() << ' ' << q.back() << '\n';

    std::cout << std::endl;

    while (!q.empty()) {
        std::cout << q.front() << ' ' << q.back() << '\n';
        q.pop();
    }
}
void list() {
    std::cout << "/***** std::list *****/\n\n";
    std::list<int> list;
    list.push_front(3);
    list.push_front(01);
    list.push_back(-456);
    list.push_back(-45);

    for (auto i : list)
        std::cout << i << ' ';

    std::cout << std::endl;

    list.pop_back();

    for (auto i : list)
        std::cout << i << ' ';

    std::cout << std::endl;

    list.pop_front();

    for (auto i : list)
        std::cout << i << ' ';

    std::cout << std::endl;

    if (list.empty())
        std::cout << "elfogyott\n";
    else
        std::cout << "van meg " << list.size();

    std::cout << std::endl;
}

int main() {
    vector();
    map();
    set();
    stack();
    queue();
    list();
}