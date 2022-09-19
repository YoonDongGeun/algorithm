#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// ȥ�� ���� ���ؼ� ���� ���ٽ��� ������
// ���� ��α� : https://yabmoons.tistory.com/306

// ���� �ܰ�
// 1. ��ȣ�ڵ� �迭 �Է¹ޱ� (16���� ���ڸ����� �ٷ� 2������ �ٲ��ֱ�)
// 2. �迭 ���� Ž���ϴٰ� ��ȣ�ڵ� ���۵Ǵ� �������� Ȯ��
// 3. ��ȣ�ڵ� �迭 �Է¹޾Ƽ� ���� ���缭 �ٲ��ֱ�
// 4. ��ȣ�ڵ尡 �ùٸ��� ���� �� �����ֱ�
//
// �̷� ������ ��� �����ϴ����� �߿��� ����
// 1. 0~9���� ���� �� 0�� ������ ������ �����ʾƼ� �� �ʿ� ����
// 2. ���� ���� ������ ũ�Ⱑ ���� �����̴�
// 3. �迭 Ȱ���� �ſ� �߿���!

int T,N,M;
// ������ 500������ 16���� �����Ϸ��� 2000���� ��
char code[2000][2000];
// 16���� > 2���� �迭
string sixteen[16] = {"0000", "0001", "0010", "0011","0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
// 0~9 ���� �ڵ� �迭
string num[10] = { "211", "221", "122","411","132","231","114","312","213","112" };
int ans = 0;

void binary()
{
	int idx = 7;
	int result[8] = { 0, };

	for (int y = 0; y < N; y++)
	{
		for (int x = 4 * M -1;x>=0;x--)
		{
			int part[3] = { 0,0,0 };
			// ���� �ڵ� Ư¡ - 0���� �����ϰ� 1�� ������(ex : 0 - 0001101)
			// �Ųٷ� ���� ������ 1 > 0 > 1 ������ ����, 0�� ������ ������ Ȯ���� �𸣴ϱ� ���� �ʱ�
			// ���� 0�� ��ȸ�� ������ �迭 ������ ���� �ʱ� ������ ����

			//��ȣ�ڵ尡 �����ϴ� ���������� ����. ���α��̰� ��Ȯ���� �ʱ� ������ �ߺ� ����
			if (code[y][x] == '1' && code[y - 1][x] == '0')
			{
				while (code[y][x] == '1')
				{
					part[2]++; x--;
				}
				while (code[y][x] == '0')
				{
					part[1]++; x--;
				}
				while (code[y][x] == '1')
				{
					part[0]++; x--;
				}
				x++;
				
				// ���� ����
				int div = part[2];
				if (part[1] < div) div = part[1];
				if (part[0] < div) div = part[0];

				for (int i = 0; i < 3; i++) part[i] /= div;

				string temp;
				// temp�� ��ġ�ϴ� ���� ã��
				temp += to_string(part[0]) + to_string(part[1]) + to_string(part[2]);
				for (int i = 0;i<10;i++)
					if (temp == num[i])
					{
						result[idx] = i;
						idx--;
						break;
					}

				// 8�� ���� �Է� �ٵǸ� �� ��ȣ�ڵ尡 �ùٸ��� Ȯ��
				if (idx == -1)
				{
					int value = (result[0] + result[2] + result[4] + result[6]) * 3 + result[1] + result[3] + result[5] + result[7];
					// �ùٸ��� �����ֱ�
					if (value % 10 == 0)
						for (int i = 0; i < 8; i++)
							ans += result[i];
					idx = 7;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				char temp;
				cin >> temp;
				if (temp <= '9') temp = temp - '0';
				else temp = temp - 'A' + 10;

				for (int z = 0; z < 4; z++)
					code[y][x * 4 + z] = sixteen[int(temp)][z];
			}
		}

		cout << "#" << tc << " " << ans << "\n";
		ans = 0;
	}
	return 0;
}