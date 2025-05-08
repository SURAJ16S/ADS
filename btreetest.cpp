#include<iostream>
using namespace std;

class emp{
    public:
        string name;
        string id;
        emp *leftc;
        emp *rightc;
        void create();
        void insert(emp *root, emp *next);
        void display(emp *root);
        void preorder(emp *root);
        void postorder(emp *root);
        void searchemp(emp * root, string ss);
        void modifyemp(emp * root, string ss);
        int height(emp * root);
        int countnode(emp * root);
        void displayroot(emp *root);
        void mirror(emp * root);
} *root = nullptr, *nextn = nullptr, *stk[50], *temp = nullptr;

void emp::create(){
    int choice;
    root = new emp;

    cout << "Enter Employee Details" << endl;
    cout << "Enter Employee Name: ";
    cin.ignore();
    getline(cin, root->name);
    cout << "Enter Employee ID: ";
    getline(cin, root->id);

    root->leftc = root->rightc = nullptr;
    do{
        cout << "Do You Want to Enter the Details Again (yes:1 | no:0): ";
        cin >> choice;
        if (choice == 1){
            nextn = new emp;
            
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, nextn->name);
            cout << "Enter ID: ";
            getline(cin, nextn->id);
            nextn->leftc = nextn->rightc = nullptr;
            insert(root, nextn);
        } 
        else{
            break;
        }
    } while (choice == 1);
}

void emp::insert(emp *root, emp *next){
    int choice;
    cout << "Which Side Do You Want To Store The Details (left: 1 | right: 0): ";
    cin >> choice;

    if (choice == 1) {
        if (root->leftc == nullptr) {
            root->leftc = next;
        } else {
            insert(root->leftc, next);
        }
    } else {
        if (root->rightc == nullptr) {
            root->rightc = next;
        } else {
            insert(root->rightc, next);
        }
    }
}

void emp::display(emp *root){
    if (root == nullptr) {
        cout << "No Employee Data Available" << endl;
        return;
    }
    display(root->leftc);
    cout << "Employee Name: " << root->name << "  Employee ID: " << root->id << endl;
    display(root->rightc);
}

void emp::preorder(emp *root){
    if (root == nullptr) return;
    cout << "Employee Name: " << root->name << "  Employee ID: " << root->id << endl;
    preorder(root->leftc);
    preorder(root->rightc);
}

void emp::postorder(emp *root){
    if (root == nullptr) return;
    postorder(root->leftc);
    postorder(root->rightc);
    cout << "Employee Name: " << root->name << "  Employee ID: " << root->id << endl;
}

void emp::searchemp(emp *root, string ss){
    if (root == nullptr) {
        cout << "Employee Not Found" << endl;
        return;
    }
    if (root->id == ss) {
        cout << "Employee Found" << endl;
        return;
    }
    searchemp(root->leftc, ss);
    searchemp(root->rightc, ss);
}

int emp::height(emp *root){
    if (root == nullptr) return 0;
    int lh = height(root->leftc);
    int rh = height(root->rightc);
    return max(lh, rh) + 1;
}

void emp::modifyemp(emp *root, string ss){
    if (root == nullptr) {
        cout << "Employee Not Found" << endl;
        return;
    }
    if (root->id == ss) {
        cout << "Enter New Name: ";
        cin.ignore();
        getline(cin, root->name);
        cout << "Enter New ID: ";
        getline(cin, root->id);
        cout << "Employee Details Updated" << endl;
        return;
    }
    modifyemp(root->leftc, ss);
    modifyemp(root->rightc, ss);
}

int emp::countnode(emp *root){
    if (root == nullptr) return 0;
    return 1 + countnode(root->leftc) + countnode(root->rightc);
}

void emp::mirror(emp *root){
    if (root == nullptr) return;
    mirror(root->leftc);
    mirror(root->rightc);
    swap(root->leftc, root->rightc);
}
void emp::mirror(emp *root){
    if (root == nullptr) return;
    mirror(root->leftc);
    mirror(root->rightc);
    emp *temp = root->leftc;
    root->leftc = root->rightc;
    root->rightc = temp;
}

void emp::displayroot(emp *root){
    if (root != nullptr) {
        cout << "Employee Name: " << root->name << "  Employee ID: " << root->id << endl;
    } else {
        cout << "No Employee Data Available" << endl;
    }
}

int main(){
    emp employee;
    int choice;
    string id;
    do {
        cout << "Employee Management System\n1.Insert Employee Details\n2.Display details\n3.Search Employee\n4.Modify Employee Details\n5.Display Using Pre Order traversal\n6.Display Using Post Order Traversal\n7.Height Of Tree\n8. Count Total Available Nodes\n9. Mirror The Tree\n10.Display Root Node\n11.Exit Employee management System" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                employee.create();
                cout << "Employee Created Successfully" << endl;
                break;
            case 2:
                employee.display(root);
                break;
            case 3:
                cout << "Enter Employee ID to Search: ";
                cin >> id;
                employee.searchemp(root, id);
                break;
            case 4:
                cout << "Enter Employee ID to Modify: ";
                cin >> id;
                employee.modifyemp(root, id);
                break;
            case 5:
                employee.preorder(root);
                break;
            case 6:
                employee.postorder(root);
                break;
            case 7:
                cout << "Height of the tree is: " << employee.height(root) << endl;
                break;
            case 8:
                cout << "Total Number of Employees: " << employee.countnode(root) << endl;
                break;
            case 9:
                employee.mirror(root);
                break;
            case 10:
                employee.displayroot(root);
                break;
            case 11:
                cout << "Exiting Employee Management System" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 11);
    return 0;
}
