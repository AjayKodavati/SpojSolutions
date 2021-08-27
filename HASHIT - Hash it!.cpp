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
    		if(key[k] == s){
    			return k;
    		}
	}
	return -1;
}
bool insert(string s){
	int hash = calculateHashValue(s) % N;
	if(key[hash] == s){
		return false;
	}
	else{
		for(int j=1; j<=19; j++){
			int new_hash = (hash+(23*j)+(j*j))%101;
			if(key[new_hash] == s){
				return false;
			}
		}
	}

	if(mark[hash] == 'E'){
    mark[hash] = 'O';
		key[hash] = s;
		return true;
	}
	for(int j=1; j<=19; j++){
		int new_hash = (hash+(j*j)+(23*j))%101;
		//If new index is empty
		if(mark[new_hash] == 'E'){
      mark[new_hash] = 'O';
			key[new_hash] = s;
			return true;
		}
	}
	return false;
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
			
			
			if(oper == "ADD"){
				//Adding only non duplicate strings
				insert(str);
			}
			else{			
			    //first seraching for existance of string	
				int re = find(str);
			    //delete if string is present
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
		

