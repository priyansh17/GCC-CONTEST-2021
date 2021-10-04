#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b) {
    int index1=0,index2=0;
    int cost=0,count=0;
    int n1=a.size(),n2=b.size();
    while(index1<n1 && index2<n2 && cost<=maxSum){
        if(a[index1]<=b[index2])
            { if(cost+a[index1]>maxSum) return count; 
            cost+=a[index1]; index1++; count++;}
        else
            { if(cost+b[index2]>maxSum) return count;
            cost+=b[index2]; index2++; count++;}
    }
    
    while(index1<n1 && cost<=maxSum)
        { if(cost+a[index1]>maxSum) return count;
        cost+=a[index1]; index1++; count++;}
    
    while(index2<n2 && cost<=maxSum)
        { if(cost+b[index2]>maxSum) return count;
        cost+=b[index2]; index2++; count++;}
    
    return count;
    
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
