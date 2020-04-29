#include <iostream>
#include <cmath>

using namespace std;

double f1(double n) {
	double v;
	if (n < 0)
		v = -n - 2;
	else
		v = 5 * (n * n * n) + 2 * (n * n);
	return v;
}

double f2(double& m) {
	m = f1(m);
	return m;
}

int main() {
	setlocale(LC_ALL, "rus");

	double x, y, b;
	cout << "Введите первое значение ";
	cin >> x;
	cout << "Введите шаг ";
	cin >> b;
	cout << "Введите количество ";
	cin >> y;

	double n = x;

	for (int i = 1; i <= y; i++, x += b) {
		cout << "К значению " << x << " результат " << f1(x);
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= y; i++, x += b) {

		cout << " К значению " << x << endl;
		cout << " результат " << f2(x);
		cout << endl;
	}

	system("pause");
	return 0;
}