/*
* @Author: sherlock
* @Date:   2017-08-05 17:27:30
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-06 18:00:37
*/

#include <iostream>
#include <map>
#include <set>

using namespace std;

struct item
{
	int weight;
	int value;
	char name;
};

int max(int x, int y){return x>y?x:y;}

pair<int , set<char> > knapsack(int W, item items[], int n){
	int dp_matrix[n+1][W+1];

	for ( int i = 0; i <= n; ++i){
		for ( int j = 0; j<= W; ++j){
			if (i == 0 || j == 0){
				dp_matrix[i][j] = 0; 
			}
			else if (items[i-1].weight <= j){
				dp_matrix[i][j] = max(items[i-1].value + dp_matrix[i-1][j-items[i-1].weight], dp_matrix[i-1][j]);
				
			}
			else{
				dp_matrix[i][j] = dp_matrix[i-1][j];
			}
		}
	}
	for ( int i = 0; i <= n; i++){
		for ( int j = 0; j<=W; j++)
			cout << dp_matrix[i][j] << ' ';
		cout << endl;
	}

	set<char> knapsack_items;
	
	pair<int , set<char> > x;
	x.first =  dp_matrix[n][W];
	int j = W;
	for(int i = n; i > 0; i--){
		if (dp_matrix[i][j] != dp_matrix[i-1][j]){
			knapsack_items.insert(items[i-1].name);
			j = j - items[i-1].weight;
		}
	}


	x.second = knapsack_items;
	return x;
}

item get_item(int weight, int value, char name){
	item _;
	_.weight = weight;
	_.value = value;
	_.name = name;
	return _;
}

int main(){
	item items [4];
	items [0] = get_item(1, 1, 'a');
	items [1] = get_item(3, 4, 'b');
	items [2] = get_item(4, 5, 'c');
	items [3] = get_item(5, 7, 'd');

	pair<int , set<char> > ans = knapsack(7, items, 4);

	cout << "Max value of knapsack is " << ans.first;
	cout << " and the items included in the knapsack are ";
	for (set<char>::iterator i = (ans.second).begin(); i != (ans.second).end(); ++i){
		cout << *i << ", ";
	}

    return 0;
}