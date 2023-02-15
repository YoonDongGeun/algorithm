#include <iostream>
using namespace std;

// ���� ���̷���
// �ݺ��� N ������ �� �ƴ϶�, ��ͷ� N * N ���� ������

int K, P;
long long N;

long long dfs(long now)
{
	if (now == 1) return P;
	
	long long temp = dfs(now / 2);
	temp = temp * temp % 1000000007;
	if (now % 2) temp = (temp * P) % 1000000007;
	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> P >> N;
	N *= 10;
	cout << dfs(N) % K % 1000000007;
}