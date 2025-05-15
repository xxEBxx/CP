#include<bits/stdc++.h>

using namespace std;

unordered_map<string,int> generate(){
    int count=1;
    int n=26;
    unordered_map<string,int> m;
    for(int i=0;i<n;i++){
        string word="";
        word+=(char) ('a'+i);
        m[word]=count;
        count++;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string word="";
            word+=(char) ('a'+i);
            word+=(char) ('a'+j);
            m[word]=count;
            count++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                string word = "";
                word += (char) ('a' + i);
                word += (char) ('a' + j);
                word += (char) ('a' + k);
                m[word] = count;
                count++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    string word = "";
                    word += (char) ('a' + i);
                    word += (char) ('a' + j);
                    word += (char) ('a' + k);
                    word += (char) ('a' + l);

                    m[word] = count;
                    count++;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    for(int g=l+1;g<n;g++){
                        string word = "";
                        word += (char) ('a' + i);
                        word += (char) ('a' + j);
                        word += (char) ('a' + k);
                        word += (char) ('a' + l);
                        word += (char) ('a' + g);

                        m[word] = count;
                        count++;
                    }
                }
            }
        }
    }
    return m;
}


int main(){
    string s;
    unordered_map<string,int> m=generate();
    while(cin>>s){
        if(s.empty())return 0;
        cout<<m[s]<<endl;
    }
}