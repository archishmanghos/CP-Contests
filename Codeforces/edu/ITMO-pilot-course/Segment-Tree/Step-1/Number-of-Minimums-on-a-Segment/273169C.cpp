#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;
const int INF = 1e9;

struct Node {
	pair<int, int> data;
	Node *left, *right;
	Node(int val) {
		data.first = val;
		data.second = 1;
		left = right = NULL;
	}
};

class SegTree {
private:
	int n;
	Node* root;
	Node* buildTree(int l, int r, int &idx, vector<int> &a) {
		if (l == r) return new Node(a[idx++]);

		int mid = (l + r) / 2;
		Node *root = new Node(0);
		root->left = buildTree(l, mid, idx, a);
		root->right = buildTree(mid + 1, r, idx, a);
		if (root->left->data.first == root->right->data.first) {
			root->data.first = root->left->data.first;
			root->data.second = root->left->data.second + root->right->data.second;
		} else {
			if (root->left->data.first < root->right->data.first) root->data = root->left->data;
			else root->data = root->right->data;
		}

		return root;
	}

	void update(int l, int r, int idx, int val, Node* root) {
		if (idx < l or idx > r) return;
		if (l == r) {
			root->data.first = val;
			root->data.second = 1;
			return;
		}

		int mid = (l + r) / 2;
		if (idx <= mid) update(l, mid, idx, val, root->left);
		else update(mid + 1, r, idx, val, root->right);
		if (root->left->data.first == root->right->data.first) {
			root->data.first = root->left->data.first;
			root->data.second = root->left->data.second + root->right->data.second;
		} else {
			if (root->left->data.first < root->right->data.first) root->data = root->left->data;
			else root->data = root->right->data;
		}
	}

	pair<int, int> query(int l, int r, int L, int R, Node *root) {
		if (l >= L and r <= R) return root->data;
		if (r < L or l > R) return {INF, 0};

		int mid = (l + r) / 2;
		pair<int, int> leftQ = query(l, mid, L, R, root->left);
		pair<int, int> rightQ = query(mid + 1, r, L, R, root->right);
		if (leftQ.first == rightQ.first) {
			return {leftQ.first, leftQ.second + rightQ.second};
		} else {
			if (leftQ.first < rightQ.first) return leftQ;
			return rightQ;
		}
	}

public:
	void build(vector<int> &a) {
		int idx = 0;
		n = a.size();
		root = buildTree(0, n - 1, idx, a);
	}

	void update(int idx, int value) {
		update(0, n - 1, idx, value, root);
	}

	pair<int, int> query(int l, int r) {
		return query(0, n - 1, l, r, root);
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	SegTree st;
	st.build(A);

	while (M--) {
		int type; cin >> type;
		if (type == 1) {
			int idx, val;
			cin >> idx >> val;
			st.update(idx, val);
		} else {
			int l, r; cin >> l >> r;
			pair<int, int> answer = st.query(l, r - 1);
			cout << answer.first << ' ' << answer.second << '\n';
		}
	}
	return 0;
}