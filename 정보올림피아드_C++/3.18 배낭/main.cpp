/*
�賶�� W���Ը�ŭ ������ �������� �Ѵ�.
���ǵ��� ���Կ� ������ �����ִ�.
������ �ִ밡 �ǰ� �Ҷ� �� �ִ��� ���Ͻÿ�.

input :
������ ���� n (1 <= n <= 100), ���� w (1 <= w <= 10000)
wi (����)
vi (����)
*/

 
#include <iostream>

using namespace std;

int n, w, wi[101], vi[101];

void input() {
	cin >> n;
	cin >> w;
	for (int i = 0; i < n; i++)	{
		cin >> wi[i + 1]; cin >> vi[i + 1];
	}
}

int max(int a, int b) {
	return a > b ? a : b;
}

int f(int index, int remainWeight) {
	if (index > n) {
		return 0;
	}
	if (wi[index] <= remainWeight)
		return max(f(index + 1, remainWeight), f(index + 1, remainWeight - wi[index]) + vi[index]); // ���� ���� Ʈ���������� ���� �����Ǵ� �� (void �����̾��ٸ�, terminal �������� v ���� ���ϸ鼭 ����������)

	if (wi[index] > remainWeight)
		return f(index + 1, remainWeight);

}

int main() {
	input();
	cout << f(0, w);
	 
	return 0;
}