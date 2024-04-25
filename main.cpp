#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

float round(float var)
{
    int value = (int)(var * 100 + .5);
    return (float)value / 100;
}

bool check_number(char str) {
    if (isdigit(str) == false){
        return false;
    }
    return true;
}

class Student {
private:
    static const int MAX_STUDENTS = 100;
    int rollno[MAX_STUDENTS];
    int age[MAX_STUDENTS];
    string name[MAX_STUDENTS];
    float cgpa[MAX_STUDENTS];
    int numOfStudents;
    static const int MAX_NCGPA = 100;
public:
    Student() {
        numOfStudents = 0;
        ncgpa=0;
    }

    void addNewStudent(int stdId, string stdName, int stdAge,float stdcgpa) {
        if (numOfStudents < MAX_STUDENTS) {
            rollno[numOfStudents] = stdId;
            name[numOfStudents] = stdName;
            age[numOfStudents] = stdAge;
            cgpa[numOfStudents] = stdcgpa;
            if (stdcgpa >= 9){
            	ninames[ncgpa]=stdName;
            	nicgpa[ncgpa] = stdcgpa;
                ncgpa++;
            }
            numOfStudents++;
        } else {
            cout << "\t\tMaximum limit of students reached! Cannot add more." << endl;
        }
    }

    int checkrollnum(int rno){
        for(int i=0; i < numOfStudents ; i++){
            if(rno == rollno[i]){
                cout<<"\t\tRoll number already exists. "<<endl;
                return 1;
            }
        }
        return 0;
    }

    void displayStudent(int index) {
        cout << "\t\tRoll No : " << rollno[index] << endl;
        cout << "\t\tName : " << name[index] << endl;
        cout << "\t\tAge : " << age[index] << endl;
        cout<<"\t\tCGPA : "  << fixed << setprecision(2) << round(cgpa[index])<<endl;
    }

    int searchStudent(int searchRollno) {
        for (int i = 0; i < numOfStudents; i++) {
            if (rollno[i] == searchRollno) {
                return i; 
            }
        }
        return -1; 
    }

    void updateStudent(int index, int choice) {
        switch (choice) {
            case 1: {
                int rno;
                cout << "\t\tEnter New Rollno :";
                cin >> rno;
                int n=0;
                for(int i=0; i < numOfStudents ; i++){
                    if(rno != rollno[i]){
                        n++;
                    }
                }
                if(n < numOfStudents){
                    cout<<"\t\tThis Roll Number already exists. Cannot be reassigned"<<endl;
                    break;
                }
                rollno[index] = rno;
                break;
            }
            case 2: {
                string name;
                cout << "\t\tEnter New Name :";
                cin.ignore();
                getline(cin, name);
                this->name[index] = name;
                break;
            }
            case 3: {
                int stdAge;
                cout << "\t\tEnter New Age :";
                cin >> stdAge;
                age[index] = stdAge;
                break;
            }
            case 4:{
                float stdcgpa;
                cout<<"\t\tEnter new CGPA :";
                cin>>stdcgpa;
                cgpa[index] = stdcgpa;
                break;
            }
            default:
                cout << "\t\tInvalid choice" << endl;
        }
    }

    void displayAllStudents() {
        if (numOfStudents == 0) {
            cout << "\t\tNo Students registered!" << endl;
            return;
        }
        for (int i = 0; i < numOfStudents; i++) {
            displayStudent(i);
            cout << endl;
        }
    }

    void display9plist(){
        cout<<"\t\t---------9 POINTERS LIST----------"<<endl;
        for(int i=0 ; i < ncgpa ; i++)
        {
            cout<<"\t\t"<<i+1<<". "<<ninames[i]<<"\t\t\t\t\t\t"<<fixed<<setprecision(2)<<round(nicgpa[i])<<endl;
        }
    }

};

class stdteachsch
{
    string teaname[30];
    string slot[30][25];
    int num_slots[30];
    string stdslots[25];
    int numstdslots;
    static int numofteachers;

public:
    void setteaslots(string nam, char arr[], int num)
    {
        teaname[numofteachers] = nam;
        num_slots[numofteachers] = num;
        for (int i = 0; i < num; i++)
        {
            slot[numofteachers][i] = arr[i];
        }
        numofteachers++;
    }

    void getteachslots()
    {
        string tchname;
        string times;
        int n = 1;
        cout << "\t\tEnter your name: ";
        cin >> tchname;
        for (int i = 0; i < numofteachers; i++)
        {
            if (teaname[i] == tchname)
            {
                cout << "\n\t\tYou are already registered!";
                return;
            }
        }
        teaname[numofteachers] = tchname;
        cout << "\t\t------------------------Slots-----------------------" << endl;
        cout << "\t\t             9-10    10-11    11-12    1-2    2-3   " << endl;
        cout << "\t\tMONDAY        A        B        C       D      E   " << endl;
        cout << "\t\tTUESDAY       F        G        H       I      J   " << endl;
        cout << "\t\tWEDNESDAY     K        L        M       N      O   " << endl;
        cout << "\t\tTHURSDAY      P        Q        R       S      T   " << endl;
        cout << "\t\tFRIDAY        U        V        W       X      Y   " << endl;

        cout << "\t\tEnter your free slots in the form (A,B,C...): ";
        cin >> times;
        for (int i = 0; i < times.length(); i++)
        {
            if (times[i] == ',')
            {
                n++;
            }
        }
        num_slots[numofteachers] = n;

        int slotIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (times[slotIndex] != ',')
            {
                slot[numofteachers][i] = times[slotIndex++];
            }
            else
            {
                slotIndex++;
                i--;
            }
        }
        numofteachers++;
    }

    void getstdslots()
    {
        string stdslo;
        int n = 1;
        cout << "\t\t------------------------Slots-----------------------" << endl;
        cout << "\t\t             9-10    10-11    11-12    1-2    2-3   " << endl;
        cout << "\t\tMONDAY        A        B        C       D      E   " << endl;
        cout << "\t\tTUESDAY       F        G        H       I      J   " << endl;
        cout << "\t\tWEDNESDAY     K        L        M       N      O   " << endl;
        cout << "\t\tTHURSDAY      P        Q        R       S      T   " << endl;
        cout << "\t\tFRIDAY        U        V        W       X      Y   " << endl;

        cout << "\t\tEnter your free slots in the form (A,B,C...): ";
        cin >> stdslo;

        for (int i = 0; i < stdslo.length(); i++)
        {
            if (stdslo[i] == ',')
            {
                n++;
            }
        }
        numstdslots = n;
        int slotindex = 0;
        for (int i = 0; i < numstdslots; i++)
        {
            if (stdslo[slotindex] != ',')
            {
                stdslots[i] = stdslo[slotindex++];
            }
            else
            {
                slotindex++;
                i--;
            }
        }
    }

    void dispcommon()
    {
        string teacher;
        cout<<"\t\tThe available teachers :"<<endl;
        for(int i = 0 ; i < numofteachers ; i++)
        {
            cout<<teaname[i]<<endl;
        }
        cout << "\t\tEnter the teacher's name you want to check with: ";
        cin >> teacher;
        int ind = -1;
        for (int i = 0; i < numofteachers; i++)
        {
            if (teaname[i] == teacher)
            {
                ind = i;
                break;
            }
        }
        if (ind == -1)
        {
            cout << "\t\tTeacher not found!" << endl;
            return;
        }

        string cmnslots[25];
        int n = 0;
        for (int i = 0; i < num_slots[ind]; i++)
        {
            for (int j = 0; j < numstdslots; j++)
            {
                if (slot[ind][i] == stdslots[j])
                {
                    cmnslots[n++] = stdslots[j];
                }
            }
        }

        if (n == 0)
        {
            cout << "\t\tNo common slots found." << endl;
            return;
        }

        cout << "\t\tThe common slots are: ";
        for (int i = 0; i < n; i++)
        {
            cout << cmnslots[i] << ' ';
        }
        cout << endl;
    }
};

int stdteachsch::numofteachers = 0;

int main()
{
    Student students;
    stdteachsch tch;
    string choice;
    char arr1[3] = {'A', 'G', 'T'};
    tch.setteaslots("Bijji", arr1, 3);
    char arr2[4] = {'Q','I','K','W'};
    tch.setteaslots("Max",arr2,4);
    char arr3[4]= {'Y','I','L','T'};
    tch.setteaslots("Pratika",arr3,4);
    char arr4[6]= {'B','E','H','M','O','Q'};
    tch.setteaslots("Arun",arr4,6);
    char arr5[2]={'A','I'};
    tch.setteaslots("Manjulika",arr5,2);
    do {
        system("cls");
        int option;
        cout << "\n\t\t--------------------------------";
        cout << "\n\t\t*** Student Management System ***";
        cout << "\n\t\t--------------------------------";
        cout << "\n\t\t 1. Add New Student" << endl;
        cout << "\n\t\t 2. Display All Students" << endl;
        cout << "\n\t\t 3. Search Student" << endl;
        cout << "\n\t\t 4. Update Student" << endl;
        cout << "\n\t\t 5. 9 pointers list" << endl;
        cout << "\n\t\t 6. Register your free slots (only for teachers)" << endl;
        cout << "\n\t\t 7. Check common slots with your teacher." << endl;
        cout << "\n\t\t 8. Exit" << endl;
        cout << "\n\t\t Enter Your Choice : ";
        cin >> option;

        switch (option) {
            case 1: {
                int rno, age;
                string name;
                float cgpa;
                cout << "\t\tEnter Rollno :";
                cin >> rno;

                if((students.checkrollnum(rno))==1){
                    break;
                }
                cout << "\t\tEnter Name :";
                cin.ignore();
                getline(cin, name);
                cout << "\t\tEnter Age :";
                cin >> age;
                cout << "\t\tEnter CGPA :";
                cin >> cgpa;
                students.addNewStudent(rno, name, age, cgpa);
                break;
            }
            case 2:
                students.displayAllStudents();
                break;
            case 3: {
                int rollno;
                cout << "\t\tEnter Rollno :";
                cin >> rollno;
                int index = students.searchStudent(rollno);
                if (index != -1) {
                    cout << "\t\t--------Student Found ------------" << endl;
                    students.displayStudent(index);    
                } else {
                    cout << "\t\tStudent not found" << endl;
                }
                break;
            }
            case 4: {
                int rollno;
                cout << "\t\tEnter Rollno :";
                cin >> rollno;
                int index = students.searchStudent(rollno);
                if (index != -1) {
                    int choice;
                    cout << "\t\t---Student registered -----" << endl;
                    cout << "\t\t 1. Update Rollno " << endl;
                    cout << "\t\t 2. Update Name " << endl;
                    cout << "\t\t 3. Update Age " << endl;
                    cout << "\t\t 4. Update CGPA " << endl;
                    cout << "\t\t Enter Your Choice :";
                    cin >> choice;
                    students.updateStudent(index, choice);
                } else {
                    cout << "\t\tStudent not registered." << endl;
                }
                break;
            }
            case 5:{
                students.display9plist();
                break;
            }
            case 6:{
                tch.getteachslots();
                break;
                }
            case 7:
            {
                tch.getstdslots();
                tch.dispcommon();
                break;
            }
        
            case 8:
                exit(1);
            default:{
                cout << "\t\tInvalid choice " << endl;
            }
        }
    cout << "\t\tDo You Want to Continue (Yes/No) ? :";
    cin >> choice;
    } while (choice[0] == 'y' || choice[0] == 'Y');

    return 0;
}
