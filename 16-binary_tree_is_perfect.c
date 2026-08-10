#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_h = 1 + tree_height(tree->left);

	if (tree->right != NULL)
		right_h = 1 + tree_height(tree->right);

	if (left_h > right_h)
		return (left_h);

	return (right_h);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 if not or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	if (tree_height(tree->left) == tree_height(tree->right))
	{
		if (binary_tree_is_perfect(tree->left) &&
		    binary_tree_is_perfect(tree->right))
			return (1);
	}

	return (0);
}
