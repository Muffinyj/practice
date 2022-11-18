#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct deck {
	int heap[MAX_SIZE];
	int cnt;
}deck;

void nodeChange(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push(deck* root, int data) {
	if (root->cnt >= MAX_SIZE) return;

	root->heap[root->cnt] = data;

	int now = root->cnt;
	int parent = (root->cnt - 1) / 2;

	while (now > 0 && root->heap[now] < root->heap[parent]) {
		nodeChange(&root->heap[now], &root->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}

	root->cnt++;
}

int pop(deck* root) {
	if (root->cnt <= 0) return -1;

	int res = root->heap[0];
	root->cnt--;

	root->heap[0] = root->heap[root->cnt];

	int now = 0;
	int l = 1, r = 2;
	int target = 0;
	int tmp = 0;

	while (l < root->cnt) {
		if (root->heap[target] > root->heap[l]) target = l;

		if (root->heap[target] > root->heap[r] && r < root->cnt) target = r;

		if (target == now) break;
		else {
			tmp = root->heap[now];
			root->heap[now] = root->heap[target];
			root->heap[target] = tmp;

			now = target;

			l = now * 2 + 1;
			r = now * 2 + 2;
		}
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	deck card;

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		card.cnt = i;
		push(&card, tmp);
	}

	int card1 = 0;
	int card2 = 0;
	int res = 0;
	while(card.cnt > 1) {
		card1 = pop(&card);
		card2 = pop(&card);
		res = res + card1 + card2;
		push(&card, card1 + card2);
	}
	printf("%d", res);

	return 0;
}