//3n + 1 Problem - SPOJ (PROBTNPO)

#include <iostream>

using namespace std;

long long unsigned int cycleLength[1000000] = {0};


//long long int calculateCycleLength(int number) {
//	long long unsigned int count = 1;
//	long long unsigned int original = number;
//	//printf("Printing Cycle Length of %d\n", multi(number));
//	while(number!=1) {
//		if(number<1000000 && cycleLength[number]!=0) {
//			count += (cycleLength[number]-1);
//			break;
//		}
//		if(number&1) 
//			count+=2,number=(3*number+1)>>1;
//		else 
//			++count,number=number>>1;
//	}
//	if(original < 1000000)
//		cycleLength[original] = count;
//	//printf("Cycle Length of %d : %d\n", original, cycleLength[original]);
//	return 0;
//}


int calculateCycleLength (long long unsigned int j) {
		int k = 1;
		long long unsigned int original = j;
		while (j > 1)
        {
            if (j & 1)
                j = 3 * j + 1;
            else
                j >>= 1;
            ++k;
        }
        
        if(original < 1000000)
			cycleLength[original] = k;
			
		return cycleLength[original];
}

int main() {
	long long unsigned int nTestCases, firstNumber, secondNumber;
	long long unsigned int largestTillNow;
	while (scanf("%llu %llu", &firstNumber, &secondNumber) != EOF) {
		if(firstNumber < secondNumber) {
			largestTillNow = cycleLength[firstNumber];
			for(long long unsigned int i=firstNumber; i<=secondNumber; i++) {
				long long unsigned int temp;
				if(cycleLength[i]==0) {
					temp = calculateCycleLength(i);
				} else {
					temp = cycleLength[i];
				}
				if(temp>largestTillNow)	largestTillNow = cycleLength[i];
				//printf("Largest:%llu  CycleLength[%llu]:%llu\n", largestTillNow, i, temp);
			}
		} else {
			largestTillNow = cycleLength[secondNumber];
			for(long long unsigned int i=secondNumber; i<=firstNumber; i++) {
				if(cycleLength[i]==0) {
					calculateCycleLength(i);
				}
				if(cycleLength[i]>largestTillNow)	largestTillNow = cycleLength[i];
			}
		}
		
		printf("%llu %llu %llu\n", firstNumber, secondNumber, largestTillNow);
		
	}
	return 0;
	
}

