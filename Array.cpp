#include "DataStructure.h"

/*
void iterator()
{
map<char, int> myMap;
map<char, int>::iterator it;

for(it = myMap.begin(); it != myMap.end(); ++it)
{
if(it->second == 1)
return it->first;
}
}
*/

int Array::firstDuplicate(vector<int> a) {
	map<int, int> myMap;
	int i = 0;

	if (a.size() < 2)
		return -1;

	for (i = 0; i<a.size(); ++i)
	{
		++myMap[a[i]];
		if (myMap[a[i]] == 2)
			return a[i];
	}

	return -1;
}


char Array::firstNotRepeatingCharacter(string s) {

	map<char, int> myMap;

	for (int i = 0; i<s.size(); ++i)
	{
		++myMap[s[i]];
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if (myMap[s[i]] == 1)
			return s[i];
	}

	return '_';
}
