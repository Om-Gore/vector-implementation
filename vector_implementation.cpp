#include <bits/stdc++.h>
using namespace std;

const int DEFAULT_VECTOR_SIZE=1;

template <typename T>

class myVector {
    private: 
    int  size;
    int  capacity;
    T* elements;

    public:

        //vector<float> v;
        //contructor
        myVector(){

            //size implies elements present in myVector 
            size=0;

            //capacity implies actual size of myVectors i.e. how much elemets the myVector can accomodate  
            capacity=DEFAULT_VECTOR_SIZE;

            // allocating memory in heap and assing pointer to elements 
            elements= new T[DEFAULT_VECTOR_SIZE]; //we can also write elements = (T*) malloc(capacity*sizeof(T));
        }

        //vector<int> v(5,2); implies v={2,2,2,2,2}
        myVector(int n,T value){

            size=n;
            capacity=n*2;
            elements= new T[capacity];

            //initializing with given value
            for(int i=0; i<size; i++){ 
                elements[i]=value;
            }

        }

        //vector v(v1);
        //copy constructor
        myVector(const myVector& vec){
           
           capacity=vec.capacity;
           size=vec.size;

            elements=new T[capacity];

            for(int i=0; i<size; i++){
                elements[i]=vec[i];
            }
        }

        //destructor is called when object goes out of scope
        ~myVector(){
            //free the block of memory allocated and pointed by pointer elements
            delete[] elements;
        }


        //v.size()
        //note that data-member and member function should not have same name
        int  Size() const{
            return size;
        }

        //v.capacity()
        //note that data-member and member function should not have same name
        int  Capacity() const{
            return capacity;
        }

        //v.isEmpty()
        bool isEmpty() const{
            return size==0;
        }


        //v[1]=2;
        T operator[] (int index){
            return elements[index];
        }


        //x=v[1];
        const T& operator[] (int index) const{
            return elements[index];
        }


        //v1=v2;
        myVector& operator=(myVector& vec){
            if(capacity<vec.Size()){
                delete[] elements;
                capacity=vec.Capacity();
                elements=new T[capacity];
            }

            size=vec.Size();
            for(int i=0; i<size; i++){
                elements[i]=vec.elements[i];
            }

            return *this;
        }

        //v.push_back(1);
        //complexity depends on whether capacity==size
        //if capacity==size then complexity is O(n) else complexity is O(1)
        void push_back(const T& value){
            if(capacity==size){

                capacity=2*capacity;
                T* temp= new T[capacity];

                for(int i=0; i<size ; i++){
                    temp[i]=elements[i];
                }
                
                delete[] elements;

                elements=temp;
            }

            elements[size]=value;
            size++;
        }


        //v.pop_back();
        void pop_back(){
            if(size>0) size--;
        }

        //v.clear();
        void clear(){
            size=0;
        }

        //v.erase(2);
        void erase(int index){
            for(int i=index; i<size-1; i++){
                elements[i]=elements[i+1];
            }
            size--;
        }


        //v.insert(2,3);
        void insert(int index,T value){
            if(size==capacity){
                capacity=2*size;

                T* temp= new T[capacity];

                for(int i=0; i<size; i++){
                    temp[i]=elements[i];
                }
                
                delete[] elements;
                elements=temp;
            }

            int temp=value;

            for(int i=index; i<size; i++){

                int x=elements[i];
                elements[i]=temp;
                temp=x;
            }

            elements[size]=temp;
            size++;

        }

};

int main(){
    
    myVector<int> vec(5,2);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);

    vec.insert(2,3);
    
    

    for(int i=0; i<vec.Size(); i++){
        cout<<"index "<<i<<" = "<<vec[i]<<endl;
    }

    cout<<"size is "<<vec.Size()<<endl;
    cout<<"capacity is "<<vec.Capacity()<<endl;

    return 0;
}
