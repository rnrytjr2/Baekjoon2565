// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int length;
vector<pair<int, int>> datas;
int DP[500];
int answer = 0;
int main()
{
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		int left, right;
		cin >> left >> right;
		datas.push_back(make_pair(left, right));
	}
	sort(datas.begin(), datas.end());
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (datas[i].second > datas[j].second)
			{
				DP[i] = max(DP[i], DP[j] + 1);
				answer = max(answer, DP[i]);
			}
		}
	}
	cout << length- answer-1;
}

