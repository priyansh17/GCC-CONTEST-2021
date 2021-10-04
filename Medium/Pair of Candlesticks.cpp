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

long totalPairs(int n, vector<long>& values) {
    if(n==2) return 1;
    long answer=0;
    for(long i=0;i<n-1;i++){
        long maxm=values[i+1];
        answer++;
        for(long j=i+2;j<n;j++){
            if(maxm>values[i]) break;
            if(maxm<values[j]){
                answer++;
                maxm=values[j];
            }
        }
    }
    return answer;
}

int main(){
   int n;
   cin >> n;
   vector<long> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
	long answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}
