#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<iterator>

using namespace std;

class BinaryHeap {
	private :
		vector<int> heap;
		int left(int parent);
		int right(int parent);
		int parent(int child);
		void heapifyup(int index);
		void heapifydown(int index);
	public :
	    BinaryHeap(){}
		void Insert(int element);
		void DeleteMin();
		int ExtractMin();
		void DisplayHeap();
		int Size();	
};


int BinaryHeap::left(int parent) {
	int r = 2*parent+1;
	if(heap.size() > 1){
		return r;
	}else{
		return -1;
	}
}

int BinaryHeap::right(int parent) {
	int r = 2*parent+2;
	if(heap.size()>1){
		return r;
	}else{
		return -1;
	}
}

int BinaryHeap::parent(int child) {
	int p = (child-1)/2;
	if(child <= 0){
		return -1
	}else {
		return p;
	}
}

void BinaryHeap::heapifyup(int index) {
     if(index >= 0 && parent(index)>=0 && heap[parent(index)]>heap[index]){
        // swap the two elements
        int temp = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = temp;
        heapifyup(parent(in));
	 }	
}

void BinaryHeap::heapifydown(int index) {
	int child = left(index);
	int child1 = rigth(index);
	
	if(child >=0 && child2 >=0 && heap[child]>heap[child1]) {
		child = child1;
	}
	if(child>0) {
		int temp = heap[child];
		heap[child] = heap[child1];
		heap[child1] = temp; 
	    heapifydown(child);
	}
}

void BinaryHeap::DeleteMin() {
	if(heap.size() == 0){
		cout<<"Heap is Empty."<<end;
	    return;
	}
	heap[0] = heap[heap.size()-1];
	heap.pop_back();
	heapifydown(0);
	cout<<"Element Deleted."<<endl;
}

void BinaryHeap::DisplayHeap() {
	vector<int>::iterator it;
	cout<<"Heap --> ";
	for(it=heap.begin();it!=heap.end();it++) {
		cout<<*it<<" ";
	}
	cout<<endl;
}

int BinaryHeap::ExtractMin() {
	return heap.front();   // returns the first element in the heap
}

void BinaryHeap::Insert(int element) {

}

int BinaryHeap::Size() {
	return heap.size();
}

int main() {
       BinaryHeap h;
    while (1)
    {
        cout<<"---------------------------"<<endl;
        cout<<"     Operations on Heap"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Minimum Element"<<endl;
        cout<<"3.Extract Minimum Element"<<endl;
        cout<<"4.Print Heap"<<endl;
        cout<<"5.Exit"<<endl;
        int choice, element;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element to be inserted: ";
            cin>>element;
            h.Insert(element);
            break;
        case 2:
            h.DeleteMin();
            break;
        case 3:
            cout<<"Minimum Element: ";
            if (h.ExtractMin() == -1)
            {
                cout<<"Heap is Empty"<<endl;
            }
            else
                cout<<"Minimum Element:  "<<h.ExtractMin()<<endl;
            break;
        case 4:
            cout<<"Displaying elements of Heap:  ";
            h.DisplayHeap();
            break;
        case 5:
            exit(1);
        default:
            cout<<"Enter Correct Choice"<<endl;
        }
        
        fflush(stdin);
        getchar();
        system("cls");
    }
    return 0; 	
}
