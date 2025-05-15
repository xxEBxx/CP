#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; test_case++) {
        int n;
        cin >> n;
        string line;
        cin >> line;

        unordered_map<char, int> map;
        int count = 0;

        for (char letter : line) {
            map[letter]++;
        }

        for (const auto& element : map) {
            if (element.first - 'A' + 1 <= element.second) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
