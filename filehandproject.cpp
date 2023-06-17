#include<iostream>
#include<fstream>
using namespace std; 

int ID;//global id defined
class student
{
    public:

    int id;
    string name;
    string stream;
    int age;
    void addstudent()
    {
        //take input all student data
        cout<<"enter student name\n";
        cin.get(); //for clearing buffer when we take input from keyboard and form takeing file use cin.ignore()
        getline(cin,name);
        cout<<"enter age\n";
        cin>>age;
        cout<<"enter stream\n";
        cin.get();
        getline(cin,stream);
        ID++;
        //open  student file and put all data in student file
        ofstream fout;
        fout.open("student.txt",ios::app);
        fout<<"\n"<<ID; //\n for after every line    change
        fout<<"\n"<<name;
        fout<<"\n"<<age;
        fout<<"\n"<<stream;

        fout.close();

        //now open id file for updateing id
        fout.open("id.txt",ios::app);
        fout<<"\n"<<ID;
        fout.close();

        cout<<"record added successfullay\n";


    }
    void printallstudent()
    {
        ifstream fin;
        fin.open("student.txt");
        student p;
        while(!fin.eof())
        {
            fin>>p.id;
            fin.ignore();//for clearing buffer when take input from file
            getline(fin,p.name);
            fin>>p.age;
            fin.ignore();
            getline(fin,p.stream);

            cout<<p.id<<endl;
            cout<<p.name<<endl;
            cout<<p.age<<endl;
            cout<<p.stream<<endl;
        }
       fin.close();
    }
    void searchstudent(int x)
    {
     ifstream fin;
        fin.open("student.txt");
        student p;
        while(!fin.eof())
        {
            fin>>p.id;
            fin.ignore();//for clearing buffer when take input from file
            getline(fin,p.name);
            fin>>p.age;
            fin.ignore();
            getline(fin,p.stream);

            if(p.id==x)
            {
            cout<<p.id<<endl;
            cout<<p.name<<endl;
            cout<<p.age<<endl;
            cout<<p.stream<<endl;
            }
        }
        fin.close();
     }
    
    void deletestudent(int y)
    {
     ifstream fin;
     fin.open("student.txt");

     ofstream fout;
     fout.open("temp.txt");
     student s;
     while(!fin.eof())
     {
        fin>>s.id;
        fin.ignore();
        getline(fin,s.name);

        fin>>s.age;

        fin.ignore();
        getline(fin,s.stream);

        if(s.id!=y)
        {
           fout<<s.id<<endl;
           fout<<s.name<<endl;
           fout<<s.age<<endl;
           fout<<s.stream<<endl;
        }
     }
    fin.close();
    fout.close();
    remove("student.txt"); //first remove file using remove() then rename
    rename("temp.txt","student.txt");
    }
    void updatestudent(int id) //for update first delete that di then add new at that id
    {
        student s;
     deletestudent(id);

     cout<<"enter name\n";
     cin.get();
     getline(cin,s.name);
     cout<<"enter age\n";
     cin>>s.age;
     cout<<"enter stream\n";
     cin.get();
     getline(cin,s.stream);

     ofstream fout;
    fout.open("student.txt",ios::app);

     fout<<"\n"<<id;//not s.id bcz we given id as parametrer
     fout<<"\n"<<s.name;
     fout<<"\n"<<s.age;
     fout<<"\n"<<s.stream;
     fout<<"record update successfullay\n"; 
     fout.close();
    }

};
int main()
{
    ifstream fin;
    fin.open("id.txt");
    if(!fin)
    {
        cout<<"file not found\n";
    }
    else
    {
     while(!fin.eof())
     {
        fin>>ID;
     }
    }
    fin.close();
    int choice;
    while(true){
    cout<<"\nenter your choice\n";
    cout<<"1. add student\n";
    cout<<"2. print all student\n";
    cout<<"3. search a student\n";
    cout<<"4. delete a student\n";
    cout<<"5. update a student\n";
    cin>>choice;
    student s;
    int id;
    
    switch(choice)
    {
        case 1:
        s.addstudent();
        break;
        case 2:
        s.printallstudent();
        break;
        case 3:
        cout<<"enter student id\n";
        cin>>id;
        s.searchstudent(id);
        break;
        case 4:
        cout<<"enter student id\n";
        cin>>id;
        s.deletestudent(id);
        break;
        case 5:
        cout<<"enter student id:";
        cin>>id;
        s.updatestudent(id);
        break;
        
        default:
        return 0;
    }
    }

}