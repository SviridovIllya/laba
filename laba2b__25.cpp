#include <iostream>
#include <cstring>
#include <cstdlib>//srand
#include <time.h>//for time()

using namespace std;

class Node
{
public:
    int key;
    Node **forward;
    Node(int, int);
};

Node::Node(int key, int level)
{
    this->key = key;
    forward = new Node*[level+1];
    memset(forward, 0, sizeof(Node*)*(level+1));
}
class SkipList
{
    int MAXLVL;
    float P;
    int level;
    Node *header;
public:
    SkipList(int MAXLVL, float P)
    {
        this->MAXLVL = MAXLVL;
        this->P = P;
        level = 0;
        header = new Node(-1, MAXLVL);
    }
    int rand_lvl()
    {
        float r = (float)rand()/RAND_MAX;
        int lvl = 0;
        while(r < P && lvl < MAXLVL)
        {
            lvl++;
            r = (float)rand()/RAND_MAX;
        }
        return lvl;
    }
    Node* new_node(int key, int level)
    {
        Node *n = new Node(key, level);
        return n;
    }
    void add(int key)
    {
        Node *current = header;
        Node *update[MAXLVL+1];
        memset(update, 0, sizeof(Node*)*(MAXLVL+1));
        for(int i = level; i >= 0; i--)
        {
            while(current->forward[i] != NULL &&
                  current->forward[i]->key < key)
                current = current->forward[i];
            update[i] = current;
        }
        current = current->forward[0];
        if (current == NULL || current->key != key)
        {
            int rlevel = rand_lvl();
            if(rlevel > level)
            {
                for(int i=level+1;i<rlevel+1;i++)
                    update[i] = header;
                level = rlevel;
            }
            Node* n = new_node(key, rlevel);
            for(int i=0;i<=rlevel;i++)
            {
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;
            }
        }
    }
    void searchElement(int key)
    {
        Node *current = header;
        for(int i = level; i >= 0; i--)
        {
            while(current->forward[i] &&
                  current->forward[i]->key < key)
                current = current->forward[i];

        }
        current = current->forward[0];
        if(current and current->key == key)
            cout<<"Found key: "<<key<<"\n";
    }
    void print()
    {
        cout<<"Skip List"<<"\n";
        for(int i=0;i<=level;i++)
        {
            Node *node = header->forward[i];
            cout<<"Level "<<i<<": ";
            while(node != NULL)
            {
                cout<<node->key<<" ";
                node = node->forward[i];
            }
            cout<<"\n";
        }
    }
};
void Demo()
{
    SkipList list_demo(3, 0.5);
    list_demo.add(3);
    list_demo.add(6);
    list_demo.add(7);
    list_demo.add(9);
    list_demo.add(12);
    list_demo.add(19);
    list_demo.add(17);
    list_demo.add(26);
    list_demo.add(21);
    list_demo.add(25);
    list_demo.print();
    list_demo.searchElement(19);
    list_demo.print();
}

SkipList list(3, 0.5);

void interactive()
{

    int chose=0;
    int number=0;
    cout << "choose an action with Skip List" << endl;
    cout << "1.Add" << endl;
    cout << "2.Search key " << endl;
    cout << "3.Exit" << endl;
    cin >> chose;
    switch (chose) {
        case 1:
            cout << "enter number" << endl;
            cin >> number;
            list.add(number);
            list.print();
            interactive();
            break;
        case 2:
            cout << "enter number" << endl;
            cin >> number;
            list.add(number);
            list.print();
            cout << "enter number to search" << endl;
            int number_to_search;
            cin >> number_to_search;
            list.searchElement(number_to_search);
            interactive();
            break;
        case 3:
            break;
    }
}
void main_menu(){
    int chose_menu=0;
    cout << "0.Exit" << endl;
    cout << "1.Demo" << endl;
    cout << "2.Interactive" << endl;
    cin >> chose_menu;
    switch (chose_menu) {
        case 0:
            break;
        case 1:
            Demo();
            break;
        case 2:
            interactive();
            break;
    }
}
int main()
{
    main_menu();
    return 0;
}