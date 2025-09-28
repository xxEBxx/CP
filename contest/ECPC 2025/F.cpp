#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define f first
#define s second

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int  main() {
    int n,t;
    cin>>n>>t;
    int m=36;
    vector<double> w(m);
    for (int i=0;i<m;i++) {
        cin>>w[i];
    }
    int total=0;
    vector<pair<int,double>> b(n);//first is price
    for (int i=0;i<n;i++) {
        int id,d,raw_b;
        cin>>id>>d>>raw_b;
        b[i] = {d,w[id-1]*(double)raw_b/100.0};
    }

    vector<double> curr(t+1,0.0),nex(t+1,0.0);

    for (int time =0;time<=t;time++) {
        if (b[0].first <= time)
            curr[time] =max(curr[time],b[0].second);
    }

    for (int i=1;i<n;i++) {

        for (int time =0;time<=t;time++) {
            nex[time] = curr[time];
            if (time >= b[i].f)
                nex[time] = max(nex[time],
                    b[i].s+curr[time-b[i].f]);
        }
        curr=nex;
    }
    printf("%.6f",curr[t]);

}
