#include <iostream>
using namespace std;

unsigned long long precompute[1000001];
unsigned long long precomputedValues[1000001];

long long precomputeValues(){

	//Initialize them to zero
	for (int i=0; i<1000001; i++){
		precompute[i] = 0;
	}
	
	//Find all the values for the function
	for (int i=1; i<=1000001; i++){
		for(int j=1; j*i<1000000; j++){
			if(j*i!=i)
				precompute[j*i]+=i;
		}
	}
}

long long precomputeFinalValues(){
	precomputedValues[0]=0;
	precomputedValues[1]=0;
	for (int i=2;i<1000001;i++){
		precomputedValues[i] = 	precomputedValues[i-1] + precompute[i];
	}
}

int main() {

	//Precomputer everything
	precomputeValues();
	precomputeFinalValues();
	int t, currNumber;
	cin>>t;
	
	while(t--){
		cin>>currNumber;
		cout<<precomputedValues[currNumber]<<endl;
	}
	
	return 0;
}