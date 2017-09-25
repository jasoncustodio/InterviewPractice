/*
Program: Blogs
Author:  Jason Custodio
Class:   CS163
Date:    01/23/2014
Description: Contains all structs and classes necessary for this program.
Two structs are used as nodes, each containing a class.
Class Blog will be a LLL using these nodes.
*/

#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

template<typename T>
struct ListNode
{
	ListNode(const T &v) : value(v), next(0) {}
	T value;
	ListNode *next;
};

template<typename T>
struct Tree 
{
	Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
	T value;
	Tree *left;
	Tree *right;
};

class StringPractice
{
	public:
		string reverseString(string s);
};

class Array
{
	public:
		int firstDuplicate(vector<int> a);
		char firstNotRepeatingCharacter(string s);
};

class LinkedList
{
	public:
		ListNode<int> * removeKFromList(ListNode<int> * l, int k);
		bool isListPalindrome(ListNode<int> * l);
		bool isListPalindrome2(ListNode<int> * head);
		ListNode<int> * reverseList(ListNode<int> * head);
		ListNode<int> * InsertTail(int length);
};

class HashTable
{
	public:
		vector<vector<string>> groupingDishes(vector<vector<string>> dishes);
		bool areFollowingPatterns(vector<string> strings, vector<string> patterns);
		bool containsCloseNums(vector<int> nums, int k);
		bool containsCloseNums2(vector<int> nums, int k);
};

class TreePractice
{
	public:
		bool hasPathWithGivenSum(Tree<int> * t, int s);
		bool isTreeSymmetric(Tree<int> * t1, Tree<int> * t2);
		bool isTreeSymmetric(Tree<int> * t);
		string findProfession(int level, int pos);
};

