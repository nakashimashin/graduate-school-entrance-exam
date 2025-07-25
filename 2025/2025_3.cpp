#include <iostream>
#include <random> 
#include <algorithm> 
using namespace std;

int main()
{
	int N_medal[200][3];
	int N_rank[200];
	random_device rd;
	mt19937 gen(rd());

	// --- N_rank（1〜200をランダムにシャッフル） ---
	std::vector<int> ranks(200);
	for (int i = 0; i < 200; ++i) ranks[i] = i + 1;
	std::shuffle(ranks.begin(), ranks.end(), gen);
	for (int i = 0; i < 200; ++i) N_rank[i] = ranks[i];
	// --- N_medal: 各要素に 0〜3 のランダム値を代入 ---
	std::uniform_int_distribution<> dist(0, 3);
	for (int n = 0; n < 200; ++n) {
		for (int m = 0; m < 3; ++m) {
			N_medal[n][m] = dist(gen);
		}
	}
	// （確認用出力：先頭5件）
	for (int i = 0; i < 200; i++) {
		cout << N_rank[i] << endl;
	}
	//for (int n = 0; n < 200; n++) {
	//	cin >> N_rank[n];
	//}
	//for (int n = 0; n < 200; n++) {
	//	for (int m = 0; m < 3; m++) {
	//		cin >> N_medal[n][m];
	//	}
	//}
	

	// (問3-1) ランキング表示
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			if (N_rank[j] == i + 1) {
				cout << i + 1 << "位：国番号" << j << endl;
			}
		}
	}

	//(問3-2) ランキング再計算
	for (int i = 0; i < 200; i++) {
		int rank = 1;
		for (int j = 0; j < 200; j++) {
			if (i == j) continue;
			if ((N_medal[i][0] < N_medal[j][0])
				|| (N_medal[i][0] == N_medal[j][0]) && (N_medal[i][1] < N_medal[j][1])
				|| (N_medal[i][0] == N_medal[j][0]) && (N_medal[i][1] == N_medal[j][1]) && (N_medal[i][2] < N_medal[j][2])
				|| (N_medal[i][0] == N_medal[j][0]) && (N_medal[i][1] == N_medal[j][1]) && (N_medal[i][1] == N_medal[j][1] && (i < j))) {
				rank++;
			}
		}
		N_rank[i] = rank;
	}

	return 0;
}
