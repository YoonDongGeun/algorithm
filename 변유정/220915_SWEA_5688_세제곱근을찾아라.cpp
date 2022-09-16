#include <iostream>
using namespace std;

///  �ڷ��� ����
///  ���������� �õ��غôٰ� ����
/// 
/// float, double �� ��� ���� ���� �ƴ϶� �ִ��� ����� ���� ������
/// 
/// �ݷ� (48228548,48228549,48228550)
/// ��� 364�� ���´�
/// �ε� �Ҽ����� �Ǽ�ó���� ���� ���� �ʿ�

int T;
long long N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (long long x = 1; x <= 1000000; x++)
		{
			if (x * x * x == N)
			{
				cout << "#" << tc << " " << x << "\n";
				break;
			}

			else if (x * x * x > N)
			{
				cout << "#" << tc << " " << -1 << "\n";
				break;
			}
		}
	}
}

//���� Ʋ�ȴ� �ڵ�

//#include <cmath>
//using namespace std;
//
//int T;
//long long N;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++)
//	{
//		cin >> N;
//		int a = cbrt(N);
//		float b = cbrt(N);
//		if (a == b) cout << "#" << tc << " " << a << "\n";
//		else cout << "#" << tc << " " << -1 << "\n";
//	}
//}