#include <iostream>
#include <vector>
#include "String.h"

void sortStrings(std::vector<String>& strings, int begin = 0, int end = -1) {
	if (end == -1)
		end = strings.size() - 1;
	int left = begin;
	int right = end;
	String pivot = strings[(left + right) / 2];
	while (left <= right)
	{
		while (pivot.Compare(strings[left]) > 0)
			left++;
		while (pivot.Compare(strings[right]) < 0)
			right--;

		if (left <= right)
		{
 			auto temp = strings[left];
			strings[left] = strings[right];
			strings[right] = temp;
			left++;
			right--;
		}
	}

	if (right > begin)
		sortStrings(strings, begin, right);
	if (left < end)
		sortStrings(strings, left, end);
}

void writeStrings(std::vector<String> strings) {
	for (String str : strings)
		std::cout << str << " ";
	std::cout << '\n';
}

int main()
{
	std::vector<String> strings = std::vector<String>();
	for (int i = 97; i < 123; i++)
		strings.push_back(String(i % 2 == 0 ? 
			new char(std::toupper(i)) : 
			new char(i), 1));
	std::cout << "Not sorted array:" << std::endl;
	writeStrings(strings);
	sortStrings(strings);
	std::cout << "Sorted array:" << std::endl;
	writeStrings(strings);
}
