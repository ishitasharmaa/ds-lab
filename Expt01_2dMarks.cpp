#include <iostream>
#include <vector>

using namespace std;

const int NUM_SUBJECTS = 5;
const int NUM_STUDENTS = 3;

void calculateTotalAndAverage(vector<vector<int> > &marks)
{
    int numStudents = marks.size();

    cout << "Student | ";
    for (int j = 0; j < NUM_SUBJECTS; ++j)
    {
        cout << "Subject " << (j + 1) << " | ";
    }
    cout << "Total" << endl;

    for (int i = 0; i < numStudents; ++i)
    {
        int total = 0;
        cout << "       " << (i + 1) << "   | ";
        for (int j = 0; j < NUM_SUBJECTS; ++j)
        {
            total += marks[i][j];
            cout << "       " << marks[i][j] << "    | ";
        }
        cout << "   " << total << endl;
    }

    cout << "Subject Avg | ";
    for (int j = 0; j < NUM_SUBJECTS; ++j)
    {
        int subjectTotal = 0;
        for (int i = 0; i < numStudents; ++i)
        {
            subjectTotal += marks[i][j];
        }
        double subjectAverage = static_cast<double>(subjectTotal) / numStudents;
        cout << "   " << subjectAverage << "   | ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int> > marks(NUM_STUDENTS, vector<int>(NUM_SUBJECTS));

    for (int i = 0; i < NUM_STUDENTS; ++i)
    {
        cout << "Enter marks for Student " << (i + 1) << " (5 subjects): ";
        for (int j = 0; j < NUM_SUBJECTS; ++j)
        {
            cin >> marks[i][j];
        }
    }

    cout << "Calculating totals and averages..." << endl;
    calculateTotalAndAverage(marks);

    return 0;
}