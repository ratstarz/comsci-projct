#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//find average grade
float calculateAverage(float math_grade, float science_grade, float english_grade, float history_grade, float art_grade) {
    return (math_grade + science_grade + english_grade + history_grade + art_grade) / 5.0;
}


//find highest grade out of the 5
float findHighest(float math_grade, float science_grade, float english_grade, float history_grade, float art_grade) {
    float highest = math_grade;
    if (science_grade > highest) highest = science_grade;
    if (english_grade > highest) highest = english_grade;
    if (history_grade > highest) highest = history_grade;
    if (art_grade > highest) highest = art_grade;
    return highest;
}


//find lowest grade out of the 5
float findLowest(float math_grade, float science_grade, float english_grade, float history_grade, float art_grade) {
    float lowest = math_grade;
    if (science_grade < lowest) lowest = science_grade;
    if (english_grade < lowest) lowest = english_grade;
    if (history_grade < lowest) lowest = history_grade;
    if (art_grade < lowest) lowest = art_grade;
    return lowest;
}

//sorts the average grade to it's grade equivalent
float getGrade(float average) {
    if (average >= 96) return 1.0;
    if (average >= 94) return 1.25;
    if (average >= 92) return 1.5;
    if (average >= 90) return 1.75;
    if (average >= 88) return 2.0;
    if (average >= 86) return 2.25;
    if (average >= 84) return 2.5;
    if (average >= 82) return 2.75;
    if (average >= 80) return 3.0;
    return 5.0;
}
//determines if the subject is passing, and if it is, it is added to the counter which is to be displayed
int countPassing(float math_grade, float science_grade, float english_grade, float history_grade, float art_grade) {
    int count = 0;
    if (math_grade >= 80) count++;
    if (science_grade >= 80) count++;
    if (english_grade >= 80) count++;
    if (science_grade >= 80) count++;
    if (art_grade >= 80) count++;
    return count;
}

//if the user didn't enter a valid input (0-100) then it will loop until it has met the requirment and move onto the next grade 
float getValidGrade(string subject) {
    float grade;
    do {
        cout << "Enter " << subject << " grade (0-100): ";
        cin >> grade;
        if (grade < 0 || grade > 100) {
            cout << "Invalid input. Please enter a grade between 0 and 100." << endl;
        }
    } while (grade < 0 || grade > 100);
    return grade;
}
//this is the function to check if the student is in the directors list
bool checkDirectorsList(float gwa) {
    return (gwa <= 1.5);
}

int main() {
    // Student information
    string name;
    int id, age, gradeLevel;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter ID number: ";
    cin >> id;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter grade level: ";
    cin >> gradeLevel;

    // Grades;)
    cout << "\nGRADE ENTRY\n" << endl;
    float math = getValidGrade("Math");
    float science = getValidGrade("Science");
    float english = getValidGrade("English");
    float history = getValidGrade("History");
    float art = getValidGrade("Art");

    float average = calculateAverage(math, science, english, history, art);
    float highest = findHighest(math, science, english, history, art);
    float lowest = findLowest(math, science, english, history, art);
    int passing = countPassing(math, science, english, history, art);
    float gwa = getGrade(average); // Use the getGrade function to get the GWA

    cout << "\nSTUDENT INFORMATION\n" << endl;
    cout<< "Name: "<< name<<endl;
    cout << "ID: " << id << endl;
    cout << "Age: " << age << " years old" << endl;
    cout << "Grade level: " << gradeLevel << "th grade" << endl;
    cout << "Birth year: " << (2024 - age) << endl;

    cout << "\nSUBJECT GRADES:\n" << endl;
    cout << "Math: " << math << "%" << endl;
    cout << "Science: " << science << "%" << endl;
    cout << "English: " << english << "%" << endl;
    cout << "History: " << history << "%" << endl;
    cout << "Art: " << art << "%" << endl;

    cout << "\nGRADE STATISTICS:\n" << endl;
    cout << fixed << setprecision(2); // Set precision to two decimal places
    cout << "Average grade: " << average << "%" << endl;
    cout << "Grade Equivalent: " << gwa << endl;
    cout << "Highest grade: " << highest << "%" << endl;
    cout << "Lowest grade: " << lowest << "%" << endl;
    cout << "Passed: " << passing << " out of 5" << endl;

    cout << "\nGWA: " << gwa << endl;
    
    //this is used to display the correct message depending if user has met requirement to be in the director's list
    if (checkDirectorsList(gwa)) {
        cout << "Director's List Status: YES (Congratulations)" << endl;
    } else {
        cout << "Director's List Status: NO" << endl;
    }

    return 0;
    
    //Documentation 
//1.getValidGrade : Ensures user inputs a grade between 0-100.
//2.getGrade : Converts average grade to grade point equivalent.
//3.checkDirectorsList : Checks if the student qualifies for the Director's List (GWA <= 1.5).
}

