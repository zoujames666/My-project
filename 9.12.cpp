#include<iostream>
#include<cstdlib>
#include <vector>
#include<cstring>
#include<algorithm>
using namespace std;//这是我的第一次提交 
int findvalue(double *weight,int value,int n){
	double trial[n];
	std::copy(weight, weight+n, trial);
	sort(trial,trial+n);
	for(int i=0;i<n;i++){
		if(trial[n-value]==weight[i])
		return i;
	}
}
std::vector<int> CalcVolumePlan(int X, const std::vector<double>& availables){
	int n,x1=X;
	n=availables.size();
	vector<int> ret(n);
	double weight[n];
	double sum=0.0;
	for(int i=0;i<n;i++){
		if(availables[i]>0)
		sum+=availables[i];
	}
	for(int i=0;i<n;i++){
		if(availables[i]>0)
		weight[i]=availables[i]/sum;
		else
		weight[i]=0.0;
		
	}
	for(int i=0;i<n;i++){
		ret[i]=X*weight[i];
		x1-=ret[i];
		
	}
	int k=0;
	while(x1>0){
		ret[findvalue(weight,k+1,n)]++;
		k++;
		x1--;
	}
	int j=0;

	return ret;
}
int main(){
	int x=4;
	double b[3]={0.0,150.0,100.0};
	vector<double> availables(b,b+3);
	vector<int> ret=CalcVolumePlan(x,availables);
	for (int i=0;i<ret.size();i++)
        cout<<ret[i]<<endl;
} 
