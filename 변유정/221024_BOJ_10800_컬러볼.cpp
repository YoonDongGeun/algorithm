#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ���� + ������
// �׳� ������ ���� �ð����⵵ n^2 ����

// ���������� ���ϱ�
// �켱 ���� �켱������ ��� (struct Ball) - �Ʊ��� ����
// ���� - �� ������ ����

// ���ʴ�� �����ָ鼭 idx�� �´� ans �� �ֱ� (���Կ� �� index �迭�� �� �ο����ָ鼭 �ֱ�)
struct Ball {
	int weight, color, idx;

	bool operator<(const Ball& b) const {
		if (weight == b.weight) return color < b.color;
		else return weight < b.weight;
	}
};

int N, ball[200001][2] = { 0, };
int ans[200001] = { 0, };
vector <Ball> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a,i });
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int weight = v[i].weight;
		int color = v[i].color;
		int idx = v[i].idx;

		ball[color][0] += weight;
		ball[weight][1] += weight;
		sum += weight;

		ans[idx] = sum - ball[color][0] - ball[weight][1] + weight;
		if (i > 0 && (v[i - 1].color == color) && (v[i - 1].weight == weight))
			ans[idx] = ans[v[i - 1].idx];
	}
	for (int i = 0; i < N; i++) cout << ans[i] << '\n';
}