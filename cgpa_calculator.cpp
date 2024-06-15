#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    int creditHours;
    double grade;
};

double CalculateCGPA (const vector<Course>& courses){
    double totalGradePoints = 0.0;
    int totalCreditHours = 0;

    for(const Course& course: courses){
        totalGradePoints += course.grade * course.creditHours;
        totalCreditHours += course.creditHours;
    }

    if(totalCreditHours > 0){
        return totalGradePoints / totalCreditHours;
    } else {
        return 0.0;
    }
}

int main()
{
    vector<Course> courses;

    cout << "CGPA Calcualtor" << endl;
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for(int i= 0; i < numCourses; i++){
        Course course;

        cout << "\nEnter details for Course " << i+1 << ":" << endl;
        cout << "Course Name : ";
        cin.ignore();
        getline(cin,course.name);
        cout << "Credit Hours: ";
        cin >> course.creditHours;
        cout << "Grade (0-4): ";
        cin >> course.grade;

        if(course.grade < 0 || course.grade > 4){
            cout << "Invalid grade. Please enter a grade between 0 and 4." << endl;
            i--;
            continue;
        }
        courses.push_back(course);
    }
    double cgpa = CalculateCGPA(courses);
    cout << fixed << setprecision(2);
    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}