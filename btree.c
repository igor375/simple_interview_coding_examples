#include <stdio.h>
#include <stdlib.h>

struct tree_item {
	int v;
	struct tree_item *l;
	struct tree_item *r;
};

void tree_reverse(struct tree_item *h)
{
	if (h->l)
		tree_reverse(h->l);
	if (h->r)
		tree_reverse(h->r);

	void *tmp = h->l;
	h->l = h->r;
	h->r = tmp;
}

void tree_destroy(struct tree_item *h)
{
	if (h->l)
		tree_destroy(h->l);
	if (h->r)
		tree_destroy(h->r);
	free(h);
}

void tree_print(struct tree_item *h)
{
	printf("%d\n", h->v);
	if (h->l)
		tree_print(h->l);
	if (h->r)
		tree_print(h->r);
}

// simple, not balanced
void _tree_add(struct tree_item *h, struct tree_item *n)
{
	if (h->l && n->v <= h->v)
		_tree_add(h->l, n);
	else if (h->r && n->v > h->v)
		_tree_add(h->r, n);
	else if (!h->l && n->v <= h->v)
		h->l = n;
	else if (!h->r && n->v > h->v)
		h->r = n;
}

void tree_add(struct tree_item **h, int val) {
	struct tree_item *new_item = malloc(sizeof(struct tree_item));
	new_item->v = val;
	new_item->l = 0;
	new_item->r = 0;
	if (!(*h))
		*h = new_item;
	else
		_tree_add(*h, new_item);
}

int main(void)
{
	struct tree_item *h = 0;
	tree_add(&h, 5);
	tree_add(&h, 3);
	tree_add(&h, 8);
	tree_add(&h, 2);
	tree_add(&h, 4);
	tree_add(&h, 7);
	tree_add(&h, 10);
	printf("aaa1\n");

	tree_print(h);
	printf("aaa2\n");
	tree_reverse(h);
	printf("aaa3\n");
	tree_print(h);
	printf("aaa4\n");

	tree_destroy(h);
	printf("aaa5\n");
}
