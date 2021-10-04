#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b) {
    int index=-1,sum=0,index2=-1;
    while(index+1<a.size() && sum+a[index+1]<=maxSum){
        index++;
        sum+=a[index];
    }
    int answer=index+1;
    while(index2+1<b.size()){
        if(sum+b[index2+1]<=maxSum){
            index2++;
            sum+=b[index2];
            answer=max(answer,index+1+index2+1);
        }else{
            if(index==-1) break;
            else {
                sum-=a[index];
                index--;
            }
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, maxSum;
    cin >> n >> m >> maxSum;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(maxSum, a, b);
    cout << result;
    return 0;
}
