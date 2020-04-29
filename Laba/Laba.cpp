#include <iostream>

using namespace std; 
void f(int *&arr, int &n){
	int n2 = n + (n - 1);
	int *mas = new int[n2];
	int j = 0;
	for (int i = 0; i < n; i++) {
		mas[j] = arr[i];
		if (i != n - 1) {
			mas[j + 1] = 0;
			j += 2;
		}	
	}
	arr = mas;
	n = n2;
}

int main() {
	setlocale(LC_ALL, "rus"); 
	
	int N;
	cout << "Введите длину массива = ";
	cin >> N;
	int *mas = new int[N];
	cout << "Введите элементы массива = ";
	for (int i = 0; i < N; i++) {
		cin >> mas[i];
	}
	f(mas, N);
	for (int i = 0; i < N; i++) {
		cout << mas[i];
	}
	cout << endl;
	
	system("pause");
	return 0;
}
