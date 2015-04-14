#pragma once

#include <iostream>

template <typename T> class Node
{
public:
	Node() {}
	~Node() { next = NULL; prev = NULL; delete data; }
	T data;
	Node * next;
	Node * prev;
};

template <typename T> class XList
{
public:
	XList() : head(NULL), tail(NULL), count(0) {}
	XList(XList<T> const & other) : head(NULL), tail(NULL), count(0) { *this = other; }
	~XList() { Clear(); }
	void Add_head(T const _data);
	void Add_tail(T const _data);
	void Del_head(void);
	void Del_tail(void);
	bool Empty(void) const { return (head == NULL); };
	void Clear(void);
	int Get_count(void) const { return count; }
	T& Get_head(void) const { if (head == NULL) throw "List empty!"; return head->data; }
	T& Get_tail(void) const { if (head == NULL) throw "List empty!"; return tail->data; }
	void operator=(const XList<T>& other);
	friend class Node<T>;

	class XListIterator
	{
	public:
		XListIterator & operator++ () { _node = _node->next; return *this; }
		XListIterator  operator++ (int) { XListIterator tmp = *this; _node = _node->next; return tmp; }
		XListIterator & operator-- () { _node = _node->prev; return *this; }
		XListIterator operator-- (int) { XListIterator tmp = *this; _node = _node->prev; return tmp; }
		bool operator== (XListIterator const & other) { return (_node == other._node); }
		bool operator!= (XListIterator const & other) { return !(_node == other._node); }
		T &operator *() { return _node->data; }
		T *operator ->(){ return &_node->data; }

		XListIterator() : _node(0) {}
	private:
		Node<T> * _node;
		XListIterator(Node<T> * m_node) :_node(m_node) {}
		friend class XList<T>;
		friend class Node<T>;
	};
	XListIterator Head_XList(void) const { if (head == NULL) throw "List empty."; return XListIterator(head); }
	XListIterator Tail_XList(void) const { if (head == NULL) throw "List empty."; return XListIterator(tail); }
	XListIterator End(void) const { return XListIterator(0); }
private:	
	Node<T> * head;
	Node<T> * tail;
	int count;
};

template <typename T>
void XList<T>::Add_head(T const _data)
{
	Node<T> * to_add = new Node<T>;
	if (head == NULL)
	{
		to_add->next = NULL;
		to_add->prev = NULL;
		to_add->data = _data;
		head = to_add;
		tail = to_add;
		++count;
	}
	else
	{
		head->prev = to_add;
		to_add->data = _data;
		to_add->next = head;
		to_add->prev = NULL;
		head = to_add;
		++count;
	}
}

template <typename T>
void XList<T>::Add_tail(T const _data)
{
	Node<T> * to_add = new Node<T>;
	if (head == NULL)
	{
		to_add->next = NULL;
		to_add->prev = NULL;
		to_add->data = _data;
		head = to_add;
		tail = to_add;
		++count;
	}
	else
	{
		tail->next = to_add;
		to_add->next = NULL;
		to_add->prev = tail;
		to_add->data = _data;
		tail = to_add;
		++count;
	}
}

template <typename T>
void XList<T>::Del_head(void)
{
	if (head != NULL)
	{
		Node<T> * to_del = head;
		head = head->next;
		head->prev = NULL;
		delete to_del;
		--count;
	}
}

template <typename T>
void XList<T>::Del_tail(void)
{
	if (head != NULL)
	{
		Node<T> * to_del = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete to_del;
		--count;
	}
}

template <typename T>
void XList<T>::Clear(void)
{
	if (head != NULL)
	{
		Node<T> * to_del = this->head;
		Node<T> * current = this->head;
		while (to_del != NULL)
		{			
			current = current->next;
			delete to_del;
			to_del = current;
		}
		this->head = NULL;
		this->tail = NULL;
		this->count = 0;
	}
}

template <typename T>
void XList<T>::operator=(const XList<T>& other)
{
	if (&other == this)
		return;

	Clear();

	Node<T> * m_node = other.head;
	while (m_node)
	{
		Add_tail(m_node->data);
		m_node = m_node->next;
	}
}