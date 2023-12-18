#pragma once
class List
{ 
private:
	struct Node
	{
		const char* data;
		Node* previous;
		Node* next;
	};

	Node* head;
	Node* tail;
	int size;
	void Copy(const List& other);
	void Move(List&& other) noexcept;
public:
	List();
	List(const List& other);
	List(List&& other) noexcept;

	~List();
	void Clear();
	List& operator=(const List& other);
	List& operator=(List&& other);

	void PopFront();

	void Add(const char*& value, const int& position);

	int Size();

	void PushBack(const char*& value);

	int SearchFirstSymbol(const char& symbol);
	void Show()const;
};

