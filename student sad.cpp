#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct uvstudet{
	string name;
	double gpa;
	string status;
};
void create(string &f){
	f.append(".txt");
	fstream file(f,ios::out);
	if(!file.is_open()){
		cout<<"eror creating the file ";
	}
	else{
		file<<"student Full-Name\tGPA\tStatus";
		file.close();
		cout<<"file created sucussus fully you are redy to go "<<endl;
	}
}
void rgstration(uvstudet*p,string filename,int &count){
	if(count>40){
		cout<<"database full";
	}
	else{
	cout<<"student regstration\n";
	fstream file(filename,ios::out|ios::app|ios::in);
	if(!file.is_open()){
		cout<<"there is no such file in dictionary ";
	}
	else{
	int i=count;
			cout<<"enter Student "<<i+1<<"full name";getline(cin,(p+i)->name);
			cout<<"semester GPA ";cin>>(p+i)->gpa;cin.ignore();
			cout<<"status ";cin>>(p+i)->status;cin.ignore();
			file<<(p+i)->name<<"\t"<<(p+i)->gpa<<"\t"<<(p+i)->status<<endl;
			count++;
			file.close();
			cout<<"student sucususufuly regestered";
	}
}
}
void chek(uvstudet*p,string filename,int &count){
	string header;
	if(count==0){
		cout<<"database is epty"<<endl;
	}
	else{
	
	fstream file(filename,ios::out|ios::in);
	if(!file.is_open()){
		cout<<"there is no such file or databse is empty";
	}
	else{
		cout<<"cheking for status of student "<<endl;
		getline(file,header);
		for(int i=0;i<count;i++){
			file>>(p+i)->name>>(p+i)->gpa>>(p+i)->status;
			if((p+i)->gpa<2.0){
				(p+i)->status="warnning";
				cout<<(p+i)->name<<" reported warnning "<<endl;	
			}
			else if((p+i)->gpa>3.7){
				(p+i)->status="exelent";
			}
				file<<header<<endl;
				file<<(p+i)->name<<"\t"<<(p+i)->gpa<<"\t"<<(p+i)->status<<endl;
			
		}
		file.close();
		cout<<"cheked sucususufuly"<<endl;
	}
}
}	
int main(){
	string filename;
	uvstudet*ptr=new uvstudet[50];
	int count=0;
	cout<<"student managemnent system "<<endl;
	cout<<"to use the system create file first";
	cout<<"\n enter file name ";getline(cin,filename);
	create(filename);
	int choice;
	while(true){
	cout<<"welcome to student managenement sytem"<<endl;
	cout<<"1.regster new student"<<endl;
	cout<<"2.chek and mark warning students"<<endl;
	cout<<"3.exit."<<endl;
	cout<<"ENTER your choice :";
	while(!(cin>>choice)&&choice>3&&choice<1){
		cout<<"invalid input try agan";
		cin.clear();
	    cin.ignore(100000,'\n');}
	    cin.ignore();
	switch(choice){
		case 1:rgstration(ptr,filename,count);break;
		case 2:chek(ptr,filename,count);break;
		case 3: cout<<"thank you for chosing us";return 0;break;
	}
	}
}