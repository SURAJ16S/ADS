/*tree can be implemented using both the array and linked list 
in array there is a problem of memory wastage (as if left or right child is not present in that case memory is still have to be allocated to total n(n-1) nodes) and more number of comparison 
in case of linked list there is not memory wastage as only the nodes are present are allocated the memory else the memory is not allocated and less number of comparison is required
total comparisons are only equals to total number of nodes present in the tree 

so linked list is better than array in case of tree implementation

check reference book before coming to the netx class 
*/
#include<iostream>
using namespace std;

class employee{
 public:
  string name;
  string employeeid;
    
    employee *next;
void acceptdata();
void display();
void revdisplay();
void search(string ss);
void update(string ss);
}*start=NULL,*temp=NULL,*tail=NULL;

void employee::acceptdata(){
    employee *nnode;
    nnode = new employee;

    cout<<"Enter Employee Name : ";
    cin>>nnode->name;
    
    cout<<"Enter Employee ID : ";
    cin>>nnode->employeeid;

    nnode->next=NULL;

    if(start==NULL){
        start=nnode;
        temp=start;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nnode;
    }
}

void employee::display(){
temp=start;
if(temp==NULL){
    cout<<"No Employee Data Available"<<endl;
    return;
}
else{
    while(temp!=NULL){
        cout<<"Employee Name : "<<temp->name<<"\nEmployee ID : "<<temp->employeeid<<endl;
        temp=temp->next;
    }
}

}

void employee::revdisplay(){
temp=tail;
if(temp==NULL){
    cout<<"No Employee Data Available"<<endl;
    return;
}
else{
    while(temp!=NULL){
        cout<<"Employee Name : "<<temp->name<<"\nEmployee ID : "<<temp->employeeid<<endl;
        temp=temp->next;
    }

}
}

void employee::update(string ss){
temp=start;
int flag=0;
while(temp!=NULL){
    if(temp->employeeid == ss){
        flag=1;
        break;
    }
    temp=temp->next;
}
if(flag==0){
    cout<<"Employee Not Found"<<endl;
}
else{
    cout<<"Employee Found"<<endl;
    cin.ignore();
    cout<<"Enter New Employee Name : ";
    cin>>temp->name;
    cout<<"Enter New Employee ID : ";
    cin>>temp->employeeid;
}
}

void employee::search(string ss){
temp=start;
int flag=0;
while(temp!=NULL){
    if(temp->employeeid == ss){
        flag=1;
        break;
    }
    temp=temp->next;
}
if(flag==0){
    cout<<"Employee Not Found"<<endl;
}
else{
    cout<<"Employee Found"<<endl;
}
}

int main(){
string s;
employee e;
int choice;
do{
    cout<<"Employee management system"<<endl;
cout<<"1.Accept Employee Data\n2.Display Employee Data\n3.Search Employee Data\n4.Update Employee Data\n5.Reverse Display\n6.Exit\nEnter Your Choice : ";
cin>>choice;

switch(choice){
    case 1:
        e.acceptdata();
        break;
    case 2:
        e.display();
        break;
    case 3:
        cout<<"Enter Employee ID to Search : ";
        cin>>s;
        e.search(s);
        break;
    case 4:
        cout<<"Enter Employee ID to Update : ";
        cin>>s;
        e.update(s);
        break;
    case 5:
    e.revdisplay();
        break;
    case 6:
        cout<<"Exiting..."<<endl;
        break;
    default:
        cout<<"Invalid Choice"<<endl;
}
}while(choice!=6);

    return 0;
}