#include <iostream>
#include <vector>
#include <algorithm>

long long int needed(std::vector<long long int> v, long long int h) {
    long long int need = 0;
    for (long long int i : v) {
        if (i <= h) {
            need += h - i;
        }
    }
    return need;
}

long long int findh(std::vector<long long int> v, long long int x) {
    auto max_element = std::max_element(v.begin(), v.end());
    long long int max = *max_element;
    auto min_element = std::min_element(v.begin(), v.end());
    long long int min = *min_element;
    long long int h = (max+x)/2;

    while (1 - (needed(v, h) <= x && needed(v, h + 1) > x)) {
        if (needed(v, h) > x) {
            max = h;
            if ((h + min) / 2 < h - 1)
                h = (h + min) / 2;
            else
                h--;
        } else {
            min = h;
            if ((h + max) / 2 > h + 1)
                h = (h + max) / 2;
            else
                h++;
        }
    }

    return h;
}

int main() {
    int t, n;
    
    long long int x,value;
    std::vector<long long int> v;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        std::cin >> x;
        for (int j = 0; j < n; j++) {
            std::cin >> value;
            v.push_back(value);
        }
        std::cout << findh(v, x) << "\n";
        v.clear();
    }
    return 0;
}
