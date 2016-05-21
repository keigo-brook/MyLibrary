/*
 * Created by KeigoOgawa
 * Queue
 */

#include "../myHeahder.h"
 
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

template<typename T> int take(T& q) {
    q.top();
    q.pop();
}

void test_queue() {
    // descending order
    std::priority_queue<int, std::vector<int>, std::greater<int> > que;

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
}
