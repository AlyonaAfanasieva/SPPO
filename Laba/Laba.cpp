#include <iostream>

using namespace std;

struct element {                
	int value;
	element* pointer;
	element() {
		value = 0;
		pointer = NULL;
	}
};

void Input(element*& first, int n) {       
	element* p = first;
	int i = 0;
	while (i < n) {
		element* pl = new element();
		cin >> pl->value;          
		if (first == NULL) {
			first = pl;
			p = pl;
		}
		else {
			p->pointer = pl;
			p = pl;
		}
		i++;
	}
}

void Out(element* l) {  
	while (l != NULL) {
		cout << l->value << " ";
		l = l->pointer;
	}
	cout << endl;
}

void AddToList(element* l, int n) { 
	element* p = l;
	l = l->pointer;
	while (l != NULL) {
		element* el = new element();
		el->value = n;
		el->pointer = l;
		p->pointer = el;
		p = l;
		l = l->pointer;
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	element* first = NULL;
	int N;
	cout << "Введите длину массива = ";
	cin >> N;
	cout << "Введите элементы массива = ";
	Input(first, N);               
	Out(first);                       
	AddToList(first, 0);               
	Out(first);                        

	system("pause");
	return 0;
}
