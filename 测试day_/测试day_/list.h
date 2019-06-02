#pragma once
#include<iostream>
using namespace std;

class Node
{
public:
	Node(int data) :_data(data), _next(nullptr) {}
	Node() :_next(nullptr) {}
	int _data;
	Node* _next;
};
class List
{
public:

	List()
		:_pHead(nullptr)
		, _pTail(nullptr)
	{}
	~List()
	{
		Clear();
	}

	void InsertHead(int data);//头插
	void InsertTail(int data);//尾插
	void InsertIvalue(int i, int data);//按位置插入
	void DeleteHead();
	void DeleteTail();
	void DeleteIvalue(int i);
	Node* Getip(int i);//获取某个节点是链表中的第几个
	int Getlength();
	void Print();
	bool Isempty();
	void Sort();//排序

	void Resverse();//逆序
	void Clear();

	Node* FindToTail(unsigned int k);//倒数第k个节点
private:
	Node* _pHead;
	Node* _pTail;
};
bool List::Isempty()
{
	return _pHead == nullptr ? true : false;
}
void List::Clear()
{
	Node* p = _pHead;
	while (p != nullptr)
	{
		p = p->_next;
		DeleteHead();
	}
	delete p;
	p = nullptr;



	/*Node*p = _pHead;
	Node *q = p;
	while (p != nullptr)
	{
	p = p->_next;
	delete q;
	q = p;
	}
	_pHead = nullptr;*/
}
void List::DeleteHead()
{
	if (Isempty())
		return;
	Node* p = _pHead;
	_pHead = _pHead->_next;
	delete p;
	p = nullptr;
}

void List::DeleteTail()

{
	if (Isempty())
		return;
	Node* p = Getip(Getlength() - 1);
	if (p == nullptr)
	{
		DeleteHead();
	}
	else
	{
		p->_next = nullptr;
		delete _pTail;
		_pTail = p;

	}

}

void List::DeleteIvalue(int i)
{
	if (Isempty() || i > Getlength())

		return;
	else if (i == 1)
		DeleteHead();
	else if (i == Getlength())
		DeleteTail();
	else
	{
		Node* p = Getip(i - 1);
		Node* q = Getip(i);
		p->_next = q->_next;
		delete q;
		q = nullptr;
	}
}
int List::Getlength()
{
	Node* p = _pHead;
	int i = 0;
	while (p != nullptr)
	{

		p = p->_next;
		++i;
	}
	return i;
}
Node* List::Getip(int i)
{
	if (i <= 0 || i > Getlength() || Getlength() == 0)
		return nullptr;
	Node* p = _pHead;
	while (--i)
	{
		p = p->_next;
	}
	return p;
}
void List::InsertHead(int data)
{

	Node *p = new Node(data);
	if (_pHead == nullptr)
		_pHead = _pTail = p;
	else
	{
		p->_next = _pHead;

		_pHead = p;
	}
}
void List::InsertTail(int data)
{
	Node* p = new Node(data);
	if (_pHead = nullptr)
		_pHead = _pTail = p;
	else
	{
		_pTail->_next = p;
		_pTail = p;
	}
}
void List::InsertIvalue(int i, int data)
{
	if (i == 1)
		InsertHead(data);
	else if (i == Getlength() + 1)

		InsertTail(data);
	else
	{
		Node* p = new Node(data);
		Node* q = Getip(i - 1);
		if (q != nullptr)
		{
			p->_next = q->_next;
			q->_next = p;
		}

	}
}
void List::Print()
{
	Node*p = _pHead;
	while (p)
	{
		cout << p->_data << " ";
		p = p->_next;
	}
	cout << endl;
}
void List::Resverse()
{

	Node* p = nullptr, *q = nullptr, *l = nullptr;
	if (Isempty() || _pHead->_next == nullptr)
		return;
	p = _pHead;
	q = p->_next;
	p->_next = nullptr;
	while (q->_next != nullptr)
	{
		l = q->_next;
		q->_next = p;
		p = q;
		q = l;
	}
	q->_next = p;
	_pHead = q;
}
void List::Sort()
{
	Node* p, *q = nullptr;
	for (p = _pHead; p->_next != nullptr; p = p->_next)
	{
		for (q = _pHead; q->_next != nullptr; q = q->_next)
		{
			if (q->_data > q->_next->_data)
			{
				/*int t = q->_data;
				q->_data = q->_next->_data;
				q->_next->_data = t;*/
				swap(q->_data, q->_next->_data);
			}
		}
	}
}
Node* List::FindToTail(unsigned int k)
{
	if (Isempty() || k == 0)
		return nullptr;
	Node * p = _pHead;
	Node *q = nullptr;
	for (unsigned int i = 0; i < k-1; ++i)
	{
		if (p->_next != nullptr)
			p = p->_next;
		else
			return nullptr;
	}
	q = _pHead;
	while (p->_next != nullptr)
	{
		p = p->_next;
		q = q->_next;
	}
	return q;
}
