#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct conf {
	int start;
	int end;
}conf;

int compare(const conf* a, const conf* b) {
	if (a->end != b->end) {
		if (a->end < b->end) {
			return -1;
		}
		else if (a->end == b->end) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else{
		if (a->start < b->start) {
			return -1;
		}
		else if (a->start == b->start) {
			return 0;
		}
		else {
			return 1;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	conf* c = (conf*)calloc(n, sizeof(conf));

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c[i].start, &c[i].end);
	}

	qsort(c, n, sizeof(conf), compare);

	int time = c[0].end;
	int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (time <= c[i].start) {
			cnt++;
			time = c[i].end;
		}
	}

	printf("%d", cnt);

	return 0;
}