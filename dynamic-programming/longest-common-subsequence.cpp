/*
* @Author: sherlock
* @Date:   2017-08-05 21:24:46
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-05 22:22:28
*/

#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int max(int x, int y){return x>y?x:y;}

pair<int, set<int> > longest_common_subsequence(char s1[], int s1_len, char s2[], int s2_len){
	int dp_matrix[s1_len][s2_len];

	for (int i = 0; i <=s1_len; ++i){
		for (int j = 0; j <= s2_len; ++j){
			if(i == 0 || j ==0){
				dp_matrix[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1]){
				dp_matrix[i][j] = dp_matrix[i-1][j-1] + 1;
			}
			else{
				dp_matrix[i][j] = max(dp_matrix[i-1][j], dp_matrix[i][j-1]);
			}
		}
	}

	for (int i = 0; i <= s1_len; ++i){
		for (int j = 0; j <= s2_len; ++j)
			cout << dp_matrix[i][j] << ' ';
		cout << endl;
	}

	int j = s2_len;
	set<int> s;
	for (int i = s1_len; i >= 0; --i){
		if(dp_matrix[i][j] !=dp_matrix[i-1][j] && dp_matrix[i][j] != dp_matrix[i][j-1]){
			s.insert(i);
			j--;
		}
		else if(dp_matrix[i][j] == dp_matrix[i][j-1]){
			while(dp_matrix[i][j] == dp_matrix[i][j-1]){
				j--;
			}
			if(dp_matrix[i][j] !=dp_matrix[i-1][j] && dp_matrix[i][j] != dp_matrix[i][j-1]){
				s.insert(i);
				j--;
			}
		}
	}
	
	pair<int, set<int> > x;
	x.first = dp_matrix[s1_len][s2_len];
	x.second = s;
	return x;
}

int main(){
	char s1[] = "acbcf";
	char s2[] = "abcdaf";
    pair<int, set<int> > x;
    x = longest_common_subsequence(s1, strlen(s1), s2, strlen(s2));

    cout << "The length of LCS is " <<  x.first << " and the LCS is ";
    for (set<int>::iterator i = (x.second).begin(); i != (x.second).end(); ++i){
    	cout << s1[*i - 1] << ' ';
    }
    return 0;
}