#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
struct task {
	int id;
	string title;
	string decription;
	string priority;
	string assigned;
	string status;
	string duedate;
	
};
void syncdata(task*t,int &count,string f){
	fstream file(f,ios::out|ios::trunc);//every time the fuction called it wipes everyting and write it agan 
	if(!file.is_open()){
		//cheking wheter the file is opend 
		cout<<"couldn't open the file or file doesnt exist \n";
	}
	else{
		//writing inside the file
			file << "ID\tTITLE\tDECRIPTION\tPRIORITY\tASSIGNED TO\tSTATUS\tDUEDATE"<<endl;
        for(int i=0; i<count; i++){
            file <<(t+i)->id <<"\t"<<(t+i)->title<<"\t"<<(t+i)->decription<<"\t"<<(t+i)->priority<<"\t"<<(t+i)->assigned<<"\t"<< (t+i)->status<<"\t"<<(t+i)->duedate <<endl;
        }
        	file.close();//closong the file properly
	}
		
	}
void add(task*t,int &count,string f){
	int lastId;
	if(count==0){
		lastId=1;
	}
	else{
	lastId=(t+count-1)->id+1;//deteting bug fixer and the id automaticaly updated by the previus incid inrement
}
	fstream file(f,ios::app|ios::out|ios::in);
	if(!file.is_open()){
		cout<<"couldn't open the file or file doesnt exist \n";
	}
	else{
		if(count==50){
			//chkeing if teh task list is full
			cout<<"database full \n ";
		}
		else{
			cout<<"-------adding new task--------\n";
			(t+count)->id=lastId;//adding new id incrementtaly 
			cout<<"task id = "<<lastId<<endl;
			cout<<"enter task title ";getline(cin,(t+count)->title);//getting every line until the user hits enter
			cout<<"enter task decription ";getline(cin,(t+count)->decription);
			cout<<"enter task priority(high,emdium,low) ";getline(cin,(t+count)->priority);
			cout<<"enter  assignannce ";getline(cin,(t+count)->assigned);
			cout<<"enter task status ";getline(cin,(t+count)->status);
			cout<<"enter task duedate ";getline(cin,(t+count)->duedate);
			file<<(t+count)->id<<"\t"<<(t+count)->title<<"\t"<<(t+count)->decription<<"\t"<<(t+count)->priority<<"\t"<<(t+count)->assigned<<"\t"<<(t+count)->status<<"\t"<<(t+count)->duedate<<endl;
			count++;//updating or incrimenting after adding each task
			file.close();
			cout<<"task sucusussfully aded to the list.........\n";
			
		}
	}
}
void view(task*t,int &count,string f){
	fstream file(f,ios::in);//reading only
	if(!file.is_open()){
		cout<<"file doesnt exist \n";
	}
	else{
		if(count==0){
			cout<<"thre is no task to see\n";
		}
		else{//setw() it is from library helps us to make the list look like atable when displaing 
			cout <<left<<setw(5)<<"ID"<<setw(20)<<"TITLE"<<setw(25)<<"DECRIPTION"<<setw(15)<<"PRIORITY"<<setw(15)<<"ASSIGNED"<<setw(15)<<"STATUS"<<"DUEDATE"<<endl;//prin using set width left mean the task is or the output is left alighned 
			for (int i = 0; i < count; i++) {
           
		   cout<<left<<setw(5)<<(t + i)->id;
           cout <<setw(20) <<(t + i)->title; 
           cout <<setw(25)<<(t + i)->decription;
           cout <<setw(15)<<(t + i)->priority;
           cout <<setw(15)<<(t + i)->assigned;
           cout <<setw(15)<<(t + i)->status;
           cout <<(t + i)->duedate << endl;
    }
			
		}
	}
}
void markasdone(task*t,int&count,string f){
	int id;
	bool found=false;
	if(count==0){
		cout<<"there is no avalable task\n";
	}
	else{
		cout<<"----------status updator------------\n";
		cout<<"enter the task id ";
		while(!(cin>>id)){
			cout<<"envalid input try agan ";
			cin.clear();
			cin.ignore(100000,'\n');
		}
			cin.ignore();//cleaning or takin honly the value of the choice remiving the eneter tab
	for(int i=0;i<count;i++){
		
	
		if(id==(t+i)->id){
			cout<<"enter new status to be marked (done,pendding,failed) ";getline(cin,(t+i)->status);
			syncdata(t,count,f);//calling function to syncy or update data
			cout<<"task status successusfuly updated.........\n";
			found=true;
			break;//stop cheking the rest of teh data to prevent over working
		}
		
	}
	if(!found){
			cout<<"id not found\n";}

	}
}
void update(task*t,int&count,string f){
	int id;
	bool found=false;
	if(count==0){
		cout<<"there is no task to be updated \n";
	}
	else{
		cout<<"---------task updataor seystem---------\n";
		cout<<"enter the task id ";
		while(!(cin>>id)){
			cout<<"envalid input try agan ";
			cin.clear();
			cin.ignore(100000,'\n');
		}
			cin.ignore();
		for(int i=0;i<count;i++){
			if(id==(t+i)->id){
				cout<<"task "<<(t+i)->title<<" founded \n";
			cout<<"enter new title ";getline(cin,(t+i)->title);//as usual recieveing every ting line by line from teh user until th euser cliks enter
			cout<<"enter new decription ";getline(cin,(t+i)->decription);
			cout<<"enter new priority ";getline(cin,(t+i)->priority);
			cout<<"enter new assignance ";getline(cin,(t+i)->assigned);
			cout<<"enter new status ";getline(cin,(t+i)->priority);
			cout<<"enter new duedate ";getline(cin,(t+i)->duedate);
			syncdata(t,count,f);//caling the function to update cahnges
			found=true;
			cout<<" task update sucussusfully done \n";
			break;//stof cheking after the currunt task
				
			}
	
		}
		if(!found){
			cout<<"id not found\n";
		}
			
		
	}
}
void deletet(task*t,int&count,string f){
	int id=0;
	bool found=false;
	if(count==0){
		cout<<"there is no recored to be deleted\n";
	}
	else{
		cout<<"----------task deleting system------------\n";
		cout<<"enter the task id to be deleted --> ";
		while(!(cin>>id)){
			cout<<"error pleas try agan ";
			cin.clear();//removing and cleaning te error messages that cames wehn invalid enput cliked
			cin.ignore(1000000,'\n');
		}
		cin.ignore();
		for(int i=0;i<count;i++){
			if(id==(t+i)->id){
					found=true;
				for(int j=i;j<count-1;j++){
				*(t+j)=*(t+(j+1));//deleting the whole data or the whole row
			}
			count--;
			cout<<"tsak "<<(t+i)->title<<" deleted sucussus fully \n";
				syncdata(t,count,f);//updating the data to the file
				break;//stop cheking the rest of the data after deletion
			
		}
	
		}
		if(!found){
			cout<<"id not found\n";}
		
		
		
	}
}
void loadData(task*t,int&count,string f){
	string header;
	fstream file(f,ios::in);
	if(file.is_open()){
	 	getline(file,header); 
	while(file >> (t+count)->id){
		file.ignore();
	        getline(file, (t + count)->title, '\t');
	        getline(file, (t + count)->decription, '\t');
	        getline(file, (t + count)->priority, '\t');
            getline(file, (t + count)->assigned,'\t');
            getline(file, (t + count)->status, '\t');
            getline(file, (t + count)->duedate);
            count++;				
}
	file.close();
}

	
}
int main(){
int count =0;//the no of tasks or index of the task
string filename;//to be stored in the strage sysem
int choice;
string lineexist;
task*s=new task[50];//only 50 tasks maximum to be stored in one file ;
	cout<<"-------Welcome to task manager-------\n";
	cout<<"pleas enter the litst name for your task : ";
	getline(cin,filename);//accepting until the user cliks enter 
	filename.append(".txt");//adding the file format 
	ifstream test(filename);//chekign if exists
	if(!test){
	ofstream newFile(filename);//creating new file
    newFile <<"ID\tTITLE\tDECRIPTION\tPRIORITY\tASSIGNED TO\tSTATUS\tDUEDATE"<<endl;
    newFile.close();
	}
	else{
		cout<<filename<<"alrady exists"<<endl;
			test.close(); 


}

loadData(s, count, filename);//if atask alarady registered  prevent from wipe out when aprogram rus again 

while(true){
	cout<<"\n--------task manager to "<<filename<<" ---------\n";
	cout<<"1. Add New Task\n";
	cout<<"2. View All Tasks\n";
	cout<<"3. Mark Task as Done\n";
	cout<<"4. Update Task Details\n";
	cout<<"5. Delete a Task\n";
	cout<<"6. Exit\n";
	cout<<"pleas enter your choice >> ";
	//input validation loop
	while(!(cin>>choice)||choice>6||choice<1){
		cout<<"invalid input try agan :";
		cin.clear();//removing the bad errir message
		cin.ignore(100000,'\n');//removeth the bad input
	}
	cin.ignore();//this ignores the tab that is coming from the while loop if sucussus
	switch(choice){
		//function calling for the menu
		case 1:add(s,count,filename);break;
		case 2:view(s,count,filename);break;
		case 3:markasdone(s,count,filename);break;
		case 4:update(s,count,filename);break;
		case 5:deletet(s,count,filename);break;
		case 6: cout<<"exiting......\n";return 0 ;break;
		
	}
	
}

}