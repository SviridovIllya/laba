#include <iostream>
#include <time.h>
#include <vector>
//вариант 2
// подвариант  1

using namespace std;

class Point
{

    double x, y;
public:
    void random()
    {
        x = rand() % 100;
        y = rand() % 100;
    }
    void input()
    {
        cout << "enter for x" << endl;
        cin >> x;
        cout << "enter for y" << endl;
        cin >> y;
    }

    void print()
    {
        cout << " x=" << x << " y=" << y << endl;
    }

};

class Stack {
    int bSize;
    Point* buffer;
    int top;
public:
    Stack(int N = 3);
    ~Stack();
    int push(Point rect);
    void print();
    void clear();
    int pop(Point& rect);
    int peek(Point& rect);
    bool is_Empty();
};


Stack::Stack(int N)
{
    top = 0;
    buffer = new Point[N];
    bSize = N;
}

Stack::~Stack()
{
    delete buffer;
}

int Stack::push(Point rect)
{
    if (top >= bSize)
        return -1;
    buffer[top] = rect;
    top++;
    return 0;
}

int Stack::peek(Point& rect)
{
    if (is_Empty())
    {
        return -1;
    }
    else
    {
        rect = buffer[top - 1];
        return 0;
    }
}
int  Stack::pop(Point& rect)
{
    if (is_Empty())
    {
        return -1;
    }
    else
    {
        rect = buffer[--top];
        return 0;
    }
}

void Stack::print()
{
    for (int i = top - 1; i >= 0; i--)
    {
        buffer[i].print();
        cout << endl;
    }

}

bool Stack::is_Empty()
{
    return top == 0;
}
void Stack::clear()
{
    top = 0;
}
void menuStatic()
{
    Stack stack1;
    do
    {
        cout << "1.add" << endl;
        cout << "2.remove " << endl;
        cout << "3.print " << endl;
        cout << "4.clear " << endl;
        cout << "5.top" << endl;
        cout << "6.is empty" << endl;
        cout << "7.exit" << endl;
        int choice;
        cout << "choose action" << endl;
        cin >> choice;
        Point rect;
        switch (choice)
        {
            case 1: cout << "adding " << endl;
                rect.input();
                if (stack1.push(rect) != 0)
                    cout << "stack is full!" << endl;
                break;
            case 2: cout << "removing " << endl;
                if (stack1.pop(rect) != 0)
                    cout << "stack is empty" << endl;
                else
                    rect.print();
                break;
            case 3: cout << "show " << endl;
                stack1.print();
                break;
            case 4: cout << "clear " << endl;
                stack1.clear();
                break;
            case 5: cout << stack1.peek(rect) << endl;
                rect.print();
                break;
            case 6:cout << stack1.is_Empty() << endl;
                break;
            case 7: return;
        }
    } while (true);
}
void demo_static()
{
    Stack stack2;
    Point rect;
    cout << "enter a point" << endl;
    rect.input();
    rect.print();
    stack2.push(rect);
    stack2.print();
    cout << "input some point" << endl;
    rect.input();
    stack2.push(rect);
    rect.input();
    stack2.push(rect);
    stack2.print();
    stack2.pop(rect);
    stack2.print();
    return;
}
void benchmark_of_static()
{
    int time1, time2;

    Stack stack2(11000000);
    Point rect;
    time1 = clock();
    for (int i = 0; i < 1000; i++)
    {
        for (int k = 0; k < 10000; k++)
        {
            rect.random();
            if (stack2.push(rect) != 0)
            {
                cout << "memory out";
                return;
            }
        }
    }
    time2 = clock();
    cout << "time=" << (double)(time2 - time1)/CLK_TCK << endl;

}
void menu_of_static_array()
{
    int modeSelect;
    cout << "choose mode" << endl;
    cout << "1.manual" << endl;
    cout << "2.demo" << endl;
    cout << "3.benchmark" << endl;
    cout << "4.exit" << endl;
    cin >> modeSelect;
    switch (modeSelect)
    {
        case 1: menuStatic();
            break;
        case 2:
            demo_static();
            break;
        case 3:
            benchmark_of_static();
            break;
        case 4: return;
    }
}

class Stack_on_dynamic {
    vector<Point> buffer;
    int top;
public:
    Stack_on_dynamic();
    void push(Point rect);
    void print();
    void clear();
    int pop(Point& rect);
    int peek(Point& rect);
    bool is_Empty();
};


Stack_on_dynamic::Stack_on_dynamic()
{
    top = 0;
}


void Stack_on_dynamic::push(Point rect)
{
    buffer.push_back(rect);
    top++;
}

int Stack_on_dynamic::peek(Point& rect)
{
    if (is_Empty())
    {
        return -1;
    }
    else
    {
        rect = buffer[top - 1];
        return 0;
    }
}
int  Stack_on_dynamic::pop(Point& rect)
{
    if (is_Empty())
    {
        return -1;
    }
    else
    {
        rect = buffer[--top];
        return 0;
    }
}

void Stack_on_dynamic::print()
{
    for (int i = top - 1; i >= 0; i--)
    {
        buffer[i].print();
        cout << endl;
    }

}

bool Stack_on_dynamic::is_Empty()
{
    return top == 0;
}
void Stack_on_dynamic::clear()
{
    top = 0;
}
void menu_dynamic()
{
    Stack_on_dynamic stack1;
    do
    {
        cout << "1.add" << endl;
        cout << "2.remove" << endl;
        cout << "3.print" << endl;
        cout << "4.clear" << endl;
        cout << "5.top" << endl;
        cout << "6.is empty" << endl;
        cout << "7.exit" << endl;
        int chose;
        cout << "choose an action" << endl;
        cin >> chose;
        Point test;
        switch (chose)
        {
            case 1: cout << "adding " << endl;
                test.input();
                stack1.push(test);
                break;
            case 2: cout << "removing" << endl;
                if (stack1.pop(test) != 0)
                    cout << "stack is empty" << endl;
                else
                    test.print();
                break;
            case 3: cout << "show " << endl;
                stack1.print();
                break;
            case 4: cout << "clear " << endl;
                stack1.clear();
                break;
            case 5: cout << stack1.peek(test) << endl;
                test.print();
                break;
            case 6:cout << stack1.is_Empty() << endl;
                break;
            case 7: return;
        }
    } while (true);
}
void demo_dynamic()
{
    Stack_on_dynamic stack2;
    Point test;
    cout << "enter a point" << endl;
    test.input();
    test.print();
    stack2.push(test);
    stack2.print();
    cout << "input some point" << endl;
    test.input();
    stack2.push(test);
    test.input();
    stack2.push(test);
    stack2.print();
    stack2.pop(test);
    stack2.print();
    return;
}
void benchmark_dynamic()
{
    int time1, time2;

    Stack_on_dynamic stack2;
    Point rect;
    time1 = clock();
    for (int i = 0; i < 1000; i++)
    {
        for (int k = 0; k < 10000; k++)
        {
            rect.random();
            stack2.push(rect);
        }
    }
    time2 = clock();
    cout << "time=" << (double)(time2 - time1) / CLK_TCK << endl;
}
void menu_dynamic_array()
{
    int modeSelect;
    cout << "choose mode" << endl;
    cout << "1.manual" << endl;
    cout << "2.demo" << endl;
    cout << "3benchmark" << endl;
    cout << "4.exit" << endl;
    cin >> modeSelect;
    switch (modeSelect)
    {
        case 1:
            menu_dynamic();
            break;
        case 2:
            demo_dynamic();
            break;
        case 3:
            benchmark_dynamic();
            break;
        case 4:
            return;
    }
}
struct ListItem {
    Point value;
    ListItem* next;

};
class Stack_on_list {
    ListItem* top;
public:
    Stack_on_list();
    void push(Point rect);
    void print();
    void clear();
    int pop(Point& rect);
    int peek(Point& rect);
    bool is_Empty();
};


Stack_on_list::Stack_on_list()
{
    top = nullptr;
}


void Stack_on_list::push(Point rect)
{
    ListItem* tmp=new ListItem;
    tmp->value = rect;
    tmp->next = top;
    top = tmp;
}

int Stack_on_list::peek(Point& rect)
{
    if (top== nullptr)
    {
        return -1;
    }
    else
    {
        rect = top->value;
        return 0;
    }
}
int  Stack_on_list::pop(Point& rect)
{
    if (is_Empty())
    {
        return -1;
    }
    else
    {
        rect = top->value;
        top = top->next;
        return 0;
    }
}

void Stack_on_list::print()
{
    ListItem* tmp=top;
    while (tmp!= nullptr)
    {
        tmp->value.print();
        tmp = tmp->next;
    }

}

bool Stack_on_list::is_Empty()
{
    return top == nullptr;
}
void Stack_on_list::clear()
{
    ListItem* tmp;
    while (top != nullptr)
    {
        tmp=top;
        top = top->next;
        delete tmp;
    }
}
void menulist()
{
    Stack_on_list stack1;
    do
    {
        cout << "1.add " << endl;
        cout << "2.remove " << endl;
        cout << "3.print " << endl;
        cout << "4.clear" << endl;
        cout << "5.top" << endl;
        cout << "6.is empty" << endl;
        cout << "7.exit" << endl;
        int choice;
        cout << "choose an action" << endl;
        cin >> choice;
        Point rect;
        switch (choice)
        {
            case 1: cout << "adding " << endl;
                rect.input();
                stack1.push(rect);
                break;
            case 2: cout << "removing " << endl;
                if (stack1.pop(rect) != 0)
                    cout << "stack is empty" << endl;
                else
                    rect.print();
                break;
            case 3: cout << "show" << endl;
                stack1.print();
                break;
            case 4: cout << "clear" << endl;
                stack1.clear();
                break;
            case 5: if(stack1.peek(rect)!=0)cout << "stack is empty" << endl;
                else
                    rect.print();
                break;
            case 6:cout << stack1.is_Empty() << endl;
                break;
            case 7: return;
        }
    } while (true);
}
void demo_list()
{
    Stack_on_list stack2;
    Point rect;
    cout << "enter a point" << endl;
    rect.input();
    rect.print();
    stack2.push(rect);
    stack2.print();
    cout << "input some point" << endl;
    rect.input();
    stack2.push(rect);
    rect.input();
    stack2.push(rect);
    stack2.print();
    stack2.pop(rect);
    stack2.print();
    return;
}
void benchmarklist()
{
    int time1, time2;

    Stack_on_list stack2;
    Point rect;
    time1 = clock();
    for (int i = 0; i < 1000; i++)
    {
        for (int k = 0; k < 10000; k++)
        {
            rect.random();
            stack2.push(rect);
        }
    }
    time2 = clock();
    cout << "time=" << (double)(time2 - time1) / CLK_TCK << endl;
}
void menu_of_list()
{
    int modeSelect;
    cout << "choose mode" << endl;
    cout << "1.manual" << endl;
    cout << "2.demo" << endl;
    cout << "3.benchmark" << endl;
    cout << "4.exit" << endl;
    cin >> modeSelect;
    switch (modeSelect)
    {
        case 1:
            menulist();
            break;
        case 2:
            demo_list();
            break;
        case 3:
            benchmarklist();
            break;
        case 4:
            return;
    }
}
int main(){
    int stack;
    do {
        cout << "choose type of the stack" << endl;
        cout << "1. dynamic " << endl;
        cout << "2. static " << endl;
        cout << "3. list" << endl;
        cout << "4. exit" << endl;
        cin >> stack;

        switch (stack)
        {
            case 1:
                menu_dynamic_array();
                break;
            case 2:
                menu_of_static_array();
                break;
            case 3:
                menu_of_list();
                break;
        }
    } while (stack != 4);
    return 0;
}
