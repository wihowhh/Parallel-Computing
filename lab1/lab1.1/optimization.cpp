#include<iostream>
#include<windows.h>
using namespace std;

const long long int SCALE = 100;

long long int matrix[SCALE][SCALE], vector[SCALE], sum[SCALE] = {0};

LARGE_INTEGER nFreq;
LARGE_INTEGER nBeginTime;
LARGE_INTEGER nEndTime;

//init
void initdata(){
    for(int i = 0; i < SCALE; i++){
        vector[i] = i;
        for(int j = 0; j < SCALE; j++){
            matrix[i][j] = i + j;
        }
    }
} 

//����cache���Ż��㷨���ı䰴�з��ʵ�ƽ���㷨����Ϊ���з��ʣ���֤ÿ��Ԫ��ֻ������һ�Σ����ٶ�ȡʱ��
double optimization() {
    double time = 0;
    QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
    for (int i = 0; i < SCALE; i++){
		for (int j = 0; j < SCALE; j++){
			sum[j] += matrix[i][j] * vector[i];
		}
    }
    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    return time;
}

int main(){
    initdata();
    double time = optimization();
    
	cout << "�����ÿһ����̶������ĳ˻��ǣ�";
	for (int i = 0; i < SCALE; i++)
	{
		cout << sum[i] << " ";
	}
	cout << endl;
	cout << "����1.1�ķѵ�ʱ���ǣ�" << time*10000;
	return 0;
}

