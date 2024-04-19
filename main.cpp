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

class Student {
private:
    static const int MAX_STUDENTS = 100; // Maximum number of students
    int rollno[MAX_STUDENTS];
    int age[MAX_STUDENTS];
    string name[MAX_STUDENTS];
    float cgpa[MAX_STUDENTS];
    int numOfStudents;
    static const int MAX_NCGPA = 100;
	int ncgpa;
	string ninames[MAX_NCGPA];
	float nicgpa[MAX_NCGPA];
	
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
            cout << "Maximum limit of students reached! Cannot add more." << endl;
        }
    }

    int checkrollnum(int rno){
        for(int i=0; i < numOfStudents ; i++){
            if(rno == rollno[i]){
                cout<<"Roll number already exists. "<<endl;
                return 1;
            }
        }
        return 0;
    }

    void displayStudent(int index) {
        cout << "Roll No : " << rollno[index] << endl;
        cout << "Name : " << name[index] << endl;
        cout << "Age : " << age[index] << endl;
        cout<<"CGPA : "  << fixed << setprecision(2) << round(cgpa[index])<<endl;
    }

    int searchStudent(int searchRollno) {
        for (int i = 0; i < numOfStudents; i++) {
            if (rollno[i] == searchRollno) {
                return i; // Return index if found
            }
        }
        return -1; // Return -1 if not found
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
                    cout<<"This Roll Number already exists. Cannot be reassigned"<<endl;
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

    void deleteStudent(int index) {
        for (int i = index; i < numOfStudents - 1; i++) {
            rollno[i] = rollno[i + 1];
            name[i] = name[i + 1];
            age[i] = age[i + 1];
            cgpa[i] = cgpa[i+1];
        }
        numOfStudents--;
        cout << "\t\tStudent Removed Successfully" << endl;
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
        cout<<"\t\t\t---------9 POINTERS LIST----------"<<endl;
        for(int i=0 ; i < ncgpa ; i++)
        {
            cout<<i+1<<". "<<ninames[i]<<"\t\t\t\t\t\t"<<fixed<<setprecision(2)<<round(nicgpa[i])<<endl;
        }
    }

};

void splitString(const string& input, char delimiter, string arr[], int size, int& index)
{
    istringstream stream(input);
    string token;
    while (getline(stream, token, delimiter) && index < size)
    {
        arr[index++] = token;
    }
}

class stdteachsch
{
private:
    string name[30];
    string slots[30][25];
    string stdslots[25];
    int num_slots;
    static int numofteachers;

public:
    void setdata(string s, char arr[], int num)
    {
        name[numofteachers] = s;
        num_slots = num;
        for (int i = 0; i < num; i++)
        {
            if (i < 25)
                slots[numofteachers][i] = arr[i];
            else
            {
                cout << "\t\tThe slots shouldn't be more than 25" << endl;
                break;
            }
        }
        numofteachers++;
    }

    stdteachsch() {}

    void getslots()
    {
        string name1;
        string times;
        char dl = ',';
        int idx = 0;
        int nslot = 0;
        cout << "\t\tEnter your name: ";
        cin >> name1;
        for (int i = 0; i < numofteachers; i++)
        {
            if (name[i] == name1)
            {
                cout << "\t\tYou are already registered!" << endl;
                return;
            }
        }
        name[numofteachers]=name1;
        cout << "\t\t------------------------Slots-----------------------" << endl;
        cout << "\t\t             9-10    10-11    11-12    1-2    2-3   " << endl;
        cout << "\t\tMONDAY        A        B        C       D      E   " << endl;
        cout << "\t\tTUESDAY       F        G        H       I      J   " << endl;
        cout << "\t\tWEDNESDAY     K        L        M       N      O   " << endl;
        cout << "\t\tTHURSDAY      P        Q        R       S      T   " << endl;
        cout << "\t\tFRIDAY        U        V        W       X      Y   " << endl;

        cout << "\t\tEnter your free slots in the form (A,B,C...): ";
        cin >> times;
        int len = times.length();
        for (int i = 0; i < len; i++)
        {
            if (times[i] == dl)
            {
                nslot++;
            }
        }
        num_slots = nslot;
        if (len > 25)
        {
            cout << "\t\tNumber of slots should not exceed 25" << endl;
            return;
        }

        splitString(times, dl, slots[numofteachers], num_slots, idx);
        numofteachers++;
    }

    int nstdslots = 1;
    void getstdslots()
    {
        string times;
        char dl = ',';
        int index = 0;
        cout << "\t\t------------------------Slots-----------------------" << endl;
        cout << "\t\t             9-10    10-11    11-12    1-2    2-3   " << endl;
        cout << "\t\tMONDAY        A        B        C       D      E   " << endl;
        cout << "\t\tTUESDAY       F        G        H       I      J   " << endl;
        cout << "\t\tWEDNESDAY     K        L        M       N      O   " << endl;
        cout << "\t\tTHURSDAY      P        Q        R       S      T   " << endl;
        cout << "\t\tFRIDAY        U        V        W       X      Y   " << endl;

        cout << "\t\tEnter your free slots in the form (A,B,C...): ";
        cin >> times;
        int len = times.length();
        for (int i = 0; i < len; i++)
        {
            if (times[i] == dl)
            {
                nstdslots++;
            }
        }
        if (len > 25)
        {
            cout << "\t\tNumber of slots should not exceed 25" << endl;
            return;
        }

        splitString(times, dl, stdslots, 25, index);
    }

    void dispcommon()
    {
        int ncm = 0;
        string tname;
        int ind = -1; // Initialize with -1
        int ncmslots = 0;
        string opti;
        cout << "\t\tThe registered teachers are:" << endl;
        for (int i = 0; i < numofteachers; i++)
        {
            cout << "\t\t" << i + 1 << ". " << name[i] << endl;
        }
        cout << "\t\tGive the teacher's name you want to check common slots with: ";
        cin >> tname;

        for (int i = 0; i < numofteachers; i++)
        {
            if (name[i] == tname)
            {
                ind = i;
                break;
            }
        }
        if (ind != -1)
        {
            for (int i = 0; i < num_slots; i++)
            {
                for (int j = 0; j < nstdslots; j++)
                {
                    if (slots[ind][i] == stdslots[j])
                    {
                        cout << "\t\tThe common slot is/are: " << stdslots[j] << endl;
                        ncmslots++;
                    }
                }
            }
            if (ncmslots == 0)
            {
                cout << "\t\tThere are no common slots with you and the respective teacher." << endl;
                cout << "\t\tWould you still like to check the teacher's free slots? [Yes/No] ";
                cin >> opti;
                if (opti[0] == 'y' || opti[0] == 'Y')
                {
                    cout << "\t\tFor the teacher: " << name[ind] << endl;
                    cout << "\t\tThe free slots are: ";
                    for (int i = 0; i < num_slots; i++)
                    {
                        if (!slots[ind][i].empty())
                            cout << slots[ind][i] << " ";
                    }
                    cout << endl;
                }
            }
        }
        else
        {
            cout << "\t\tTeacher not registered. Please request the teacher to register on this application!" << endl;
        }
    }
};

int stdteachsch::numofteachers = 0;


int main() {
    Student students;
    stdteachsch tch;
    string choice;
    char arr1[3] = {'A', 'G', 'T'};
    tch.setdata("Bijji", arr1, 3);
    char arr2[4] = {'Q','I','K','W'};
    tch.setdata("Max",arr2,4);
    char arr3[4]= {'Y','I','L','T'};
    tch.setdata("Pratika",arr3,4);
    char arr4[6]= {'B','E','H','M','O','Q'};
    tch.setdata("Arun",arr4,6);
    char arr5[2]={'A','I'};
    tch.setdata("Manjulika",arr5,2);
    do {
        system("cls");
        int option;
        cout << "\n\t\t--------------------------------";
        cout << "\n\t\t*** Student Management System ***";
        cout << "\n\t\t--------------------------------";
        cout << "\n\t\t 1. Add New Student" << endl;
        cout << "\t\t 2. Display All Students" << endl;
        cout << "\t\t 3. Search Student" << endl;
        cout << "\t\t 4. Update Student" << endl;
        cout << "\t\t 5. Delete Student" << endl;
        cout << "\t\t 6. 9 pointers list" << endl;
        cout << "\t\t 7. Register your free slots (only for teachers)" << endl;
        cout << "\t\t 8. Check common slots with your teacher." << endl;
        cout << "\t\t 9. Exit" << endl;
        cout << "\t\t Enter Your Choice : ";
        cin >> option;

        switch (option) {
            case 1: {
                int rno, age;
                string name;
                float cgpa;
                cout << "Enter Rollno :";
                cin >> rno;
                if((students.checkrollnum(rno))==1){
                    break;
                }
                cout << "Enter Name :";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Age :";
                cin >> age;
                cout << "Enter CGPA :";
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
                    cout << "\t\t 4.Update CGPA " << endl;
                    cout << "\t\t Enter Your Choice :";
                    cin >> choice;
                    students.updateStudent(index, choice);
                } else {
                    cout << "\t\tStudent not registered." << endl;
                }
                break;
            }
            case 5: {
                int rollno;
                cout << "Enter Rollno to Delete :";
                cin >> rollno;
                int index = students.searchStudent(rollno);
                if (index != -1) {
                    students.deleteStudent(index);
                } else {
                    cout << "\t\tStudent not registered." << endl;
                }
                break;
            }
            case 6:{
                students.display9plist();
                break;
            }
            case 7:{
                tch.getslots();
                break;
                }
            case 8:
            {
                tch.getstdslots();
                tch.dispcommon();
                break;
            }
        
            case 9:
                exit(1);
            default:
                cout << "\t\tInvalid choice " << endl;
        }
        cout << "\t\tDo You Want to Continue (Yes/No) ? :";
        cin >> choice;
    } while (choice[0] == 'y' || choice[0] == 'Y');

    return 0;
}
