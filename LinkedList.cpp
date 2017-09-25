#include "DataStructure.h"

/*
	Create a new list, only copy the ones that do not equal k.
	return the new list.
*/

ListNode<int> * LinkedList::removeKFromList(ListNode<int> * l, int k) 
{
	ListNode<int> * head = NULL;
	ListNode<int> * tail = NULL;

	for (l; l; l = l->next)
	{
		if (l->value != k)
		{
			ListNode<int> * newNode = new ListNode<int>(l->value);

			if (head == NULL)
			{
				head = tail = newNode;
			}
			else
			{
				tail->next = newNode;
				tail = tail->next;
			}
		}
	}

	return head;
}

/*
	Push onto stack, while popping, check if it equals the same.
*/

bool LinkedList::isListPalindrome(ListNode<int> * l)
{
	ListNode<int> * head = NULL;
	ListNode<int> * current = NULL;

	for (current = l; current; current = current->next)
	{
		ListNode<int> * newNode = new ListNode<int>(current->value);

		if (head == NULL)
			head = newNode;
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	for (current = l; current; current = current->next, head = head->next)
		if (current->value != head->value)
			return false;

	return true;
}

/*
	O(n) by reversing the list and checking
*/

bool LinkedList::isListPalindrome2(ListNode<int> * head)
{
	if (!head || (head && !head->next))			// 0 or 1 items
		return true;

	ListNode<int> * slow = head;				// Stays ahead by 1
	ListNode<int> * fast = head;				// Stays ahead by 2
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->next = reverseList(slow->next);
	slow = slow->next;
	while (slow) {
		if (head->value != slow->value)
			return false;
		head = head->next;
		slow = slow->next;
	}
	return true;
}

ListNode<int> * LinkedList::reverseList(ListNode<int> * head) {
	ListNode<int> * pre = NULL;
	ListNode<int> * next = NULL;

	while (head) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

ListNode<int> * LinkedList::InsertTail(int length)
{
	ListNode<int> * head = NULL;
	ListNode<int> * tail = NULL;

	for (int i = 0; i < length; ++i)
	{
		ListNode<int> * temp = new ListNode<int>(rand() % 100);

		if (!head)
			head = tail = temp;
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}
	return head;
}