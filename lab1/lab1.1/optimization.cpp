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

//利用cache的优化算法，改变按列访问的平凡算法，变为按行访问，保证每个元素只被访问一次，减少读取时间
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
    
	cout << "矩阵的每一列与固定向量的乘积是：";
	for (int i = 0; i < SCALE; i++)
	{
		cout << sum[i] << " ";
	}
	cout << endl;
	cout << "程序1.1耗费的时间是：" << time*10000;
	return 0;
}

