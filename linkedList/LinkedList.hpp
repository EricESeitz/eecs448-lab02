/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
		// ***Eric S. Feb/08/2019: Returns m_size
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;
	// ***Eric S. Feb/08/2019: Searches from m_front to back, Compares contents of temp to value. Returns true if matching value found. Else returns false

	if(temp != nullptr)
	{
		do
	 {
		 if (temp -> getValue() == value)
		 {
		 	 isFound = true;
			 return(isFound);
		 }
		 temp = temp->getNext();
	 }while(temp->getNext() != nullptr);
  }

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;
	// ***Eric S. Feb/08/2019: Removes back pointer

	if(!isEmpty())
	{
		if (m_front -> getNext() != nullptr)	//there is an m_front and at least 1 next node
		{
			secondintoLast = m_front;
			lastNode = m_front->getNext();

			while (lastNode -> getNext() != nullptr)	//propogate down the list until last node is found
			{
				lastNode = lastNode -> getNext();
				secondintoLast = secondintoLast -> getNext();
			}
			secondintoLast->setNext(nullptr);	//disconnect last node from chain
			delete lastNode;
			m_size--;
			isRemoved = true;
		}
		else	//There is only m_front, delete m_front
		{		lastNode = m_front;
		m_front = nullptr;
		delete lastNode;
		m_size--;
		isRemoved = true;
		}
	}

	return(isRemoved);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
