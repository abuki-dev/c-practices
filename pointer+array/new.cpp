#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string filename,body;
	cout<<"pleas tell your file name ";
	getline(cin,filename);
	cout<<"then tell me the content to be pleased iside your file";
	getline(cin,body);
	filename.append(".txt");
	fstream file(filename,ios::out|ios::app); 
	if(file.is_open()){
		file.seekp(0,ios::end);
		file<<"\n";//if a file exists prevent over writing 
			file<<body<<"  ";
		file.close();
	
		cout<<"adede a data inside";
	}
	else{
		cout<<"the file can not be oppened";
	}
}
