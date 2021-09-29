#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<bool> primes(N,true);
vector<int> prfx(N,0);

void sieve() {
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if(primes[i]) {
            for (int j = 2*i; j <= N; j += i){
                primes[j] = false;
            }
        }
    } 
    for (int i = 2; i < N; i++) {
        if (primes[i]){
            string k = to_string(i);
            int n = k.size(),flag = 0, div = 10;
            for (int j = 0; j < n; j++){
                if( k[j] == '0' || primes[i % div] == false ){
                    flag++;
                    break;
                }
                div *= 10;
            }
            prfx[i] = (flag == 0) ? 1 : 0;
        }
         prfx[i] += prfx[i - 1];
    }
    
}


int main() {
    //using fast io
    int t;
    scanf("%d",&t);
    sieve();
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",prfx[n]);
    }
   
}
