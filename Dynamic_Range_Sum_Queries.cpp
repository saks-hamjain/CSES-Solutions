#include<bits/stdc++.h>
using namespace std;

class Fenwick {
public:
    long long  N;
    vector<long long > arr;
    vector<long long> Tree;
    Fenwick(long long n,vector<long long> array) {
        N = n;
        arr = array;
        Tree.resize(n+1,0);
        Build();
    }
    void Build()
    {
        for (long long i=1;i<=N;i++) {
            Tree[i] += arr[i-1];
            if ((i+(i&(-i))) <= N) {
                Tree[i+(i&(-i))] += Tree[i];
            }
        }
    }
    long long Sum(long long idx) {
        long long  runningsum =0;
        while (idx >0) {
            runningsum += Tree[idx];
            long long rbit = idx & (-idx);
            idx -= rbit;
        }
        return runningsum;
    }
    long long  RangeQuery(int l, int r) {
        return Sum(r)-Sum(l-1);
    }
    void Update(long long  idx ,long long val) {
        arr[idx -1] += val;
        while (idx <= N) {
            Tree[idx] += val;
            long long  rbit = idx & (-idx);
            idx += rbit;
        }
    }
};
int main()
{
    long long  n,q;
    cin>>n>>q;
    vector<long long> arr(n,0);
    for(int i=0;i<n;i++)
    cin>>arr[i];

    Fenwick f(n,arr);
    for (int i=0;i<q;i++) {
        long long ty,first,sec;
        cin>>ty>>first>>sec;
        if (ty == 2) {
            cout<<f.RangeQuery(first,sec)<<endl;
        }
        else {
            long long  dif = sec - arr[first -1];
            arr[first -1] += dif;
            f.Update(first,dif);
        }
    }

    return 0;
}