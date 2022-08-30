class NumArray {
public:
	vector<int> tree;
	int n;

	void build(vector<int> &nums, int start, int end, int node) {
		if (start == end)
		{
			tree[node] =  nums[start];
			return;

		}

		int mid = (start + end) / 2;

		build(nums, start, mid, 2 * node);
		build(nums, mid + 1, end, 2 * node + 1);

		tree[node] = tree[2 * node] + tree[2 * node + 1];

	}

	int sum(int start, int end, int l, int r, int node) {
		if (start > r || end < l) return 0;

		if (start >= l && end <= r) return tree[node];
		int mid = (start + end) / 2;
		int ans1 = sum(start, mid, l, r, 2 * node);
		int ans2 = sum(mid + 1, end, l, r, 2 * node + 1);

		return ans1 + ans2;
	}

	void up(int node, int start, int end, int idx, int value) {
		if (start == end) {
			tree[node] = value;
			return;
		}
		int mid = (start + end) / 2;

		if (idx <= mid && start <= idx) up(2 * node, start, mid, idx, value);
		else
			up(2 * node + 1, mid + 1, end, idx, value);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}

	NumArray(vector<int>& nums) {
		n = nums.size();
		tree.resize(4 * n);
		build(nums, 0, n - 1, 1);

	}


	void update(int index, int val) {
		up(1, 0, n - 1, index, val);
	}


	int sumRange(int l, int r) {
		return sum(0, n - 1, l, r, 1);
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */