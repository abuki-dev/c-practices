#include<iostream>
#include<fstream>
using namespace std;
int main(){
	cout<<"price recordor"<<endl;
	double price[4];
	for(int i=0;i<4;i++){
		cout<<"enter price of item "<<i+1;
		cin>>price[i];
	}
	ofstream file("pricec.txt",ios::app);
	if(!file.is_open()){
		cout<<"no such file in the dictionary";
	}
	else{
		file<<"list\titem prices"<<endl;
		for(int i=0;i<4;i++){
			file<<i+1<<"\t"<<price[i]<<endl;
		}
		file.close();
		cout<<"writing sucususs";
	}
	return 0;
}