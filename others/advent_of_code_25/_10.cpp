#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();

typedef double T; // long double, Rational, double + mod<P>...
typedef vector<T> vd;
typedef vector<vd> vvd;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const T eps = 1e-8, inf = 1/.0;
#define MP make_pair
#define ltj(X) if(s == -1 || MP(X[j],N[j]) < MP(X[s],N[s])) s=j

struct LPSolver {
	int m, n;
	vector<int> N, B;
	vvd D;

	LPSolver(const vvd& A, const vd& b, const vd& c) :
		m(sz(b)), n(sz(c)), N(n+1), B(m), D(m+2, vd(n+2)) {
		rep(i,0,m) rep(j,0,n) D[i][j] = A[i][j];
		rep(i,0,m) { B[i] = n+i; D[i][n] = -1; D[i][n+1] = b[i];}
		rep(j,0,n) { N[j] = j; D[m][j] = -c[j]; }
		N[n] = -1; D[m+1][n] = 1;
	}

	void pivot(int r, int s) {
		T *a = D[r].data(), inv = 1 / a[s];
		rep(i,0,m+2) if (i != r && abs(D[i][s]) > eps) {
			T *b = D[i].data(), inv2 = b[s] * inv;
			rep(j,0,n+2) b[j] -= a[j] * inv2;
			b[s] = a[s] * inv2;
		}
		rep(j,0,n+2) if (j != s) D[r][j] *= inv;
		rep(i,0,m+2) if (i != r) D[i][s] *= -inv;
		D[r][s] = inv;
		swap(B[r], N[s]);
	}

	bool simplex(int phase) {
		int x = m + phase - 1;
		for (;;) {
			int s = -1;
			rep(j,0,n+1) if (N[j] != -phase) ltj(D[x]);
			if (D[x][s] >= -eps) return true;
			int r = -1;
			rep(i,0,m) {
				if (D[i][s] <= eps) continue;
				if (r == -1 || MP(D[i][n+1] / D[i][s], B[i])
							 < MP(D[r][n+1] / D[r][s], B[r])) r = i;
			}
			if (r == -1) return false;
			pivot(r, s);
		}
	}

	T solve(vd &x) {
		int r = 0;
		rep(i,1,m) if (D[i][n+1] < D[r][n+1]) r = i;
		if (D[r][n+1] < -eps) {
			pivot(r, n);
			if (!simplex(2) || D[m+1][n+1] < -eps) return -inf;
			rep(i,0,m) if (B[i] == -1) {
				int s = 0;
				rep(j,1,n+1) ltj(D[i]);
				pivot(i, s);
			}
		}
		bool ok = simplex(1); x = vd(n);
		rep(i,0,m) if (B[i] < n) x[B[i]] = D[i][n+1];
		return ok ? D[m][n+1] : inf;
	}
};

static const T INF = 1e100;

struct ILPSolver {
	int n;
	vd c;
	T best;
	vd bestx;

	ILPSolver(int n_, const vd& c_) : n(n_), c(c_), best(-INF), bestx(n_, 0) {}

	void add_leq_constraint(vvd &A, vd &b, const vd &row, T rhs) {
		A.push_back(row);
		b.push_back(rhs);
	}

	bool is_int(T v) {
		return fabsl(v - llround(v)) <= 1e-9;
	}

	void dfs(const vvd &A0, const vd &b0) {
		vd x;
		T val = LPSolver(A0, b0, c).solve(x);
		if (val <= -INF/2) return;
		if (val >= INF/2) return;
		if (val <= best + 1e-9) return;

		int k = -1;
		for (int i = 0; i < n; i++) {
			if (!is_int(x[i])) { k = i; break; }
		}
		if (k == -1) {
			best = val;
			bestx = x;
			return;
		}

		T v = x[k];
		long long fl = (long long)floor(v + 1e-12);
		long long ce = (long long)ceil(v - 1e-12);

		{
			vvd A = A0;
			vd b = b0;
			vd row(n, 0);
			row[k] = 1;
			add_leq_constraint(A, b, row, (T)fl);
			dfs(A, b);
		}
		{
			vvd A = A0;
			vd b = b0;
			vd row(n, 0);
			row[k] = -1;
			add_leq_constraint(A, b, row, (T)(-ce));
			dfs(A, b);
		}
	}
};

vector<string> split(const string &s, const char _=' ') {
	vector<string> ans;
	int n = (int)s.size();
	for (int i=0; i<n; ++i) if (s[i] != _) {
		ans.emplace_back("");
		while (s[i] != _ and i < n) ans.back().push_back(s[i++]);
	}
	return ans;
}

void solve1(auto &goal, auto &buttons, auto &req, string &file) {

	int ans = 0;
	for (int i=0; i<(int)goal.size(); ++i) {

		int best = 1e9;
		vector<int> &r = req[i], &g = goal[i];
		vector<vector<int>> &b = buttons[i];

		int m = (int)g.size();
		for (int mask=0; mask<1<<(int)b.size(); ++mask) {

			int cnt = __builtin_popcount(mask);
			vector<int> result(m, 0);

			for (int bit=0; bit<(int)b.size(); ++bit) {
				if ((mask >> bit) & 1) {
					for (int pos: b[bit]) result[pos] ^= 1;
				}
			}

			int eq = 1;
			for (int j=0; j<m; ++j) if (g[j] != result[j]) eq = 0;
			if (eq) best = min(best, cnt);
		}

		ans += best;
	}

	cout << "part 1 - " << file << ": " << ans << endl;
}

void solve2(auto &goal, auto &buttons, auto &req, string &file) {

	int ans = 0;
	for (int idx=0; idx<(int)req.size(); ++idx) {

		auto &r = req[idx];
		auto &b = buttons[idx];

		int n = (int)b.size();
		int m = (int)r.size();

		vvd Aeq(m, vd(n, 0));
		for (int j = 0; j < n; ++j) {
			for (int ch : b[j]) {
				if (0 <= ch && ch < m) Aeq[ch][j] += 1;
			}
		}

		vd beq(m);
		for (int i = 0; i < m; ++i) beq[i] = (T)r[i];

		vvd A; A.reserve(2*m);
		vd bb; bb.reserve(2*m);

		for (int i = 0; i < m; ++i) {
			A.push_back(Aeq[i]);
			bb.push_back(beq[i]);
		}
		for (int i = 0; i < m; ++i) {
			vd row = Aeq[i];
			for (auto &v : row) v = -v;
			A.push_back(row);
			bb.push_back(-beq[i]);
		}

		vd c(n, -1);

		ILPSolver ilp(n, c);
		ilp.dfs(A, bb);

		for (int j = 0; j < n; ++j) ans += llround(ilp.bestx[j]);
	}

	cout << "part 2 - " << file << ": " << ans << endl;
}

void solve(ifstream &fin, string &file) {

	vector<vector<int>> req, goal;
	vector<vector<vector<int>>> buttons;

	string line; while (getline(fin, line)) {

		vector<string> splt = split(line);
		vector<int> v;
		for (int i=1; i<(int)splt[0].size()-1; ++i) {
			v.push_back(splt[0][i] == '#');
		}
		goal.push_back(v);

		vector<vector<int>> b;
		for (int i=1; i<(int)splt.size(); ++i) {
			string nums = splt[i].substr(1, splt[i].size() - 2);
			vector<int> curi;
			for (string &s: split(nums, ',')) curi.push_back(stoll(s));
			i < splt.size() - 1 ? b.push_back(curi) : req.push_back(curi);
		}
		buttons.push_back(b);
	}

	solve1(goal, buttons, req, file);
	solve2(goal, buttons, req, file);
}

signed main() {
	for (string file: {"test", "input"}) {
		ifstream fin(PATH + "/others/advent_of_code_25/" + file + ".txt");
		if (!fin) { cerr << "Error: Input file not found!"; return 1; }

		solve(fin, file);
		fin.close();
	}
}