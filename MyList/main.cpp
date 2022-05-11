// Author DM Spring 2022.
// This program contains a list class that is implemented using a doubly linked list.
// Additionally, each Node has a C-array using dynamic memory.
#include "my_test.h"

// ctrl + e to toggle comment
// #fixme call delete for every time I used new in the test cases.
int main() {
    //test_clear();
    //test_printArray();
    //test_constructor();
    //test_list_constructor();
    //test_insertAtEnd();
    //test_char_array();
    //test_vector();
	//test_getArrayValue();
	//test_shallowCopy();
	//test_deepCopy();
	//test_insertAtFront();
	//test_assign();
	//test_popBack();	// why is Node clear being called?
	//test_constructor();
	// What else can I add to MyList to make it better? More tests?
	test_c_array();

	return 0;
}
