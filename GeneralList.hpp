#include <iostream>

template <class Data>
class List {
	private:
		struct _list {
			Data value;
			struct _list *next;
			struct _list *prev;
		};
		typedef struct _list Dlist;

		size_t _size;
		Dlist *_front;
		Dlist *_back;

		void reccopy(const Dlist *ptr) {
			if(ptr) { // if(ptr != nullptr) {
				reccopy(ptr->next);
				push_front(ptr->value);
			}
		}
	public:
		List() {
			_size = 0;
			_front = nullptr;
			_back = nullptr;
		}

		List(const List &list) {
			_front=nullptr;
			_back=nullptr;
			_size=0;
			reccopy(list._front);
		}

		~List() {
			while(!empty()) {
			//while(_size > 0) {
				pop_front();
			}
		}

		Data &front() const {
			return _front->value;
		}

		Data &back() const {
			return _back->value;
		}

		size_t size() const {
			return _size;
		}

		size_t length() const {
			return _size;
		}

		void push_front(Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->prev = nullptr;

			if(_front==nullptr) {
				newNode->next=nullptr;
				_back=newNode;
			}
			else {
				newNode->next=_front;
				_front->prev = newNode;
			}

			_front=newNode;
			_size++;
		}

		void push_back(Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->next=nullptr;

			if(_back!=nullptr) {
				_back->next=newNode;
				newNode->prev = _back;
			}

			if(_front==nullptr) {
				_front=newNode;
				newNode->prev = nullptr;
			}

			_back=newNode;
			_size+=1;
		}

		void pop_front() {
			Dlist *front_to_delete = _front;
			_front = _front->next;

			if(_front==nullptr) {
				_back = nullptr;
			}
			else {
				_front->prev = nullptr;
			}

			delete front_to_delete;
			_size -= 1;
		}

		//CONVERT THIS FUNCTION. OKAY, WE DID!
		void pop_back() {
			Dlist *back_to_remove = _back;

			if(_front != _back) {
				Dlist *new_back = _back->prev;
				new_back->next = nullptr;
				_back = new_back;
			}
			else {
				_front = nullptr;
				_back = nullptr;
			}

			delete back_to_remove;
			_size-=1;
		}

		// Leave this alone!
		bool empty() const {
			return ((_front==nullptr) && (_back==nullptr));
		}
		
		// Modify this.
		void print() {
			Dlist *temp; // Changed to Dlist by Lloyd.
			for(temp=_front; temp!=nullptr; temp=temp->next) {
				std::cout << temp->value << " ";
			}
			std::cout << std::endl;
		}

		void print_back(){
			Dlist *temp;
			for(temp=_back; temp != nullptr; temp=temp->prev){
				std::cout << temp->value << " ";
			}
			std::cout << std::endl;
		}

		//assignment operator overload	
		List &operator=(List &list) {
			//Make sure the list on the left is empty or empty
			//it to prevent memory leaks		
			while (!empty()) {
				pop_front();
			}	
			
			_front=nullptr;
			_back=nullptr;
			_size=0;
			reccopy(list._front);
			
			return *this;
		}

		template<typename V> bool operator==(const List<V> &a) {
			Dlist *loc1;
			Dlist *loc2;
			if (_size == a._size) {
				if (_front == nullptr && a._front == nullptr) {
					return true;
				}
				loc1 = _front;
				loc2 = a._front;
				while (true) {
				// Evaluate the loop at the end.
					if (loc1->value != loc2->value) {
						return false;
					}
				       	if (loc1 -> next == nullptr) {
						return true;
					}
					loc1 = loc1 -> next;
					loc2 = loc2 -> next;
				}
			}
		}

		template<typename V> bool operator!=(const List<V> &a) {
			Dlist *loc1;
			Dlist *loc2;
			if (_size == a._size) {
				if (_front == nullptr && a._front == nullptr) {
					return false;
				}
				loc1 = _front;
				loc2 = a._front;
				while (true) {
				// Evaluate the loop at the end.
					if (loc1->value != loc2->value) {
						return true;
					}
				       	if (loc1 -> next == nullptr) {
						return false;
					}
					loc1 = loc1 -> next;
					loc2 = loc2 -> next;
				}
			}
		}
};
