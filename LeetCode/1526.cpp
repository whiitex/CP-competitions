class Solution {
public:
	int minNumberOperations(vector<int>& vec) {
		int n = vec.size(), ans = vec[0];

		for (int i=0; i<n-1; ++i) {
			if (vec[i] < vec[i+1]) ans += vec[i+1] - vec[i];
		}

		return ans;
	}
};