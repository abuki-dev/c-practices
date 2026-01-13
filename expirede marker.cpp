#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct product{
	string name;
	double price;
	string exp;
};
int main(){
	product*ptr=new product[5];
	string header;
	fstream file("inv.txt",ios::in);
	if(!file.is_open()){
		cout<<"no suchi file in the dictionary";
	}
	else{
		getline(file,header);
		for(int i=0;i<5;i++){
			file>>(ptr+i)->name;
			file>>(ptr+i)->price;
			file>>(ptr+i)->exp;
		}
		file.close();
	}
	string expname;
	cout<<"what is name of product expired ";getline(cin,expname);
	for(int j=0;j<5;j++){
		if(expname==(ptr+j)->name){
			(ptr+j)->price=0.00;
			(ptr+j)->exp="expired";
			cout<<" item "<<(ptr+j)->name<<" marked expired"<<endl;
		}

}
fstream overr("inv.txt",ios::out);
if(!overr.is_open()){
	cout<<"file not found";
}
else{
	overr<<header<<endl;
	for(int k=0;k<5;k++){
		overr<<(ptr+k)->name<<"\t"<<(ptr+k)->price<<"\t"<<(ptr+k)->exp<<endl;
	}
	overr.close();
	cout<<"sucussusfuly markd expired items";
}
delete [] ptr;
ptr=nullptr;
return 0;

}
