#include <iostream>
#include <set>
#include <iterator> // For std::distance

int main() {
    std::set<int> mySet = {1, 2, 3, 4, 5};

    // Define two iterators
    std::set<int>::iterator it1 = mySet.lower_bound(1);
    std::set<int>::iterator it2 = mySet.upper_bound(4);

    // Calculate the distance between the two iterators
    std::ptrdiff_t distance = std::distance(it1, it2);

    std::cout << "Distance between iterators: " << distance << std::endl;

    return 0;
}
