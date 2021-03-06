#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);
static int GroupCounter=0;
static int maxM;
static int minM;
static int F,S,T;

class group{
  public:
        int groupId;
        int size=0;
        vector<int> dept={F,S,T};
        set<string> members;
        group(){}
        group(int x){
            groupId=x;
        }
};

group FormNewGroup(string e1,string e2,map<string,int> &d){
    group newGroup(GroupCounter++);
    newGroup.members.insert(e1);
    newGroup.members.insert(e2);
    newGroup.size=2;
    newGroup.dept[d[e1]-1]--;
    newGroup.dept[d[e2]-1]--;
    return newGroup;
}

int FindGroup(int Id,vector<group> &groups){
    for(int g=0;g<groups.size();g++)
        if(groups[g].groupId==Id)
            return g;
}

void AddMember(group &G,string e,map<string,int> &employees,map<string,int> &departments){
    if(G.size<maxM && G.dept[departments[e]-1]>0){
        G.size++;
        G.dept[departments[e]-1]--;
        G.members.insert(e);
        employees[e]=G.groupId;
    }
}

bool MergeGroups(group &G1,group &G2,map<string,int> &employees,map<string,int> &departments){
    vector<int> maxArr={F,S,T};
    if(G1.size + G2.size > maxM) return false;
    for(int i=0;i<3;i++)
        if(G1.dept[i]+G2.dept[i]<maxArr[i]) return false;
    for(auto i:G2.members){
        G1.dept[departments[i]-1]--;
        employees[i]=G1.groupId;
        G1.members.insert(i);
    }
    G1.size+=G2.size;
    return true;
}

void printResult(vector<group> &groups){
    if(groups.size()==0){
        cout<<"no groups"<<endl;
        return;
    }
    int maxSize=INT_MIN;
    set<string> names;
    for(int i=0;i<groups.size();i++)
        maxSize=max(maxSize,groups[i].size);
     if(maxSize<minM){
         cout<<"no groups"<<endl;
         return;
    }
    for(auto g:groups)
         if(g.size==maxSize)
             for(auto i:g.members)
                names.insert(i);
    for(auto name:names)
        cout<<name<<endl;
}

// void printallgroups(vector<group> &groups){
//     for(auto i:groups){
//         for(auto j:i.members)
//             cout<<j<<" ";
//         cout<<endl;}
// }

void theHackathon(int n, int m, int a, int b, int f, int s, int t) {
    F=f;S=s;T=t;
    maxM=b;minM=a;
    map<string,int> employees;
    map<string,int> departments;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        employees[name]=-1;
        cin>>departments[name];
    }
    vector<group> groups;
    while(m--){
        string e1,e2;
        cin>>e1>>e2;
        if(employees[e1]==-1 && employees[e2]==-1){
            //cout<<"Request new group: "<<e1<<" "<<e2<<endl;
            group newGroup=FormNewGroup(e1,e2,departments);
            groups.push_back(newGroup);
            employees[e1]=employees[e2]=newGroup.groupId;
        }
        else if(employees[e1]==-1){
            //cout<<"Request add member: "<<e1<<" "<<e2<<endl;
            group &G=groups[FindGroup(employees[e2],groups)];
            AddMember(G,e1,employees,departments);
        }
        else if(employees[e2]==-1){
            //cout<<"Request add member: "<<e1<<" "<<e2<<endl;
            group &G=groups[FindGroup(employees[e1],groups)];
            AddMember(G,e2,employees,departments);
        }else if(employees[e1]!=employees[e2]){
            //cout<<"Request merge groups: "<<e1<<" "<<e2<<endl;
            int index1=FindGroup(employees[e1],groups);
            int index2=FindGroup(employees[e2],groups);
            group &G1=groups[index1];
            group &G2=groups[index2];
            if(G1.size>G2.size){
                if(MergeGroups(G1,G2,employees,departments)) 
                    groups.erase(groups.begin()+index2);
            }else{ 
                if(MergeGroups(G2,G1,employees,departments)) 
                    groups.erase(groups.begin()+index1);
            }
        }
    }
    //printallgroups(groups);
    printResult(groups);
}

int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);

    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
