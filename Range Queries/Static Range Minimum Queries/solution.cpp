#include <bits/stdc++.h>
#define ll long long
using namespace std;

void construct(vector<ll> &tree, vector<ll> &arr, int start, int end, int node) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    int mid = (start+end) >> 1;
    int leftNode = node << 1;
    int rightNode = leftNode + 1;
    construct(tree, arr, start, mid, leftNode);
    construct(tree, arr, mid+1, end, rightNode);

    tree[node] = min(tree[leftNode], tree[rightNode]);
}

int query(vector<ll> &tree, int start, int end, int l, int r, int node) {
    if (r < start || end < l) return INT_MAX;
    if (l <= start && end <= r) return tree[node];

    int mid = (start+end) >> 1;
    int leftNode = node << 1;
    int rightNode = leftNode + 1;

    int leftResult = query(tree, start, mid, l, r, leftNode);
    int rightResult = query(tree,  mid+1, end, l, r, rightNode);

    return  min(leftResult, rightResult);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, q, l, r;
    cin >> n >> q;
    
    vector<ll> arr(n), tree(4*n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    construct(tree, arr, 0, n-1, 1);

    while (q--) {
        cin >> l >> r;
        cout << query(tree, 0, n-1, l-1, r-1, 1) << '\n';
    }
    
    return 0;
}
