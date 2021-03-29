#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <vector>

namespace lab {
template <typename IterIm, typename IterOut>
IterOut copy(IterIm begin_1, IterIm end_1, IterOut begin_2) {
    // TODO: Írjuk át egy tömörebb while loopba
    // TODO: Írjuk át egy for loopba
    while (begin_1 != end_1) {
        *begin_2 = *begin_1;
        ++begin_1;
        ++begin_2;
    }

    return begin_2;
}
}  // namespace lab

template <typename Cont>
void print(Cont cont) {
    for (auto i : cont)
        std::cout << i << ' ';
    std::cout << '\n';

    return;
}

int main() {
    std::array<int, 10> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int>    vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int>      lst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    print(arr);
    print(vec);
    print(lst);

    std::array<int, 10> arr_copy(arr);
    std::vector<int>    vec_copy(vec);
    std::list<int>      lst_copy(lst);

    print(arr_copy);
    print(vec_copy);
    print(lst_copy);

    // TODO: Csináljuk meg ugyanezt ciklus nélül!

    for (auto& i : arr_copy)
        i += 2;

    for (auto& i : vec_copy)
        i += 3;

    for (auto& i : lst_copy)
        i += 5;

    print(arr_copy);
    print(vec_copy);
    print(lst_copy);

    std::array<int, 10> arr_own_copy;
    std::vector<int>    vec_own_copy(10);
    std::list<int>      lst_own_copy(10);

    lab::copy(arr.begin(), arr.end(), arr_own_copy.begin());
    lab::copy(vec.begin(), vec.end(), vec_own_copy.begin());
    lab::copy(lst.begin(), lst.end(), lst_own_copy.begin());

    print(arr_own_copy);
    print(vec_own_copy);
    print(lst_own_copy);
}