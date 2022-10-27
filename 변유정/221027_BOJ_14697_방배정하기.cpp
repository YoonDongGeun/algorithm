#include <iostream>
using namespace std;

// �˰��� �з� : ���Ʈ���� �˰���

// ���� �ܰ� : ��� ���
// 1. �� 3���� �ο��� ���ʴ�� ���ֱ�
// 2. 0�� �Ǹ� ans ��� 1���� �ٲٰ� �ǵ��ư���
// 3. �̹� �����߰ų�, ���� ��� ���� ������ �ǵ��ư���

int ans = 0, room[3] = { 0, },sixth;
void nobed(int now, int left)
{
	if (ans == 1 || left < 0) return;
	if (left == 0)
	{
		ans = 1;
		return;
	}
	for (int i = now; i < 3; i++)
		nobed(i, left - room[i]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ans = 0;
	for (int i = 0; i < 3; i++)
		cin >> room[i];
	cin >> sixth;
	nobed(0, sixth);
	cout << ans;
	return 0;
}