#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int A1() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while (k--) {
		int g;
		cin >> g;
		int i, istep;
		float fstep;
		for (istep = n / 2, i = n / 2, fstep = n / 2; i >= 0 && i < n && a[i] != g && istep; fstep /= 2, istep = round(fstep), i = (a[i] < g) ? i += istep : i -= istep);
		if (i < n && a[i] == g)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 90;
}