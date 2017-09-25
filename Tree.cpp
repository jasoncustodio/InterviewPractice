#include "DataStructure.h"

/*
	Path from root to leaf with a given sum
*/

//bool hasPathWithGivenSum(Tree<int>* t, int s) {
//	if (!t)
//		return s == 0;
//	s -= t->value;
//	return hasPathWithGivenSum(t->left, s) || hasPathWithGivenSum(t->right, s);
//}

bool TreePractice::hasPathWithGivenSum(Tree<int> * t, int s)
{
	if (!t)
		return false;

	if(t->value == s && t->left == NULL && t->right == NULL)
		return true;

	return hasPathWithGivenSum(t->left, s - t->value) || hasPathWithGivenSum(t->right, s - t->value);
}

/*
	Mirror Image of a tree
*/

bool TreePractice::isTreeSymmetric(Tree<int> * t1, Tree<int> * t2)
{
	if (!t1 && !t2)
		return true;

	if (!t1 || !t2)
		return false;

	return (t1->value == t2->value) && isTreeSymmetric(t1->left, t2->right) && isTreeSymmetric(t1->right, t2->left);
}

bool TreePractice::isTreeSymmetric(Tree<int> * t)
{
	return isTreeSymmetric(t, t);
}

/*
	Use Tree Level Formula to find profession
*/

string TreePractice::findProfession(int level, int pos)
{
	// Base case
	if (level == 1)
		return "engineer";

	// Recursively find parent's profession. If parent
	// is a docter, this node will be a docter if it is
	// at odd position and an engineer if at even position
	if (findProfession(level - 1, (pos + 1) / 2) == "doctor")
		return (pos % 2) ? "doctor" : "enginner";

	// If parent is an engineer, then current node will be
	// an enginner if at add position and doctor if even
	// position.
	return (pos % 2) ? "engineer" : "doctor";
}



