//till next lab learn the code, bookname,author,publisher, etc
//data structure and algorithm analysis by mark allen weiss


#include<iostream>
using namespace std;

class emp{
    public:
        string name ;
        string id;
        emp *leftc ;
        emp *rightc;
        void create();
        void insert(emp *root, emp *next);
        void display(emp *root);
        void preorder(emp *root);
        void postorder(emp *root);
        void searchemp(emp * root, string ss);
        void modifyemp(emp * root, string ss);
        int height(emp * root);
        void countnode(emp * root);
        void displayroot(emp *root);
        void mirror(emp * root);

}*root,*nextn, *stk[50],*temp=nullptr;

void emp::create(){
    int choice;
 
    root = new emp;

    cout<<"Enter Employee Details"<<endl;
    cout<<"Enter Employee Name: ";
    cin.ignore();
    getline(cin, root->name);
    cout << "Enter Employee ID: ";
    getline(cin, root->id);

    root->leftc = root->rightc = NULL;
    do{
        cout << "Do You Want to Enter the Details Again (yes:1 | no:0): ";
        cin >> choice;
        if (choice == 1) {
            nextn = new emp;
            
            cout<<"Enter Name : ";
            cin.ignore();
            getline(cin,nextn->name);
            cout<<"Enter ID : ";
            getline(cin,nextn->id);
            nextn->leftc = nextn->rightc = NULL;
            insert(root, nextn);
        } 
        else{
            break;
        }
    }while(choice == 1);
}

void emp::insert(emp *root, emp *next){
    int choice;
    cout << "Which Side Do You Want To Store The Details (left: 1 | right: 0): ";
    cin >> choice;

    if(choice == 1){
        if(root->leftc==NULL){
            root->leftc=next;
        } 
        else{
            insert(root->leftc,next);
        }
    }
    else if(choice ==0){
        if(root->rightc==NULL){
            root->rightc=next;
        } 
        else{
            insert(root->rightc,next);
        }    
    }
}

int top=-1;
void emp::display(emp *root){
    //in-order traversal
   if(root==NULL){
       cout<<"No Employee Data Available"<<endl;
       return;
   }
   else{


     temp=root;
do{

    while(temp!=NULL){
        top++;
        temp[top]=*temp;
        temp=temp->leftc;
    }
    if(top!=-1){
        temp=stk[top];
        top--;
        cout<<"Root Nodes"<<endl;
        if(temp->leftc == NULL && temp->rightc ==NULL){
            cout<<"\nName :"<<temp->name<<"ID :"<<temp->id<<endl;
        }
        temp=temp->rightc;
    }
}while(top!=-1 || temp!=NULL);

       display(root->leftc);
       cout<<"Employee Name : "<<root->name;
       cout<<"  Employee ID : "<<root->id<<endl;
       display(root->rightc);
   }
}

void emp::preorder(emp *root){
/*preorder - dlr*/
   if(root==NULL) return;
   else{
  cout<<"Employee Name : "<<root->name;
       cout<<"  Employee ID : "<<root->id<<endl;
   display(root->leftc);
display(root->rightc);
}
   }

/*postorder - dlr*/
   void emp::postorder(emp *root){
   if(root==NULL) return;
   else{
   
        display(root->leftc);
        display(root->rightc);
        cout<<"using postorder traversal"<<endl;
        cout<<"Employee Name : "<<root->name;
        cout<<"  Employee ID : "<<root->id<<endl;
}
   }


void emp::searchemp(emp *root , string ss){
    if(root==NULL){
        cout<<"Employee Not Found"<<endl;
        return;
    }
    else{
        if(root->id==ss){
            cout<<"Employee Found"<<endl;
            return;
        }
        else{
            searchemp(root->leftc,ss);
            searchemp(root->rightc,ss);
        }
    }
    cout<<"Employee Not Found"<<endl;
}

int emp::height(emp *root){
    int lh = 0,rh =0;
    if(root==NULL){
        cout<<"No Employee Data Available"<<endl;
        return 0;
    }
    else{
        lh = height(root->leftc);
        rh = height(root->rightc);
        if(lh>rh){
           // return lh+1;
           cout<<"Height of the tree is : "<<lh+1<<endl;
        }
        else{
            // return rh+1;
            cout<<"Height of the tree is : "<<rh+1<<endl;
        }
    }    
}

void emp::modifyemp(emp *root , string ss){
    if(root==NULL){
        cout<<"Employee Not Found"<<endl;
        return;
    }
    else{
        if(root->id==ss){
            cout<<"Employee Found"<<endl;
            cout<<"Enter New Name : ";
            cin>>root->name;
            cout<<"Enter New ID : ";
            cin>>root->id;
            cout<<"Employee Details Updated"<<endl;
            return;
        }
        else{
            modifyemp(root->leftc,ss);
            modifyemp(root->rightc,ss);
        }
    }
    cout<<"Employee Not Found"<<endl;
}

void emp::countnode(emp *root){
    int count = 0;
    if(root==NULL){
        cout<<"No Employee Data Available"<<endl;
        return;
    }
    else{
        countnode(root->leftc);
        count++;
        countnode(root->rightc);
    }
    cout<<"Total Number of Employees : "<<count<<endl;
}

void emp::mirror(emp *root){
    if(root==NULL){
        cout<<"No Employee Data Available"<<endl;
        return;
    }
    else{
        mirror(root->leftc);
        mirror(root->rightc);
        temp = root->leftc;
        root->leftc = root->rightc;
        root->rightc = temp;
    }
}

void emp::displayroot(emp *root){
    cout<<"Employee Name : "<<root->name;
    cout<<"  Employee ID : "<<root->id<<endl;
}

int main(){
    emp employee;
    int choice;
    string id;
    do{
        cout<<"Employee Management System\n1.Insert Employee Details\n2.Display details\n3.Search Employee\n4.Modify Employee Details\n5.Display Using Pre Order traversal\n6.Display Using Post Order Traversal\n7.Height Of Tree\n8. Count Total Available Nodes\n9. Mirror The Tree\n10.Display Root Node\n11.Exit Employee management System"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
            employee.create();
            cout<<"Employee Created Successfully"<<endl;
            break;

            case 2:
            employee.display(root);
            break;

            case 3:
            cout<<"Enter Employee ID to Search : ";
            cin>>id;
            employee.searchemp(root,id);
            break;

            case 4:
            cout<<"Enter Employee ID to Modify : ";
            cin>>id;
            employee.modifyemp(root,id);
            cout<<"Employee Details Update Successfully"<<endl;
            break;

            case 5:
            employee.preorder(root);
            break;

            case 6:
            employee.postorder(root);
            break;

            case 7:
            employee.height(root);
            break;
            
            case 8:
            employee.countnode(root);
            break;

            case 9:
            employee.mirror(root);
            break;

            case 10:
            employee.displayroot(root);
            break;

            case 11: 
            cout<<"Exiting Employee Management System"<<endl;
            break;
        
            default:
            cout<<"Invalid choice"<<endl;
        }
    }while(choice!=11);

    return 0;
}
