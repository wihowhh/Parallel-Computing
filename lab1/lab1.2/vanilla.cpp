#include<iostream>
#include<windows.h>
using namespace std;

//数据规模取2的幂，方便后续设计算法
const long long int SCALE = 256;  //1024, 8192, 32768, 131072
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

//用链式算法，逐个数相加
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

    cout << SCALE <<"个数相加结果为：" << sum << endl;
	cout << "程序2.1耗费的时间是：" << time*100;

    return 0;
}