#include <string>
#include <vector>


using namespace std;
bool Check(long long num);
long long Check2(long long num, long long arg, long long arg2);

vector<unsigned long long> powerList = { 1 };


bool Check(long long num) {
    long long N = 1;
    long long arg = 1;
    long long max_arg = 1;
    // �ڸ��� üũ
    while (num > N) {
        arg += 1;
        max_arg = powerList[arg] - 1;
        N = powerList[max_arg] - 1;
    }

    // ���� �ڸ� üũ
    long long check_index = (max_arg / 2);
    long long check_space = (check_index + 1) / 2;
    long long cnt1 = 0;
    for (int i = 0; i < 63; i++) {
        if (num & (unsigned long long) 1 << i) {
            cnt1++;
        }
    }
    if (cnt1 == Check2(num, check_index, check_space)) {
        return 1;
    }
    else {
        return 0;
    }
    // �� ���� �� ���� �ٷ� �Ʒ��� ������ �����ϸ� ������� ���ұ�???... �˰�ʹ�...
    //return (cnt1 == Check2(num, check_index, check_space))?1:0;

};

long long Check2(long long num, long long arg, long long arg2) {

    if ((0 <= arg) && (arg < 63))
    {
        if (num & ((unsigned long long) 1 << arg)) {
            if (arg2 == 0) {
                return 1;
            }
            return 1 + Check2(num, arg - arg2, arg2 / 2) + Check2(num, arg + arg2, arg2 / 2);
        }
    }
    return 0;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    unsigned long long temp = 1;
    for (int i = 1; i < 64; i++) {
        temp = temp * 2;
        powerList.push_back(temp);
    }
    //2^1-1=1 �ִ밪 2^1-1 ������ üũ�ϴ� �ڸ� 2^0
    //2^2-1=3 �ִ밪 2^3-1 ������ üũ�ϴ� �ڸ� 2^1
    //2^3-1=7 �ִ밪 2^7-1 ������ üũ�ϴ� �ڸ� 2^3
    //2^4-1=15�ִ밪 2^15-1  ������ üũ�ϴ� �ڸ� 2^7
    //2^5-1=31
    //2^6-1=63
    // 1. ������ ����üũ�ϱ�(��� ����üũ)
    // 2. ���ڰ� 1�� �ݵ�� �����ϴ� �ڸ��� 1���� üũ�ϱ�
    // 1<= numbers <= 10^15
    // 1<= numbers <= (2^15) * (5^15)
    // 1<= numbers <= 2^50;
    for (int i = 0; i < numbers.size(); i++) {
        answer.push_back(Check(numbers[i]));
    }

    return answer;
}

int main() {


    return 0;
}