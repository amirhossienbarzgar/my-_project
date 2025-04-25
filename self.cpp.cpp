#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#define CL_RED "\033[1;31m"
#define CL_BLUE "\033[1;34m"
#define CL_GREEN "\033[1;32m"
#define CL_MAGENTA "\033[1;35m"
#define cl_rang "\033[1;40m"
#define CL_DEFAULT "\033[0m"

using namespace std;


class Reservation;
class Student;
class Meal;
class Dinninghall;

class Student {
private:
    int user_id;
    string student_id;
    vector<Reservation> reservation;
    string name;
    string email;
    float balance;
    bool is_active;

public:
    Student();
    void print();
    bool cancel_reservation();
    int getuser_id();
    string getstudent_id();
    string getname();
    string getemail();
    float getbalance();
    bool getis_active();
    void setuserid(int);
    void setstudent_id(string);
    void setname(string);
    void setemail(string);
    void setbalance(float);
    void setis_active(bool);
};


enum meal_type { VEG, NON_VEG, VEGAN };


class Meal {
private:
    int meal_id;
    string name;
    float price;
    meal_type type;
    vector<string> side_items;

public:
    Meal();
    void print();
    void update_price(float);
    void add_side_item(string);
    int getmeal_id();
    string getname();
    float getprice();
    meal_type getmeal_type();
    vector<string> getside_item();
    void setmeal_id(int);
    void setname(string);
    void setprice(float);
    void setmeal_type(meal_type);
    void setside_item(string);
};


enum status { PENDING, CONFIRMED, CANCELLED };


class Dinninghall {
private:
    int hall_id;
    string name;
    string address;
    int capacity;

public:
    Dinninghall();
    void print();
    int gethall_id();
    string getname();
    string getaddress();
    int getcapacity();
    void sethall_id(int);
    void setname(string);
    void setaddress(string);
    void setcapacity(int);
};

class Reservation {
private:
    int reservation_id;
    Student student;
    Dinninghall dhall;
    Meal meal;
    status res_status;

public:
    Reservation();
    void print();
    bool cancel();
    int getreservation_id();
    Student getstudent();
    Dinninghall getdhall();
    Meal getmeal();
    status getstatus();
    void setreservation_id(int);
    void setstudent(Student);
    void setdhall(Dinninghall);
    void setmeal(Meal);
    void setstatus(status);
};


Student::Student() {
    user_id = 0;
    student_id = "";
    name = "";
    email = "";
    balance = 0;
    is_active = false;
}

void Student::print() {
    cout << "User ID: " << user_id << endl;
    cout << "Student ID: " << student_id << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Balance: " << balance << endl;
    cout << "Active Status: " << (is_active ? "Active" : "Inactive") << endl;
}

int Student::getuser_id() {
    return user_id;
}

string Student::getstudent_id() {
    return student_id;
}

string Student::getname() {
    return name;
}

string Student::getemail() {
    return email;
}

float Student::getbalance() {
    return balance;
}

bool Student::getis_active() {
    return is_active;
}

void Student::setuserid(int x) {
    user_id = x;
}

void Student::setstudent_id(string st) {
    student_id = st;
}

void Student::setname(string st) {
    name = st;
}

void Student::setemail(string st) {
    email = st;
}

void Student::setbalance(float fl) {
    balance = fl;
}

void Student::setis_active(bool check) {
    is_active = check;
}


Meal::Meal() {
    meal_id = 0;
    name = "";
    price = 0;
    type = VEG;
}

void Meal::print() {
    cout << "Meal ID: " << meal_id << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Meal Type: ";
    switch (type) {
        case VEG: cout << CL_GREEN "Veg" CL_DEFAULT; break;
        case NON_VEG: cout << CL_RED "Non-Veg" CL_DEFAULT; break;

    }
    cout << endl;

    cout << "Side Items: ";
    for (const auto& item : side_items) {
        cout << item << " ";
    }
    cout << endl;
}
int Meal :: getmeal_id(){
    return meal_id;
}
string Meal :: getname(){
    return name;
}
float Meal :: getprice(){
    return price;
}

void Meal::add_side_item(string st) {
    side_items.push_back(st);
}

vector<string> Meal::getside_item() {
    return side_items;
}

meal_type Meal::getmeal_type() {
    return type;
}

void Meal::setmeal_id(int x) {
    meal_id = x;
}

void Meal::setname(string st) {
    name = st;
}

void Meal::setprice(float fl) {
    price = fl;
}

void Meal::setmeal_type(meal_type t) {
    type = t;
}

void Meal::setside_item(string st) {
    side_items.push_back(st);
}


Reservation::Reservation() {
    reservation_id = 0;
    res_status = PENDING;
}

void Reservation::print() {
    cout << "Reservation ID: " << reservation_id << endl;
    cout << "Reservation Status: ";
    switch (res_status) {
        case PENDING: cout << "Pending"; break;
        case CONFIRMED: cout << CL_GREEN "Confirmed" CL_DEFAULT; break;
        case CANCELLED: cout << CL_RED "Cancelled" CL_DEFAULT; break;
    }
    cout << endl;

    student.print();
    dhall.print();
    meal.print();
}

bool Reservation::cancel() {
    res_status = CANCELLED;
    cout << "Reservation cancelled." << endl;
    return true;
}

int Reservation::getreservation_id() {
    return reservation_id;
}

Student Reservation::getstudent() {
    return student;
}

Dinninghall Reservation::getdhall() {
    return dhall;
}

Meal Reservation::getmeal() {
    return meal;
}

status Reservation::getstatus() {
    return res_status;
}

void Reservation::setreservation_id(int id) {
    reservation_id = id;
}

void Reservation::setstudent(Student st) {
    student = st;
}

void Reservation::setdhall(Dinninghall di) {
    dhall = di;
}

void Reservation::setmeal(Meal me) {
    meal = me;
}

void Reservation::setstatus(status s) {
    res_status = s;
}
Dinninghall :: Dinninghall(){
    hall_id = 0;
    name = " ";
    address = " ";
    capacity = 0;
}
void Dinninghall :: print(){
    cout << "hall id  is " << hall_id << endl;
    cout << "name is " << name << endl;
    cout << "address is " << address << endl;
    cout << "capacity is " << capacity << endl;
}
int Dinninghall ::  gethall_id(){
    return hall_id;
}
string Dinninghall ::  getname(){
    return name;
}
string Dinninghall ::  getaddress(){
    return address;
}
int Dinninghall ::  getcapacity(){
    return capacity;
}
void Dinninghall ::  sethall_id(int x){
    hall_id = x;
}
void Dinninghall ::  setname(string st){
    name = st;
}
void Dinninghall ::  setaddress(string st){
    address = st;
}
void Dinninghall ::  setcapacity(int x){
    capacity = x;
}


void printMenuOption(string option) {
    cout << option << endl;
}

void printMenu(string* menu, int size) {
    cout << endl;
    for (int i = 0; i < size; i++) {
        Sleep(100);
        cout << CL_BLUE << i + 1 << ". " << menu[i] << CL_DEFAULT<< endl;
    }
}


int main() {
    string menu[] = {
        "1. Reserve Meal",
        "2. Cancel Reservation",
        "3. Exit"
    };


    string meals[] = {
        "1. Chelow Kabab 15$",
        "2. Fesenjan 10$",
        "3. Ghormeh Sabzi 12$",
        "4. Gheymeh 12$",
        "5. Dolmeh 10$"
    };

    Student student;
    Meal chelowKabab, fesenjan, ghormehSabzi, gheymeh, dolmeh;
    Dinninghall dinninghall, golestan;  // اضافه کردن سالن جدید
    Reservation r;


    dinninghall.setaddress("Birjand");
    dinninghall.setcapacity(200);
    dinninghall.sethall_id(6546);
    dinninghall.setname("Shokat");


    golestan.setaddress("amir abad");
    golestan.setcapacity(150);
    golestan.sethall_id(6547);
    golestan.setname("Golestan");

    chelowKabab.setmeal_id(4566);
    chelowKabab.setprice(15);
    chelowKabab.setname("Chelow Kabab");
    chelowKabab.setmeal_type(NON_VEG);

    fesenjan.setmeal_id(4567);
    fesenjan.setprice(10);
    fesenjan.setname("Fesenjan");
    fesenjan.setmeal_type(NON_VEG);

    ghormehSabzi.setmeal_id(4568);
    ghormehSabzi.setprice(12);
    ghormehSabzi.setname("Ghormeh Sabzi");
    ghormehSabzi.setmeal_type(NON_VEG);

    gheymeh.setmeal_id(4569);
    gheymeh.setprice(12);
    gheymeh.setname("Gheymeh");
    gheymeh.setmeal_type(NON_VEG);

    dolmeh.setmeal_id(4570);
    dolmeh.setprice(10);
    dolmeh.setname("Dolmeh");
    dolmeh.setmeal_type(VEG);
    student.setbalance(30);

    int option;
    bool buy = false;

    while (true) {
        printMenu(menu, sizeof(menu) / sizeof(string));
        cin >> option;

        switch (option) {
            case 1: {
                int meal;
                cout << "Enter the meal:\n";
                for (int i = 0; i < sizeof(meals) / sizeof(string); i++) {
                    Sleep(100);
                    cout << CL_GREEN <<meals[i] << CL_DEFAULT << endl;
                }
                cin >> meal;


                Meal selectedMeal;
                if (meal == 1) {
                    selectedMeal = chelowKabab;
                } else if (meal == 2) {
                    selectedMeal = fesenjan;
                } else if (meal == 3) {
                    selectedMeal = ghormehSabzi;
                } else if (meal == 4) {
                    selectedMeal = gheymeh;
                } else if (meal == 5) {
                    selectedMeal = dolmeh;
                } else {
                    cout << "Invalid meal option. Please try again.\n";
                    break;
                }


                if (student.getbalance() < selectedMeal.getprice()) {
                    Sleep(100);
                    cout << CL_RED "Insufficient balance.\n";
                    cout << "the balance is :" << student.getbalance();
                    break;
                }
                if (student.getis_active()){
                    Sleep(100);
                    cout << CL_RED "you have meal for today" CL_DEFAULT;
                    break;
                }


                int hallChoice;

                cout << CL_BLUE "Select a dining hall:\n";
                Sleep (100);
                cout << "1. " << dinninghall.getname() << " (Capacity: " << dinninghall.getcapacity() << ")\n";
                Sleep(100);
                cout << "2. " << golestan.getname() << " (Capacity: " << golestan.getcapacity() << CL_DEFAULT<< ")\n";

                cin >> hallChoice;

                Dinninghall selectedHall;
                if (hallChoice == 1) {
                    selectedHall = dinninghall;
                } else if (hallChoice == 2) {
                    selectedHall = golestan;
                } else {
                    cout << "Invalid dining hall option. Please try again.\n";
                    break;
                }


                cout << CL_GREEN "Reservation successful!\n" CL_DEFAULT;
                student.setbalance(student.getbalance() - selectedMeal.getprice());
                r.setdhall(selectedHall);
                r.setmeal(selectedMeal);
                r.setstudent(student);
                r.setstatus(CONFIRMED);
                student.setis_active(true);
                Sleep(100);
                r.print();
                break;
            }

            case 2: {
                cout << CL_RED "Cancelling reservation...\n" CL_DEFAULT;
                student.setbalance(student.getbalance() + chelowKabab.getprice());
                cout << CL_GREEN "new balance is :"<<student.getbalance() << CL_DEFAULT << endl;
                r.cancel();
                break;
            }

            case 3:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }


    }

}

