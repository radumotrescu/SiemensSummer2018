#include <iostream>
#include <list>

#include <Amount.h>
#include <Complex.h>

class AmountList {
public:
	friend std::ostream& operator<<(std::ostream& os, const AmountList& amountList);

	AmountList() : m_first(nullptr), m_last(nullptr), m_size(0) { }
	AmountList(const AmountList& other) { }
	~AmountList() { this->Clear(); }

	AmountList& InsertFront(Amount* amount) {
        ++m_size;

        Node* entry = new Node(amount, m_first);
        m_first = entry;

        if (m_size == 1) m_last = m_first;

		return *this;
	}

	AmountList& InsertBack(Amount* amount) {
        ++ m_size;

        Node* entry = new Node(amount, nullptr);

        if (m_last)
            m_last->next = entry;
        else
            m_first = entry;
           
        m_last = entry;

		return *this;
	}

	Amount* RemoveFront() {
        if (!m_first) throw "Empty list";

        --m_size;
        if (m_size == 0) m_last = nullptr;

        Node* first = m_first;
        Amount* amount = first->amount;

        m_first = m_first->next;

        delete first;
		return amount;
	}

	Amount* RemoveBack() {
        if (!m_last) throw "Empty list";

        Node* last = m_last;
        Amount* amount = m_last->amount;

        --m_size;
        if (m_size == 0) {
            m_first = nullptr;
            m_last = nullptr;
        } else {
            m_last = this->GetNode(m_size - 1);
            m_last->next = nullptr;
        }

        delete last;
        return amount;
	}

	AmountList& Clear() {
        Node* node = m_first;
        for (size_t i = 0; i < m_size; ++i) {
            Node* next = node->next;
            delete node;
            node = next;
        }
        
        m_size = 0 ;
        m_first = m_last = nullptr;

		return *this;
	}

	size_t Size() const {
		return m_size;
	}

	Amount* Get(const size_t index) {
		if (index >= m_size) throw "Out of bounds";
		return this->GetNode(index)->amount;
	}

private:
	struct Node {
		Node(Amount* amount, Node* next) : amount(amount), next(next) { }

		Amount* amount;
		Node* next;
	};

	Node* GetNode(const size_t index) {
		Node* node = m_first;
		for (size_t i = 0; i < index; ++i) 
			node = node->next;
		
		return node;
	}

	Node* m_first;
	Node* m_last;
	size_t m_size;
};

std::ostream& operator<<(std::ostream& os, const AmountList& amountList) {
	AmountList::Node* node = amountList.m_first;
	for (size_t i = 0; i < amountList.Size(); ++i) {
		os << *(node->amount) << std::endl;
		node = node->next;
	}

	return os;
}

/************************************************************************************************************************/

// OMG SO MUCH COPY-PASTA
class ComplexList {
public:
	friend std::ostream& operator<<(std::ostream& os, const ComplexList& amountList);

	ComplexList() : m_first(nullptr), m_last(nullptr), m_size(0) { }
	ComplexList(const ComplexList& other) { }
	~ComplexList() { this->Clear();  }

	ComplexList& InsertFront(Complex* data) {

        return *this;
	}

	ComplexList& InsertBack(Complex* data) {
		// Implement this method

		return *this;
	}

	Complex* RemoveFront() {
		// Implement this method

		return nullptr;
	}

	Complex* RemoveBack() {
		// Implement this method

		return nullptr;
	}

	ComplexList& Clear(){
		// Implement this method

		return *this;
	}

	size_t Size() const {
		return m_size;
	}

	Complex* Get(const size_t index) {
		if (index >= m_size) throw "Out of bounds";
		return this->GetNode(index)->data;
	}

private:
	struct Node {
		Node(Complex* data, Node* next) : data(data), next(next) { }

		Complex* data;
		Node* next;
	};

	Node* GetNode(const size_t index) {
		Node* node = m_first;
		for (size_t i = 0; i < index; ++i)
			node = node->next;

		return node;
	}

	Node* m_first;
	Node* m_last;
	size_t m_size;
};

std::ostream& operator<<(std::ostream& os, const ComplexList& complexList) {
	ComplexList::Node* node = complexList.m_first;
	for (size_t i = 0; i < complexList.Size(); ++i) {
		os << *(node->data) << std::endl;
		node = node->next;
	}

	return os;
}

/************************************************************************************************************************/


template<typename T> class List {
    public:

    template<typename T> friend std::ostream& operator<<(std::ostream& os, const List<T>& list) ;

    List() : m_first(nullptr), m_last(nullptr), m_size(0) { }
    List(const List& other) { }
    ~List() { this->Clear(); }

    List& InsertFront(T* data) {
        ++m_size;

        Node* entry = new Node(data, m_first);
        m_first = entry;

        if (m_size == 1) m_last = m_first;

        return *this;
    }

    List& InsertBack(T* data) {
        ++m_size;

        Node* entry = new Node(data, nullptr);

        if (m_last)
            m_last->next = entry;
        else
            m_first = entry;

        m_last = entry;

        return *this;
    }

    T* RemoveFront() {
        if (!m_first) throw "Empty list";

        --m_size;
        if (m_size == 0) m_last = nullptr;

        Node* first = m_first;
        T* data = first->data;

        m_first = m_first->next;

        delete first;
        return amount;
    }

    T* RemoveBack() {
        if (!m_last) throw "Empty list";

        Node* last = m_last;
        T* data = m_last->data;

        --m_size;
        if (m_size == 0) {
            m_first = nullptr;
            m_last = nullptr;
        } else {
            m_last = this->GetNode(m_size - 1);
            m_last->next = nullptr;
        }

        delete last;
        return amount;
    }

    List& Clear() {
        Node* node = m_first;
        for (size_t i = 0; i < m_size; ++i) {
            Node* next = node->next;
            delete node;
            node = next;
        }

        m_size = 0;
        m_first = m_last = nullptr;

        return *this;
    }

    size_t Size() const {
        return m_size;
    }

    T* Get(const size_t index) {
        if (index >= m_size) throw "Out of bounds";
        return this->GetNode(index)->data;
    }

    private:
    struct Node {
        Node(T* data, Node* next) : data(data), next(next) { }

        T* data;
        Node* next;
    };

    Node* GetNode(const size_t index) {
        Node* node = m_first;
        for (size_t i = 0; i < index; ++i)
            node = node->next;

        return node;
    }

    Node* m_first;
    Node* m_last;
    size_t m_size;
};

template<typename T> std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    List<T>::Node* node = list.m_first;
    for (size_t i = 0; i < list.Size(); ++i) {
        os << *(node->data) << std::endl;
        node = node->next;
    }

    return os;
}

/************************************************************************************************************************/

template<typename T> void Print(const std::list<T*>& list) {
    for (auto& entry : list)
        std::cout << *entry << std::endl;
    std::cout << std::endl;
}

/************************************************************************************************************************/

int main() {

	Amount electricityBill(15, 90);
	Amount gasBill(20, 30);
	Amount phoneBill(10, 25);

    std::list<Amount*> stdListAmount;
    stdListAmount.push_back(&electricityBill);
    stdListAmount.push_back(&gasBill);
    stdListAmount.push_back(&phoneBill);

    Print<Amount>(stdListAmount);
	
	// Uncomment the part below after you have implemented AmountList

	AmountList bills;
	bills.InsertBack(&electricityBill).InsertBack(&gasBill).InsertFront(&phoneBill);

	std::cout << "I have the following expenses (generated from AmountList):" << std::endl;
	std::cout << bills << std::endl << std::endl;

	/************************************************************************************************************************/

	Complex somethingComplex(2.0, 0.0);
	Complex anotherComplexThing(3.0, 24.0);

	// Uncomment the part below after you have implemented ComplexList

	//ComplexList data;
	//data.InsertFront(&somethingComplex).InsertBack(&anotherComplexThing);

	//std::cout << "I have the following data (generated from ComplexList):" << std::endl;
	//std::cout << data << std::endl << std::endl;

	return 0;
}