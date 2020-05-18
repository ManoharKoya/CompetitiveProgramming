#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string>
#include<cmath>
#include <sstream>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;


int main() {
	int T, digit_1, digit_2, a, max=0, sum=0;
	long long N, L;
	const long long maxN = 2500;
	char c;
	cin >> T;
	string str(""), str2;
	stringstream sstr;
	for (int tt = 1; tt <= T; tt++) {
		sum = 0;
		str.clear();
		cin >> N;
		if (N % 2) L = (int)((N + 1) / 2);
		else L = (int)((N / 2));
		for (int i = 0; i < N; i++) {
			cin >> c;
			sstr << c;
			sstr >> str2;
			sstr.str("");
			sstr.clear();
			str.append(str2);
		}

		for (int i = 0; i < L; i++) {
			digit_1 = str[i] - '0';
			sum += digit_1;
		}

		max = sum;
		for (int j = L, i = 0; j < N; j++, i++) {
			digit_1 = str[i] - '0';
			digit_2 = str[j] - '0';
			sum = sum + digit_2 - digit_1;
			if (sum > max) max = sum;
		}
		
		cout << "Case #" << tt << ": " << max << endl;
	}
	system("pause");
	return 0;
}