#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 10;

struct Event {
	int x, y1, y2;
	bool isleft;
};

struct Node {
	int cnt, len, tot;
};

Event e[N*2];
Node sgt[N*8];

bool cmp(const Event& a, const Event& b) {
	return a.x < b.x;
}

void build(int index, int begin, int end) {
	sgt[index].tot = end - begin + 1;
	if (begin >= end) return;
	int mid = (begin + end) / 2;
	build(index * 2, begin, mid);
	build(index * 2 + 1, mid + 1, end);
}

void push_up(int index) {
	if (sgt[index].cnt > 0) sgt[index].len = sgt[index].tot;
	else sgt[index].len = sgt[index*2].len + sgt[index*2+1].len;
}

void update(int index, int begin, int end, int left, int right, int val) {
	if (left <= begin && right >= end) {
		sgt[index].cnt += val;
		push_up(index);
		return;
	}
	int mid = (begin + end) / 2;
	if (right <= mid) update(index * 2, begin, mid, left, right, val);
	else if (left > mid) update(index * 2 + 1, mid + 1, end, left, right, val);
	else {
		update(index * 2, begin, mid, left, mid, val);
		update(index * 2 + 1, mid + 1, end, mid + 1, right, val);
	}
	push_up(index);
}

int main() {
	long long res = 0;
	int n, m = 0, t = 0, x1, y1, x2, y2;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (y1 == y2) continue;
		e[t] = {x1, y1, y2, true};
		e[t+1] = {x2, y1, y2, false};
		m = max(m, y2);
		t += 2;
	}
	build(1, 0, m - 1);
	sort(e, e + t, cmp);
	update(1, 0, m - 1, e[0].y1, e[0].y2 - 1, 1);
	for (int i=1; i<t; i++) {
		res += 1LL * (e[i].x - e[i-1].x) * sgt[1].len;
		if (e[i].isleft) update(1, 0, m - 1, e[i].y1, e[i].y2 - 1, 1);
		else update(1, 0, m - 1, e[i].y1, e[i].y2 - 1, -1);
	}
	printf("%lld\n", res);
	return 0;
}