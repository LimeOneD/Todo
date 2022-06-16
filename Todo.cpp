#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void add()
{
	string task;
	cout<< "Enter the task"<<endl;
	getline(cin>> ws, task);
	
	string id;
	cout<< "Enter the task id " << endl;
	cin>> id;

	string deadline;
	cout << "Enter the deadline (ddmm) " << endl;
	cin >>deadline;

	
	ofstream ofs;
	ofs.open("Todo.txt", std::ios_base::app | std::ios_base::in);
	ofs << id<< deadline << task << endl;
	ofs.close();
	
}

void del()
{
	std::cout<<"Enter the id of the task to be deleted"<< std::endl;
	string id; std::cin >> id;
	string line;
	ifstream fin;
	fin.open("Todo.txt");
	ofstream temp;
	temp.open("temp.txt");

	while(getline(fin, line))
	{
		if(id != line.substr(0,2))
		{
			temp<<line << std::endl;
		}
	}
	temp.close();
	fin.close();

	remove("Todo.txt");
	rename("temp.txt", "Todo.txt");
}

void display()
{
	std::ifstream ifs;
	ifs.open("Todo.txt", std::ifstream::in);

	string s;

	while(getline(ifs, s))

	{
	       string id = s.substr(0,2);
	       string deadline = s.substr(2,4);
	       string task = s.substr(6);

		 std::cout<< "|"<< " " << "Task ID" << " " <<  " " << "|" << " " << "Task description" << " " << "|" << " " << "Task deadline(ddmm)" << " " << "|" << " " << std::endl;
	       std::cout<< "|"<< " " << id << " " <<  " " << "|" << " " << task << " " << "|" << " " << deadline << " " << "|" << " " << std::endl;
	}
}



void help()
{
	cout << "help" <<endl;
}


int main()
{
	

	std::cout<< "[h] Help" << std::endl;
	std::cout<< "[e] Eneter new task" << std::endl;
	std::cout<< "[d] Delete task" << std::endl;
	std::cout<< "[q] Quit" << std::endl<<endl<<endl;
	
	//display();

	cout<<endl<<endl;	
	
	cout<< "Enter your choice"<< endl;
	char s; std::cin>>s;

		if(s=='h')
		{
			help();
			cout<<endl<<endl;
			display();
			cout<<endl<<endl;
			main();
		}
		else if(s=='e')
		{
			add();
			cout<<endl<<endl;
			display();
			cout<<endl<<endl;
			main();
		}

			
		else if(s=='d')
		{
			del();
			cout<<endl<<endl;
			display();
			cout<<endl<<endl;
			main();
		}
		
		else if(s=='q')
			return 0;

}
