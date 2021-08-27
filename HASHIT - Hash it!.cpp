#include<bits/stdc++.h>
using namespace std;

const int N=101;
string key[N+1];
vector<char> mark(N+1,'E');

int calculateHashValue(string s){
	int val = 0;
	for(int i = 0; i < s.length(); i++){
		val += (i+1) * int(s[i]);
	}
	return 19 * val;
}

int find(string s){
	int k1 = calculateHashValue(s) % N;
	for(int i = 0; i <= 19; i++){
		int k = (k1 + i*i + 23*i) % N;
    		if(key[k] == s and mark[k] == 'O'){
    			return k;
    		}
	}
	return -1;
}

int insert(string s){
	int k1 = calculateHashValue(s) % N;
    if (mark[k1] == 'E'){
    	mark[k1] = 'O';
    	key[k1] = s;
    	return k1;
    }
    else{
    	for(int i = 0; i <= 19; i++){
    		int k = (k1 + i*i + 23*i) % N;
    		if(key[k] == s and mark[k] == 'O'){
    			return -1;
    		}
    		if (mark[k] == 'E'){
		    	mark[k] = 'O';
		    	key[k] = s;
		    	return k;
		    }
    	}
    }
    return -1;
}

int size(){
	int cnt = 0;
	for(int i = 0;i < N+1; i++){
		cnt += mark[i] == 'O' ? 1 : 0;
	}
	return cnt;
}

void printHashTable(){
	for(int i = 0; i < N+1; i++){
		if(mark[i] == 'O'){
			cout << i << ":" << key[i] << "\n";
		}
	}
}

int main(){
	
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			string oper = s.substr(0,3);
			string str = s.substr(4);
			
			//cout << oper << str <<" ";
			if(oper == "ADD"){
				int val = insert(str);
			}
			else{				
				int re = find(str);
				//cout << re << " ";
				if(re != -1){
					mark[re] = 'E';
				}
			}
		}
		cout << size() << "\n";
		printHashTable();
		cout << "\n";
	}
	return 0;
}
		
