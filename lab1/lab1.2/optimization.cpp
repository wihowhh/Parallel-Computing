#include<iostream>
#include<windows.h>
using namespace std;

//数据规模取2的幂，方便后续设计算法
const long long int SCALE = 64;
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

//采用相邻配对原则, 两两相加，一层层累加求和，并行求解
double optimization() {
    double time = 0;
    long long int sum1 = 0;
	long long int sum2 = 0;
    QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);

    for(int i = 0; i < SCALE; i += 2){
        sum1+=vector[i];
        sum2+=vector[i+1];
    }
    sum=sum1+sum2;
    
    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    return time;
}

int main() {
    initdata();
    double time = optimization();

    cout << SCALE <<"个数相加结果为：" << sum << endl;
	cout << "程序2.1耗费的时间是：" << time*100;

    return 0;
}