#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node<T> * next;
};

template<class T>
class Iterator{
private:
	Node<T>* startNode;
	Node<T>* currentNode;
public:
	Iterator(Node<T> * startNode);
	bool end();
	void begin();
	Node<T> * current();
	void next();
};

template <class T>
class LinkedList{
private:
	Node<T> * head;
	Node<T> * tail;
public:
	void insertEnd(T value);
	void add(int index, T value);
	void edit(int index, T value);
	void remove(int index);
	T get(int index);
	void print();
	Iterator<T> * makeIterator();
};


template <class T> Iterator<T>::Iterator(Node <T> * startNode){ // @suppress("Class members should be properly initialized")
	this->startNode = startNode;
}

template <class T> bool Iterator<T>::end(){
	return this->currentNode == NULL;
}

template <class T> void Iterator<T>::begin(){
	this->currentNode = startNode;
}

template <class T> void Iterator<T>::next(){
	this->currentNode = this->currentNode->next;
}

template <class T> Node<T> * Iterator<T>::current(){
	return this->currentNode;
}

template <class T> Iterator<T> * LinkedList<T>::makeIterator(){
	return new Iterator<T>(head);
}

template <class T> void LinkedList<T>::insertEnd(T value){
	if(head==NULL){
		head = new Node<T>();
		head->data = value;
		tail = head;
		return;
	}
	tail->next = new Node<T>();
	tail->next->data = value;
	tail = tail->next;
}

template <class T> void LinkedList<T>::add(int index,T value){
	if(index == 0){
		Node <T> * newNode = new Node<T>();
		newNode->data = value;
		newNode->next = head;
		head = newNode;
		return;
	}
	Node <T> * current = head;
	for(int i = 0; i < index - 1; ++i)
		current = current->next;
	Node <T> * newNode = new Node<T>();
	newNode->data = value;
	newNode->next = current->next;
	current->next = newNode;
	if(current == tail){
		tail = newNode;
	}
}

template <class T> void LinkedList<T>::remove(int index){
	if(index == 0){
		Node <T> * temp = head;
		head = head->next;
		delete temp;
		temp = NULL;
		return;
	}
	Node <T> * current = head;
	for(int i = 0; i < index - 1; ++i)
		current = current->next;
	Node <T> * temp = current->next;
	current->next = temp->next;
	if(temp == tail){
		tail = current;
	}
	current->next = current->next->next;
	delete temp;
	temp = NULL;
}

template <class T> void LinkedList<T>::print(){
	Node <T> * temp = head;
	while(temp != NULL){
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

string stringAfterSpace(std::string word)
{
	for(unsigned int i = 0; i < word.size(); i++)
		if (isspace(word[i]))
			return word.substr(i);
	return "";
}

string stringBeforeSpace(std::string word)
{
    for(unsigned int i = 0; i < word.size(); i++)
        if (isspace(word[i]))
        	return word.substr(0,i);
    return "";
}

int main() {
	LinkedList <string> * linkedList = new LinkedList<string>();
	string totalUserInput = "", input = "", command = "";
	bool running = true;

	while(running){

		getline (cin, totalUserInput);
		input = stringAfterSpace(totalUserInput);
		command = stringBeforeSpace(totalUserInput);

		//"insertEnd "lolol""

		if(command == "insertEnd"){
			cout << "yoooo";
			running = false;
		}
		else if(command == "search"){
			;
		}
		else if(command == "print"){
			;
		}
		else if(command == "edit"){
			;
		}
		else if(command == "quit"){
			;
		}
		running = false;

	}

	return 0;
}






