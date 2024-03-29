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

    tree[node] = tree[leftNode] + tree[rightNode];
}

void update(vector<ll> &tree, vector<ll> &arr, int start, int end, int pos, int value, int node) {
    if (start == end) {
        tree[node] = value;
        arr[pos] = value;
    } else {
        int mid = (start+end) >> 1;
        int leftNode = node << 1;
        int rightNode = leftNode + 1;

        if (start <= pos && pos <= mid) {
            update(tree, arr, start, mid, pos, value, leftNode);
        } else {
            update(tree, arr, mid+1, end, pos, value, rightNode);
        }


        tree[node] = tree[leftNode] + tree[rightNode];
    }
}

ll query(vector<ll> &tree, vector<ll> &arr, int start, int end, int l, int r, int node) {
    if (r < start || end < l) return 0;

    if (l <= start && end <= r) return tree[node];

    int mid = (start+end) >> 1;
    int leftNode = node << 1;
    int rightNode = leftNode + 1;

    ll leftResult = query(tree, arr, start, mid, l, r, leftNode);
    ll rightResult = query(tree, arr, mid+1, end, l, r, rightNode);

    return leftResult + rightResult;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, op, l, r, pos, value;
    cin >> n >> q;

    vector<ll> arr(n), tree(4*n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    construct(tree, arr, 0, n-1, 1);

    while (q--) {
        cin >> op ;
        if (op == 1) {
            cin >> pos >> value;
            update(tree, arr, 0, n-1, pos-1, value, 1);
        }
        else {
            cin >> l >> r;
            cout << query(tree, arr, 0, n-1, l-1, r-1, 1) << '\n';
        }
    }
    return 0;
}
