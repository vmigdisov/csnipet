#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tree_node {
	int val;
	struct tree_node *left, *right;
};

enum { ITERACTION, RECURSION };
enum { PREORDER, INORDER, POSTORDER };

int *traverse(int, int, struct tree_node *, int *);

int main(int argc, char *argv[]) {
	int order = -1;
	if (argc > 1) {
		if (!strcmp(argv[1], "preorder")) order = PREORDER;
		else if (!strcmp(argv[1], "inorder")) order = INORDER;
		else if (!strcmp(argv[1], "postorder")) order = POSTORDER;
	}
	if (argc < 2 || order == -1) {
		printf("usage: %s order (preorder, inorder, postorder) [-r recursive]\n", argv[0]);
		return 1;
	}
	int method = argc > 2 && !strcmp(argv[2], "-r") ? RECURSION : ITERACTION;
	int size;
	struct tree_node left = { 3, 0, 0 };
	struct tree_node right = { 2, &left, 0 };
	struct tree_node root = { 1, 0, &right };
	int *result = traverse(order, method, &root, &size);
	for (int i = 0; i < size ; i++) printf("%d ", result[i]);
	printf("\n");
	return 0;
}

void recursion(int order, struct tree_node *node, int *size, int *arr) {
	if (node) {
		if (order == PREORDER) arr[(*size)++] = node->val;
		recursion(order, node->left, size, arr);
		if (order == INORDER) arr[(*size)++] = node->val;
		recursion(order, node->right, size, arr);
		if (order == POSTORDER) arr[(*size)++] = node->val;
	}
}

int *traverse(int order, int method, struct tree_node *root, int *size) {
	*size = 0;
	if (!root) return 0;
	int arr[100];
	if (method == ITERACTION) {
		struct tree_node *stack[100];
		int index = 0;
		if (order == PREORDER) {
			stack[index] = root;
			while (index >=0 ) {
				struct tree_node *node = stack[index--];
				arr[(*size)++] = node->val;
				if (node->right) stack[++index] = node->right;
				if (node->left) stack[++index] = node->left;
			}
		} else if (order == INORDER) {
			struct tree_node *node = root;
			while (index > 0 || node) {
				while (node) {
					stack[index++] = node;
					node = node->left;
				}
				node = stack[--index];
				arr[(*size)++] = node->val;
				node = node->right;
			}
		} else if (order == POSTORDER) {
			printf("POSTORDER\n");
			return 0;
		}
	} else if (method == RECURSION) {
		recursion(order, root, size, arr);
	}
	int *result = malloc(*size * sizeof *result);
	for (int i = 0; i < *size; i++) result[i] = arr[i];
	return result;
}

