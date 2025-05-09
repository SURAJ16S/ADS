/*
Assignment 6

Problem Statement : a medical record system is a software application used to manage medical records including patient information medical history 
and treatment plan. hash table can be used as a data structure to efficiently store and retrieve medical records.
*/

#include<iostream>
using namespace std;

class MedicalRecord {
    int key[20],c[20],n; // keys and hash table (c[]) and total elements (n)
    //c[] is the hash table, c[i] = -2 means empty, c[i] = -1 means deleted
    
    //data to be accepted in array 
    string name[20],history[20],plan[20]; // patient info arrays
    int age[20];
     
    int loc; //loc : location for the hash table (where the records is stored)
public:
    void table();    // initialize table

    void accept();   // input records
    void display();  // display all records
    
    void search();   // search by key
    void modify();  // modify record by key
    void count(); // count records
};

void MedicalRecord::table() {
    //accept the total number of records
    cout<<"Enter number of records: ";
    cin>>n;
//accept total keys for the n records
    cout<<"Enter the key values: ";
    for (int i = 0; i < n; i++) {
        cin>>key[i];
        //hash the key for the index location in hash table
        loc = key[i] % 10;
    }
    for (int i = 0; i < 10; i++) {   //set all records to -2 (empty)
        c[i] = -2; // -2 means empty
    }
}

//algorithm of table :
//1. accpe the total keys to enter
//2. accept the key values
//3. loc = key[i] % 10 //apply hashing function
//4. set the hash table values to -2(empty)

void MedicalRecord::accept() {
    for (int i = 0; i < n; i++) {
        loc = key[i] % 10;
        while (c[loc] != -2) {
            loc = (loc + 1) % 10; //increment location by one 
        } // linear probing
        c[loc] = i;

        //accept the values 
        cout<<"Enter the name of the patient: ";
        cin>>name[i];
        cout<<"Enter the age of the patient: ";
        cin>>age[i];
        cout<<"Enter the medical history of the patient: ";
        cin>>history[i];
        cout<<"Enter the treatment plan of the patient: ";
        cin>>plan[i];
    }
}

//algorithm of accept :
/*
1. apply for loop from 0 to n (total records)
2. hash the key value and store into loc
3. while c[loc] ! =-2 (not empty) then update loc to (loc+1)%10 (linear probing) 
*/

void MedicalRecord::display() {
    cout<<"The records are:\n";
    cout<<"| Key | Index | Name | Age | Medical History | Treatment Plan |\n";
    cout<<"---------------------------------------------------------------\n";
    for (int i = 0; i < 10; i++) {
        if (c[i] != -2) {
            int index = c[i];         //store the hashtable[] index in index variable
            cout<<"| "<<key[index]<<" | "<<index<<" | "<<name[index]<<" | "<<age[index]<<" | "<<history[index]<<" | "<<plan[index]<<" |\n";
        }
    }
}

void MedicalRecord::search() {
    //accept the key to search
    int k;
    cout<<"Enter the key to be searched: ";
    cin>>k;
    //conver key to index
    loc = k % 10; //convert key to index
    //searching for the key in the hash table using linear probing   //c is the hash table
    while (c[loc] != -2 && key[c[loc]] != k){
        loc = (loc + 1) % 10; // Move to the next index if not equal
    }

    if (c[loc] == -2) {
        cout<<"Record not found.\n";
    } else {
        int index = c[loc];
        cout<<"The record is:\n";
        cout<<"| Key | Index | Name | Age | Medical History | Treatment Plan |\n";
        cout<<"---------------------------------------------------------------\n";
        cout<<"| "<<key[index]<<" | "<<index<<" | "<<name[index]<<" | "<<age[index]<<" | "<<history[index]<<" | "<<plan[index]<<" |\n";
    }
}

void MedicalRecord::modify(){
    int k;
    cout<<"Enter the key to be modified: ";
    cin>>k;
    loc = k % 10;
    while (c[loc] != -2 && key[c[loc]] != k) loc = (loc + 1) % 10;
    if (c[loc] == -2) {
        cout<<"Record not found.\n";
    } else {
        int index = c[loc];
        cout<<"Enter the new name of the patient: ";
        cin>>name[index];
        cout<<"Enter the new age of the patient: ";
        cin>>age[index];
        cout<<"Enter the new medical history of the patient: ";
        cin>>history[index];
        cout<<"Enter the new treatment plan of the patient: ";
        cin>>plan[index];
        cout<<"Record modified successfully.\n";
    }
}

void MedicalRecord::count() {
    int count = 0;
    for (int i = 0; i < 10; i++){
        if (c[i] != -2){    //-2 means empty so increment the variable only if not equals to -2 , (not taken -1 as it is used in the chain concept )
         count++;
        }
    }
    cout<<"Total records: "<<count<<endl;
}
//main function and calling using the object 
int main() {
    MedicalRecord m;
    int choice;
    do {
        cout<<"\n1. Accept the records\n2. Display the records\n3. Search the records\n4. Modify the records\n5. Count total records\n6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1: m.table(); 
            m.accept(); 
            break;
            case 2: m.display(); 
            break;
            case 3: m.search(); 
            break;
            case 4: m.modify(); 
            break;
            case 5: m.count(); 
            break;
            case 6: cout<<"Exiting...\n"; 
            break;
            default: cout<<"Invalid choice!\n"; break;
        }
    } while (choice != 6);
    return 0;
}
