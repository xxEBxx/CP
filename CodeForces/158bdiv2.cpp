#include <iostream>
#include <vector>
int tp=0;

int findmin(const std::vector<int>& arr, int n) {
    if (arr.empty()) {
        return -1; // Return -1 to indicate an empty array
    }

    int minindex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[minindex]) {
            minindex = i;
        }
    }
    return minindex;
}

void print(const std::vector<int>& arr3){
    for (int i : arr3){
        std::cout<<i<<"\t";
    }
}

void tpcount(const std::vector<int>& arr3, int n, int common_values) {
    if (n == 1) {
        tp += arr3[0] - common_values;
        return;
    }
    int minindex = findmin(arr3, n);
    if (minindex==-1){
        return ; 
    }
    tp += arr3[minindex] - common_values;

    std :: cout << minindex << std::endl;

    std::vector<int> arr1(arr3.begin(), arr3.begin() + minindex-1);
    std::vector<int> arr2(arr3.begin() + minindex + 1, arr3.end());

    print(arr1);
    print(arr2);

    tpcount(arr1, minindex, arr3[minindex]);
    tpcount(arr2, n - minindex - 1, arr3[minindex]);
}

int main() {
    int t, n, value;
    std::cin >> t;

    for (int k = 0; k < t; k++) {
        std::cin >> n;
        std::vector<int> arr;
        for (int i = 0; i < n; i++) {
            std::cin >> value;
            arr.push_back(value);
        }

        tpcount(arr, n, 0);
        std::cout << tp << std::endl;

        tp = 0;
    }

    return 0;
}
