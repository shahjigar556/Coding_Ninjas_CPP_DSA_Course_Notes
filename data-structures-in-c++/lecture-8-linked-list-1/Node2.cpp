class Node
{
public:
	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

/*
class Node
{
private:
	int data;
	Node *next;

public:
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	void setData(int data)
	{
		this->data = data;
	}
	int getData() const
	{
		return this->data;
	}
	void setNext(Node *next)
	{
		this->next = next;
	}
	Node *getNext() const
	{
		return this->next;
	}
};
*/