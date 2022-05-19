// This file contains unit tests for Node and MyList.
#include "my_list.h"

// testing more complex data
void test_complex() {
	vector<double> v = {1, 2.5, 3.1, 4.9, 5.1, 6.5};

	vector<vector<double>> u = {};
	// the setup should be four copies of v inside u and an array
	for (unsigned i = 0; i <= 3; i++) {
		u.push_back(v);
	}

	vector<string> holidays = {"Christmas", "Thanksgiving", "New Years", "Halloween", "Valentines", "Veterans Day", "Labor Day", "Independence Day"};

	int size = holidays.size();
	
	string* ar = new string[ size ];

	int i = 0;
	// copying data from holidays to ar
	for (const string& s : holidays) {
		ar[i] = s;
		cout << ar[i] << endl;
		i++;
	}
	// how do I get holidays data into 'n'? setArray method
	Node<vector<vector<double>>, string>* n = new Node<vector<vector<double>>, string>();

	n->deepCopy(ar, size);

	delete[] ar;
	// what should I assert first? A value in holidays matches hs at same index with getArrayValue(index)
	assert(holidays[size - 1] == n->getArrayValue(size - 1) );

	cout << holidays[size - 1] << ", " << n->getArrayValue(size - 1) << endl;

	// how do I get u into n? 
	n->setValue(u);
	// #fixme
	int vSize = v.size();

	assert( u[3][vSize - 1] == n->getValue()[3][vSize - 1] );

	cout << u[3][vSize - 1] << ", " << n->getValue()[3][vSize - 1] << endl;

	delete n;
}

void test_clear() {
	MyList<int, int> L;
    int i = 0;
    while (i <= 10) {
        L.insertAtEnd(i);
        i++;
    }
    L.dump(cout);
    L.clear();
	assert(L.getSize() == 0);
	cout << L.getSize() << endl;
}

void test_printArray() {
	// testing default constructor
	Node<int, int>* n = new Node<int, int>();
	// I should initialize each value in array to 0. C++ does not do this automatically.
	cout << "getValue " << n->getValue() << endl;

	assert(n->getValue() == 0);
	// how do I assert for a print statement?
	n->printArray();

	delete n;
}
// Node constructor with 3 parameters
void test_constructorA() {
	int* arr = new int[10];

	for (unsigned i = 0; i <= 9; i++) {
		arr[i] = 5;
		// cout << arr[i] << " arr ";
	}
	cout << endl;

	Node<int, int>* n = new Node<int, int>(3, arr, 10);

	 n->printArray();

	 int* a = n->getArray();
	 // cout << "arr[1]  " << arr[1] << " *(a+1) " << *(a + 1) << endl;
	 for (unsigned i = 0; i <= 9; i++) {
		//assert(arr[i] == *(a  + i));	// checking if second each element was properly copied
		cout << *(a + i) << ", ";
	 }
	cout << endl;
	 //cout << "a " << a <<  "  &a " << &a << endl;
	//size_t t = sizeof(arr) / sizeof(arr[0]);
	//cout << " size here " << t << endl;	// this is peculiar to me that its only size 2
	// why isnt this calling Node destructor?
	delete[] arr;

	delete n;
}
// testing Node constructor with 2 parameters.
void test_constructorB(){
	Node<int, double>* m = new Node<int, double>(2, 4);

	m->printArray();

	unsigned n = m->getSize();

	assert(n == 4);
	
	for (unsigned i = 0; i < n; i++) {
		assert(m->getArrayValue(i) == 0);
	}
}

// testing Node constructor with 2 parameters.
void test_constructorB2(){
	Node<int, string>* w = new Node<int, string>(2, 5);

	w->printArray();

	unsigned n = w->getSize();
	
	assert(n == 5);

	for (unsigned i = 0; i < n; i++) {
		w->setArrayValue(i,  "spring");

		assert(w->getArrayValue(i) == "spring");
	}

	w->printArray();
}

void test_list_constructor() {
		MyList<int, int>* m = new MyList<int, int>();
		assert(m->getSize() == 0);
		assert(m->getFront() == nullptr);
		assert(m->getEnd() == nullptr);
		delete m;
}

void test_insertAtEnd() {
	MyList<int, int>* v = new MyList<int, int>();

	for (unsigned i = 0; i <= 20; i++) {
		v->insertAtEnd(2);
	}

	Node<int, int>* c = v->getFront();
	
	while (c != nullptr) {
		cout << c->getValue() << ", ";
		assert(c->getValue() == 2);
		c = c->getNext();
	}
	delete v;
}
// testing if it takes a char array to make a string type
void test_char_array() {
	char* str = new char[3];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	
	for (int i = 0; i <= 2; i++) {
		cout << str[i] << ", ";
	}

	Node<char, char>* n = new Node<char, char>('a', str, 3);
	n->printArray();
	cout << n->getSize() << endl;

	delete[] str;

	delete n;
}

void test_getValue() {
	 Node<char, int>* n = new Node<char, int>('a');
	 // how do I convert from 97 to 'a'? char(e->x())
	 cout << "value " << char(n->getValue()) << endl;

	delete n;
}

void test_deepCopy() {
	Node<int, string>* m = new Node<int, string>();

	string s = "hello world";
	
	string* a = new string[5];
	// add 5 copies of s to array
	for (unsigned i = 0; i <= 4; i++) {
			a[i] = s;
			cout << a[i] << ", ";
	}
	cout << endl;

	m->printArray();	// should be empty

	m->deepCopy(a, 5);	

	m->printArray();	// should be exactly the same as "a"
	
	assert(m->getSize() == 5);
	// asserting for each value in hs array
	string* hs = m->getArray();

	for (int i = 0; i <= 4; i++) {
		// cout << a[i] << ", " << hs[i] << endl;
		assert(a[i] == hs[i]);
	}
	// what about a method that allows the user to get a value at a certain index in hs?

	delete[] a;

	delete m;
}
// #fixme
void test_clear_node() {
	// Node<double, string>* n = new Node<double, string>();	
}
void test_getArrayValue() {
	int* a = new int[6];
	
	for (unsigned i = 0; i <= 5; i++) {
			a[i] = 3;
	} 

	Node<int, int>* m = new Node<int, int>(1, a, 6);
	
	for (unsigned i = 0; i <= 5; i++) {
		assert(m->getArrayValue(i) == a[i] );
	}

	cout << m->getArrayValue(0) << endl;

	delete[] a;

	delete m;
}

void test_setArrayValue() {
}

void test_shallowCopy() {
	// setup
	Node<double, int>* n = new Node<double, int>();

	int size = 5;

	int* ar = new int[size];

	for (int i = 0; i <= size - 1; i++) {
		ar[i] = i + 1;
		cout << ar[i] << ", ";
	}

	n->shallowCopy(ar, size);

	n->printArray();

	assert(&ar[0] == n->getArray());

	// it should fail this same assertion if I run it for deepCopy
	ar[4] = -1;

	int* hs = n->getArray();

	assert(hs[4] == - 1);

	delete[] ar;

	delete n;
}

void test_insertAtFront() {
	MyList<double, string>* l = new MyList<double, string>();

	for (int i = 0; i <= 9; i++) {
		l->insertAtFront(i + 0.1*i);
	}

	assert(l->getSize() == 10);
	// asserting for each node in the list
	Node<double, string>* c = l->getFront();
	// 9.9 8.8 7.7 ..
	double i = 9;

	double s = i + 0.1* i;

	while (c != nullptr) {
		s = i + 0.1 * i;
		assert(c->getValue() == s);
		c = c->getNext();
		i--;
	}

	l->dump(cout);

	delete l;
}

void test_assign() {
	MyList<int, string>* m = new MyList<int, string>();
	// assigns 5 nodes with value 2
	m->assign(2, 5);
	// node for traversal
	Node<int, string>* c = m->getFront();

	int i = 0;

	while (i <= 4) {
		// cout << c->getValue() << ", ";
		assert(c->getValue() == 2);
		c = c->getNext();
		i++;
	}

	assert(m->getSize() == 5);

	delete m;
}

void test_popBack() {
	MyList<int, string>* m = new MyList<int, string>();
	// assign 7 nodes with value 3
	m->assign(3, 7);

	int size = 7;

	while (!m->isEmpty()) {
		assert(m->getSize() == size);
		m->popBack();
		size--;
	}
	delete m;
}

void test_popFront() {
}

void test_remove() {
}
// testing c-array stuff, not related to node
void test_c_array() {
	char* no = new char[5];
	cout << "test_c_array\n";
	// add the alphabet using ascii code
	for (unsigned int i = 0; i <= 4; i++) {
		no[i] = 'a';
	}

	for (unsigned int i = 0; i <= 4; i++) {
		cout << *(no + i )<< endl;
	}

	delete[] no;
}
