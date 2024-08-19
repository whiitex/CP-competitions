class Solution {
public:
	long long minimumOperations(vector<int>& vec, vector<int>& target) {
		int n = vec.size();
		vector<int> opp(n), opm(n);
		for (int i=0; i<n; ++i) {
			if (target[i] > vec[i]) {
				opp[i] = target[i] - vec[i];
				opm[i] = 0;
			} else if (target[i] < vec[i]) {
				opm[i] = vec[i] - target[i];
				opp[i] = 0;
			} else {
				opm[i] = 0;
				opp[i] = 0;
			}
		}

		long long ans = 0;

		opp.push_back(0);
		stack<int> stp; stp.push(0);
		for (int i=0; i<n+1; ++i) {
			if (opp[i] < stp.top()) {
				int mx = 0;
				while (!stp.empty() and stp.top() > opp[i]) {
					mx = max(mx, stp.top());
					stp.pop();
				}
				ans += mx - opp[i];
			}
			stp.push(opp[i]);
		}

		opm.push_back(0);
		stack<int> stm; stm.push(0);
		for (int i=0; i<n+1; ++i) {
			if (opm[i] < stm.top()) {
				int mx = 0;
				while (!stm.empty() and stm.top() > opm[i]) {
					mx = max(mx, stm.top());
					stm.pop();
				}
				ans += mx - opm[i];
			}
			stm.push(opm[i]);
		}

		return ans;
	}
};
