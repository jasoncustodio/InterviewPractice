#include "DataStructure.h"

/*
	Group dishes based on the same ingredient
*/

vector<vector<string>> HashTable::groupingDishes(vector<vector<string>> dishes)
{
	map<string, vector<string>>::iterator it;
	vector<vector<string>> returnDish;
	map<string, vector<string>> myMap;
	int i, j;

	for (i = 0; i < dishes.size(); ++i)
	{
		for (j = 1; j < dishes[i].size(); ++j)
		{
			myMap[dishes[i][j]].push_back(dishes[i][0]);
		}
	}

	for (i = 0, it = myMap.begin(); it != myMap.end(); ++it)
	{
		if (it->second.size() > 1)
		{
			returnDish.emplace_back();
			returnDish[i].push_back(it->first);
			sort(it->second.begin(), it->second.end());
			returnDish[i].insert(returnDish[i].end(), it->second.begin(), it->second.end());
			++i;
		}
	}

	return returnDish;
}

//vector<vector<string>> groupingDishes(vector<vector<string>> dishes) {
//	map<string, vector<string>> m;
//	for (d : dishes) {
//		for (int i = 1; i < d.size(); ++i) {
//			m[d[i]].push_back(d[0]);
//		}
//	}
//	vector<vector<string>> ans;
//	for (p : m) {
//		if (p.second.size() > 1) {
//			sort(p.second.begin(), p.second.end());
//			p.second.insert(p.second.begin(), p.first);
//			ans.push_back(p.second);
//		}
//	}
//	sort(ans.begin(), ans.end());
//	return ans;
//}

/*
	Find pattern based on the input string, return a bool
*/

bool HashTable::areFollowingPatterns(vector<string> strings, vector<string> patterns)
{
	map<string, string> check;
	map<string, string> checkString;

	int i;

	for (i = 0; i < strings.size(); ++i)
	{
		if (!check.count(patterns[i]) && !checkString.count(strings[i]))
		{
			check[patterns[i]] = strings[i];
			checkString[strings[i]] = patterns[i];
		}

		if (check[patterns[i]] != strings[i])
			return false;
	}

	return true;
}

/*
	Find distance 'k' between two duplicates; return boolean
*/

//bool HashTable::containsCloseNums(vector<int> nums, int k)
//{
//	map<int, tuple<int, int>> myMap;
//	int count = 0;
//	int index = 0;
//
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		get<0>(myMap[nums[i]])++;
//		count = get<0>(myMap[nums[i]]);
//		index = get<1>(myMap[nums[i]]);
//
//		if (count == 2)
//		{
//			if (i - index == k)
//				return true;
//		}
//		else
//		{
//			get<1>(myMap[nums[i]]) = i;
//		}
//	}
//
//	return false;
//}

bool HashTable::containsCloseNums(vector<int> nums, int k)
{
	map<int, int> count;
	map<int, int> index;

	for (int i = 0; i < nums.size(); ++i)
	{
		++count[nums[i]];

		if (count[nums[i]] > 1)
			if (i - index[nums[i]] <= k)
				return true;

		index[nums[i]] = i;
	}

	return false;
}

bool HashTable::containsCloseNums2(vector<int> nums, int k) 
{
	unordered_map<int, int> cnt;

	for (int i = 0; i<nums.size(); ++i) 
	{
		if (i - k - 1 >= 0)
			--cnt[nums[i - k - 1]];

		if (cnt[nums[i]])
			return true;

		++cnt[nums[i]];
	}
	return false;
}
