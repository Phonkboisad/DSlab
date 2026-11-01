#include <bits/stdc++.h>
using namespace std;
 
 
//#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
 
 
 
/*void bubblesort(vector<int>&arr){
    int n= arr.size();
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped= true;
            }
        }
        if(!swapped)break;
 
    }
} */
bool binsearch(const vector<int>&arr, int x){
    int l= 0, r = arr.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid]==x) return true;
        else if(arr[mid]<x)l=mid +1;
        else r = mid -1;
    }
    return false;
}
int main() {
 
    int n, q;
    cin >> n>>q;
    vector<int >arr(n);
    for(auto &i:arr){cin >> i;}
       sort(all(arr));
    while(q--){
        int num;
        cin >> num;
        if(binsearch(arr,num))cout <<"found\n";
        else cout << "not found\n";
    }
    return 0;
