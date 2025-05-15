#include<bits/stdc++.h>

using namespace std;

int main() {
    string s = "4*(1+2*(9/3)-5)";
    stack<char> op;  // Specify data type for stack
    string res = "";
    int i = 0;
    while (i < s.size()) {
        if (s[i] == '(' || s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/') {
            if (s[i]=='+' || s[i]=='-'){
                if (op.top()=='*' || op.top()=='/'){
                    res+=op.top();
                    res+=" ";
                    op.pop();
                }
            }
            op.push(s[i]);
        }
        else if (s[i]==')'){
            while ( op.top() != '(' ){
                res+=op.top();
                res+=" ";
                op.pop();
            }
            op.pop();
        }
        else if((int)s[i]<58 && (int)s[i]>47){
            res+=s[i];
            res+=" ";
        }
        i++;
    }
    while (!op.empty()){
        res+=op.top();
        res+=" ";

        op.pop();
    }
    cout<<res<<endl;
    return 0;
}
