#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int inf = 1e18;
const int N = 1e5; 


int num_of_inversion;

void merge(vector<int> &arr, int l, int m, int r) {
    int i, j, k, nl, nr;
    nl = m - l + 1;
    nr = r - m;
    vector<int> larr(nl), rarr(nr);

    for(i = 0; i < nl; i++){
        larr[i] =  arr[l+i];
    }
    for(j = 0; j < nr; j++){
        rarr[j] =  arr[m+1+j];
    }
    
    i = 0; j = 0; k = l;
    while(i < nl && j < nr) {
        if(larr[i] < rarr[j]) {
             arr[k] = larr[i];
            i++;
        }else{
            num_of_inversion += nl - i;
             arr[k] = rarr[j];
            j++;
        }
        k++;
    }

    while(i < nl) {   
         arr[k] = larr[i];
        i++; k++;
    }

    while(j < nr) {  
         arr[k] = rarr[j];
        j++; k++;
    }

}


void mergesort(vector<int> &arr, int l, int r) {
    int m;
    if(l < r) {
        int m = l+(r-l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    mergesort(v, 0, n - 1);
    cout << num_of_inversion << '\n';
}