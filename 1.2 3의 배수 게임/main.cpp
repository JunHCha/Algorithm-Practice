#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)	{
		if (i % 3 == 0) {
			cout << "x ";
		}
		else {
			cout << i << " ";
		}
	}
	system("pause");
	return 0;
}