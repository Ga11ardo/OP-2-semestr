#include<iostream>
#include <sstream>
#include <regex>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    Node* parent;
    Node(T d) : data(d), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <typename T>
class Set {
    //- визначення пустоти множини
    //- перевірка приналежності елемента множині
    //- видалення елемента з множини
    //- перетин двох множин

    Node<T>* root;

    Node<T>* insertHelper(Node<T>* root, T data, Node<T>* parent) {
        if (search(data)) {
            cout << "Множина не має дублікатiв!" << endl;
        }
        else if (root == nullptr) {
            root = new Node<T>(data);
            root->parent = parent;
            return root;
        }
        else if (data < root->data) {
            root->left = insertHelper(root->left, data, root);
        }
        else {
            root->right = insertHelper(root->right, data, root);
        }
        return root;
    };

    bool searchHelper(Node<T>* root, T data) {
        if (root == nullptr) {
            return false;
        }
        else if (root->data == data) {
            return true;
        }
        else if (root->data > data) {
            return searchHelper(root->left, data);
        }
        else {
            return searchHelper(root->right, data);
        }
    };

    Node<T>* removeHelper(Node<T>* root, T data) {
        if (root == nullptr) {
            return root;
        }
        else if (data < root->data) {
            root->left = removeHelper(root->left, data);
        }
        else if (data > root->data) {
            root->right = removeHelper(root->right, data);
        }
        else { //Знайдено вузол для видалення
            if (root->left == nullptr && root->right == nullptr) {
                root = nullptr;
            }
            else if (root->right != nullptr) {//Знайдено наступний елемент
                root->data = successor(root);
                root->right = removeHelper(root->right, root->data);
            }
            else { // Знайдено попередній елемент
                root->data = predecessor(root);
                root->left = removeHelper(root->left, root->data);
            }
        }
        return root;
    };

    T successor(Node<T>* root) {
        root = root->right;
        while (root->left != nullptr) {
            root = root->left;
        }
        return root->data;
    }

    T predecessor(Node<T>* root) {
        root = root->left;
        while (root->right != nullptr) {
            root = root->right;
        }
        return root->data;
    };

public:
    Set() : root(nullptr) {}

    void insert(T data) {
        root = insertHelper(root, data, nullptr);
    }

    bool search(T data) {
        return searchHelper(root, data);
    }

    bool empty() {
        return !root;
    }

    void remove(T data) {
        if (search(data)) {
            root = removeHelper(root, data);
        }
        else {
            cout << "Data is not found in the set!" << endl;
        }
    }

    Set<T> operator/(Set<T>& other) {
        Set<T> result;

        for (typename Set<T>::Iterator it = this->begin(); it != this->end(); ++it) {
            if (other.search(*it)) {
                result.insert(*it);
            }
        }

        return result;
    }

    class Iterator {
        // - ітератор для доступу до елементів списку з операціями:
        //1) встановлення на початок множини .begin()
        //2) перевірка кінця множини !=
        //3) доступ до значення поточного елемента множини *
        //4) перехід до наступного елемента множини ++ 
        Node<T>* current;
    public:
        Iterator(Node<T>* ptr) : current(ptr) {}

        bool operator!=(const Iterator& other) {
            return current != other.current;
        }

        Iterator& operator++() {
            if (current == nullptr)
                return *this;
            if (current->right != nullptr) {
                current = current->right;
                while (current->left != nullptr)
                    current = current->left;
            }
            else {
                Node<T>* parentNode = current->parent;
                while (parentNode != nullptr && current == parentNode->right) {
                    current = parentNode;
                    parentNode = parentNode->parent;
                }
                current = parentNode;
            }
            return *this;
        }

        T& operator*() {
            return current->data;
        }
    };

    Iterator begin() {
        Node<T>* current = root;
        if (current != nullptr) {
            while (current->left != nullptr)
                current = current->left;
        }
        return Iterator(current);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};

int choice();

bool validateInt(const string& input);

template <typename T>
T getInput() {
    string inputStr;
    cin >> inputStr;
    istringstream iss(inputStr);
    T value;
    iss >> value;
    return value;
}

template <typename T>
Set<T> createAndFillSet() {
    Set<T> mySet{};
    int numElements;
    int valid = 0;
    do {
        cout << "Введiть кiлькiсть елементiв: ";
        string n;
        cin >> n;
        if (validateInt(n)) {
            valid = 1;
            numElements = stoi(n);
        }
    } while (!valid);

    cout << "Введiть елементи: \n";
    for (int i = 0; i < numElements; ++i) {
        cout << "Елемент номер " << i + 1 << ": ";
        T element;
        cin >> element;
        mySet.insert(element);
    }
    return mySet;
}

template <typename T>
void display(Set<T>& S) {
    if (S.empty()) {
        cout << "Множина порожня!" << endl;
    }
    else {
        cout << "Множина елементiв: ";
        for (typename Set<T>::Iterator it = S.begin(); it != S.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

template <typename T>
void Task(Set<T>& A) {
    display(A);
    //Перевірка на порожню множину
    if (A.empty()) {
        cout << "Множина порожня" << endl;
    }
    else cout << "Множина не порожня" << endl;

    //Пошук елементу
    cout << "\nВведiть елемент для пошуку: ";
    T searchElement = getInput<T>();
    if (A.search(searchElement)) {
        cout << "Елемент присутнiй у множинi" << endl;
    }
    else {
        cout << "Елемент вiдсутнiй у множинi " << endl;
    }

    //Видалення елементу
    cout << "\nВведiть елемент для видалення: ";
    T removeElement = getInput<T>();
    if (A.search(removeElement)) {
        A.remove(removeElement);
        cout << "Елемент був видалений з множини:" << endl;
        display(A);
    }
    else {
        cout << "Елемент вiдсутнiй у множинi " << endl;
    }

    // Перевірка перетину множин
    cout << "\nВведiть кiлькiсть елементiв для другоi множини:  ";
    int numElements;
    cin >> numElements;
    cout << endl << "Введiть елементи для другоi множини: \n";
    Set<T> B;
    for (int i = 0; i < numElements; ++i) {
        cout << "Елемент номер " << i + 1 << ": ";
        T element = getInput<T>();
        B.insert(element);
    }
    display(B);

    Set<T> intersectionSet = A / B;
    cout << endl << "\nПеретин двох множин: " << endl;
    display(intersectionSet);
}