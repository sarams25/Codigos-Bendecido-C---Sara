// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser
//https://www.online-cpp.com/E8plckSIUj
#include<iostream>
using namespace std;

class Vector {
private:
    int* v;
    int capacidad;    
    int size;
    
public:
    Vector(){
        capacidad = 5;
        size = 0;
        v = new int[capacidad];
    }
    
    Vector(int t){
        if(t <= 0){
            t = 1;
        }
        capacidad = t;
        size = 0;
        v = new int[capacidad];
    }
    
    Vector(const Vector& other) {
        capacidad = other.capacidad;
        size = other.size;
        v = new int[capacidad];
        for (int i = 0; i < size; i++) {
            v[i] = other.v[i];
        }
    }
    
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] v;
            capacidad = other.capacidad;
            size = other.size;
            v = new int[capacidad];
            for (int i = 0; i < size; i++) {
                v[i] = other.v[i];
            }
        }
        return *this;
    }
    
    ~Vector() {
        delete[] v;
    }
    
    void add(int dato){
        if(size == capacidad){
            resize();
        }
        v[size++] = dato;
    }
    
    void resize(){
        capacidad += 10;
        int* v2 = new int[capacidad];
        for (int i = 0; i < size; i++) {
            v2[i] = v[i];
        }
        delete[] v;
        v = v2;
    }
    
    void insertar(int i, int dato){
        if(size == capacidad){
            resize();
        }
        
        for (int j = size; j > i; j--) {
            v[j] = v[j - 1];
        }
        v[i] = dato;
        size++;
    }
    
    void eliminar(int i){
        for (int j = i; j < size - 1; j++) {
            v[j] = v[j + 1];
        }
        size--;
    }
    
    void eliminar_todo(int dato){
        
        for (int j = 0; j < size; j++) {
                if (v[j]==dato){
                    eliminar(j);
                    j--;
                }
            
        }
        cout<<endl;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return v[index];
    }
    
    void set(int index, int value) {
        if(index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        v[index] = value;
    }
    
    int getSize() {
        return size;
    }
    
    void print(){
        cout<<"=================================================="<<endl;
        for (int i = 0; i < size; i++) {
            cout<<v[i]<<"\t";
        }
        cout<<endl;
        cout<<"=================================================="<<endl;
    }
    
    int find(int dato){
        for (int j = 0; j < size; j++) {
            if(v[j]== dato){
                cout<<v[j]<< endl; 
                return j; 
            }
        }
        return -1; 
    }

    
    /*
    ===================================================
    
                    Recursividad
                    
    ===================================================
    */
    //Busqueda Binaria
    int busquedaBinaria(int x, int linferior, int lsuperior){
            if(linferior >= lsuperior){
                return -1; 
            }
            int i = (lsuperior + linferior)/2;  
            if(v[i]>x){
                return busquedaBinaria(x, linferior, i- 1); 
            }else if (v[i] < x){
                return busquedaBinaria(x, i+1, lsuperior);
            }else{
                cout << "El dato " << x << " se encuentra en la posición " << i << endl; 
                return i; 
            }
            
        }
        /*
    ===================================================
    
                    Ordenamiento 
                    
    ===================================================
    */
        
        //Bubble Sort
        void bubbleSort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (v[j] > v[j + 1]) {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
        cout << "Vector ordenado Bubble Sort." << endl;
        cout << endl;
    }
    //Shell Sort 
    void shellSort() {
        for (int gap = size/2; gap > 0; gap /= 2) {
            for (int i = gap; i < size; i++) {
                int temp = v[i];
                int j;
                for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                    v[j] = v[j - gap];
                }
                v[j] = temp;
            }
        }
        cout << "Vector ordenado Shell Sort." << endl;
        cout << endl;
    }
    
    //Insert Sort
    void insertSort() {
        for (int i = 1; i < size; i++) {
            int key = v[i];
            int j = i - 1;
            
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j = j - 1;
            }
            v[j + 1] = key;
        }
        cout << "Vector ordenado Insert Sort." << endl;
        cout << endl;
    }
    
    //Add Ord (Inserción ordenada)
    void addOrd(int dato) {
        if (size == capacidad) {
            resize();
        }
        
        int i = size - 1;
        while (i >= 0 && v[i] > dato) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = dato;
        size++;
        cout << "Dato " << dato << " insertado en orden." << endl;
        cout << endl;
    }
    
    //Quick Sort
    void quickSort() {
        quickSortHelper(0, size - 1);
        cout << "Vector ordenado Quick Sort." << endl;
        cout << endl;
    }
    
private:
    void quickSortHelper(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSortHelper(low, pi - 1);
            quickSortHelper(pi + 1, high);
        }
    }
    
    int partition(int low, int high) {
        int pivot = v[high];
        int i = (low - 1);
        
        for (int j = low; j <= high - 1; j++) {
            if (v[j] < pivot) {
                i++;
                // Intercambio manual
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
        // Intercambio manual
        int temp = v[i + 1];
        v[i + 1] = v[high];
        v[high] = temp;
        return (i + 1);
    }
    
public:
    //Merge Sort
    void mergeSort() {
        mergeSortHelper(0, size - 1);
        cout << "Vector ordenado Merge Sort." << endl;
        cout << endl;
    }
    
private:
    void mergeSortHelper(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            mergeSortHelper(left, mid);
            mergeSortHelper(mid + 1, right);
            
            merge(left, mid, right);
        }
    }
    
    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        int* L = new int[n1];
        int* R = new int[n2];
        
        for (int i = 0; i < n1; i++)
            L[i] = v[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = v[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                v[k] = L[i];
                i++;
            } else {
                v[k] = R[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            v[k] = L[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            v[k] = R[j];
            j++;
            k++;
        }
        
        delete[] L;
        delete[] R;
    }
    
public:
    //Selection Sort
    void selectionSort() {
        for (int i = 0; i < size - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < size; j++) {
                if (v[j] < v[min_idx])
                    min_idx = j;
            }
            // Intercambio manual
            int temp = v[min_idx];
            v[min_idx] = v[i];
            v[i] = temp;
        }
        cout << "Vector ordenado Selection Sort." << endl;
        cout << endl;
    }
    
    // Heap Sort (tu implementación)
    bool ishoja(int i,int n){
        if (izq(i)>=n){
            return true;
        }
        else{
            return false;
        }
    }
    
    int izq(int i){
        return 2*i+1;
    }
    
    int der(int i){
        return 2*(i+1);
    }
    
    int padre(int i){
        return (i-1)/2;
    }
    
    int lastpadre(){
        return (size-2)/2;
    }
    
    void heapify(int i, int n){
        if (!ishoja(i,n)){
            int mayor =v[i];
            int mayor_pos=i;
            
            if (v[izq(i)]>v[i]){
                mayor=v[izq(i)];
                mayor_pos=izq(i);
            }
            
            if (der(i)<n){
                if(v[der(i)]>mayor){
                    mayor=v[der(i)];
                    mayor_pos=der(i);
                }
            }
            
            if (mayor_pos!=i){
                int temp=v[i];
                v[i]=v[mayor_pos];
                v[mayor_pos]=temp;
                heapify(mayor_pos,n);
            }
        }
    }
    
    void heapsort(){
        int last = lastpadre();
        for (int i = last; i >= 0; i--) {
            heapify(i,size);
        }
        print();
        int temp;
        for (int i = 0; i < size; i++) {
            temp=v[0];
            v[0]=v[size - 1-i];
            v[size - 1-i]=temp;
            heapify(0,size - 1-i);
            print();
        }
        cout << "Vector ordenado Heap Sort." << endl;
        cout << endl;
    }
    
    
};