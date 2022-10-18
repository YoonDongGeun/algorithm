#include <iostream>
#include <cstring>
using namespace std;

// ���� ���� + ��Ʈ��ŷ
// �ð� ���̱�
// 1. ���ص� �ּڰ� ans���� ���� ��ǰ���� Ƚ�� now�� Ŀ���� return
// 2. ���ɰ˻� �� �ϳ��� ��� ���ϸ� break

// ���� �ܰ�
// 1. �� �ϳ��� 0 �Ǵ� 1�� �ٲ��ֱ�
// 2. �ϳ��� �ٲ��ָ鼭 Ȯ���ϱ�
// 3. 0, 1 �Ѵ� Ž���ϰ� �ǵ��ƿ��� ���� ������ �迭�� �����ֱ�

int D, W, MK;
bool film[13][20];
int ans;
bool used[13];

void pass_test(int now, int put_p)
{
	if (now > ans) return;
	int p = 0;
	for (int i = 0; i < W; i++)
	{
		int kk = MK;
		int idx = D - 1;
		while (--kk)
		{
			if (idx == 0) break;
			if (film[idx][i] != film[idx - 1][i])
				kk = MK;
			idx--;
		}
		if (kk == 0) p++;
		else break;
	}
	if (p == W)
	{
		if (ans > now) ans = now;
		return;
	}

	for (int i = put_p; i < D; i++)
	{
		if (used[i]) continue;
		used[i] = 1;
		int temp[20];
		for (int k = 0; k < W; k++) temp[k] = film[i][k];
		for (int k = 0; k < W; k++) film[i][k] = 0;
		pass_test(now + 1, i);
		for (int k = 0; k < W; k++) film[i][k] = 1;
		pass_test(now + 1, i);
		for (int k = 0; k < W; k++) film[i][k] = temp[k];
		used[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> D >> W >> MK;
		for (int y = 0; y < D; y++)
			for (int x = 0; x < W; x++)
				cin >> film[y][x];
		ans = 1e9;
		memset(used, 0, sizeof(used));
		pass_test(0, 0);
		cout << "#" << tc << " " << ans << '\n';
	}
}