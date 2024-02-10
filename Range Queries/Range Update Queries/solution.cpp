#include <bits/stdc++.h>

#define ll long long
using namespace std;

/*
 * Solving with range-update and range query with lazy propogation.
 * */

void construct(vector<ll> &tree, vector<ll> &arr, int start, int end, int node) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) >> 1;
    int leftNode = node << 1;
    int rightNode = leftNode + 1;

    construct(tree, arr, start, mid, leftNode);
    construct(tree, arr, mid + 1, end, rightNode);

    tree[node] = tree[leftNode] + tree[rightNode];
}

void updateRange(vector<ll> &tree, vector<ll> &arr, int start, int end, int l, int r, int value,
                 int node) {
    if (start > end || r < start || l > end) return;
    if (start == end) {
        tree[node] += value;
        return;
    }

    int mid = (start + end) >> 1;
    int leftNode = node << 1;
    int rightNode = leftNode + 1;

    updateRange(tree, arr, start, mid, l, r, value, leftNode);
    updateRange(tree, arr, mid+1, end, l, r, value, rightNode);

    tree[node] = tree[leftNode] + tree[rightNode];

}

void updateRangeLP(vector<ll> &tree, vector<ll> &lazy, vector<ll> &arr, int start, int end, int l, int r, int value,
                 int node) {
    // begin lazy
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        // transfer laziness to subtree if exits.
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    // done

    if (start > end || r < start || l > end) return;
    if (l <= start && end <= r) {
        tree[node] += (end-start+1)*value;
        if (start != end) {
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }
        return;
    }

    int mid = (start + end) >> 1;
    int leftNode = node << 1;
    int rightNode = leftNode + 1;

    updateRangeLP(tree, lazy, arr, start, mid, l, r, value, leftNode);
    updateRangeLP(tree, lazy, arr, mid+1, end, l, r, value, rightNode);

    tree[node] = tree[leftNode] + tree[rightNode];

}

ll query(vector<ll> &tree, vector<ll> &arr, int start, int end, int pos, int node) {
    if (start == end) return tree[node];
    int mid = (start + end) >> 1;
    int leftNode = node << 1;
    int rightNode = leftNode + 1;

    if (pos <= mid) {
        return query(tree, arr, start, mid, pos, leftNode);
    } else {
        return query(tree, arr, mid+1, end, pos, rightNode);
    }
}

ll queryRangeLP(vector<ll> &tree, vector<ll> &lazy, vector<ll> &arr, int start, int end, int l, int r, int node) {
    if (start > end || r < start || l > end) return 0;
    // begin lazy
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        // transfer laziness to subtree if exits.
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    // done

    if (l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start + end) >> 1;
    int leftNode = node << 1;
    int rightNode = leftNode + 1;
    ll leftResult = queryRangeLP(tree, lazy, arr, start, mid, l, r, leftNode);
    ll rightResult = queryRangeLP(tree, lazy, arr, mid+1, end, l, r, rightNode);

    return leftResult+rightResult;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n), tree(4 * n), lazy(4 * n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    construct(tree, arr, 0, n-1, 1);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, value;
            cin >> l >> r >> value;
            updateRangeLP(tree, lazy, arr, 0, n - 1, l - 1, r - 1, value, 1);
        } else {
            int pos; cin >> pos;
            cout << queryRangeLP(tree, lazy, arr, 0, n-1, pos-1, pos-1, 1) << endl;
        }

    }
    return 0;
}
