#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string line;
	ifstream file("storage of items.txt");
	if(!file.is_open()){
		cout<<"could't  fined teh file";
	}
	else{
		while(true){
			getline(file,line);
			if(file.eof()){
				break;
			}
			cout<<line<<endl;
		}
		file.close();
	}
	
	return 0;
}