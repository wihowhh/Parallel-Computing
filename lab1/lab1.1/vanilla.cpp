#include<iostream>
#include<windows.h>
using namespace std;

const long long int SCALE = 100;  //200, 300, 400, 500

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

//���з���Ԫ��
double vanilla() {
    double time = 0;
    QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
    for (int j = 0; j < SCALE; j++){
		for (int i = 0; i < SCALE; i++){
			sum[j] += matrix[i][j] * vector[i];
		}
    }
    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    return time;
}

int main(){
    initdata();
    double time = vanilla();
    
	cout << "�����ÿһ����̶������ĳ˻��ǣ�";
	for (int i = 0; i < SCALE; i++)
	{
		cout << sum[i] << " ";
	}
	cout << endl;
	cout << "����1.1�ķѵ�ʱ���ǣ�" << time*10000;
	return 0;
}

