#include<iostream>
#include<fstream>
using namespace std;
int main(){
	double *ptr=new double[5];
	fstream file("STUDENTS.txt",ios::in);
	if(!file.is_open()){
		cout<<"no such file";
	}
	else{
		cout<<"the old values are ";
		for(int i=0;i<5;i++){
			file>>*(ptr+i);
			cout<<*(ptr+i)<<" ";
		}
		file.close();
		
	}
	fstream reverse("STUDENTS.txt",ios::out);
		if(!reverse.is_open()){
			cout<<"cant creat the file ";
		}
		else{
			for(int j=4;j>=0;j--){
				reverse<<*(ptr+j)<<endl;
				
			}
			reverse.close();
			cout<<"reverely writen scussusfuly";
		}
	
}