//
// Created by benje on 10/24/2024.
//
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

struct triple{
    int a;int b;int c;
};
int main(){fast();
        int r,c,d;cin>>r;cin >> c;cin >> d;
    vector<vector<char>> m(r,vector<char>(c,' '));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> m[i][j];
        }
    }
    int res = 0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if (m[i][j] != 'H')continue;
            int found1=0;
            int found2=0;
            queue<triple> q;
            vector<vector<int>> visited(r,vector<int>(c,0));
            visited[i][j] = 1;
            q.push({i,j,0});
            while(!q.empty()){
                triple fromt = q.front();
                q.pop();
                int ii = fromt.a;
                int jj = fromt.b;

                if(ii + 1 < r && m[ii+1][jj] != 'H' && m[ii+1][jj] != '#' && !visited[ii+1][jj]){
                    if(m[ii+1][jj] == 'S' && ((fromt.c + 1) <= d) && !found1) { found1 = 1; m[ii+1][jj] = '#';}
                    if(m[ii+1][jj] == 'P' && ((fromt.c + 1) <= d)&& !found2) { found2 = 1;m[ii+1][jj] = '#' ;}
                    if(m[ii+1][jj] == '.'){
                        q.push({ii+1,jj,fromt.c + 1});
                        visited[ii+1][jj] = 1;
                    }
                }
                if(ii - 1 >= 0 && m[ii-1][jj] != 'H' && m[ii-1][jj] != '#' && !visited[ii-1][jj]){
                    if(m[ii-1][jj] == 'S' && ((fromt.c + 1) <= d) && !found1) { found1 = 1;m[ii-1][jj] = '#' ; }
                    if(m[ii-1][jj] == 'P' && ((fromt.c + 1) <= d)&& !found2) { found2 = 1; m[ii-1][jj] = '#' ;}
                    if(m[ii-1][jj] == '.'){
                        q.push({ii-1,jj,fromt.c + 1});
                        visited[ii-1][jj] = 1;
                    }
                }
                if(jj - 1 >= 0 && m[ii][jj-1] != 'H' && m[ii][jj-1] != '#' && !visited[ii][jj-1]){
                    if(m[ii][jj-1] == 'S' && ((fromt.c + 1) <= d) && !found1) { found1 = 1;m[ii][jj-1] = '#'; }
                    if(m[ii][jj-1] == 'P' && ((fromt.c + 1) <= d)&& !found2) { found2 = 1; m[ii][jj-1] = '#';}
                    if(m[ii][jj-1] == '.'){
                        q.push({ii,jj-1,fromt.c + 1});
                        visited[ii][jj-1] = 1;
                    }
                }
                if(jj + 1 < c && m[ii][jj + 1] != 'H' && m[ii][jj + 1] != '#' && !visited[ii][jj + 1]){
                    if(m[ii][jj + 1] == 'S' && ((fromt.c + 1) <= d) && !found1) { found1 = 1; m[ii][jj + 1] ='#';}
                    if(m[ii][jj + 1] == 'P' && ((fromt.c + 1) <= d) && !found2) { found2 = 1;m[ii][jj + 1] = '#'; }
                    if(m[ii][jj + 1] == '.'){
                        q.push({ii,jj + 1,fromt.c + 1});
                        visited[ii][jj + 1] = 1;
                    }
                }











            }
            if(found1 && found2)res++;



        }
    }



    cout << res;


    return 0;
}