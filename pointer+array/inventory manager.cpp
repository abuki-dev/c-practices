#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	char choice;
	string filename,name,quality;
	cout<<"hello this is inventory managenement syatem"<<endl;
	cout<<"pleas tell me your filename ";
	getline(cin,filename);
	filename.append(".txt");
	fstream file(filename,ios::out|ios::app);//open an dstart at end whenever you starts writing
	if(!file.is_open()){
		cout<<"could no creat the file pleas chek your path";
	}
	else{
		cout<<"+++++++++++++++++++\n";
		cout<<"inventory recorfing\n";
		cout<<"do you want record theitem(y/n)";
		cin>>choice;
		cin.ignore();
		file<<"item name \t quality"<<endl;
		while(choice=='y'){
			cout<<"pleas enter item name ";
			getline(cin,name);
			cout<<"item quality ";
			getline(cin,quality);
			file<<name<<"\t"<<quality<<endl;
			cout<<"do you want add another item (y/n) ";
			cin>>choice;
			cin.ignore();
			
		}

		file.close();
		cout<<"sucusussfuly recoderd items";
	}
	return 0;
	
	
}