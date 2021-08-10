/*
https://www.acmicpc.net/problem/10818
����
N���� ������ �־�����. �̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 1,000,000)�� �־�����. ��° �ٿ��� N���� ������ �������� �����ؼ� �־�����. ��� ������ -1,000,000���� ũ�ų� ����, 1,000,000���� �۰ų� ���� �����̴�.

���
ù° �ٿ� �־��� ���� N���� �ּڰ��� �ִ��� �������� ������ ����Ѵ�.
*/

//�ִ� �ּҸ� ã���� �Ǵµ� ���� Sort�� �ʿ�� ����. O(N)�̸� �Ǵµ� ���� O(NlogN)???
 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> container;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	{
		int temp;
		cin >> temp;
		container.push_back(temp);
	}
	sort(container.begin(), container.end());
	cout << container.at(0) << " " << container.at(n - 1);
	 
	return 0;
}