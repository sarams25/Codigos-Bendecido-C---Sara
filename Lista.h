#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // FUNCIONES_H

#include <sstream>
#include <string>
#include <type_traits>

using namespace std;

#ifndef FUNCIONES_TO_STRING
#define FUNCIONES_TO_STRING

// Verificación si un tipo tiene un método to_string()
template <typename, typename = void>
struct has_to_string : std::false_type {};

template <typename T>
struct has_to_string<T, std::void_t<decltype(std::declval<T>().to_string())>> 
    : std::is_same<decltype(std::declval<T>().to_string()), std::string> {};

#endif // FUNCIONES_TO_STRING

template <typename T>
class Nodo {
    T dato;
    Nodo* next;

    // General template for types that can be converted to string
    template <typename U>
    typename std::enable_if<std::is_arithmetic<U>::value, std::string>::type
    convert_to_string(const U& value) const {
        return std::to_string(value);
    }

    // Specialization for std::string
    template <typename U>
    typename std::enable_if<std::is_convertible<U, std::string>::value, std::string>::type
    convert_to_string(const U& value) const {
        return value;
    }

    template <typename U>
    typename std::enable_if<has_to_string<U>::value, std::string>::type
    convert_to_string(const U& value) const {
        return value.to_string();
    }

    // Fallback for types that do not have a direct conversion
    template <typename U>
    typename std::enable_if<!std::is_arithmetic<U>::value && !std::is_convertible<U, std::string>::value && !has_to_string<U>::value, std::string>::type
    convert_to_string(const U&) const {
        return "[Unsupported Type]";
    }
    
public:

    Nodo(T value) : dato(value), next(nullptr) {}

    std::string to_string() const {
        return convert_to_string(dato);
    }
    
    T getDato(){
        return dato;
    }
    
    void setDato(T d){
        dato = d;
    }
    
    Nodo* getNext(){
        return next;
    }
    
    void setNext(Nodo* n){
        next = n;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Nodo<T>& obj) {
        return os << obj.to_string();
    }
    
    Nodo<T>& operator=(const Nodo<T>& other) {
        if (this != &other) {
            dato = other.dato;
            next = other.next;
        }
        return *this;
    }
    

};

template <typename T>
class Lista {
private:
    
    Nodo<T>* head;
    int size;

public:
    // Constructor
    Lista() : head(nullptr), size(0) {}

    // Destructor
    ~Lista() {
        while (head) {
            Nodo<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
    }

    // Add a new node at the end
    void add(T value) {
        Nodo<T>* newNode = new Nodo<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Nodo<T>* temp = head;
            while (temp->getNext()) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
        size++;
    }
    
    int getSize(){
        return size;
    }

    // Get the value at a given index
    T get(int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
        Nodo<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->getNext();
        }
        return temp->getDato();
    }
    
    // Get the value at a given index
    Nodo<T>* getNodo(int index) {
        //Incluya su código aquí
    }

    // Insert a node at a given position
    void insert(int index, T value) {
        //Incluya su código aquí
    }

    // Remove a node at a given position
    void remove(int index) {
        //Incluya su código aquí
    }

    // Get the size of the list
    int getSize() const {
        return size;
    }

    int find(T value) const {
        //Incluya su código aquí
        return -1; // Not found
    }

    // Print the linked list
    void print() {
        Nodo<T>* temp = head;
        while (temp) {
            std::cout << temp->getDato() << " -> ";
            temp = temp->getNext();
        }
        std::cout << "nullptr\n";
    }
    
    // Overload the [] operator for accessing elements
    Nodo<T>* operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return getNodo(index);
    }
    
    std::string to_string() const {
        string s = "";
        Nodo<T>* temp = head;
        while (temp) {
            s = s + temp->to_string() + " -> ";
            temp = temp->getNext();
        }
        s = s + "nullptr\n";
        return s;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& obj) {
        return os << obj.to_string();
    }

    Lista<T>& operator=(const Lista<T>& other) {
        if (this != &other) {
            head = other.head;
            size = other.size;
        }
        return *this;
    }
    
    
};