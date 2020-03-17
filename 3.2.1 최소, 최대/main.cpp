/*
https://www.acmicpc.net/problem/10818
문제
N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.

출력
첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
*/

//최대 최소만 찾으면 되는데 굳이 Sort할 필요는 없다. O(N)이면 되는데 굳이 O(NlogN)???
#define _CRT_SECURE_NO_WARNINGS
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
	system("pause");
	return 0;
}