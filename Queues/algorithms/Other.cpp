/**============================================================================
Name        : Other.cpp
Created on  : 11.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../QueuesAlgorithms.h"


namespace QueuesAlgorithms::Algoritms {


	int max(const std::vector<int>& orig, std::vector<int>& current_vector, int iter) {
		auto max = std::max_element(current_vector.begin(), current_vector.end());
		int maxVal = *max + iter;
		current_vector.erase(max);
		int count = 0;
		for (int v : orig) {
			count++;
			if (v = maxVal)
				return count;
		}
		return -1;
	}

	int magic(std::vector<int>& arr, int x, int iter, const std::vector<int>& orig) {
		std::queue<int> queue;
		for (int i : arr)
			queue.push(i);

		arr.clear();
		while (false == queue.empty() && x-- > 0) {
			arr.push_back(queue.front());
			queue.pop();
		}

		int pos = max(orig, arr, iter);
		std::for_each(arr.begin(), arr.end(), [&queue](int v) {
			queue.push(v > 0 ? v - 1 : 0);
			});

		arr.clear();
		while (false == queue.empty()) {
			arr.push_back(queue.front());
			queue.pop();
		}
		return pos;
	}

	void findPositions(std::vector<int> arr, int x) {
		std::vector<int> data = arr;
		for (int i = 0; i < x; i++) {
			int X = magic(data, x, i, arr);

			std::cout << X << " [ ";
			for (int i : data)
				std::cout << i << " ";
			std::cout << "]" << std::endl;
		}
	}


	void QueueRemovals()
	{
		int x = 5;
		std::vector<int> arr = { 1, 2, 2, 3, 4, 5 };
		findPositions(arr, x);
	}
}

void QueuesAlgorithms::Other()
{

}
