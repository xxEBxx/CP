#include<bits/stdc++.h>

using namespace std;

int main(){
    multiset<int> previous = {1, 2, 2, 3, 4, 2, 5};

    auto it=previous.find(2);
    previous.erase(it);

    for (int x : previous) {
        cout << x << " ";
    }


}