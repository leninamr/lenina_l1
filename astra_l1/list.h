#pragma once
class List {

	private:

		class Elem
		{
		public:
			Elem(int data, Elem* next = nullptr) {
				this->data = data;
				this->next = next;
			};
			~Elem() {};

			int data;
			Elem* next;
		};

		Elem* head;
		Elem* tail;
		size_t size;

	public:
		List();
		~List() {};
		void reset_list();		
		void add_first(int newElem);
		size_t get_size() const;
		bool isEmpty();
		void push_back(int newElem);
		void push_front(int newElem);
		void pop_back();
		void pop_front();
		void insert(int, size_t);
		int at(size_t index) const;
		void remove(size_t);
		void print_to_console();
		void clear();
		void set(size_t, int);
		void swap(size_t, size_t);
		
};