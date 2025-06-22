#include<bits/stdc++.h>
using namespace std;

struct Node{
    long long totalSum,prefix,suffix,maxSum;
    Node(long long val = 0) {
        totalSum = val;
        prefix = suffix = maxSum = max(0LL,val);
    }

};
Node merge(Node left,Node right) {
    Node parent;
    parent.totalSum = left.totalSum + right.totalSum;
    parent.prefix = max(left.prefix,left.totalSum + right.prefix);
    parent.suffix = max(right.suffix,right.totalSum + left.suffix);
    parent.maxSum = max({left.maxSum,right.maxSum,left.suffix + right.prefix});
    return parent;
}
class Segment {
    public:
    int n;
    vector<Node> tree;
    vector<long long> arr;
    Segment(int val,vector<long long> a) {
        n = val;
        tree.resize(n*4);
        arr = a;
        build(0,0,n-1);
    }
   void build(int idx,int l,int r)
    {
         if (l==r) {
             tree[idx] = Node(arr[l]);
             return;
         }
        int mid = (l+r)/2;
        build(idx*2+1,l,mid);
        build(idx*2+2,mid+1,r);
        tree[idx] = merge(tree[2*idx+1],tree[2*idx+2]);
    }

    void update(int idx,int l,int r,int pos,long long val) {
        if (l == r) {
            tree[idx] = Node(val);
            return;
        }
        int mid = (l+r)/2;
        if (pos <= mid)
            update(idx*2+1,l,mid,pos,val);
        else
            update(idx*2+2,mid+1,r,pos,val);

        tree[idx] = merge(tree[2*idx+1],tree[2*idx+2]);
    }
};

int main()
{
     int n,q;
     cin>>n>>q;
     vector<long long > arr(n,0);
     for(int i=0;i<n;i++)
          cin>>arr[i];

      Segment seg(n,arr);
    for (int i=0;i<q;i++) {
        int idx;
        long long val;
        cin>>idx>>val;
        seg.update(0,0,n-1,idx-1,val);
        cout<<seg.tree[0].maxSum<<endl;
    }
    return 0;
}