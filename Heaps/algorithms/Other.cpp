/**============================================================================
Name        : Other.cpp
Created on  : 11.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../HeapsAlgorithms.h"

namespace
{
	/*
	namespace MinHeapTest_FirstKelements {

		class MinHeap {
		private:
			int size;
			int* arr;

		public:
			// Constructor to initialize the size and arr
			MinHeap(int size, int input[]);

			// Min Heapify function, that assumes that 2*i+1 and 2*i+2 are
			// min heap and fix the heap property for i.
			void heapify(int i);

			// Build the min heap, by calling heapify for all non-leaf nodes.
			void buildHeap();
		};

		// Constructor to initialize data members and creating mean heap
		MinHeap::MinHeap(int size, int input[])
		{
			// Initializing arr and size

			this->size = size;
			this->arr = input;

			// Building the Min Heap
			buildHeap();
		}

		// Min Heapify function, that assumes 2*i+1 and 2*i+2 are
		// min heap and fix min heap property for i
		void MinHeap::heapify(int i)
		{
			// If Leaf Node, Simply return
			if (i >= size / 2)
				return;

			// variable to store the smallest element
			// index out of i, 2*i+1 and 2*i+2
			int smallest;

			// Index of left node
			int left = 2 * i + 1;

			// Index of right node
			int right = 2 * i + 2;

			// Select minimum from left node and
			// current node i, and store the minimum
			// index in smallest variable
			smallest = arr[left] < arr[i] ? left : i;

			// If right child exist, compare and
			// update the smallest variable
			if (right < size)
				smallest = arr[right] < arr[smallest] ? right : smallest;

			// If Node i violates the min heap
			// property, swap  current node i with
			// smallest to fix the min-heap property
			// and recursively call heapify for node smallest.
			if (smallest != i) {
				std::swap(arr[i], arr[smallest]);
				heapify(smallest);
			}
		}

		// Build Min Heap
		void MinHeap::buildHeap()
		{
			// Calling Heapify for all non leaf nodes
			for (int i = size / 2 - 1; i >= 0; i--) {
				heapify(i);
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////

		void __first_K_elements__(int arr[], int size, int k) {
			// Creating Min Heap for given array with only k elements
			MinHeap* minHeap = new MinHeap(k, arr);

			// Loop For each element in array after the kth element
			for (int i = k; i < size; i++) {
				if (arr[0] > arr[i]) { // if current element is smaller  than minimum element, do nothing and continue to next element
					continue;
				} else { // Otherwise Change minimum element to current element, and call heapify to restore the heap property
					arr[0] = arr[i];
					minHeap->heapify(0);
				}
			}
			// Now min heap contains k maximum elements, Iterate and print
			for (int i = 0; i < k; i++) {
				std::cout << arr[i] << " ";
			}
		}

		void Test()
		{
			int arr[] = { 111, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
			size_t size = sizeof(arr) / sizeof(arr[0]);

			// Size of Min Heap
			int k = 3;
			__first_K_elements__(arr, size, k);
		}
	}
	*/

	namespace MinHeap {

		template<typename Type>
		class BaseHeap {
		protected:
			std::vector<Type> vector;

		public:
			inline size_t size() const noexcept {
				return this->vector.size();
			}

			inline bool has_elements() const noexcept {
				return !this->vector.empty();
			}

			inline bool empty() const noexcept {
				return this->vector.empty();
			}

			inline void reserve(const size_t size) {
				this->vector.reserve(size);
			}

			// Just push. No heapify!
			inline void push(const Type value) noexcept {
				this->vector.push_back(value);
			}

			inline Type head() const noexcept {
				return vector.front();
			}

			void PrintElements() const noexcept {
				for (const auto i : this->vector)
					std::cout << i << " ";
				std::cout << std::endl;
			}
		};


		template<typename Type>
		class MinBinaryHeap : public BaseHeap<Type> {
		private:
			using BaseHeap<Type>::vector;

		public:
			MinBinaryHeap() = default;

			MinBinaryHeap(const Type* data, size_t size) {
				vector.reserve(size);
				vector.assign(data, data + size);
				make_heap();
			}

		public:
			// Add and heapify.
			void add(Type value) {
				/** Index of new element in vector will be equal to: **/
				size_t index = this->vector.size();
				/** Parent element index will :**/
				size_t parent_index = index / 2 - 1;
				/** Push the new element into vector. **/
				this->vector.push_back(value);

				while (index > 0 && vector[parent_index] > vector[index]) {
					std::swap(vector[parent_index], vector[index]);
					index = parent_index;
					parent_index = index / 2 - 1;
				}
			}

			void heapify(size_t index) {
				size_t left, right, current;
				while (true) {
					left = 2 * index + 1;
					right = 2 * index + 2;
					current = index;

					if (this->size() > left && this->vector[current] > this->vector[left])
						current = left;
					if (this->size() > right && this->vector[current] > this->vector[right])
						current = right;
					if (current == index)
						break;
					std::swap(this->vector[index], this->vector[current]);
					index = current;
				}
			}

			Type pop() {
				Type root = this->vector.front();
				this->vector.erase(this->vector.begin());
				this->heapify(0);
				return root;
			}

			void update_head(const Type new_val) {
				this->vector[0] = new_val;
				this->heapify(0);
			}

			void make_heap() {
				for (int i = this->size() / 2; i >= 0; i--)
					heapify(i);
			}

			bool IsHeapValid() {
				for (int i = this->size(); (i / 2 - 1) >= 0; i--)
					if (this->vector[i / 2 - 1] > this->vector[i - 1])
						return false;
				return true;
			}
		};

		//////////////////////////////////////////////////////////////////////

		void Tests() {
			int arr[] = { 11,9,3,7,6,5,8,1 };
			MinBinaryHeap<int> heap(arr, std::size(arr));

			// heap.PrintElements();

			int max = 0;
			while (heap.has_elements()) {
				max = heap.pop();
				std::cout << max << std::endl;
			}
		}


		void Pop_Test() {
			// int arr[] = { 20,15,11,9,8,7,6,5,3,1 };
			int arr[] = { 11,9,8,7,6,5,3,1 };

			MinBinaryHeap<int> heap(arr, std::size(arr));


			while (false == heap.empty()) {
				int element = heap.pop();
				std::cout << "Pop-ed element: " << element << std::endl;
				std::cout << "Is heap valid: " << std::boolalpha << heap.IsHeapValid() << std::endl;
				heap.PrintElements();
			}
		}
	}

	namespace BinaryHeap {

		template<typename Type>
		class MaxBinaryHeap {
		private:
			std::vector<Type> vector;

		public:
			MaxBinaryHeap() = default;

			MaxBinaryHeap(const Type* data, size_t size) {
				vector.reserve(size);
				vector.assign(data, data + size);
				make_heap();
			}

		public:
			inline size_t size() const noexcept {
				return this->vector.size();
			}

			inline void reserve(const size_t size) {
				this->vector.reserve(size);
			}

			// Just push. No heapify!
			void push(const Type value) noexcept {
				this->vector.push_back(value);
			}

			// Add and heapify.
			void add(Type value) {
				/** Index of new element in vector will be equal to: **/
				size_t index = this->vector.size();
				/** Parent element index will :**/
				size_t parent_index = (index - 1) / 2;
				/** Push the new element into vector. **/
				this->vector.push_back(value);

				while (index > 0 && vector[parent_index] < vector[index]) {
					std::swap(vector[parent_index], vector[index]);
					index = parent_index;
					parent_index = (index - 1) / 2;
				}
			}

			void heapify(size_t index) {
				size_t left, right, current;
				while (true) {
					left = 2 * index + 1;
					right = 2 * index + 2;
					current = index;

					if (size() > left && this->vector[left] > this->vector[current])
						current = left;
					if (size() > right && this->vector[right] > this->vector[current])
						current = right;
					if (current == index)
						break;
					std::swap(this->vector[index], this->vector[current]);
					index = current;
				}
			}

			Type pop() {
				Type root = this->vector.front();
				this->vector.erase(this->vector.begin());
				this->heapify(0);
				return root;
			}

			void make_heap() {
				for (int i = size() / 2; i >= 0; i--)
					heapify(i);
			}

			void PrintElements() {
				for (const auto i : this->vector)
					std::cout << i << " ";
				std::cout << std::endl;
			}

			bool IsHeapValid() {
				for (int i = this->size(); (i / 2 - 1) >= 0; i--)
					if (this->vector[i / 2 - 1] < this->vector[i - 1])
						return false;
				return true;
			}
		};


		///////////////////////////////////////////////////////////

		void Tests() {
			MaxBinaryHeap<int> heap;


			heap.push(1);
			heap.push(3);
			heap.push(5);
			heap.push(6);
			heap.push(7);
			heap.push(8);
			heap.push(9);
			heap.push(11);
			heap.push(15);
			heap.push(20);
			heap.make_heap();
			heap.PrintElements();


			/*
			heap.add(1);
			heap.add(3);
			heap.add(5);
			heap.add(6);
			heap.add(7);
			heap.add(8);
			heap.add(9);
			heap.add(11);
			heap.add(15);
			heap.add(20);
			*/

			/*
			heap.PrintElements();

			std::cout << heap.pop() << std::endl;
			heap.PrintElements();

			std::cout << heap.pop() << std::endl;
			heap.PrintElements();



			heap.add(210);
			heap.PrintElements();


			heap.pop();
			heap.make_heap();
			heap.PrintElements();
			*/

		}

		void Tests2() {
			int arr[] = { 1,2,3 };
			MaxBinaryHeap<int> heap(arr, std::size(arr));

			heap.PrintElements();
			std::cout << heap.IsHeapValid() << std::endl;
		}

		void Find_N_Max_Elements_Slow() {
			int arr[] = { 111, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
			size_t size = sizeof(arr) / sizeof(arr[0]);


			unsigned int N = 3;
			MaxBinaryHeap<int> heap(arr, size);
			while (N--) {
				std::cout << heap.pop() << std::endl;
			}
		}

		void Find_N_Max_Elements() {
			int data[] = { 111, 3, 2, 87, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
			size_t size = std::size(data);

			constexpr size_t N = 3;
			MinHeap::MinBinaryHeap<int> heap(data, N);
			for (size_t index = N; index < size; index++)
				if (data[index] > heap.head())
					heap.update_head(data[index]);

			heap.PrintElements();
		}

		//--------------------------------------------------------------------------------------//

		void _largest_triple_products([[maybe_unused]] const std::vector<int>& number) {
		}

		void Largest_Triple_Products() {
			std::vector<int> number = { 1, 2, 3, 4, 5 };
			_largest_triple_products(number);
		}
	};

	namespace Algoritms
	{
		bool IsMaxHeap(const std::vector<int>& data)
		{
			for (size_t i = 0; i <= (data.size() / 2 - 1); i++) {
				if (data[i * 2 + 1] > data[i]) // If left child is greater, return false
					return false;
				else if (data.size() > i * 2 + 2 && data[i * 2 + 2] > data[i]) // If right child EXISTS and is greater, return false
					return false;
			}
			return true;
		}

		bool IsMinHeap(const std::vector<int>& data)
		{
			for (size_t i = 0; i <= (data.size() / 2 - 1); i++) {
				if (data[i] > data[i * 2 + 1])
					return false;
				else if (data.size() > i * 2 + 2 && data[i] > data[i * 2 + 2])
					return false;
			}
			return true;
		}

		/***********************************************************************************************************/

		// to heapify a subtree with root at given index
		void _MaxHeapify_1(std::vector<int>& numbers, size_t index)
		{
			const auto left = 2 * index + 1;
			const auto right = 2 * index + 2;
			auto largest = index;
			if (left < numbers.size() && numbers[left] > numbers[index])
				largest = left;
			if (right < numbers.size() && numbers[right] > numbers[largest])
				largest = right;
			if (largest != index)
			{
				std::swap(numbers[index], numbers[largest]);
				_MaxHeapify_1(numbers, largest);
			}
		}

		void _Convert2MaxHeap_1(std::vector<int>& numbers) {
			for (int i = (numbers.size() - 2) / 2; i >= 0; --i)
				_MaxHeapify_1(numbers, i);
		}

		void _MaxHeapify_2(std::vector<int>& numbers, size_t index) {
			size_t left, right, current;
			while (true) {
				left = 2 * index + 1;
				right = 2 * index + 2;
				current = index;

				if (numbers.size() > left && numbers[left] > numbers[current])
					current = left;
				if (numbers.size() > right && numbers[right] > numbers[current])
					current = right;
				if (current == index)
					break;
				std::swap(numbers[index], numbers[current]);
				index = current;
			}
		}

		void _Convert2MaxHeap_2(std::vector<int>& numbers) {
			for (int i = (numbers.size() - 2) / 2; i >= 0; --i)
				_MaxHeapify_2(numbers, i);
		}

		void Conver_MinHeap_to_MaxHeap() {
			{
				std::vector<int> numbers = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
				std::cout << "Is MIN heap: " << std::boolalpha << IsMinHeap(numbers) << ". Is MAX heap: " << std::boolalpha << IsMaxHeap(numbers) << std::endl;
				_Convert2MaxHeap_1(numbers);
				std::cout << "Is MIN heap: " << std::boolalpha << IsMinHeap(numbers) << ". Is MAX heap: " << std::boolalpha << IsMaxHeap(numbers) << std::endl;
			}
			{
				std::vector<int> numbers = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
				std::cout << "Is MIN heap: " << std::boolalpha << IsMinHeap(numbers) << ". Is MAX heap: " << std::boolalpha << IsMaxHeap(numbers) << std::endl;
				_Convert2MaxHeap_2(numbers);
				std::cout << "Is MIN heap: " << std::boolalpha << IsMinHeap(numbers) << ". Is MAX heap: " << std::boolalpha << IsMaxHeap(numbers) << std::endl;
			}
		}
	}

	namespace HeapifyTests {

		template<typename T>
		void print(const std::vector<T>& data) {
			for (const auto& v : data)
				std::cout << v << " ";
			std::cout << "\n";
		}

		//-----------------------------------------------------------------------------------------------------------//

		template<typename T, typename Pred>
		bool is_heap(const std::vector<T>& data) {
			auto valid = Pred();
			for (size_t i = 0; i < data.size() / 2; i++) {
				if (valid(data[i * 2 + 1], data[i]))
					return false;
				if (data.size() > (i * 2 + 2) && valid(data[i * 2 + 2], data[i]))
					return false;
			}
			return true;
		}

		template<typename T, typename Pred = std::greater<T>>
		bool is_max_heap(const std::vector<T>& data) {
			return is_heap<T, Pred>(data);
		}

		template<typename T, typename Pred = std::less<T>>
		bool is_min_heap(const std::vector<T>& data) {
			return is_heap<T, Pred>(data);
		}

		//-----------------------------------------------------------------------------------------------------------//

		void max_heapify(std::vector<int>& numbers, int index) {
			size_t left, right, current;
			while (true) {
				left = 2 * index + 1;
				right = 2 * index + 2;
				current = index;

				if (numbers.size() > left && numbers[left] > numbers[current])
					current = left;
				if (numbers.size() > right && numbers[right] > numbers[current])
					current = right;
				if (current == index)
					break;
				std::swap(numbers[index], numbers[current]);
				index = current;
			}
		}

		void make_max_heap(std::vector<int>& numbers) {
			for (int i = numbers.size() / 2; i >= 0; i--)
				max_heapify(numbers, i);
		}

		void MaxHeapifyTest() {
			std::vector<int> numbers = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 15 };
			print(numbers);
			make_max_heap(numbers);
			print(numbers);
		}

		//--------------------------------------------------------------------------------------------------------------------//

		void max_heapify_recurcive(std::vector<int>& numbers, size_t index)
		{
			auto left = 2 * index + 1;
			auto right = 2 * index + 2;
			auto largest = index;
			if (left < numbers.size() && numbers[left] > numbers[index])
				largest = left;
			if (right < numbers.size() && numbers[right] > numbers[largest])
				largest = right;
			if (largest != index)
			{
				std::swap(numbers[index], numbers[largest]);
				max_heapify_recurcive(numbers, largest);
			}
		}

		void make_max_heap_recurcive(std::vector<int>& numbers) {
			for (int i = (numbers.size() - 2) / 2; i >= 0; --i)
				max_heapify_recurcive(numbers, i);
		}

		void MaxHeapifyTestRecursive() {
			std::vector<int> numbers = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 15 };
			print(numbers);
			make_max_heap_recurcive(numbers);
			print(numbers);
		}

		//--------------------------------------------------------------------------------------------------------------------//

		void max_heapify_TEST(std::vector<int>& numbers, int index) {
			//std::cout << "heapify for [" << index << "] = " << numbers[index] << std::endl;
			size_t left, right, current;
			while (true) {
				left = 2 * index + 1;
				right = 2 * index + 2;
				current = index;

				if (numbers.size() > left && numbers[left] > numbers[current])
					current = left;
				if (numbers.size() > right && numbers[right] > numbers[current])
					current = right;
				if (current == index)
					break;
				std::swap(numbers[index], numbers[current]);
				index = current;
			}
			//print(numbers);
		}

		void make_max_heap_TEST(std::vector<int>& numbers) {
			for (int i = numbers.size() / 2; i >= 0; i--)
				max_heapify_TEST(numbers, i);
		}

		void MaxHeapifyTest_TEST() {
			std::vector<int> numbers = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 15 };
			//std::vector<int> numbers = { 21, 18, 15, 13,11, 10,9,8,7,6,22222, 12, 1};

			print(numbers);
			std::cout << "IS max heap: " << std::boolalpha << is_min_heap(numbers) << std::endl;
			std::cout << "IS max heap: " << std::boolalpha << is_max_heap(numbers) << std::endl;

			make_max_heap_TEST(numbers);

			print(numbers);
			std::cout << "IS max heap: " << std::boolalpha << is_min_heap(numbers) << std::endl;
			std::cout << "IS max heap: " << std::boolalpha << is_max_heap(numbers) << std::endl;
		}
	}
}


void HeapsAlgorithms::Other()
{

}
