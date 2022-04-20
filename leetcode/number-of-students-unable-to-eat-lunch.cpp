#include <deque>
#include <iostream>

#include "../util.h"

using namespace std;

int queueLoop(deque<int> students, deque<int> sandwiches);

int main() {
    deque<int> students = { 1, 1, 1, 0, 0, 1 };
    deque<int> sandwiches = { 1, 0, 0, 0, 1, 1 };

    int studentsWithoutFood = queueLoop(students, sandwiches);
    cout << "Output: " << studentsWithoutFood;

    return 0;
}


/**
 * @brief Loops through the cafeteria process and finds how many students
 * cannot eat.
 * 
 * @param students list of students' sandwich preferences
 * @param sandwiches list of sandwiches with their types
 * @return int the number of students that are unable to eat
 */
int queueLoop(deque<int> students, deque<int> sandwiches) {
    int nSandwiches = sandwiches.size();

    for (int i = 0; i < nSandwiches; i++) {
        bool sandwichTaken = false;

        for (int j = 0; j < students.size(); j++) {
            if (sandwiches[0] == students[0]) {
                sandwiches.pop_front();
                students.pop_front();
                sandwichTaken = true;
                break; // Don't loop over the other students
            } else {
                int frontStudent = students[0];
                students.pop_front();
                students.push_back(frontStudent);
            }
        }

        // If the sandwich was not taken after every student was looped over,
        // the remaining students cannot eat. Break the loop.
        if (sandwichTaken == false) {
            break;
        }
    }

    return students.size();
}