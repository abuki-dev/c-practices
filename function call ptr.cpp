#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct student{
	string name;
	string cource;
	double mark;
};
void create(string &f){
	f.append(".txt");
	fstream file(f,ios::app);
	if(!file.is_open()){
		cout<<"cannot create the file";
	}
	else{
		file.close();
		cout<<"file creation sucussufuly done"<<endl;
	}
}
void recorder(student*s,int size,string &f){
	fstream file(f,ios::app|ios::out|ios::in);
	if(!file.is_open()){
		cout<<"error cant find the file pleae chek "<<endl;//after
	}
	else{
		for(int i=0;i<size;i++){
			cout<<"tell me student "<<i+1<<" name";getline(cin,(s+i)->name);
			cout<<"corce name ";getline(cin,(s+i)->cource);
			cout<<"final score";cin>>(s+i)->mark;cin.ignore();
			file<<(s+i)->name<<"\t"<<(s+i)->cource<<"\t"<<(s+i)->mark<<endl;
		}
		file.close();
		cout<<"data written succussus fully"<<endl;
	}
}
void reader(student*s,int size,string &f){
	string line;
	fstream file(f,ios::in);
	if(!file.is_open()){
		cout<<"the file doesnt exist"<<endl;
	}
	else{
		while(getline(file,line)){
			cout<<line<<endl;
		}
		cout<<" displaying sucussus"<<endl;
		file.close();
		
	}
}
int main(){
	student*ptr=new student[3];
	string filename;
	cout<<"this is student recording system"<<endl;
	cout<<"first create file or use existing file"<<endl;
	cout<<"enter file name";getline(cin,filename);
	create(filename);
	int choice;
	while(true){
		cout<<"\n choose correct opteions below "<<endl;
		cout<<"1.record data to file"<<endl;
		cout<<"2.read data from thefile"<<endl;
		cout<<"3.exit"<<endl;
		if(!(cin>>choice)){
			cin.clear();
			cin.ignore(10000,'\n');
			cout<<"pleas choose correct option ";
			continue;
		}
		cin.ignore();
		switch(choice){
			case 1:recorder(ptr,3,filename);break;
			case 2:reader(ptr,3,filename); break;
			case 3:cout<<"exiting.......";
			 return 0;break;
			 default :cout<<"invalid choice try agan ";
			 
		}
	}
	cout<<"tank you fo rchoosing us";
	return 0;
}