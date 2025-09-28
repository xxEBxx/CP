#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int  main() {
    fast();
    int n;
    cin >> n;
    string city,domain,value,pers;
    cin >> city >> domain >> value >> pers;
    int p,r,m;
    cin >> p >> r >> m;
    int tot = -1;
    for (int i=0;i<n-1;i++) {
        string c,d,v,pe;
        cin >> c >> d >> v >> pe;
        int pi,ri,mi;
        cin >> pi >> ri >> mi;
        if (c != city)
            continue;
        if (domain == d)
            continue;
        if (v != value)
            continue;
        int div = 0;
        if (pers != pe)
            div += 1000;
        div += ((p*pi) + (r*ri) + (m*mi));
        tot = max(div,tot);
    }
    cout << tot;

}
