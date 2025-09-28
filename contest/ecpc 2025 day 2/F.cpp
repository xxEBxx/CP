
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

bool isempty(vi arr) {
    for (auto elem : arr)
        if (elem != 0)
            return false;
    return true;
}
int n;
bool valid = true;
string pre ;
pair<bool,string> solve(vi bag,int i) {
    if (i == pre.size())
        return {true,""};

    if (isempty(bag))
        return {false,""};

    //we either take same letter, if works go back
    //else take the one just bigger
    char c = pre[i];
    if (bag[c-'a']>0) {
        bag[c-'a']--;
        auto res = solve(bag,i+1);
        bag[c-'a']++;
        if (res.f) {
            return {true,c + res.s};
        }
    }
    int j = c-'a'+1;//next char
    while (j<26 && bag[j]==0)
        j++;
    if (j==26)
        return {false,""};
    bag[j]--;
    //we took an element bigger than pre[i]

    string curr="";
    curr += (char)('a'+j);
    for (int index=0;index<26;index++) {
        for (int occ=0;occ<bag[index];occ++) {
            curr += (char)('a'+index);
        }
    }
    return {true , curr};
}

int main() {
    fast();
    cin>>n;
    vector<string> arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr[0]));
    for (int i=1;i<n;i++) {
        vi bag(26,0);
        for (char c:arr[i]) {
            bag[c-'a']++;
        }
        pre = arr[i-1];

        //lets solve for pre and bag
        int pos =0;
        stack<int> tied;
        //places where we tied to backtrack to
        while (pos<pre.size() && pos<arr[i].size()) {
            int c = pre[pos] - 'a';//index of the letter
            if (bag[c] > 0) {
                tied.push(pos);

            }
        }

        auto res = solve(bag,0);
        if (!res.f) {
            cout<<-1<<endl;
            return 0;
        }
        arr[i] = res.s;
    }
    for (auto elem : arr) {
        cout<<elem<<endl;
    }
    return 0;
}
