#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;

bool mycomp(pair<int,int> &a,pair<int,int> &b){
    return a.first<b.first;
}
 
int securitiesBuying(int z,vector<int> arr)
{
    int no_of_stocks=0;
    vector<pair<int,int>> s(arr.size());
    for(int i=0;i<arr.size();i++)
        s[i]=make_pair(arr[i],i+1);
    int cost=0,index=0;
    sort(s.begin(),s.end(),mycomp);
   
    while(cost<=z && index<s.size()){
        int val=cost+s[index].first*s[index].second;
        if(val<z){
            cost=val;
            no_of_stocks+=s[index].second;
        }else{
            int stock= (z-cost)/(s[index].first);
            if(stock==0) break;
            cost+= stock*s[index].first;
            no_of_stocks+=stock;
        }
        index++;
    }
    return no_of_stocks;
}
 
int main(){
 
int z;
cin>>z;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);
 
 
while (iss >> data)
    input_data.push_back(data);
 
int n= input_data.size();
 
 
vector<int> security_value(n);
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }
 
 
 
int no_of_stocks_purchased = securitiesBuying(z,security_value);
cout << no_of_stocks_purchased;

}
 
 
