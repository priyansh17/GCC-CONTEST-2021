using namespace std;
#include <string>
#include <iostream>
#include <bits/stdc++.h>


string solution(string n){
    map<long,long> m;
    m[0]++;
    for(long i=0;i<n.size();i++){
        if(n[i]=='0'){
            long local=0;
            while(n[i]=='0' && i<n.size())
                {local++;i++;}
            m[local]++;
        }
    }
    auto it=m.rbegin();
    if(it->second!=1)    return "B";
    else if((it->first)&1) return "A";
    else return "B";
}

/*  Do not edit below code */
int main() {
	string  n;
	cin >> n;	
    string answer=solution(n);
	cout << answer << endl;	
}
