#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void printSets(set<int> s1,set<int> s2){
    for(auto i:s1)
        cout<<i<<" ";
        cout<<endl;
    for(auto i:s2)
        cout<<i<<" ";
        cout<<endl;
}



void countStablePartitions(int n, vector<int>& values) {
    set<int> s1,s2;
    for(auto val:values)
        if(val&1) s2.insert(val);
        else s1.insert(val);
    printSets(s1,s2);
    for(auto i=s2.begin();i!=s2.end();i++){
        bool found=false;
        for(auto j=s1.begin();j!=s1.end();j++)
            {
                if(*i==1)  break;
                int val=*i>*j?*i%*j:*j%*i;
                if(!val){
                    s1.insert(*i);
                    s2.erase(i);
                    found=true;
                    break;
                }
            }
    }
    printSets(s1,s2);
    int result= 2*((1<<s2.size())-1);
    if(result==0) cout<<"NO\n0\n";
    else cout<<"YES\n"<<result<<endl;
}

int main(){
   int n=3;
   //cin >> n;
   vector<int> values={2,3,6};
   //for (int i = 0; i < n; ++i) {
       // cin >> values[i];
   //}
   countStablePartitions(n, values);
   return 0;
}
