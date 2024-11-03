#pragma once

#include <vector>

using namespace std;


//finds the index of last occurrence of target in the vector using recursive linear search
template <typename Item_Type>
int linear_search(const vector<Item_Type>& items, Item_Type& target, size_t index) {
	
	if (index == -1)
		return -1;

	else if (target == items[index])
		return index;

	else
		return linear_search(items, target, index - 1);

}

