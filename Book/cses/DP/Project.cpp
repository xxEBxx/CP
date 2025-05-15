#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,pair<ll,ll>> iii;
typedef pair<ll,ll> ii;
bool comp(const iii& a, const iii& b){
        if(a.second.second!=b.second.second)
        return a.second.second < b.second.second;

        return a.first < b.first;
    }

int main(){
    int n;cin>>n;
    vector<iii> arr(1+n);
    for(int i=1;i<1+n;i++){
        cin>>arr[i].second.first>>arr[i].second.second>>arr[i].first;
    }
    sort(arr.begin(),arr.end(),comp);
    //cout<<arr[3].first<<endl;
    set<ii> dp;

    dp.insert({arr[1].second.second,arr[1].first});
    //we sort by finish time and we keep track of it and how muxh we need
    //we keep track of finish time to binary search it after

    ll cost_max=arr[1].first;

    for(int i=2;i<n+1;i++){
        //we binary search its starting time to find element that finish just before it
        if(arr[i].second.first <= dp.begin()->first){
            cost_max=max(cost_max,arr[i].first);
            dp.insert({arr[i].second.second,cost_max});
            //cout<<"here is time and cost before before"<<arr[i].second.second<<cost_max<<endl;
            continue;
        }
        auto it=prev(dp.lower_bound({arr[i].second.first,arr[i].first}));
        //cout<<"here is iterator"<<it->first<<" "<<it->second<<endl;
        ii elem={arr[i].second.second,arr[i].first + it->second};
        if(elem.second < cost_max){
            elem.second=cost_max;
        }
        else{
            cost_max=elem.second;
        }
        //cout<<"here is time and cost"<<elem.first<<cost_max<<endl;
        dp.insert(elem);
    }
    cout<<prev(dp.end())->second;
    return 0;
}