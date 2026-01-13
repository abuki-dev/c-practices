#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	cout<<"______________________________\n";
	cout<<"product item price library module recorder\n";
	string name,folder,price,description;
	
	cout<<"pleas enter the file name you want nake as your file name ";
	getline(cin,folder);
	folder.append(".txt");
	fstream file(folder,ios::out|ios::app);
	if(file.is_open()){
		file<<"product price library module records"<<endl;
		file<<"poduct\tprice\tdecription"<<endl;
		for(int i=0;i<3;i++){
		cout<<"tell me your  products name ";
			getline(cin,name);
			cout<<"tell me product decription also ";
			getline(cin,description);
			cout<<"now tell me the price you paid ";
			cin>>price;
			cin.ignore();
	file<<name<<"\t"<<price<<"\t"<<description<<endl;
		}
		file.close();
		cout<<"you have sucussufully   ";
	}
	else{
		cout<<"pleas chek the file path or avavlabe storge";
	}
	return 0;
}