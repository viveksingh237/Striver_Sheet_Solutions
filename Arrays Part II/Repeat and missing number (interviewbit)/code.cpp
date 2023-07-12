#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
	//*********Using hashing
	// int freq[n + 1] = {0};
	// for(int i=0;i<n;i++) freq[arr[i]]++; //stroing the freq
	// int repeating = -1,missing = -1;
    
	// //checking the freq
	// for(int i = 1;i <= n;i++){
	// 	if(freq[i] == 2)
	// 	repeating = i;
	// 	else if(freq[i] == 0)
	// 	missing = i;

	// 	if(missing != -1 and repeating != -1) break;
	// }
	// return {missing,repeating};



	//***** Using sum folmulae
	// long long int sum = 0,diff = 0,nSum = 0,arrSum = 0,n2Sum = 0,arr2Sum = 0;
	// long long int missing,repeating;
	// nSum = n*(n + 1)/2;
	// n2Sum = nSum*(2*n + 1)/3;
	// for(auto& x : arr){
	// 	arrSum += x;
	// 	arr2Sum += x*x;
	// }
	// diff = nSum - arrSum;
	// sum = (n2Sum - arr2Sum)/diff;
	// missing = (sum + diff)/2;
	// repeating = (sum - missing);

	// return {(int)missing, (int)repeating};


    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 0) return {zero, one};
    return {one, zero};
}


