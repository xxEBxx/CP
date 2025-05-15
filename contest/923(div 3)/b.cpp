#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    //i will keep track of used characters to add when i have a 0
    int t,n,value;
    cin>>t;
    
    for (int i=0;i<t;i++){
        int track=97;
        cin>>n;
        string s="";
        unordered_map <char,int> map;
        for (int j=0;j<n;j++){
            cin >> value;
            if (value==0){//not found
                char char_to_add=(char)track;
                track++;
                map[char_to_add]=1;
                s+=char_to_add;
            }
            else {
                for (const auto& pair : map) {
                    if (pair.second == value) {
                        map[pair.first]++;
                        s+=pair.first;
                        break;
                    }
            }
            }
        }
        cout <<s<< endl ; 
            }
    
}