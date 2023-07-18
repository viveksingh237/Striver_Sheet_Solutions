//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    private:
    static bool cmp(Item a, Item b){
        return (double)a.value/a.weight >= (double)b.value/b.weight;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr + n, cmp); //sorting based on densities
        
        double ans = 0.0;
        int tempW = 0;
        int i = 0;
        while(i < n){
            if(tempW + arr[i].weight <= W){
            ans += arr[i].value;
            tempW += arr[i].weight;
            i++;
        }
        else{
            ans += (double)(arr[i].value*(double)(W - tempW)/arr[i].weight);
            break;
        }
    }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
