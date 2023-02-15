#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class People {
protected:
    int year;
public:
    People(int y) : year(y) {}
   virtual void disp_name() {
        cout << "####" << endl;
    };

    virtual char* getName() {
        char* a = new char;
        return a;
    }

};


class Student : public People {
protected: 
    char* name;
public:
    Student(int y, char* nname) : People(y) {
        name = new char[(sizeof(nname) / sizeof(char)) + 1];
        for (int i = 0; i < (sizeof(nname) / sizeof(char)); i++) {
            name[i] = nname[i];
        }
        name[(sizeof(nname) / sizeof(char))] = '\0';


    }

    void disp_name() override{
        cout << "STUDENT : " << name << " " << "year = " << year << endl;
    }


    char* getName() override {
        return name;
    }

    ~Student() {
        std::cout << "~student() " << name << std::endl;
        if (name) delete[] name;
    }

};

int SortFunc(People* elem1, People* elem2) {
    return strcmp(elem1->getName(), elem2->getName()) < 0;
    

}


class Programmer : public People{
protected:
    char* name;
    int expirience;
public:
    Programmer(int y, int exp, char* nname): People(y) , expirience(exp) {
        name = new char[(sizeof(nname) / sizeof(char)) + 1];
        for (int i = 0; i < (sizeof(nname) / sizeof(char)); i++) {
            name[i] = nname[i];
        }
        name[(sizeof(nname) / sizeof(char))] = '\0';

    }

    void disp_name() override {
        cout << "STUDENT : " << name << " " << "year = " << year << " " << "expirience=  " << expirience << endl;;
    }


    char* getName() override {
        return name;
    }


    ~Programmer() {
        std::cout << "~programmer() " << name << std::endl;
        if (name) delete[] name;
    }

};



int main(){

    vector<People*> vect;
    vector<People*> ::iterator It;
    People* ptr_people_tab[3];
    //create students
    ptr_people_tab[0] = new Student(1999, const_cast<char*>("Kowalski"));
    ptr_people_tab[1] = new Programmer(2000, 5, const_cast<char*>("Wisniewski"));
    ptr_people_tab[2] = new Student(1998, const_cast<char*>("Pigulski"));
    //Push to vector
    for (size_t i = 0; i < 3; ++i) {
        vect.push_back(ptr_people_tab[i]);
        vect.push_back(ptr_people_tab[2]);
        vect.push_back(ptr_people_tab[0]);
    }
   
    for (It = vect.begin(); It < vect.end(); It++) {
        (*It) ->disp_name();
    }
    cout << endl;
    sort(vect.begin() , vect.end() , SortFunc);

    for (It = vect.begin(); It < vect.end(); It++) {
        (*It)->disp_name();
    }

    
    auto last = std::unique(vect.begin(), vect.end());
    // v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
    vect.erase(last, vect.end());

    cout << endl;
    for (It = vect.begin(); It < vect.end(); It++) {
        (*It)->disp_name();
    }

    vect.clear();

    



}
