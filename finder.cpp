#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	double search;
	int location;
	double *ptr=new double[5];
	cout<<"pleas tell me what mark are you loking for now";
	cin>>search;
	cin.ignore();
	ifstream file("STUDENTS.txt");
	if(!file.is_open()){
		cout<<"ther eis no such file in the dictionary ";
	}	
	else{
		int j=0;
		while(j<5&&file>>*(ptr+j)){
			if(*(ptr+j)==search){
				location=j+1;
			}
			j++;
		}
		file.close();
	}
	cout<<"the value "<<search<<" exit in file and found at row "<<location;
	delete[] ptr;
	ptr =nullptr;
	return 0;
}