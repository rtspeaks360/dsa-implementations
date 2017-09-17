/*
* @Author: sherlock
* @Date:   2017-08-05 01:02:42
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-05 01:26:52
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct item{
	int value;
	int weight;
};

bool cmp(item lhs, item rhs){return (lhs.value/double(lhs.weight)) < (rhs.value/double(rhs.weight));}

double knapsack(int W, item arr[], int n){
	sort(arr, arr + n, cmp);

	int current_weight = 0;
	int current_value =0;

	for (int i = 0; i < n; ++i)
	{
		/* code */
		if (current_weight + arr[i].weight < W){
			current_weight += arr[i].weight;
			current_value += arr[i].value;
		}
		else{
			int remain = W - current_weight;
			current_value =+ arr[i].value * (double(remain)/arr[i].weight);
			break; 
		}
	}

	return current_value;
}


int main(){
	int n, W;
	cout << "How many pairs? " << endl;
	cin >> n;
	cout << "Max weight : ";
	cin >> W;

	item arr[10];

	for (int i = 0; i < n; ++i)
	{
		/* code */
		cout << "Enter Weight : " ;
		cin >> arr[i].weight;
		cout << endl << "Enter Value : ";
		cin >> arr[i].value;
	}

	double final_knapsack = knapsack(W, arr, n);

	cout << "Final value of knapsack is : " << final_knapsack;

    return 0;
}