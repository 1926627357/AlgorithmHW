#include<iostream>
#include<random>
#include<chrono>
#include<cmath>
using namespace std;
typedef chrono::duration<float,ratio<1,1000>> MILLISECOND;
typedef chrono::duration<float,ratio<1,1>> SECOND;
typedef chrono::duration<float,ratio<60,1>> MINUTS;

#define Thousand 1000
#define Million 1000000
#define Billion 1000000000


float PiFunc(float x){
	return 4*sqrt(1-pow(x,2));
}
float Linear(float x){
	return x;
}



void EX1(int n){
	auto start=chrono::system_clock::now();
	cout<<"[BEGIN] =======EX1======="<<endl;
	cout<<"[INPUT] n="<<n<<endl; 
	default_random_engine e(time(0));
	uniform_real_distribution<float> u(0.0,1.0);
	int circlePointNum=0;
	float xPoint,yPoint;
	for(int i=0;i<n;i++){
		xPoint=u(e);
//		yPoint=u(e);
		yPoint=xPoint; 
		if((xPoint*xPoint+yPoint*yPoint)<=1) circlePointNum++;
	}
	float ProbPi=4.0*circlePointNum/n;
	cout<<"[RESULT] "<<ProbPi<<endl;
	auto end=chrono::system_clock::now();
	auto interval = chrono::duration_cast<MILLISECOND>(end-start);
	cout<<"[COST TIME] "<<interval.count()<<"ms"<<endl;
	cout<<"[END] EXP1"<<endl;
	
}

void EX2(int n){
	auto start=chrono::system_clock::now();
	cout<<"[BEGIN] =======EX2======="<<endl;
	cout<<"[INPUT] n="<<n<<endl;
	default_random_engine e(time(0));
	uniform_real_distribution<float> u(0.0,1.0);
	int interCount=0;
	float xPoint,yPoint;
	for(int i=0;i<n;i++){
		xPoint=u(e);
		yPoint=u(e);
//		落在函数内部 
		if(yPoint<=sqrt(1-pow(xPoint,2))) interCount++;
		
	}
	float ProbPi = 4.0*interCount/n;
	cout<<"[RESULT] "<<ProbPi<<endl;
	auto end=chrono::system_clock::now();
	auto interval = chrono::duration_cast<MILLISECOND>(end-start);
	cout<<"[COST TIME] "<<interval.count()<<"ms"<<endl;
	cout<<"[END] EXP2"<<endl;
}

void EX3(int n, pair<float,float> xInterval,pair<float,float>yInterval,float (*usrFunc)(float x)){
	auto start=chrono::system_clock::now();
	cout<<"[BEGIN] =======EX3======="<<endl;
	cout<<"[INPUT] n="<<n<<"(a,b)="<<"("<<xInterval.first<<","<<xInterval.second<<")"
	<<"(c,d)="<<"("<<yInterval.first<<","<<yInterval.second<<")"
	<<endl;
	if(yInterval.first==yInterval.second){
		cout<<"[RESULT] "<<yInterval.first*(xInterval.second-xInterval.first)<<endl;
		
	}else if(yInterval.first==yInterval.second){
		cout<<"[RESULT] "<<0<<endl;
	}else{
		default_random_engine e(time(0));
		uniform_real_distribution<float> ux(xInterval.first,xInterval.second);
		uniform_real_distribution<float> uy(0.0,yInterval.second-yInterval.first);
		int interPointCount=0;
		float xPoint,yPoint;
		for(int i=0;i<n;i++){
			xPoint=ux(e);
			yPoint=uy(e);
			if(yPoint<=(*usrFunc)(xPoint)-yInterval.first) interPointCount++;
		}
		cout<<interPointCount<<endl;
		cout<<"[RESULT] "<<interPointCount*(xInterval.second-xInterval.first)*(yInterval.second-yInterval.first)/n+yInterval.first*(xInterval.second-xInterval.first)<<endl;
		
	}
	auto end=chrono::system_clock::now();
	auto interval = chrono::duration_cast<MILLISECOND>(end-start);
	cout<<"[COST TIME] "<<interval.count()<<"ms"<<endl;
	cout<<"[END] EXP3"<<endl;
}


int main(){
    
	// EX1(Million);
	// EX2(Million);
	// pair<float,float> xInterval(0.0,1.0);
	// pair<float,float> yInterval(0.0,4.0);
	// EX3(Million,xInterval,yInterval,PiFunc);
    
	return 0;
}