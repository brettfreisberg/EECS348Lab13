/*
bool fail_lecture(const vector<int>& attenance_records) {
    int absent_count = 0;
    for (int i = 1; i < attenance_records.size(); ++i){
        absent_count += attenance_records[i] == 0;
    }
    return absent_count >= 3;
}

1. There is a fault in the program. The problem is that the for loop starts at index 1 instead of 0.
This means that the first attendence will get missed since for loops start at index 0.

2. It is impossible to stop the fault line from executing since you can't have a 10 value attendence
that avoids using the for loops.

3. If you use only 1s (getting every attendence point), you will not enter an error state since skipping
the first index doesn't change anything.

4. If you do {0,1,1,1,1,1,1,1,1,1}, it will skip the first absence and the faulty program will think
you have 0 absences when in reality you have an absence. This will result in the same results and therefore
won't be a failure even though internerally there is an issue.

5. If you do {0,0,0,1,1,1,1,1,1,1}, the faulty program will think the student passed since it will skip the
first absence and think you only have 2 absences (therefore letting you pass). While the correct program
will get 3 absences and fail the student. The fault matters in this scenario.
*/

//Includes and shortening using
#include <iostream>
#include <vector>
using namespace std;

//Incorrect Version:
bool fail_lecture(const vector<int>& attenance_records) {
    int absent_count = 0;
    for (int i = 1; i < attenance_records.size(); ++i){
        absent_count += (attenance_records[i] == 0);
    }
    return absent_count >= 3;
}

//Fixed Version:
bool fail_lecture_correct(const vector<int>& attenance_records) {
    int absent_count = 0;
    // i = 0 instead of 1
    for (int i = 0; i < attenance_records.size(); ++i){
        absent_count += (attenance_records[i] == 0);
    }
    return absent_count >= 3;
}

//Prints
void run_test(const vector<int>& rec, const string& name) {
    cout << "\n" << name << endl;
    cout << "Faulty output:   " << fail_lecture(rec) << endl;
    cout << "Correct output:  " << fail_lecture_correct(rec) << endl;
}

//Main
int main() {
    // TC3: executes fault, no error state
    vector<int> testCase3 = {1,1,1,1,1,1,1,1,1,1};

    // TC4: error state but no failure
    vector<int> testCase4 = {0,1,1,1,1,1,1,1,1,1};

    // TC5: failure
    vector<int> testCase5 = {0,0,0,1,1,1,1,1,1,1};

    run_test(testCase3, "Test Case 3: Fault executed, no error state");
    run_test(testCase4, "Test Case 4: Error state, no failure");
    run_test(testCase5, "Test Case 5: Failure");

    return 0;
}