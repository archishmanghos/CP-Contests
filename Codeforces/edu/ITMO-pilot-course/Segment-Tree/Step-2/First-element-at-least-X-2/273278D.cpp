#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
	Node *left, *right;
	int val;
	Node() {
		left = right = NULL;
		val = 0;
	}
};

class SegTree {
	Node *root;
	int n;
	Node* build(int l, int r, int n, vector<int> &a) {
		Node *node = new Node();
		if (l == r) {
			node->val = a[l];
			return node;
		}

		int mid = l + (r - l) / 2;
		node->left = build(l, mid, n, a);
		node->right = build(mid + 1, r, n, a);

		node->val = max(node->left->val, node->right->val);
		return node;
	}

	void update(Node *node, int l, int r, int idx, int data) {
		if (!node or idx < l or idx > r) return;
		if (l == r and l == idx) {
			node->val = data;
			return;
		}

		int mid = l + (r - l) / 2;
		update(node->left, l, mid, idx, data);
		update(node->right, mid + 1, r, idx, data);

		node->val = max(node->left->val, node->right->val);
	}

	int query(Node *node, int l, int r, int x, int lx) {
		if (r < lx or node->val < x) return -1;
		if (l == r) return l;

		int mid = l + (r - l) / 2;
		int leftVal = query(node->left, l, mid, x, lx);
		if (leftVal != -1) return leftVal;
		int rightVal = query(node->right, mid + 1, r, x, lx);

		return rightVal;
	}
public:
	void build(vector<int> &a) {
		n = a.size();
		root = build(0, n - 1, n, a);
	}

	void update(int idx, int data) {
		update(root, 0, n - 1, idx, data);
	}

	int query(int x, int l) {
		return query(root, 0, n - 1, x, l);
	}

	int getMax() {
		return root->val;
	}
};

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	SegTree st;
	int N, M; cin >> N >> M;
	vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
	st.build(A);

	while (M--) {
		int type; cin >> type;
		if (type == 1) {
			int idx, val; cin >> idx >> val;
			st.update(idx, val);
		} else {
			int x, l; cin >> x >> l;
			cout << st.query(x, l) << '\n';
		}
	}

	return 0;
}