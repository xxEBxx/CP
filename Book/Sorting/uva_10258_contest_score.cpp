#include <bits/stdc++.h>

using namespace std;

class contestant {
public:
    int id;
    int solved;
    int penalty;
    map<int,int> uncorect_tries;
    vector<int> done_problems;
    contestant(int id) {
        this->id = id;
        this->solved = 0;
        this->penalty = 0;
    }
    void add_problem() {
        this->solved++;
    }
    void add_penalty(int num) {
        this->penalty += num;
    }
    void add_uncorect(int num){
        this->uncorect_tries[num]++;
    }
};

void sort(vector<contestant> arr){
    if(arr.size()==0){
        return ;
    }
    //Bubble sort;
    //cout<<"enterred sort"<<arr.size()<<endl;
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i].solved < arr[j].solved){
                contestant temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            else if(arr[i].solved == arr[j].solved){
                if(arr[i].penalty > arr[j].penalty){
                    contestant temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
                else if(arr[i].penalty == arr[j].penalty){
                    if(arr[i].id > arr[j].id){
                        contestant temp=arr[i];
                        arr[i]=arr[j];
                        arr[j]=temp;
                    }
                }
            }
        }
    }
    //cout<<"HELLO";
    for(int i=0;i<n-1;i++){
        cout<<arr[i].id<<" "<<arr[i].solved<<" "<<arr[i].penalty<<endl;
    }
    int i=n-1;
    cout<<arr[i].id<<" "<<arr[i].solved<<" "<<arr[i].penalty;
}

int main() {
    int t;
    cin >> t;t++;
    cin.ignore();
    while (t--) {
        vector<contestant> arr;
        vector<int> ids;
        int id, problem, time,index;
        char answer;
        string line;
        while (getline(cin,line) && !line.empty()) {
            stringstream ss(line);
            ss >> id >> problem >> time >> answer;
            //cout<<"id"<<id<<endl;
            int exist=0,already_done=0;
            for(int i=0;i<ids.size();i++){
                if(ids[i]==id){
                    exist=1;
                    index=i;
                    break;
                }
            }
            if(!exist){
                ids.push_back(id);
                contestant elghali =contestant(id);
                arr.push_back(elghali);
                index=arr.size()-1;
            }

            //cout<<arr[index].done_problems.size();
            for(int i=0;i<arr[index].done_problems.size();i++){
                if(arr[index].done_problems[i] == problem){
                    already_done=1;
                    break;
                }
            }
            if(already_done){
                continue;
            }

            if (answer == 'I') {
                arr[index].add_uncorect(problem);
            }
            if (answer == 'C'){
                //cout<<endl<<"incorect"<<arr[index].uncorect_tries[problem]<<"problem"<<problem<<endl;
                arr[index].add_problem();
                arr[index].add_penalty(time + 20 * arr[index].uncorect_tries[problem]);
                arr[index].done_problems.push_back(problem);
            }
        }
        //cout<<"help"<<arr.size();
        sort(arr);
    }
    return 0;
}
