//HW3
//Due: 11:59PM, September 6 (Friday)
//SUID : 956903134
//Name : Rajesh Palkar
/*
 I made some minor revision.
 You should use this HW3 version and ignore the previous version.
 
 The file HW3_Sample_Disply is my console display for the main funciton I provided.
 You are required to follow the same output format using my main funciton.
 Note that, during grading, other sample main functions can be used.
 
 Notice that there is one space in "CIS554 1 3".
 However, there are 2 space between "CIS554" and "CSE674".
 Moreover, there is a blank line at the beginning when each print function is invoked.
 */



#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class course
{
public:
    string name;
    int section;
    int credits;
    course() {}
    course(string n, int s, int c) { name = n; section = s; credits = c; }
    bool operator<(course c) { return (name < c.name); }
    bool operator==(course c) { return (name == c.name); }
};
void add_student(map<int, map<int, list<course> * >> &DB, int id);
void remove_student(map<int, map<int, list<course> * >> &DB, int id);
void add_course(map<int, map<int, list<course> * >> &DB, int semester, int id, course c); //20171 Spring semester of 2017; 20172: Fall semester of 2017
//All courses in the list should be sorted according to name (increasing order)
void drop_course(map<int, map<int, list<course> * >> &DB, int semester, int id, course c);
void print_student_semester_courses(map<int, map<int, list<course> * >> &DB, int semester, int id);
void print_student_all_courses(map<int, map<int, list<course> * >> &DB, int id);
void print_DB(map<int, map<int, list<course> * >> &DB);

int main() {
    map<int, map<int, list<course> *>> DB;
    add_student(DB, 11111);
    course C1("CIS554", 1, 3), C2("CSE674", 1, 3), C3("MAT296", 8, 4), C4("WRT205", 5, 3);
    
    add_course(DB, 20171, 11111, C1);
    add_course(DB, 20171, 11111, C4);
    add_course(DB, 20171, 11111, C3);
    add_course(DB, 20171, 11111, C2);
    print_student_semester_courses(DB, 20171, 11111);
    
    drop_course(DB, 20171, 11111, C1);
    print_student_semester_courses(DB, 20171, 11111);
    
    add_course(DB, 20172, 11111, C2);
    add_course(DB, 20172, 11111, C4);
    add_course(DB, 20172, 11111, C3);
    add_course(DB, 20172, 11111, C1);
    print_student_all_courses(DB, 11111);
    
    add_student(DB, 11112);
    add_course(DB, 20171, 11112, C2);
    add_course(DB, 20171, 11112, C4);
    add_course(DB, 20171, 11112, C3);
    add_course(DB, 20171, 11112, C1);
    print_student_semester_courses(DB, 20171, 11112);
    
    add_course(DB, 20172, 11112, C2);
    add_course(DB, 20172, 11112, C4);
    add_course(DB, 20172, 11112, C3);
    add_course(DB, 20172, 11112, C1);
    print_student_semester_courses(DB, 20172, 11112);
    
    print_student_all_courses(DB, 11112);
    
    print_DB(DB);
    remove_student(DB, 11111);
    print_DB(DB);
    getchar();
    getchar();
    return 0;
}

void add_student(map<int, map<int, list<course> * >> &DB, int id)
{
    /*
     * We need to check if student ID is already present.
     * if it is already present then just return as we dont have to do anything.
     * if it is not present then just create new one.
     */
    
    if (DB.find(id) == DB.end())
    {
        DB[id];
    }
    
}

void add_course(map<int, map<int, list<course> * >> &DB, int semester, int id, course c)
{
    
    map<int, map<int, list<course>* >>::iterator student_iterator = DB.find(id);
    if (student_iterator != DB.end())
    {
        map<int, list<course>*>::iterator semester_iterator = student_iterator->second.find(semester);
        
        /*
         * First we need to find student. Then we will find aprropriate semester.
         * within that semester we will check if course is already present or not ?
         */
        if (semester_iterator == student_iterator->second.end())
        {
            /*
             * as the course it not already present create list for course.
             */
            
            DB[id][semester] = new list<course>;
        }
        else
        {
            /*
             * as list for cources is already present then just search in the list.
             * if cource is already present in list we dont have to do anything.
             */
            
            list<course>* courses = semester_iterator->second;
            list<course>::iterator course_iterator = (*courses).begin();
            
            while (course_iterator != (*courses).end())
            {
                if ((*course_iterator) == c)
                {
                    return;
                }
                course_iterator++;
            }
        }
        
        /* as the cource was not present in the list we will add the new course*/
        
        DB[id][semester]->push_back(c);
        DB[id][semester]->sort();
    }
    else {
        // count << "student not found ";
    }
}

void remove_student(map<int, map<int, list<course> * >> &DB, int id)
{
    
    map<int, map<int, list<course>* >>::iterator student_iterator = DB.find(id);
    /* first find approprite studnet */
    if (student_iterator != DB.end())
    {
        /*
         * we found the student
         */
        
        map<int, list<course>*>::iterator semester_iterator = student_iterator->second.begin();
        
        /*
         * we need to search the appropriate semester from the list
         */
        
        while (semester_iterator != student_iterator->second.end())
        {
            /*
             * we have allocatred memory for list using new funtion.
             * So we need to delete memory using free funtion as compiler will not release
             */
            
            // count << "semester" << semester_iterator->first;
            
            list<course>* courses = semester_iterator->second;
            (*courses).clear();
            free(semester_iterator->second);
            semester_iterator++;
        }
        (student_iterator->second).clear();
        DB.erase(id);
    }
    else {
        // count << "studnet not present";
    }
}
void drop_course(map<int, map<int, list<course> * >> &DB, int semester, int id, course c)
{
    
    map<int, map<int, list<course>* >>::iterator student_iterator = DB.find(id);
    
    if (student_iterator != DB.end())	//This means that given student is present in database
    {
        map<int, list<course>*>::iterator semester_iterator = student_iterator->second.find(semester);
        
        if (semester_iterator == student_iterator->second.end())	//This means that student is not enrolled for given semester
        {
            return;
        }
        else //This means that student is enrolled for given semester, so need to check whether course is present under this semester or not
        {
            map<int, list<course>*>::iterator valid = student_iterator->second.begin();
            list<course>* courses = valid->second;
            list<course>::iterator course_iterator = (*courses).begin();
            
            while (course_iterator != (*courses).end())	//Iterating over all the courses under given semester
            {
                if (*course_iterator == c)	//course is present in the list which we want to drop
                {
                    (*courses).remove(c);	//Removing the course from the list
                    return;
                }
                course_iterator++;
            }
        }
    }
}

void print_student_semester_courses(map<int, map<int, list<course> * >> &DB, int semester, int id)
{
    
    
    map<int, map<int, list<course>* >>::iterator student_iterator = DB.find(id);
    if (student_iterator != DB.end())		//This means that student is present in the Database
    {
        cout << "\nstudent id = " << student_iterator->first << "\n";
        
        map<int, list<course>*>::iterator semester_iterator = student_iterator->second.find(semester);
        if (semester_iterator != student_iterator->second.end())	//This means that student has enrolled for given semester
        {
            cout << "semester = " << semester_iterator->first << "\n";
            
            map<int, list<course>*>::iterator valid = student_iterator->second.begin();
            list<course>* courses = valid->second;
            
            list<course>::iterator course_iterator = (*courses).begin();
            
            while (course_iterator != (*courses).end())	//Iterating over all the courses , student is enrolled for given semester
            {
                cout << course_iterator->name << " " << course_iterator->section << " " << course_iterator->credits << "  ";
                course_iterator++;
            }
        }
    }
    cout << "\n";
}
void print_student_all_courses(map<int, map<int, list<course> * >> &DB, int id)
{
    
    
    map<int, map<int, list<course>* >>::iterator student_iterator = DB.find(id);
    if (student_iterator != DB.end())	//This means that student is present in the Database
    {
        cout << "\nstudent id = " << student_iterator->first;
        
        map<int, list<course>*>::iterator semester_iterator = student_iterator->second.begin();
        while (semester_iterator != student_iterator->second.end())	//Iterating over all the semester student is enrolled
        {
            cout << "\nsemester = " << semester_iterator->first << "\n";
            
            list<course>* courses = semester_iterator->second;
            list<course>::iterator course_iterator = (*courses).begin();
            while (course_iterator != (*courses).end())	//Iterating over all the courses , student enrolled for this semester
            {
                cout << course_iterator->name << " " << course_iterator->section << " " << course_iterator->credits << "  ";
                course_iterator++;
            }
            semester_iterator++;
        }
        
    }
    cout << "\n";
}

void print_DB(map<int, map<int, list<course> * >> &DB)
{
    
    
    map<int, map<int, list<course>* >>::iterator student_iterator = DB.begin();
    while (student_iterator != DB.end())	//Iterating over all the student present in the database
    {
        cout << "\nstudent id = " << student_iterator->first;
        
        map<int, list<course>*>::iterator semester_iterator = student_iterator->second.begin();
        while (semester_iterator != student_iterator->second.end())	//Iterating over all the semester for this particular student id
        {
            cout << "\nsemester = " << semester_iterator->first << "\n";
            list<course>* courses = semester_iterator->second;
            list<course>::iterator course_iterator = (*courses).begin();
            while (course_iterator != (*courses).end())		//Iterating over all the courses , student enrolled for this semester
            {
                cout << course_iterator->name << " " << course_iterator->section << " " << course_iterator->credits << "  ";
                course_iterator++;
            }
            semester_iterator++;
        }
        student_iterator++;
    }
    cout << "\n";
}