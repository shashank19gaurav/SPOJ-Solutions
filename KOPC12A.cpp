#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>



using namespace std;

struct building {
    int buildingHeight;
    int costBuilding;
};

building buildings[10000]; 
int n;

bool compareBuildings(building first, building second) { 
     if ( first.buildingHeight == second.buildingHeight ) {
         return first.costBuilding > second.costBuilding;
     }
     return first.buildingHeight > second.buildingHeight;
}

long long int cost(int h) {
    long long int sum = 0;
    int diff;

    for (int i = 0; i<n; i++) {
        diff = abs(buildings[i].buildingHeight-buildings[h].buildingHeight);
        sum += buildings[i].costBuilding * diff;
    }
    return sum;
}

long long int ternarySearch(int start, int end) {
    //End is the max value of H possible
    //Start is the smallest value of H  possible
    //

    if((end - start) < 3) {
        long long int ret = cost( start );

        for (++start; start <= end; ++start ) {
            ret = min( ret, cost( start ) );
        }
        //cout<<"Terminating with "<<ret<<endl;
        return ret;
    }

    int mid1 = (2 * start + end)/3;
    int mid2 = (2 * end + start)/3;

    if(cost(mid1)>cost(mid2)) {
        start = mid1;
    } else {
        end = mid2;
    }    
    
    ternarySearch(start, end);
}


int main() {
    int nTestCase, temp, i;
    int start, end;
    scanf("%d", &nTestCase);
    while(nTestCase--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            cin>>buildings[i].buildingHeight;
        }

        for(i = 0; i < n; i++){
            cin>>buildings[i].costBuilding;
        }
        
        sort(buildings, buildings+n, compareBuildings);
        
        //Smallest possible value is the minimum of given values of H
        //Largest possible is the max value present in the H array

        cout<<ternarySearch(0, n-1);
        
        if(nTestCase!=0) {
            cout<<endl;
        }
    }


}