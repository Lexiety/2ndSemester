#include <iostream>
#include <string>
#include <memory>
using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T data);
    void clear();
    void pop_front();
    void push_front(T data);
    void insert(T data, int index);
    void removeNode(int index);
    void pop_back();
    int getSize() { return Size; }

    
    T& operator [](const int index);

private:

    template<typename T>

    class Node
    {
    public:
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T>* head;
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{

}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    Size++;

}

template<typename T>
void List<T>::pop_front() // Удаление первого элемента списка
{
    Node <T> *temp = head; // Сохраняем указатель на первый элемент
    head = head->pNext; // В head засунули адрес второго элемента
    delete temp; //Удаляем бывший первый элемент
    Size--;
}

template<typename T>
void List<T>::push_front(T data) // Добавление нового элемента в начало
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::insert(T data, int index) // Добавление нового элемента в начало
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node <T>* newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}







template<typename T>
void List<T>::removeNode(int index) // Добавление нового элемента в начало
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node <T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    removeNode(Size - 1);
}



template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;

    Node<T>* current = this->head;

    while (current != nullptr)
    {
        if (counter == index)
        {
            return current -> data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::clear()
{
    while (Size>0)
        pop_front();
}

int main()
{
    List<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.pop_front(); //Удаление первого
    lst.push_front(22); //Добавление в начало
    lst.insert(128, 2);  //Вставка
    lst.removeNode(1); //Удаление элемента
    lst.pop_back(); // Удаление последнего

    cout << lst.getSize() << endl;

    for (int i = 0; i < lst.getSize();i++)
        cout << lst[i] << endl;

    lst.clear();  //Удаление списка
    return 0;
}
