#include <iostream>
using namespace std;

template<typename T>
class myList {
public:
    struct Node {
        T data;
        Node* next = nullptr;
    };
    myList() {
        header = nullptr;
    }

    Node* push_front(const T& value) {
        Node* tmp = new Node;
        tmp->data = value;
        if (header == nullptr) {
            header = tmp;
        }
        else {
            tmp->next = header;          
            header = tmp;
        }
        return tmp;

    }

    void remove_tail() {
        Node* ptr = header;
        while (ptr->next->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = nullptr;
        delete ptr->next;
    }
    int finde(const T& value) {
        Node* ptr = header;
        int index = 0;
        while (ptr->next != nullptr && ptr->data != value) {
            ptr = ptr->next;
            index++;
        }
        if (ptr->data != value) {
            return -1;
        }
        return index;
    }
    void print() {
        Node* ptr = header;
        int index = 0;
        while (ptr != nullptr) {
            cout<<"|["<<index++<<"]"<< ptr->data<<' ';
            ptr = ptr->next;
        }
        cout << endl;
    }
    void remove_all() {
        Node* ptr ;
        int index = 0;
        while (header) {
            ptr = header->next;
            cout << "[" << index++ << "] " << header->data<<" was deleted" << endl;
            delete header;
            header = ptr;
        }
    }
    ~myList() {
        remove_all();
    }


private:

    Node* header;

};



int main()
{
    int n = 20;//Кол элементов
    myList<int> list;
    for (int i = 0; i < n; i++) {
        list.push_front(i);//Заполняем списко вставкой в начало
    }
    list.print();//Выводим списов
    list.remove_tail();//Удаляем последний элемент
    list.print();//Выводим список
    int key = 10;//Ключ для поиска
    int index = list.finde(key);
    cout << "Index of "<<key<<" element is: "<<index << endl;
    return 0;
}

