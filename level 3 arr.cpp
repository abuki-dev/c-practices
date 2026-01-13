#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct product{
	string name;
	double price;
	string expdays;
};
int main (){
	product*ptr=new product[5];
	fstream file("inv.txt",ios::out);
	if(!file.is_open()){
		cout<<"try agan";
	}
	else{
		file<<"product name\tprice\tdays befor expiry"<<endl;
		for(int i=0;i<5;i++){
			cout<<"tell me product "<<i+1<<" name ";getline(cin,(ptr+i)->name);
			cout<<"also the price ";cin>>(ptr+i)->price;cin.ignore();
			cout<<"also expdays left ";getline(cin,(ptr+i)->expdays);
			file<<(ptr+i)->name<<"\t"<<(ptr+i)->price<<"\t"<<(ptr+i)->expdays<<endl;
		}
		file.close();
	}
	string header;
	fstream read("inv.txt",ios::in);
	if(!read.is_open()){
		cout<<"no record found there";
	}
	else{
		getline(read,header);
		for(int j=0;j<5;j++){
		 read>>(ptr+j)->name;
		 read>>(ptr+j)->price;
		 read>>(ptr+j)->expdays;
		}
		read.close();
	}
		for(int j=0;j<5;j++){
	 	(ptr+j)->price*=12.4;
	           };
	    fstream over("inv.txt",ios::out);
	      if(!over.is_open()){
	      	cout<<"no such file ";
			   }
		 else{
		 	over<<header<<endl;
		 	cout<<"item\tnewprice"<<endl;
		     for(int k=0;k<5;k++){
		over<<(ptr+k)->name<<"\t"<<(ptr+k)->price<<"\t"<<(ptr+k)->expdays<<endl;
		cout<<(ptr+k)->name<<"\t"<<(ptr+k)->price<<endl;
			 }
			 over.close();
		 }
	           
}