/* Cpp basic examples */

#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>

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
class stack_employee
{
public:
    int day;

    stack_employee(int dyys)
    {
        cout << "constructor called " << dyys << endl;
        this->day = dyys;
    }

    stack_employee(const stack_employee &employee)
    {
        cout << "copy constructor called " << employee.day << endl;
        this->day = employee.day;
    }

    ~stack_employee()
    {
        cout << "destructor called" << endl;
    }

};

void stack_data_structure(void)
{
    stack<int> stack_num;
    cout << "stack size:" << stack_num.size() << endl;
    if (stack_num.empty())
    {
        cout << "stack is empty" << endl;
    }

    stack_num.push(4);
    cout << "stack size after push:" << stack_num.size() << endl;
    if (!stack_num.empty())
    {
        cout << "stack is not empty" << endl;
    }
    //cout << "top is: " << stack_num.top() << endl;

    stack_num.push(9);
    stack_num.push(5);
    cout << "top is: " << stack_num.top() << endl;
    stack_num.pop();
    cout << "top after pop is: " << stack_num.top() << endl;

    stack<int> stackNum;
    stackNum.push(3);
    stackNum.swap(stack_num);
    cout << "other stack size:" << stackNum.size() << endl;

    stack<stack_employee> empl_stack;
    //stack_employee joe(11);
    //empl_stack.push(joe);
    empl_stack.emplace(20);

    //stack_employee top_emp = empl_stack.top();
    empl_stack.pop();

}
/*stack data structure*/

/*return multiple values of a func*/
tuple<int, int, string> tupleReturnFnc(int x, int y)
{
    //return make_tuple(x + y, x - y, "return a string");
    return {x + y, x - y, "return a string"};
}

vector<int> vectorReturn()
{
    vector<int> nummbers;
    nummbers.push_back(7);
    nummbers.push_back(2);
    nummbers.push_back(3);

    return nummbers;
}

void passByRefference(int a, int b, int &sam, int &diff)
{
    sam = a + b;
    diff = a - b;
}

void multipleRetFunc(void)
{
    int a = 10;
    int b = 6;
    /*int sum;
    int diff;
    string str;*/

    //tie(sum, diff, str) = tupleReturnFnc(a, b);
    auto[sum, diff, str] = tupleReturnFnc(a, b);
    cout << "Sum: " << sum << endl;
    cout << "diff: " << diff << endl;
    cout << "string: " << str << endl;
    cout << endl;

    vector<int> retVector = vectorReturn();
    for (int i : retVector)
    {
        cout << i << endl;
    }
    cout << endl;

    int tot, sub;
    passByRefference(a, b, tot, sub);
    cout << "tot: " << tot << endl;
    cout << "sub: " << sub << endl;
}

/*return multiple values of a func*/

int main()
{
    //queue_data_structure();
    //stack_data_structure();
    multipleRetFunc();
    return 0;
}


