#include <iostream>
using namespace std;

// �˰��� : �� ������, �����̵� ������
// ������ �� : ������ �ִ� ���ǰ���(N), ������ ���� ��ĥ ���ӵ� ���� ����(M)�� ���� ������,
// �ѹ��� �����ؾ� �Ѵ� (�����Խ��ǿ� �ݷ� �����ϱ�)

// ������ : ���� ���� ������ �Ǿ��� ���� ���ְ�, ���� ������ ���� ���� �� ��
// ������ ���� �����ָ鼭 �ϴٺ��� �ð��ʰ��� ����

int T, N, M, K;
// T : testcase, N : ������ �ִ� ���� ����, M : ������ ���� ��ĥ ���ӵ� ���� ����
// K : �����ġ �۵��ϴ� �ּ� ���� ��
int home[2000010];
// home : ���� �������� ���� �� - �����̱� ������, 2���� ��������

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++)
		{
			cin >> home[i];
			home[i + N] = home[i];
			// 2��������!
		}

		int cnt = 0, sum = 0;
		for (int i = 0; i < M; i++)
			sum += home[i];
		if (sum < K) cnt++;
		if (N == M) // ������ ������ N == M �� ���� ���
		{
			cout << cnt << '\n';
			continue;
		}
		for (int i = 1; i < N; i++)
		{
			sum += (home[i -1 + M] - home[i - 1]);
			if (sum < K) cnt++;
		}
		cout << cnt << '\n';
	}
}