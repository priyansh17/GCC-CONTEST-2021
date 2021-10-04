using namespace std;
#include <string>
#include <iostream>
#include<bits/stdc++.h>
int solution(int n){
    if(n%3==0) return 2*(n/3);
    else return 2*(n/3) +1;
}


int main() {
	int n;
	cin >> n;	
    int answer=solution(n);
	cout << answer << endl;	
}
