#include<bits/stdc++.h>

using namespace std;

int main(){
    string current;
    int kk=0;
    while(getline(cin,current)){
        int count=0;
        if(current=="end"){
            return 0;
        }
        kk++;
        cout<<"Case "<<kk<<": ";
        while(current.size()>0){
            stack<char> s;
            s.push(current[0]);
            int n = current.size();
            for (int i = 1; i < n; i++) {
                if (current[i] <= s.top()) {
                    s.push(current[i]);
                } else {
                    while (current[i] > s.top()) {
                        s.pop();
                        if (s.empty()) {
                            break;
                        }
                    }
                    s.push(current[i]);
                }
            }
            int index=n-1;
            while (!s.empty()){
                if(s.top()==current[index]){
                    current.erase(index,1);
                    s.pop();
                }
                index--;
                //cout<<"index; "<<index;

            }
            count++;
            //cout<<"newword : "<<current<<endl;
        }
        cout<<count;
        cout<<endl;
    }
}
