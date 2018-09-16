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
	void insert(int index, T value);
	void edit(int index, T value);
	void remove(int index);
	T get(int index);
	void print();
	void find(string value);
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

template <class T> void LinkedList<T>::insert(int index,T value){
	if(index == 1){
		Node <T> * newNode = new Node<T>();
		newNode->data = value;
		newNode->next = head;
		head = newNode;
		return;
	}
	Node <T> * current = head;
	for(int i = 0; i < index - 2; ++i)
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
	if(index == 1){
		Node <T> * temp = head;
		head = head->next;
		delete temp;
		temp = NULL;
		return;
	}
	Node <T> * current = head;
	for(int i = 0; i < index - 2; ++i)
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
	int count = 1;
	while(temp != NULL){
		cout << count << " " << temp->data << endl;
		temp = temp->next;
		count++;
	}
}

template <class T> void LinkedList<T>::edit(int index, T value){
	Node <T> * temp = head;
	for(int i = 0; i < index-1; i++)
		temp = temp->next;
	temp->data == value;
}

template <class T> void LinkedList<T>::find(string value){
	Node <T> * temp = head;
	int count = 1;
	while(temp->data.find(value) == string::npos){
		temp = temp->next;
		count++;
	}
	cout << count << " " << temp->data << endl;
}

string stringAfterSpace(string word){
	for(unsigned int i = 0; i < word.size(); i++)
		if (isspace(word[i]))
			return word.substr(i+1);
	return "";
}

string stringBeforeSpace(string word){
    for(unsigned int i = 0; i < word.size(); i++)
        if (isspace(word[i]))
        	return word.substr(0,i);
    return word;
}

string removeQuotes(string word){
	return word.substr(1,word.size()-2);
}

int toInt(string numStr){
	return numStr[0] - '0';
}

int main() {
	LinkedList <string> * linkedList = new LinkedList<string>();
	int index = 0;
	string totalUserInput = "", input = "", command = "";
	bool running = true;

	while(running){

		getline (cin, totalUserInput);

		if(totalUserInput.size() > 0){
			input = stringAfterSpace(totalUserInput);
			command = stringBeforeSpace(totalUserInput);

			if(command == "insertEnd"){
				linkedList->insertEnd(removeQuotes(input));
			}
			else if(command == "insert"){
				index = toInt(stringBeforeSpace(input));
				input = stringAfterSpace(input);
				linkedList->insert(index, removeQuotes(input));
			}
			else if(command == "search"){
				linkedList->find(removeQuotes(input));
			}
			else if(command == "delete"){
				index = toInt(stringBeforeSpace(input));
				linkedList->remove(index);
			}
			else if(command == "print"){
				linkedList->print();
			}
			else if(command == "edit"){
				index = toInt(stringBeforeSpace(input));
				input = stringAfterSpace(input);
				linkedList->edit(index, removeQuotes(input));
			}
			else if(command == "quit"){
				running = false;
			}
		}
	}
	return 0;
}






