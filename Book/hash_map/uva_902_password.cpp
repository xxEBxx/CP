#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin>>n)
    {
        string s;
        cin >> s;
        map<string, int> freq;
        for (int i = 0; i < s.size() - n + 1; i++) {
            string word = "";
            for (int j = i; j < i + n; j++) {
                word += s[j];
            }
            freq[word]++;
        }
        string ps;
        int mf = 0;
        for (auto element: freq) {
            if (element.second > mf) {
                mf = element.second;
                ps = element.first;
            }
        }
        cout << ps << endl;
    }
    return 0;
}