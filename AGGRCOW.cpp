#include <iostream>
#include <algorithm>
using namespace std;

int positionList[100001];
int nTestCases, nCows, nPositions;

int checkIfDistanceValid(int distance){
	int nCowsPlaced = 1;
	int i=0;
	int j=i+1;
	//printf("Checking for distance :%d\n", distance);
	while(j<nPositions){
		//printf("Distance j = %d Distance i = %d\n", positionList[j], positionList[i]);
		if(positionList[j]-positionList[i]>=distance){
			nCowsPlaced++;
			i = j;
			if(nCowsPlaced==nCows)	return 1;
		}
		j++;
	}
	return 0;
}

int findLargestMinDistance(){
	int start = 0;
	int end = positionList[nPositions-1];
	int max = -1;	//Keep track largest gap possible
	int mid;
	while(start<end){
		mid = (start+end)/2;
		if(checkIfDistanceValid(mid)==1){
			//Minimum Distance is in 2nd half
			if(mid>max)	max = mid;
			start = mid+1;
		} else {
			end = mid;
		}
	}
	return max;
}

int main() {
	scanf("%d", &nTestCases);
	while(nTestCases--){
		scanf("%d %d", &nPositions, &nCows);
		for(int i=0;i<nPositions;i++){
			scanf("%d", &positionList[i]);
		}
		sort(positionList, positionList+nPositions);
		printf("%d\n", findLargestMinDistance());
	}

	return 0;
}