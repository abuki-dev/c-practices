#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	cout<<"______________________________\n";
	cout<<"this is student recording database system\n";
	string name,grade;
	fstream file("student grade data.txt",ios::out|ios::app);
	if(file.is_open()){
		
		for(int i=0;i<3;i++){
			cout<<"student "<<i+1<<" tell me your full name ";
			getline(cin,name);
			cout<<"also ypur grade ";
			getline(cin,grade);
			file<<"NAME "<<name<<"|GRADE "<<grade<<endl;
		}
		file.close();
		cout<<"you have sucussufully  recorded the student datas ";
	}
	else{
		cout<<"pleas chek the file path or avavlabe storge";
	}
	return 0;
}