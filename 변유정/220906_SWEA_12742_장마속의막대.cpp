#include <iostream>
using namespace std;

/// ó���� �迭�� ��� ���� �������� ����
/// �����ϰ� ���ľ���

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	long long a, b;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> a >> b;
		long long c = b - a;
		c = c * (c + 1) / 2;

		cout << "#" << tc << " " << c - b << "\n";
	}
}