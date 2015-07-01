#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main() {
	int n, count;
	int num, fact;
	scanf("%d", &n);
	string s;
	while(n--){
		count = 0;
		fact = 0;
		num = 0;
		cin>>s;
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]!='.'){
				count++;
			}else{
				fact = 1;
				break;
			}
		}
		
		for(int i=0;i<s.size();i++){
			if(s[i]!='.')
				num = num*10 + (s[i]-48);
		}
		if(fact==1)
			 cout<<pow(10,count)/gcd(num, pow(10,count))<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}