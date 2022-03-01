#include <iostream>
using namespace std;

template<typename T>
class LinkedList;

template<typename T>
ostream & operator << (ostream &,const LinkedList<T> &);

template<typename T>
class Nodo{
  private:
    T data;
    Nodo<T>* next;
    Nodo<T>* prev;
    template<typename U>
    friend class LinkedList;
  public:
    Nodo(T data){
        this->data = data;//O(1)
        next = NULL;//O(1)
        prev = NULL;
    }

    friend ostream& operator << <T>(ostream &, const LinkedList<T>&);
};

template<typename T>
class LinkedList{
  private:
    Nodo<T> * head;
    Nodo<T> * last;
    
    //O(1)
    int lengthRecursive(Nodo<T> * h){
      if (h == NULL){ // caso base
        return 0;
      }
      else{                  //caso recursivo
        return 1 + lengthRecursive(h->next);
      }
    }

  public:
    LinkedList(){
      head = last = NULL;
    }

    //O(n)
    T get(int index){   
      Nodo<T> *recorre = head; 
      for(int i = 0; i < index; i++){ 
          recorre = recorre->next; 
      }
      return recorre->data;         
    }

		T getIndex(T value){ 
      Nodo<T> * recorre = head; 
      int count = 0;
      while(recorre != NULL){
        if(recorre->data == value){
          return count;
        }

        count++;
        recorre = recorre->next;
      }

      return -1;
    }

    //O(1)
    void addFirst(T dato){
      Nodo<T> * nuevo = new Nodo<T>(dato);
      if(head == NULL&&last == NULL){
        head = last = nuevo;
      } else{
          nuevo->next = head;
          head->prev = nuevo;
          head = nuevo;
      }
    }

    //O(1)
    void addLast(T dato){
          Nodo<T> * nuevo = new Nodo<T>(dato);
          if(head == NULL){
            head= last = nuevo; 
          }
          else{
            last->next = nuevo;
            nuevo->prev = last;
            last = nuevo;
          }

    }

    //O(n)
    void print(){
      Nodo<T> * auxiliar = head;
      while(auxiliar != NULL){
        cout << auxiliar->data << ":";
        auxiliar = auxiliar->next;
      }
      cout << endl;
    }

    //O(n)
    void reverse(){
      Nodo<T> * auxiliar = last;
       while(auxiliar != NULL){
        cout << auxiliar->data << ":";
        auxiliar = auxiliar->prev;
      }
      cout << endl;
    }

    //O(1)
    int length (){
      return lengthRecursive(head);
    }

    //O(1)
    T getFirst(){
      if(head != NULL){
        return head->data;
      }else{
        return T();
      }
    }
    
    //O(n)
    int size(){
      int count = 0;
        Nodo<T> * temp = head;
        while(temp != NULL){
          temp = temp->next;
          count++;
        }
      return count;
    }

    //O(1)
    bool is_empty(){
      return head == NULL;
    }

    //O(1)
    T remove_front(){
        if(is_empty()){ //O(1)
            throw -1;
        } else if(head == last){
            T dato = head->data;
            delete head;
            head = last = NULL;
            return dato;
        } else{
            T dato = head->data;
            head = head->next;
            delete head->prev;
            head->prev = NULL;
            return dato;
        }
    }

		//O(n^2)
    void remove_duplicates() {
			Nodo<T> * current = head;
			while (current) {
					Nodo<T> * recorrer = current->next;
					Nodo<T> * beh = current;
					while (recorrer) {
							if (recorrer->data == current->data) {
									beh->next = recorrer->next;
							}
							else
									beh = beh->next;
									recorrer = recorrer->next;
					}
					current = current->next;
			}
		}

    //O(1)
    T remove_last(){
      if(is_empty()){ //O(1)
        throw -1;
      } else if(head == last){
        T dato = head->data;
        delete head;
        head = last = NULL;
        return dato;
      } else{
        T dato = last->data;
        last = last->prev;
        delete last->next;
        last->next = NULL;
        return dato;
      }
    }

		//O(n)
		int count(T check) {
      Nodo<T> * current = head;
      int count = 0;
      while(current != NULL) {
        if(current->data == check){
          count++;
        }

        current = current->next;
      }

      return count;
    }

		

    friend ostream& operator << <T>(ostream &, const LinkedList<T>&);

    //O(1)
    void push(T dato){
        addFirst(dato); //O(!)
    }

    //O(1)
    T pop(){
        return remove_front(); //O(1)
    }
     //O(1)
    T peek(){ //getFirst
        if(is_empty()){ //O(1)
            throw -1;
        } else{
            return head->data;
        }
    }

    //O(1)
    void queue(T dato){
        addLast(dato); //O(1)
    }

    //O(1)
    T dequeue(){
        return remove_front();
    }

    //O(n)
    T dequeueMax(){
      if(is_empty()){
        throw -1;
      }else if(head == last){
        T dato = head->data;
        delete head;
        head = last = NULL;
        return dato;
      }else{
        Nodo<T> *recorrer = head;
        Nodo<T> *max = head;
        while(recorrer != NULL){
          if(recorrer->data > max->data){
            max = recorrer;
          }
          recorrer = recorrer->next;
        }
        if(max == head){
          return remove_front();
        } else if(max == last){
          return remove_last();
        } else{
          T dato = max->data;
          Nodo<T> *previo = max->prev;
          max = max->next;
          delete previo->next;
          previo->next = max;
          max->prev = previo;
          return dato;
        }        
      }      
    }

    //O(n)
    T dequeueMin(){
      if(is_empty()){
        throw -1;
      }else if(head == last){
        T dato = head->data;
        delete head;
        head = last = NULL;
        return dato;
      }else{
        Nodo<T> *recorrer = head;
        Nodo<T> *min = head;
        while(recorrer != NULL){
          if(recorrer->data < min->data){
            min = recorrer;
          }
          recorrer = recorrer->next; 
        }
        if(min == head){
          return remove_front();
        } else if(min == last){
          return remove_last();
        } else{
          T dato = min->data;
          Nodo<T> *previo = min->prev;
          min = min->next;
          delete previo->next;
          previo->next = min;
          min->prev = previo;
          return dato;
        }
      }
    }
 
};

template<typename T>
ostream& operator<< (ostream & salida, const LinkedList<T>& lista){
    Nodo<T> * auxiliar = lista.head;
        while(auxiliar != NULL){
            salida << auxiliar->data << ":";
            auxiliar = auxiliar->next;
        }
        return salida;
}