#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct student{
	string name;
	double mark;
};
int main(){
	student *ptr=new student[3];
	for(int i=0;i<3;i++){
		cout<<"tell me name of student "<<i+1;cin>>(ptr+i)->name;
		cout<<"tell  me your marlk";cin>>(ptr+i)->mark;
	}
	fstream file("simle.txt",ios::out);//its new file so idon need append for now 
	if(!file.is_open()){
		cout<<"couldnt create the file ";
	}
	else{
		int i=0;
		while(i<3){
			file<<(ptr+i)->name<<" "<<(ptr+i)->mark<<endl;
			i++;
		}
		file.close();
	}
	double sum=0.0;
	int j=0;
	ifstream reader("simle.txt");
	if(!reader.is_open()){
		cout<<"no records found at all";
	}

	else{
		while(j<3){
			reader>>(ptr+j)->name;
			reader>>(ptr+j)->mark;
			sum+=(ptr+j)->mark;
			j++;
		}
		reader.close();
		double avregae=sum/j;
		cout<<"the total mark of students is"<<sum<<endl;
		cout<<"and the average values is"<<avregae;
		delete[] ptr;
		ptr=nullptr;
	}
	return 0;
	
}