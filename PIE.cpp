#include <iostream>
#include <algorithm>
using namespace std;

long double pi=3.14159265358979323846264338327950;
long double pieList[100001];
int nTestCases, nFreinds, nPies;

int checkIfVolumeValid(long double volume){
	int nPiePlaced = 0;
	int j=0;
	int i = 1;
	// printf("nPies for distance :%Lf\n", volume);
	while(j<nPies){
		if(pieList[j]- i * volume>=0.0){
			// printf("Pie %d given\n", j+1);
			// pieList[j] = pieList[j]-volume;
			nPiePlaced++;
			i++;
			if(nPiePlaced==nFreinds+1){
				//printf("Ho Paaya\n");
				return 1;
			}	
		} else {
			j++;
			i = 1;
		}
	}
	// printf("Na ho paaya\n");
	return 0;
}

long double findLargestPieSize(){
	long double start=0,end=pieList[nPies-1],max=0.0;
	long double mid;
	while(end - start >= 1e-6){
		mid = (start+end)/2;
		if(checkIfVolumeValid(mid)==1){
			//Minimum Distance is in 2nd half
			// if(mid>max)	max = mid;
			start = mid;
		} else {
			end = mid;
		}
	}
	return start;
}

int main() {
	scanf("%d", &nTestCases);
	int temp = 0;
	while(nTestCases--){
		scanf("%d %d", &nPies, &nFreinds);
		for(int i=0;i<nPies;i++){
			scanf("%d", &temp);
			pieList[i] = temp * temp * pi;
			//printf("%Lf\n", temp * temp * pi);
		}
		sort(pieList, pieList+nPies);
		// for(int i=0;i<nPies;i++){
			// printf("%Lf\n", pieList[i]);
		// }
		
		printf("%Lf\n", findLargestPieSize());
		// return 0;
	}

	return 0;
}