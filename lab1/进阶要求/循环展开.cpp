#include<iostream>
#include<windows.h>
using namespace std;

//数据规模取2的幂，方便后续设计算法
const long long int SCALE = 256;   //1024, 8192, 32768, 131072
long long int vector[SCALE], sum = 0;

LARGE_INTEGER nFreq;
LARGE_INTEGER nBeginTime;
LARGE_INTEGER nEndTime;


//人为指定,考虑到数据量，选择取小一点的数
void initdata(){
    for (int i = 0; i < SCALE; i++){
        vector[i] = i % 10;
    }
}

double loopunrolling() {
    double time = 0;
    long long int sum1 = 0;
	long long int sum2 = 0;
    QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);

    for(int i = 0; i < SCALE - 6; i+=6){
        sum1 += vector[i] + vector[i+1] + vector[i+2];
        sum2 += vector[i+3] + vector[i+4] + vector[i+5];
    }
    
    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    return time;
}

int main() {
    initdata();
    double time = loopunrolling();

	cout <<SCALE<<"个数相加结果为：" << sum<<endl;
	cout << "程序2.2耗费的时间是：" << time * 10000;
	return 0;
}