#include "node.h"
// MyList class inherits from Node.
// Each class should get its own template<>
template<typename T, typename E>

class MyList : public Node<T, E> {
 private:
    Node<T, E>* head;
    Node<T, E>* tail;
    int size;	// shows how many Nodes
 public:
    MyList() {
		cout << "constructor called" << endl;
      head = tail = nullptr;
		size = 0;
    }

	void clear() {
		 cout << "MyList clear" << endl;
        Node<T, E>* prev = nullptr;
        while (head != nullptr) {
            prev = head;
            head = head->getNext();
            // cout << "Deleting node " << prev->getValue() << endl;
            delete prev;
            size--;
        }
        // Avoiding dangling pointers
        head = tail = nullptr;
	}

    virtual ~MyList() {
       clear();
    }
    // Used for adding Nodes to the list.
    // I should add insertAtEnd(Node<T> n)
    void insertAtEnd(T value) {
        // Special case of empty list.
        Node<T, E>* cur = new Node<T, E>(value);
        if (head == nullptr) {
            head = tail = cur;
            size = 1;
            return;
        }
        // Non-empty list
        else {
            tail->setNext(cur);
            cur->setPrev(tail);
            tail = cur;
            size++;
            return;
        }
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }
    Node<T, E>* getFront() {
        return head;
    }
    Node<T, E>* getEnd() {
        return tail;
    }
    // Copy constructor.
    MyList(const MyList& other) {
        Node<T, E>* cur = other.head;
        // Special case of empty 'other'
        if (cur == nullptr) return;
        // Necessary in order to use insertAtEnd.
        head = nullptr;
        while (cur != nullptr) {
            this->insertAtEnd(cur->getValue());
            cur = cur->getNext();
        }
    }

    // Copy operator
    MyList& operator=(const MyList& other) {
        if (this == &other) {
            return *this;
        }

        this->~MyList();

        Node<T, E>* cur = other.head;

        while (cur != nullptr) {
            Node<T, E>* tmp = new Node<T, E>(cur->getValue());
            insertAtEnd(tmp->getValue());
            cur = cur->getNext();
        }

        return *this;
    }
    // Inserts a new node at the front
    void insertAtFront(T value) {
        if (head == nullptr) {
            Node<T, E>* cur = new Node<T, E>(value);
            head = tail = cur;
            size = 1;
            return;
        } else {
            Node<T, E>* cur = new Node<T, E>(value);
            cur->setNext(head);
            head->setPrev(cur);
            head = cur;
            size++;
            return;
        }
    }
    // Insert 'value' at 'pos' position.
    void insertAt(T value, int pos) {
        if (pos >= size || pos <= -1 || head == nullptr || tail == nullptr) {
            throw out_of_range("Invalid pos");
        }
        Node<T, E>* cur = head;
        Node<T, E>* prev = nullptr;
        int count = 0;
        while (cur) {
            if (count == pos) {
                Node<T, E>* newNode = new Node<T, E>(value);
                newNode->setPrev(prev);
                prev->setNext(newNode);
                cur->setPrev(newNode);
                newNode->setNext(cur);
                return;
            }
            count++;
            prev = cur;
            cur = cur->getNext();
        }
    }
    // Assigns 'size' number of Node's with 'value'.
    void assign(T value, int size) {
        if (size <= 0) {
            throw invalid_argument("Invalid size");  // size must be one or more
        }
        int i = 1;
        while (i <= size) {
            insertAtEnd(value);
            i++;
        }
    }
    // Delete's the last element and reduces size by one, effectively.
    void popBack() {
        Node<T, E>* cur = tail;
        if (size == 0) {
            throw length_error("Invalid pointer");
        }
        if (size == 1) {
            delete cur;
            head = tail = nullptr;
            size--;
            return;
        }
        cur->getPrev()->setNext(nullptr);
        tail = cur->getPrev();
        delete cur;
        size--;
    }
    // Deletes the first element.
    void popFront() {
        Node<T, E>* cur = head;
        if (size == 0) {
            throw length_error("Invalid pointer");
        }
        if (size == 1) {
            delete cur;
            head = tail = nullptr;
            size--;
            return;
        }
        // if it gets here, then there two or more Nodes
        cur->getNext()->setPrev(nullptr);
        head = cur->getNext();
        delete cur;
        size--;
    }
    // Removes the first element with same value as the parameter.
    void remove(T value) {
        Node<T, E>* cur = head;
        if (cur == nullptr) {
            throw length_error("Invalid pointer");
        }
        // Delete from the front of the list.
        if (cur->getValue() == value) {
            // Special case of one Node.
            if (size == 1) {
                delete cur;
                size--;
                head = tail = nullptr;
                return;
            } else {
                cur->getNext()->setPrev(nullptr);
                delete cur;
                size--;
                head = cur->getNext();
                return;
            }
        }
        while (cur != nullptr) {
            // Special case for 'tail'.
            if (cur->getValue() == value) {
                if (cur == tail) {
                    cur->getPrev()->setNext(nullptr);
                    tail = cur->getPrev();
                    delete cur;
                    size--;
                    return;
                } else {
                    cur->getPrev()->setNext(nullptr);
                    cur->getNext()->setPrev(nullptr);
                    delete cur;
                    size--;
                    return;
                }
            }
            cur = cur->getNext();
        }
        cout << "Not found\n";
    }
    // Dumps the internal state of the list to console. Handles primitive types
    void dump(ostream& output) const{
        if (head == nullptr) {
            output << "Empty\n";
            return;
        }
        Node<T, E>* cur = head;
        while (cur != nullptr) {
            output << cur->getValue() << ", ";
            cur = cur->getNext();
        }
        output << endl;
    }
};