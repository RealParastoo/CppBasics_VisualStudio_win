/* Cpp basic examples */

#include <iostream>
#include <queue>

using namespace std;

/*queue data structure*/
class queue_student
{
public:
    int score;

    queue_student(int grade)
    {
        this->score = grade;
        cout << "queue_student constructor called:" << grade << endl;
    }

    queue_student(const queue_student &student)
    {
        this->score = student.score;
        cout << "copy queue_student constructor called:" << this->score << endl;
        cout << endl;
    }

    ~queue_student()
    {
        cout << "queue_student destructor called:" << this->score << endl;
        cout << endl;
    }

};
void queue_data_structure(void)
{
    queue<int> numbers;

    numbers.push(7);
    cout << "size:" << numbers.size() << endl;
    cout << "front:" << numbers.front() << endl;
    cout << "back:" << numbers.back() << endl;
    cout << endl;

    numbers.push(9);
    numbers.push(6);
    cout << "size:" << numbers.size() << endl;
    cout << "front:" << numbers.front() << endl;
    cout << "back:" << numbers.back() << endl;
    cout << endl;

    int popVal = numbers.front();

    numbers.pop();
    cout << "size:" << numbers.size() << endl;
    cout << "front:" << numbers.front() << endl;
    cout << "back:" << numbers.back() << endl;
    cout << "popedVal:" << popVal << endl;
    cout << endl;

    queue<int> other_numbers;

    other_numbers.push(3);
    cout << "size numbers:" << numbers.size() << endl;
    cout << "size other numbers:" << other_numbers.size() << endl;
    cout << endl;

    other_numbers.swap(numbers);
    cout << "size numbers:" << numbers.size() << endl;
    cout << "size other numbers:" << other_numbers.size() << endl;
    cout << endl;

    queue<queue_student> classroom;
    queue_student joe(90);
    classroom.push(joe);
    classroom.emplace(80);

    queue_student student_copy = classroom.back();
    classroom.pop();
    cout << "after pop" << endl;

}
/*queue data structure*/

/*stack data structure*/

/*stack data structure*/
int main()
{
    queue_data_structure();
    return 0;
}


