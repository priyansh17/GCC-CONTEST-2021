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
int totalPairs(int n, vector<int>& values) {
    int answer=0;
    for(int i=0;i<n;i++){
        int maxm=INT_MIN;
        for(int j=i+1;j<n;j++){
            int val=min(values[i],values[j]);
            if(maxm<val){
                maxm=max(maxm,values[j]);
                answer++;
            }
            else if(maxm>=val && values[i]==val){
                break;
            }
        }
    }
    
    return answer;
}

int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
	int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}
