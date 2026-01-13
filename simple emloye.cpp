#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct employe{
	string name;
	double salary;
	string dept;
};
int main(){
	employe*ptr=new employe[3];
	cout<<"SIMPLE EMLOYE MANAGENMENT SYSTEM"<<endl;
	fstream file("staff.txt",ios::out);//create for recording
	if(!file.is_open()){
		cout<<"file doesnt esist or cant creat the file";
	}
	else{
		file<<"NAME\t\tSALARY\t\tDEPARTNMENT"<<endl;
		for(int i=0;i<3;i++){
			cout<<"name of employe "<<i+1;cin>>(ptr+i)->name;
			cout<<"slary: ";cin>>(ptr+i)->salary;cin.ignore();
			cout<<"employe departnment";getline(cin,(ptr+i)->dept);
			file<<(ptr+i)->name<<"\t"<<(ptr+i)->salary<<"\t"<<(ptr+i)->dept<<endl;
		}
		file.close();
		cout<<"sucusssfully recorde employes to teh file"<<endl;
	}
	string header;
	fstream read("staff.txt",ios::in);
	if(!read.is_open()){
		cout<<"eroro no such file there ";
	}
	else{
		getline(read,header);//geting the header file at the staff
		for(int j=0;j<3;j++){
		read>>(ptr+j)->name;
		read>>(ptr+j)->salary;
		read>>ws;//skip the tab fron the salary at buffer
		getline(read,(ptr+j)->dept);
		if((ptr+j)->salary>5000){
			(ptr+j)->salary*=0.90;
			cout<<" tax subtracted from employe "<<(ptr+j)->name<<endl;
		}
		else if((ptr+j)->salary<2000){
			(ptr+j)->salary+=500.00;
			cout<<"bonus is adede to employe "<<(ptr+j)->name<<endl;
		}
		else{
			cout<<"no need of change for employe "<<(ptr+j)->name<<endl;
		}
		}
		read.close();
	}
	fstream rewrite("staff.txt",ios::out);
	if(!rewrite.is_open()){
		cout<<"no file for re writiing ";
	}
	else{
		rewrite<<header<<endl;
		for(int k=0;k<3;k++){
			rewrite<<(ptr+k)->name<<"\t"<<(ptr+k)->salary<<"\t"<<(ptr+k)->dept<<endl;
		}
		rewrite.close();
		cout<<"new price for employes have been set "<<endl;
	}
	string search;

	cout<<"pleas tell me the name of department lookign for ";getline(cin,search);
	cout<<"name of employes under departnment of "<<search<<endl;
	cout<<"NAME\tsalary"<<endl;
	for(int m=0;m<3;m++){
		if((ptr+m)->dept==search){
			cout<<(ptr+m)->name<<"\t"<<(ptr+m)->salary<<endl;
		}

	}
	cout<<"im done here uffff"<<endl;
	return 0;
	
}