/* Cpp basic examples */

#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm> 

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

/*lambda expressions*/
template <typename C> void print(const string& s, const C& c) {
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

void fillVector(vector<int>& v)
{
    static int nextValue = 1;

    generate(v.begin(), v.end(), [] { return nextValue++; });
}

void lambda_exp(void)
{
    const int elementCount = 9;
    vector<int> v(elementCount, 1);

    int x = 1;
    int y = 1;

    generate_n(v.begin() + 2,
        elementCount - 2,
        [=]() mutable throw() -> int {            
            int n = x + y;
         
            x = y;
            y = n;
            return n;
        });
    print("vector v after call to generate_n() with lambda: ", v);

    cout << "x: " << x << " y: " << y << endl;

    fillVector(v);
    print("vector v after 1st call to fillVector(): ", v);
    
    fillVector(v);
    print("vector v after 2nd call to fillVector(): ", v);
}
/*lambda expressions*/

/*array of objects*/
class Square2
{
public:
    int side_len;
    string color;
    void print()
    {
        cout << "length is: " << side_len;
        cout << ", coler is: " << color <<endl;
    }
    
    Square2()
    {
        side_len = 12;
        color = "pink";
    }
    
    Square2(int len, string col)
    {
        side_len = len;
        color = col;
    }
};
void arrayOf_objects()
{
    Square2 squ[3] = {Square2(2,"red"),Square2(2,"blue") };
    for (int i = 0; i < 3; i++)
        squ[i].print();
}
/*array of objects*/

/*constructor delegation*/
class Rectangle
{
public:
    int length;
    int width;
    int area;
    string color;

    void print()
    {
        cout << "len:" << length << endl;
        cout << "width:" << width << endl;
        cout << "area:" << area << endl;
        cout << "color:" << color << endl;
    }

    Rectangle(int l, int w)
    {
        length = l;
        width = w;
        area = l * w;
        cout << "constructor 1 run" << endl;
    }
    Rectangle(int l, int w, string c):Rectangle(l, w)
    {
        color = c;
        cout << "constructor 2 run" << endl;
    }
};

void constructor_delegation()
{
    Rectangle rect1(2, 3, "red");
    rect1.print();
}
/*constructor delegation*/

/*this keyword*/
class Student;
void creat_report(Student *student);

class Student
{
public:
    int age;
    string name;

    Student(int age, string name)
    {
        this->age = age;
        this->name = name;
        cout << "  this memory address: " << this << endl;
    }
    void increas_age()
    {
        this->age = this->age + 1;
    }
    void incres_and_print()
    {
        this->increas_age();
        cout << "the age is: " << this->age << endl;
    }
    void graduate()
    {
        cout << "Congrat!" << endl;
        creat_report(this);
    }
    Student& set_name(string name)
    {
        this->name = name;
        return *this;
    }
    Student& set_age(int age)
    {
        this->age = age;
        return *this;
    }
};

void creat_report(Student* student)
{
    cout << student->age << " " << student->name << endl;
}

void this_keyword()
{
    Student stu1(21, "Jey");
    cout << "mem address is: " << &stu1 << endl;
    stu1.incres_and_print();
    stu1.graduate();
    stu1.set_name("gray").set_age(34);
    stu1.graduate();
}
/*this keyword*/

/*operator overloading*/
class num1 {
public:
    int n;

    num1(int set_n)
    {
        n = set_n;
    }
    num1 operator+(const num1& numX)
    {
        cout << "this->n: " << this->n << endl;
        cout << "numX: " << numX.n << endl;
        return num1(this->n + numX.n);
    }

    bool operator==(const num1& numX)
    {
        if (this->n == numX.n) return true;
        else return false;
    }
};

void operator_overloading()
{
    num1 x1(3);
    num1 x2(9);

    num1 x3 = x1 + x2;
    cout << "x3.n: " << x3.n << endl;

    if (x1.n == x2.n)
        cout << "x1 is equal to x2" << endl;
    else 
        cout << "x1 is NOT equal to x2" << endl;
}
/*operator overloading*/

/*function overloading*/
int add(int x, int y)
{
    return x + y;
}
int add(int x, int y, int z)
{
    return x + y + z;
}
double add(double x, double y)
{
    return x + y;
}

class Add
{
public:
    int add(int x, int y)
    {
        return x + y;
    }

    double add(double x, double y)
    {
        return x + y;
    }
};
void fn_overloading()
{
    cout << add(3, 6) << endl;
    cout << add(3, 6, 5) << endl;
    cout << add(3.1, 6.7) << endl;

    Add addfn;
    cout << addfn.add(7, 9) << endl;
    cout << addfn.add(7.3, 9.8) << endl;
}

/*function overloading*/

/*namespace basics*/
namespace raw
{
    void print(double number)
    {
        cout << "print raw: " << number << endl;
    }
}
namespace rounded
{
    void print(double number)
    {
        cout << "print raw: " << round(number) << endl;
    }
}

void namespace_basic()
{
    /*raw::print(4.67);
    rounded::print(4.67);*/

    using namespace rounded;
    print(698.14);

}
/*namespace basics*/

/*protected access specifier*/
class BaseClass {
public:
    int pub_member;
private:
    int priv_member;
protected:
    int prot_member;
};
class DerivClass : public BaseClass {
public:
    void mem_access()
    {
        pub_member = 76;
        cout << "public mem: " << pub_member << endl;
        prot_member = 64;
        cout << "protected mem: " << prot_member << endl;
    }

};

void protected_AS()
{
    DerivClass class1;
    class1.mem_access();
}
/*protected access specifier*/

/*destructor basic*/
class BaseClass0
{
public:
    BaseClass0()
    {
        cout << "Base Constructor run" << endl;
    }

    ~BaseClass0()
    {
        cout << "Base Destructor run" << endl;
    }
};

class DerivedClass0
{
public:
    DerivedClass0()
    {
        cout << "Derived Constructor run" << endl;
    }

    ~DerivedClass0()
    {
        cout << "Derived Destructor run" << endl;
    }
};

void destructor_basic()
{
    BaseClass0 example0;
    DerivedClass0 example1;
}
/*destructor basic*/

/*smart pointer*/
class SmartPtr
{
    int* sptr;
public:
    SmartPtr(int* x = NULL)
    {
        sptr = x;
    }
    ~SmartPtr()
    {
        delete(sptr);
    }
    int& operator*()
    {
        return *sptr;
    }
};

void smart_pointer(void)
{
    SmartPtr foo(new (int));
    *foo = 68;
    cout << "pointer value is: " << *foo << endl;
}
/*smart pointer*/

/*static mem variable*/
class Animal {
public:
    string species;
    static int total;

    Animal(string x)
    {
        species = x;
        total++;
    }

    ~Animal()
    {
        total--;
    }

};
int Animal::total = 0;


void static_mem_variable()
{
    Animal* lion = new Animal("lion");
    Animal* tiger = new Animal("tiger");
    Animal* bear = new Animal("bear");

    cout << lion->species << endl;
    cout << tiger->species << endl;
    cout << "total: " << Animal::total << endl;
    cout << "lion total: " << lion->total << endl;

    delete lion;
    delete tiger;
    delete bear;
    cout << "total: " << Animal::total << endl;
}
/*static mem variable*/

/*static mem func*/
class Squire1
{
private:
    int sidelen;
    static int total_sq;

public:
    int area()
    {
        return sidelen * sidelen;
    }

    Squire1(int x)
    {
        sidelen = x;
        cout << "side len is: " << this->sidelen << endl;
        total_sq++;
    }

    static int gettotal()
    {
        return total_sq;
    }

};

int Squire1::total_sq = 0;

void static_mem_func()
{
    Squire1 sq1(4);
    Squire1 sq2(7);
    cout << "Sq1: " << sq1.area() << endl;
    cout << "Sq2: " << sq2.area() << endl;
    cout << "total: " << Squire1::gettotal() << endl;
}
/*static mem func*/

int main()
{
    //queue_data_structure();
    //stack_data_structure();
    //multipleRetFunc();
    //lambda_exp();
    //arrayOf_objects();
    //constructor_delegation();
    //this_keyword();
    //operator_overloading();
    //fn_overloading();
    //namespace_basic();
    //protected_AS();
    //destructor_basic();
    //smart_pointer();
    //static_mem_variable();
    static_mem_func();
    return 0;
}
