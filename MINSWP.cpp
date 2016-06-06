#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
	int nTestCases, nRows, nColumns;
	scanf("%d", &nTestCases);
	
	char input[102][102];
	char temp;
	
	int currentCase = 1;
	while(nTestCases--) {
		int output[102][102] = {0};
		scanf("%d %d", &nRows, &nColumns);
		
		for(int i=1; i<=nRows; i++) {
			for(int j=1; j <=nColumns; j++) {
				cin>>input[i][j];
				
				if(input[i][j]=='*') {
					//Mine Found
					output[i][j] = -999;
					output[i-1][j-1]++;
					output[i][j-1]++;
					output[i+1][j-1]++;
					output[i-1][j]++;
					output[i+1][j]++;
					output[i+1][j+1]++;
					output[i][j+1]++;
					output[i-1][j+1]++;
				} 
			}
		}
	
		if(currentCase!=1)
			printf("\nCase %d:\n", currentCase);
		else
			printf("Case %d:\n", currentCase);
		for(int i=1; i<=nRows; i++) {
			for(int j=1; j <=nColumns; j++) {

				if(output[i][j]<0) {
					//Mine Found
					printf("*");
				} else {
				
					printf("%d", output[i][j]);
				}
				
			}
			if(i != nRows)
				cout<<endl;
		}
		
		currentCase++;
	
	}
	
	
	return 0;
}
