#include<iostream>
#include<cstdio>
using namespace std;

//2018.08.02
//자료구조 5639 이진 검색트리
struct Tree {
	int left = 0;
	int right = 0;
};
Tree tree[100001];

void postOrder(int);

int main() {
	int root,value;
	scanf("%d", &root);

	while ((scanf("%d", &value)) != EOF) {
		int node = root;
		while (1) {
			if (node < value) {
				if (tree[node].right != 0) {
					node = tree[node].right;
				}
				else {
					tree[node].right = value;
					break;
				}

			}
			else {
				if (tree[node].left != 0) {
					node = tree[node].left;
				}
				else {
					tree[node].left = value;
					break;
				}
			}
		}
	}
	postOrder(root);


	return 0;
}

void postOrder(int node) {
	if (tree[node].left != 0) {
		postOrder(tree[node].left);

	}
	if (tree[node].right != 0) {
		postOrder(tree[node].right);
	}
	printf("%d \n", node);
}