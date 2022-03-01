#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "lls.h"
using namespace std;

template<typename K, typename T>    // K = key, T = value
class HashPair{
public:
    K key;
    T value;

    HashPair(K key, T value){
        this->key = key;
        this->value = value;
    }
    HashPair(){
    }
    
    void setValue(T value){
      this->value = value;
    }
    void setKey(K key){
      this->key = key;
    }
};

template<typename K, typename T>    // K = key, T = value
class HashTable{
private:
    int size;
	  LinkedList<HashPair<K, T> * > * table;
    int hashFunction(K key){
        hash<K> khash;
        return khash(key)%size;
    }
public:
		// O(n)
    HashTable(int size = 20){
        this->size = size;
			table = new LinkedList<HashPair<K, T>*>[size];
        for(int i = 1; i < size; i++){
			table[i] =  LinkedList<HashPair<K, T>*>();
        }
    }

    // O(1)
    ~HashTable(){
        delete table;
    }

		// O(n^2)
    bool contains_key(K key) const{
        for (int i = 0; i < size; i++) {
          for (int j = 0; j < table[i].size(); j++) {
              if (table[i].get(j)->key == key) return true; 
          }
        }
        return false;   
      }
			
		// O(n^2)
      T get(K key)const{
        for (int i=0; i < size; i++){
          for (int j = 0; j < table[i].size(); j++) {
            if (table[i].get(j)->key == key){
            return table[i].get(j)->value;
            } else {
              continue;
            }
          }
        
        } 
        throw -1;
      }

		// O(n)
    bool put(K key, T value = 0){
      int position = hashFunction(key);
      LinkedList<HashPair<K, T>*> lista = table[position];
      bool cond = 0;
      int j = 0; 
      int pos = 0; 

      for(; j < lista.size(); j++){
        if(lista.get(j)->key == key){
          cond = 1;
          pos = j;
          break; 
        } 
      }

      if(cond == 1){
        lista.get(pos)->setValue(value);
      }
      else{
        table[position].addLast(new HashPair<K, T>(key, value));
      }
      return true; 
    }
    

    // O(n^2)
    void print(){
      for(int i =0; i<size; i++){
				for(int j =0; j<table[i].size(); j++){
          cout << "i: " << i;
          cout << " k: " << table[i].get(j)->key;
          cout << " v: " << table[i].get(j)->value;
          cout << " | " << endl;
				}
      }
    }
    // O(n^2)
		void printMessage(){
			for(int i =0; i<size; i++){
				for(int j =0; j<table[i].size(); j++){
          cout << " Message: " << table[i].get(j)->key << endl;
          cout << " Frequency: " << table[i].get(j)->value << endl;
				}
      }
		}


		// O(n^2)
    vector<K> keys() const{
      vector<K>  keys;
      for(int i =0; i<size; i++){
				for(int j =0; j<table[i].size(); j++){
          keys.push_back(table[i].get(j)->key);
				}
      }
      return keys;
    }

    // O(n^2)
    vector<T> values() const{
      vector<T>  values;
      for(int i =0; i<size; i++){
				for(int j =0; j<table[i].size(); j++){
          values.push_back(table[i].get(j)->value);
				}
      }
      return values;
    }

    // O(n^2)
    void printMaxByValue(int value){
      for(int i =0; i<size; i++){
				for(int j =0; j<table[i].size(); j++){
          if(table[i].get(j)->value == value){
            cout << " Month/Week with most attacks: " << table[i].get(j)->key << endl;
            cout << " Attacks: " << table[i].get(j)->value << endl; 
          }
				}
      }
    }
    
    //O(n^2)
    bool remove_final(K key){
      int pos;
      int postable; 
      for(int i =0; i<size; i++){
        for(int j =0; j<table[i].size(); j++){
          if(table[i].get(j)->key == key){
            pos = j;
            postable = i; 
            break; 
          }
        }
      }
      //CONDICION PARA POP
      if(pos != 0){
        table[postable].pop_at(pos); 
      }
      //CONDICION PARA LAST
      else if(1 == table[postable].size()){
        table[postable].remove_last(); 
      }
      //CONDICON PARA FRONT
      else if(pos == 0 && table[postable].size()-1 != 0){
        table[postable].remove_front(); 
      }
      return true; 
    }

    // O(n)
    bool operator==(const HashTable<K, T>& other) const{
        int comp;
        try{
            if(size > other->size){
                comp = size;
            }else{
                comp = other->size;
            }
            for(int i = 0; i < comp; i++){
                if(table[i]->value != other->table[i]->value) return true;
            }
            return false;
        }catch(T& error){
            return false;
        }
    }
};

#endif

  // get_or_default
  // is_empty()
  // put_all
  // CLEAR
