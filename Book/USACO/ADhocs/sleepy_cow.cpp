#include<bits/stdc++.h>

using namespace std;

int main(){
    ofstream fout ("herding.out");
    ifstream fin ("herding.in");
    vector<int> a(3);
    int min_el,max_el;
    fin >> a[0] >> a[1]>>a[2];
    if(a[0]+1==a[1] && a[1]+1==a[2])min_el=0;
    else if (a[1]-a[0]==2 || a[2]-a[1]==2)min_el=1;
    else min_el=2;
    max_el=max(a[1]-a[0],a[2]-a[1])-1;
    fout << min_el << endl<<max_el;
    return 0;
}