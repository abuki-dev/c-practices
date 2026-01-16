#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string line,filename;
	cout<<"inorder to read data from you file tell me the name ";
	getline(cin,filename);
	filename.append(".txt");
	fstream file(filename,ios::in);
	if(!file.is_open()){
		cout<<"there is no such file in dictionary";
	}
	else{
		while(true){
		getline(file,line);
		if(file.eof()){
			break;
		} 
			cout<<line<<endl;  }
		
		file.close();
	
	}
	return 0;
}