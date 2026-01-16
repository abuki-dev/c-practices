#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
int size;
cout<<"how many students data do you have there ";cin>>size;cin.ignore();
double *pointer=new double[size];
cout<<"well done now let us record them ";
for(int i=0;i<size;i++){
	cout<<"emter student "<<i+1<<" mark ";
	cin>>*(pointer+i);
	cin.ignore();
}
ofstream file("STUDENTS.txt");
if(!file.is_open()){
	cout<<"erorr";
}
else{
	for(int i=0;i<size;i++){
		file<<*(pointer+i)<<endl;
	}
	file.close();
	
}

ifstream folder("STUDENTS.txt");
if(!folder.is_open()){
	cout<<"no file there ";
}
else{
      int i=0;
      cout<<"values are = ";
	while(i<size&&folder>>*(pointer+i)){
	
		cout<<*(pointer+i)<<" ";
		i++;
	}
	folder.close();
	double max=*(pointer+0);
	double sum=0.00;
	for(int i=0;i<size;i++){
		if(*(pointer+i)>max){
			max=*(pointer+i);
		}
		sum+=*(pointer+i);
	}
	delete[] pointer;
    pointer = nullptr;
	
	cout<<"\n the arrays sum is "<<sum;
	cout<<"\nand the maximum is "<<max;
}
return 0;


}