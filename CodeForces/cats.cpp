#include <iostream>
#include <string>

int main() {
    int t, n;
    std::string s;

    std::cin >> t;
    std::cin.ignore();  // Consume the newline character after reading t

    for (int k = 0; k<t; k++) {
        std::cin >> n;
        std::cin.ignore();  // Consume the newline character after reading n
        std::getline(std::cin, s);
        std::cout << s << "\n";
    }

    return 0;
}
