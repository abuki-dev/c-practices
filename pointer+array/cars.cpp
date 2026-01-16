#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct cars{
	string name;
	double price;
};
void reader(cars*p){
	string header;
	string str;
	fstream file("cars.txt",ios::in);
	if(!file.is_open()){
		cout<<"no such file in the dictionary ";
	}
	else{
		getline(file,header);
		cout<<header<<endl;
		for(int i=0;i<3;i++){
			file>>(p+i)->name>>(p+i)->price>>str;
			cout<<(p+i)->name<<"\t"<<(p+i)->price<<str<<endl;
		}
		file.close();
		cout<<"data read sucuususu";
	}
	
	
	
}
int main(){
	cars*ptr=new cars[3];
	fstream file("cars.txt",ios::out);
	if(!file.is_open()){
		cout<<"cant open the file ";
	}
	else{
		file<<"car name\tprice"<<endl;
		for(int i=0;i<3;i++){
		cout<<"hello tell me car "<<i+1<<" name ";cin>>(ptr+i)->name;
		cout<<"the current price ";cin>>(ptr+i)->price;
		file<<(ptr+i)->name<<"\t"<<(ptr+i)->price<<"$"<<endl;
		}
		file.close();
		cout<<"sucussusfuly recorded cars"<<endl;
		
	}
	char choice;
	cout<<"do yo want to read what stored (y/n)";
	cin>>choice;cin.ignore();
	while(!(cin>>choice)){
		cout<<"invalid input try again ";
		cin.clear();
		cin.ignore(10000,'\n');
		cin>>choice;
	}
	if(choice=='y'){
		reader(ptr);
	}
	else if(choice=='n'){
		return 0;
	}
	else {
		cout<<"invalid input ";
	}
	
}