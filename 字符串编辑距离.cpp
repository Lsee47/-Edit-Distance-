#include<iostream>
using namespace std;

//@file		:字符串编辑距离
//@author	:Lvsq
//@time		:2022/3/22 23:01:27

//字符串最长为15个字符
int dist(string a, string b);

int minest(int a, int b, int c);

int main() {
	string a;
	string b;
	cin >> a >> b;
	cout << a[1] << endl;
	cout << "编辑距离为：" << dist(a, b) << endl;

	system("pause");
	return 0;
}

int dist(string a, string b) {
	//ai到bj的编辑距离在dis[i+1][j+1]中
	int dis[20][20];
	int la = a.length();
	int lb = b.length();
	for (int i = 0; i <= la; i++) {
		dis[i][0] = i;

	}
	for (int j = 0; j <= lb; j++) {
		dis[0][j] = j;
	}
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			if (a[i-1] == b[j-1]) {
				dis[i][j] = dis[i - 1][j - 1];
				//cout << "dis[" << i << "]" << "[" << j << "]" << "=" << dis[i][j] << endl;
			}
			else {
				dis[i][j] = minest(dis[i - 1][j - 1], dis[i - 1][j], dis[i][j - 1]) + 1;
				//cout << "dis[" << i << "]" << "[" << j << "]" << "=" << dis[i][j] << endl;
			}
		}
	}
	//cout << dis[0][1] << endl;
	//cout << dis[0][2] << endl;
	//cout << dis[0][3] << endl;
	return dis[la][lb];
}

int minest(int a, int b, int c) {
	a = a < b ? a : b;
	return a < c ? a : c;
}