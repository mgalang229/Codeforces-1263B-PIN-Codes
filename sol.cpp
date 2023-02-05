#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int n;
	cin >> n;
	string p[n];
	multiset<string> ms;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		ms.insert(p[i]);
	}
	int cnt = 0;
	string res[n];
	for (int i = 0; i < n; i++) {
		if (ms.count(p[i]) > 1) {
			string cur = p[i];
			bool ok = false;
			for (int j = 0; j < 4; j++) {
				string temp = "";
				for (int k = 0; k < 10; k++) {
					temp = cur;
					temp[j] = char('0' + k);
					if (ms.count(temp) == 0) {
						cnt++;
						ok = true;
						break;
					}
				}
				cur = temp;
				if (ok) {
					break;
				}
			}
			ms.erase(ms.find(p[i]));
			ms.insert(cur);
			p[i] = cur;
		}
		res[i] = p[i];
	}
	cout << cnt << "\n";
	for (string& x : res) {
		cout << x << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
