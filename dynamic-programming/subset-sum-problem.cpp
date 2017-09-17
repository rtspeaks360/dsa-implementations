/*
* @Author: sherlock
* @Date:   2017-08-05 22:53:39
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-05 23:52:55
*/

#include <iostream>
#include <set>

using namespace std;

pair<bool, set<int> > get_subset(int arr[], int n, int T){
	bool dp_matrix[n+1][T+1];
	for (int i = 0; i<= n; i++){
		dp_matrix[i][0] = true;
	}

	for (int i = 1; i<=n; i++){
		for(int j = 1; j <= T; j++){
			
			if(arr[i-1] > j){
				dp_matrix[i][j] = dp_matrix[i-1][j];
			}
			else{
				// if (dp_matrix[i-1][j] == true){
				// 	dp_matrix[i][j] == true;
				// }
				// // else if(arr[i-1] = j) {
				// // 	dp_matrix[i][j] = true;
				// // }
				// else{
				// 	dp_matrix[i][j] = dp_matrix[i-1][j-arr[i-1]];
				// }
				dp_matrix[i][j] = dp_matrix[i-1][j]||dp_matrix[i-1][j-arr[i-1]];
			}
		}
	}
	for(int i = 0; i <= n; i++){
		for (int j = 0; j <= T; ++j){
			cout << dp_matrix[i][j] << " ";
		}
		cout << endl;
	}

	set<int> s;
	int j = T;
	for (int i = n; i >0 ; --i){
		if (dp_matrix[i][j] != dp_matrix[i-1][j]){
			s.insert(i-1);
			j = j-arr[i-1];
		}
	}

	pair<bool, set<int> > x;
	x.first = dp_matrix[n][T];
	x.second = s;

	return x;
}

int main(){

	int arr[5] = {2, 3, 7, 8, 10};
	int T = 11;
	int n = sizeof(arr)/sizeof(int);

	pair<bool, set<int> > x = get_subset(arr, n, T);

	if (x.first){
		cout << "Toatal of " << T << " is possible by adding numbers ";
		for (set<int>::iterator i = x.second.begin(); i != x.second.end(); ++i){
			cout << arr[*i] << " ";
		}
	}
		

    return 0;
}