#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	double*ptr=new double[5];
	for(int i=0;i<5;i++){
		cout<<"please enter "<<i+1<<"item ";
		cin>>*(ptr+i);
	}
	ofstream file("pointers storer.txt");
	if(!file.is_open()){
		cout<<"the file can nnnot be created pleas che memory status";
	}
else{
	for(int i=0;i<5;i++){
		file<<*(ptr+i)<<endl;
	}
	file.close();
	cout<<"done";
    delete[] ptr;
}
return 0;


}