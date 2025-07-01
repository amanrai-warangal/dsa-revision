#include <bits/stdc++.h>
using namespace std;

class MinHeap {
	vector<int> heap;
	int size;

public:
	MinHeap() {
		size = 0;
	}

	void upHeapify(int index) {
		int childIndex = index;

		while(childIndex > 0) {
			int parentIndex = (childIndex-1)/2;
			if(heap[parentIndex] > heap[childIndex])
				swap(heap[parentIndex],heap[childIndex]);
			else
				break;

			childIndex = parentIndex;
		}
	}

	void insert(int num) {
		int index = size;
		heap.push_back(num);
		size++;

		upHeapify(index);
	}

	int pop() {
	    if(size == 0)
	        return -1;
	       
		int ans = heap[0];
		heap[0] = heap[size-1];
		size--;
		heap.pop_back();
		int parentIndex = 0;
		while(true) {
			int leftChildIndex = 2*parentIndex + 1;
			int rightChildIndex = 2*parentIndex + 2;

			int index = parentIndex;
			if(leftChildIndex < size && heap[leftChildIndex] < heap[index])
				index = leftChildIndex;
			if(rightChildIndex < size && heap[rightChildIndex] < heap[index])
				index = rightChildIndex;

			if(index == parentIndex)
				break;

			swap(heap[index],heap[parentIndex]);
			parentIndex = index;
		}

		return ans;
	}

	int top() {
	    if(size == 0)
	        return -1;
		return heap[0];
	}

	int getSize() {
		return size;
	}
};

int main()
{
	MinHeap m;
	while(true) {
		int query;
		cout << "Enter Query :";
		cin >> query;

		if(query == 0) {
			int num;
			cout << "Enter Value :";
			cin >> num;
			m.insert(num);
		}
		else if(query == 1)
			cout << "Popped Element : "  << m.pop() << endl;
		else if(query == 2)
			cout<< "Top : "  << m.top() << endl;
		else if(query == 3)
			cout << "Size : " << m.getSize() << endl;
		else {
			cout << "Bye";
			break;

		}
	}
	return 0;
}