#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

using namespace std;
// namespace has to go before template<>
// Node class that is doubly linked.
// The MyList class functions can handle primitive types.
// <Typename T> works also
// I could make the Node handle string by doing array of chars
// how do I make a template for T value and T* hs?
// Two templates allow for different types. E.g. int value and char* hs.
// One thing I can add is make E* hs to be a class. E.g. myClass* hs and let the class contain an array.
template <typename T, typename E> 

class Node {
 private:
	int size;	// size of the array "hs"
	// int capacity;	// default constructor has 10 memory spots
    T value;
    Node* next;
    Node* prev;
    E* hs;	// all I need to declare is a pointer variable for a dynamic C array on the heap.
 public:
    Node() {
        next = nullptr;
        prev = nullptr;
		hs = new E[10];
		for (int i = 0; i <= 9; i++) {
				hs[i] = E();
		}
		size = 10;
		value = T();
    }
    // parameterized constructor
	// makes a deep copy of array 'ot' and stores in 'hs'
	Node(T value, E* ot, unsigned size) {
		this->value = value;
		next = nullptr;
		prev = nullptr;
		// its still a constructor, need to allocate space
		hs = new E[size];
		for (unsigned i = 0; i <= size - 1; i++) {
			hs[i] = ot[i];
		}
		this->size = size;
	}
	// parameterized constructor. The default has a size 10 array.
    Node(T value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
        hs = new E[10];
		// set default value for each element
        for (unsigned i = 0; i <= 9; i++) {
				hs[i] = E();
		}
    }
	// used for destructor
    void clear() {
		cout << "Node clear" << endl;
		delete[] hs;
		next = nullptr;
		prev = nullptr;
		size = 0;
		value = T();
	}
    
    virtual ~Node() {
		clear();
	}

    // returns how many elements are in the array
    int getSize() {
		return size;
	}

	void setSize(int size) {
		this->size = size;
	}
	// Makes a deep copy of hs array.
	void deepCopy(E* ot, unsigned size) {
		delete[] hs;

		hs = new E[size];

		this->size = size;

		for (unsigned i = 0; i <= size - 1; i++) {
				hs[i] = ot[i];
		}
	}
	// Makes a shallow copy of hs array.
	void shallowCopy(E* ot, unsigned size) {
			delete[] hs;

			hs = ot;

			this->size = size;
	}

	// Allows the user to input an array for hs data member
	void inputArray(unsigned size) {
	}
	// prints every value in hs array
    void printArray() {
		cout << "printArray: ";

		for (int i = 0; i <= size - 2; i++) {
			cout << hs[i] << ", ";
		}

		cout << hs[size - 1] << endl;
	}
	// return the address of the first element
	E* getArray() {
		return hs;
	}

    Node* getPrev() {
        return prev;
    }

    Node* getNext() {
        return next;
    }
    // Sets the parameter, used for linking.
    // e.g. myNode.setNext(newNode) means myNode links to newNode
    void setNext(Node* cur) {
        next = cur;
    }
    void setPrev(Node* cur) {
        prev = cur;
    }
    // Returns value of a Node. If the Node is null, then it gives an exception.
    T getValue() {
        //if (this == nullptr) {
            //throw invalid_argument("empty list\n");
        //}
        return value;
    }
    
    void setValue(T value) {
		this->value = value;
	}
	// Retrieves the hs value at index.
	E getArrayValue(unsigned index) {
		if (index >= unsigned(size) ) {
			throw invalid_argument("out of bounds\n");
		}
		return hs[index];
	}
	
	bool setArrayValue(unsigned index, const E& value) {
		if (index >= unsigned(size) ){
			return false;
		} else {
			hs[index] = value;
			return true;
		}
	}
};
