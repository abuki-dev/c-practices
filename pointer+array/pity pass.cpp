#include<iostream>
#include<fstream>
using namespace std;
int main(){
	double *ptr=new double[10];
	fstream file("STUDENTS.txt",ios::in);
	if(!file.is_open()){
		cout<<"there is no such file in dictionary";
	}
	else{
		for(int i=0;i<10;i++){
		file>>*(ptr+i);
		if(*(ptr+i)<50){
			cout<<"chaged student"<<i+1<<endl;
			*(ptr+i)=50;
		}
		else{
			cout<<"no change fot student"<<i+1<<endl;
		}
		}
		file.close();
	}
	fstream add("STUDENTS.txt",ios::out);
	if(!add.is_open()){
		cout<<"no record founded ";
	}
	else{
		for(int j=0;j<10;j++){
			add<<*(ptr+j)<<endl;
		}
		add.close();
		cout<<"sucussus fuly maked shure that very bodypassed from the clas";
	}
	delete[] ptr;
	ptr=nullptr;
	return 0;

}