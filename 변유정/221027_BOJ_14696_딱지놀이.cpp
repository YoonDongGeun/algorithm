#include <iostream>
using namespace std;

// �˰��� : ����
// �迭�� �����ϰ� ���ڿ� �°� ++ �ϱ�
// ���� �ε����� �迭 ������ ��, ���ڰ� ū ���(A,B) ��� �� ����
// ���� ������ �ȳ����� ��, ���º� D ���

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int cntA, cntB;
		int AA[5] = { 0, }, BB[5] = { 0, };
		cin >> cntA;
		for (int k = 0; k < cntA; k++)
		{
			int a;
			cin >> a;
			AA[a]++ ;
		}

		cin >> cntB;
		for (int k = 0; k < cntB; k++)
		{
			int b;
			cin >> b;
			BB[b]++;
		}
		
		int k = 4;
		while (k > 0)
		{
			if (AA[k] > BB[k])
			{
				cout << 'A' << '\n';
				break;
			}
			else if (AA[k] < BB[k])
			{
				cout << 'B' << '\n';
				break;
			}
			k--;
		}
		if (k == 0) cout << 'D' << '\n';
	}
}