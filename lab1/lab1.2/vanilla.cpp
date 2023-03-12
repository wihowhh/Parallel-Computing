#include<iostream>
#include<windows.h>
using namespace std;

//���ݹ�ģȡ2���ݣ������������㷨
const long long int SCALE = 256;  //1024, 8192, 32768, 131072
long long int vector[SCALE], sum = 0;

LARGE_INTEGER nFreq;
LARGE_INTEGER nBeginTime;
LARGE_INTEGER nEndTime;


//��Ϊָ��,���ǵ���������ѡ��ȡСһ�����
void initdata(){
    for (int i = 0; i < SCALE; i++){
        vector[i] = i % 10;
    }
}

//����ʽ�㷨����������
double vanilla() {
    double time = 0;
    QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);

    for(int i = 0; i < SCALE; i++)
        sum += vector[i];
    
    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    return time;
}

int main() {
    initdata();
    double time = vanilla();

    cout << SCALE <<"������ӽ��Ϊ��" << sum << endl;
	cout << "����2.1�ķѵ�ʱ���ǣ�" << time*100;

    return 0;
}