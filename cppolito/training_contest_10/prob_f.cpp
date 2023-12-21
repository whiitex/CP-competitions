#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e8+1;

int check(int unsigned arr[], int n, int pos, int val) {
    int need = 0;
    while (pos < n and val > arr[pos]) {
        if (pos == n-1 and val > arr[pos]) need = MAXN;
        else need += val - arr[pos];
        --val;
        ++pos;
    }
    return need;
}


void solve(){
    int unsigned n, k;
    cin >> n >> k;
    int unsigned arr[n];
    for (int unsigned i=0; i<n; i++)
        cin >> arr[i];

    int best = 0;
    for (int i=0; i<n; ++i) {
        int l=1, r=2*MAXN;
        while (l<r) {
            int mid = l+r+1 >> 1;
            int need = check(arr, n, i, mid);
            if (need > k) r = mid-1;
            else l = mid;
        }
        best = max(best, l);
    }

    cout << best << '\n';
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int unsigned t;
    cin >> t;
    while (t--) {
        solve();
    }
}



/* NOOB TLE
 *
void solve() {
    int unsigned n, k;
    cin >> n >> k;
    int unsigned arr[n];
    for (int unsigned i=0; i<n; i++)
        cin >> arr[i];

    int index = n-1;
    int unsigned actual = arr[n-1];
    for (int i=n-2; i>=0; i--) {
        actual = actual + 1;
        if (arr[i] > actual) {
        actual = arr[i];
        index = i;
        }
    }

    // building max possible vector
    int unsigned arr_max[index+1];
    arr_max[index] = arr[index];
    for (int i = index-1; i>=0; i--) {
        if (arr[i] <= arr_max[i+1])
        arr_max[i] = arr_max[i+1] + 1;
        else arr_max[i] = arr[i];
    }

    // sum values in given array
    int unsigned sum = 0;
    for (int unsigned i=0; i<index+1; i++)
    sum += arr[i];


    int unsigned solution[index+1];
    for (int unsigned i=0; i<index+1; i++) {
    bool flag = true;


    while(flag) {
    int unsigned bigger[index+1];
    int unsigned count=0, j=0, my_max=arr_max[i];

    while(j<i) {
        bigger[j] = arr[j];
        j++;
    }

    while(j<index) {
    bigger[j++] = my_max - count;
    count++;
    }
    bigger[index] = arr[index];

    int unsigned big_sum = 0;
    for (size_t x=0; x<index+1; x++)
    big_sum += bigger[x];

    if (big_sum - sum <= k) {
        solution[i] = my_max;
        flag = false;
    } else {
        arr_max[i]--;
        if (arr_max[i] == arr[i]){
            flag = false;
            solution[i] = arr[i];
        }
    }


    }
    }

    int unsigned sol = 0;
    for (int unsigned x=0; x<index+1; x++)
        if (solution[x] > sol)
            sol = solution[x];

    cout << sol << '\n';
}
*/

//---------------------------------------------------------------------

/* TIME LIMIT EXCEEDED
 *
int update_arr_cp(int arr_cp[], int i, int n) {
    if (i>=n-1) return -1;
    else if (arr_cp[i] > arr_cp[i+1])
        return update_arr_cp(arr_cp, i+1, n);
    else return i;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];


    int index = n-1;
    int actual = arr[n-1];
    for (int i=n-2; i>=0; i--){
        actual = actual + 1;
        if (arr[i] > actual) {
            actual = arr[i];
            index = i;
        }
    }

    int solution[index+1];

    // filling solution[] vector
    for (int i=0; i<index+1; i++) {

        if (i == index)
            solution[i] = arr[i];
        else {

            int arr_cp[index+1];
            for (int q=0; q<index+1; q++)
                arr_cp[q] = arr[q];

            int limit = k;

            // speeding up
            int to_subtract;
            if (i < index) {
                if (arr_cp[i] < arr_cp[i+1]) {
                    to_subtract = arr_cp[i+1] - arr_cp[i] + 1;
                    if (to_subtract <= limit) {
                        arr_cp[i] += to_subtract;
                        limit -= to_subtract;
                    }
                }
            }

            // building solution array
            while (limit>0) {
                int pos_to_update = update_arr_cp(arr_cp, i, index+1);
                if (pos_to_update == -1) {
                    limit = -1;
                } else {
                    arr_cp[pos_to_update]++;
                    limit--;
                }
            }
            solution[i] = arr_cp[i];

        }

    }


    // providing solution
    int sol = 0;
    for (int i=0; i<index+1; i++)
        if (solution[i] > sol)
            sol = solution[i];

    cout << sol << '\n';
}
*/

//---------------------------------------------------------------------
