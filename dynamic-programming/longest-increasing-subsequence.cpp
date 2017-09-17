/*
* @Author: sherlock
* @Date:   2017-08-06 00:13:14
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-06 00:23:10
*/

#include <iostream>

using namespace std;

int max(int x, int y){return x>y?x:y;}

void longest_increasing_subsequence(int arr[], int n){
	int arr_inc_count[n];
	for (int i = 0; i < n; ++i){
		arr_inc_count[i] = 1;
	}

	for (int i = 0; i<n; i++)
		for (int j =0; j<i; j++)
			if (arr[i] > arr[j] )
				arr_inc_count[i] = max(arr_inc_count[i], arr_inc_count[j]+1); 

	for (int i = 0; i < n; ++i)	{
		cout << arr[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < n; ++i)	{
		cout << arr_inc_count[i] << " ";
	}
}	

int main(){
	int arr [8] = {3, 4, -1, 0, 6, 2, 3};

	longest_increasing_subsequence(arr, 7);
    return 0;
}