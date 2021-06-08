
#ifndef LAB6_DIFFERENT_LABS_TM_FUNCTIONS_H
#define LAB6_DIFFERENT_LABS_TM_FUNCTIONS_H

#include <iostream>
#include<ctime>
#include <queue>
#include <ctime>
#include <fstream>
using namespace std;

ostream& operator << (ostream& stream, tm& time) {
    string day="", month="", hour="", min="", sec="";
    if (time.tm_mday<10) day='0';
    if (time.tm_mon<10) month='0';
    if (time.tm_hour<10) hour='0';
    if (time.tm_min<10) min='0';
    if (time.tm_sec<10) sec='0';
    stream<<day<<time.tm_mday<<'.'<<month<<time.tm_mon<<'.'<<time.tm_year<<' '
          <<hour<<time.tm_hour<<':'<<min<<time.tm_min<<':'<<sec<<time.tm_sec;
    return stream;
}

istream& operator >> (istream& stream, tm& time) {
    int day, month, year, hour, min, sec;
    stream>>day>>month>>year>>hour>>min>>sec;
    time.tm_mday = day;
    time.tm_mon = month;
    time.tm_year = year;
    time.tm_hour = hour;
    time.tm_min = min;
    time.tm_sec = sec;
    return stream;
}

tm random_time () {
    tm time;
    time.tm_mday = rand()%31+1;
    time.tm_mon = rand()%12+1;
    time.tm_year = rand()%21+2000;
    time.tm_hour = rand()%24;
    time.tm_min = rand()%60;
    time.tm_sec = rand()%60;
    return time;
}

bool operator< (tm& left, tm& right) {
    if (left.tm_year>right.tm_year) return false;
    else if (left.tm_year<right.tm_year) return true;

    if (left.tm_mon>right.tm_mon) return false;
    else if (left.tm_mon<right.tm_mon) return true;

    if (left.tm_mday>right.tm_mday) return false;
    else if (left.tm_mday<right.tm_mday) return true;

    if (left.tm_hour>right.tm_hour) return false;
    else if (left.tm_hour<right.tm_hour) return true;

    if (left.tm_min>right.tm_min) return false;
    else if (left.tm_min<right.tm_min) return true;

    return (left.tm_sec<right.tm_sec);
}

bool operator<= (tm& left, tm& right) {
    if (left.tm_year>right.tm_year) return false;
    else if (left.tm_year<right.tm_year) return true;

    if (left.tm_mon>right.tm_mon) return false;
    else if (left.tm_mon<right.tm_mon) return true;

    if (left.tm_mday>right.tm_mday) return false;
    else if (left.tm_mday<right.tm_mday) return true;

    if (left.tm_hour>right.tm_hour) return false;
    else if (left.tm_hour<right.tm_hour) return true;

    if (left.tm_min>right.tm_min) return false;
    else if (left.tm_min<right.tm_min) return true;

    return (left.tm_sec<=right.tm_sec);
}

bool operator> (tm& left, tm& right) {
    if (left.tm_year>right.tm_year) return true;
    else if (left.tm_year<right.tm_year) return false;

    if (left.tm_mon>right.tm_mon) return true;
    else if (left.tm_mon<right.tm_mon) return false;

    if (left.tm_mday>right.tm_mday) return true;
    else if (left.tm_mday<right.tm_mday) return false;

    if (left.tm_hour>right.tm_hour) return true;
    else if (left.tm_hour<right.tm_hour) return false;

    if (left.tm_min>right.tm_min) return true;
    else if (left.tm_min<right.tm_min) return false;

    return (left.tm_sec>right.tm_sec);
}

bool operator>= (tm& left, tm& right) {
    if (left.tm_year>right.tm_year) return true;
    else if (left.tm_year<right.tm_year) return false;

    if (left.tm_mon>right.tm_mon) return true;
    else if (left.tm_mon<right.tm_mon) return false;

    if (left.tm_mday>right.tm_mday) return true;
    else if (left.tm_mday<right.tm_mday) return false;

    if (left.tm_hour>right.tm_hour) return true;
    else if (left.tm_hour<right.tm_hour) return false;

    if (left.tm_min>right.tm_min) return true;
    else if (left.tm_min<right.tm_min) return false;

    return (left.tm_sec>=right.tm_sec);
}

bool operator == (tm& left, tm& right) {
    return (left.tm_year == right.tm_year && left.tm_mon==right.tm_mon && left.tm_mday==right.tm_mday
            && left.tm_hour==right.tm_hour && left.tm_min==right.tm_min && left.tm_sec==right.tm_sec);
}

#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <ctime>
#include <fstream>

using namespace std;

struct linked_list {
    tm data;

    linked_list* next;
};

linked_list* create_empty() {
    linked_list* new_list;
    new_list = new linked_list;
    new_list->next = nullptr;
    new_list->data.tm_year = -1;
    return new_list;
}

void add_to_list (linked_list** first, tm add_data) {
    linked_list *new_element, *curr;

    if (*first == nullptr) {*first = create_empty();}
    new_element = new linked_list;
    new_element->data = add_data;
    new_element->next = nullptr;

    if ((*first)->data.tm_year == -1) {
        (*first)->data = add_data;
        return;
    }
    (curr) = *first;
    while ((curr) != nullptr) {
        if ((curr)->next == nullptr) {
            (curr)->next = new_element;
            return;
        }
        (curr) = (curr)->next;
    }
}

void delete_element (linked_list** first, tm value_to_delete) {
    linked_list *curr;
    linked_list* to_delete;
    while ((*first)->data == value_to_delete) {
        to_delete = (*first);
        *first = (*first)->next;
        delete to_delete;
    }
    curr = *first;
    while (curr) {
        if (!curr->next) {break;}
        if ((curr->next)->data == value_to_delete) {
            to_delete = (curr)->next;
            (curr)->next = (curr)->next->next;
            delete to_delete;
        } else { (curr) = (curr)->next;}
    }
}

vector<linked_list*> find_by_date (linked_list* first, tm date) {
    linked_list* curr = first;
    vector<linked_list*> result;
    while (curr) {
        if (curr->data == date) {
            result.push_back(curr);
        }
        curr = curr->next;
    }
    return result;
}

vector<linked_list*> find_by_interval(linked_list* first, tm start_time, tm end_time) {
    linked_list* curr = first;
    vector<linked_list*> matching;

    while (curr) {
        if ((curr->data >= start_time)&&(curr->data <= end_time)) matching.push_back(curr);
        curr = curr->next;
    }

    return matching;
}

linked_list* create_random_list (int element_amount) {
    linked_list *first;
    if (element_amount<1) {return nullptr;}
    first = create_empty();
    first->data = random_time();

    for (int i = 1; i < element_amount; i++) {
        add_to_list(&first, random_time());
    }
    return first;
}

void sort_list (linked_list* first, bool print = true) {
    vector<tm> all_dates;
    linked_list* curr = first;
    while (curr) {
        all_dates.push_back(curr->data);
        curr = curr->next;
    }
    sort (all_dates.begin(), all_dates.end(), [](tm left, tm right){return left < right;});
    curr = first;
    int index = 0;
    while (curr) {
        curr->data = all_dates[index];
        if (print) {
            cout<<curr->data<<"     ";
        }
        index++;
        curr = curr->next;
    }
    if (print) {cout<<endl;}
}

void output_list (linked_list* first) {
    linked_list* curr = first;
    while (curr) {
        cout<<curr->data<<"     ";
        curr = curr->next;
    }
    cout<<endl;
}

void do_some_function(linked_list* first, tm (*f)(tm)) {
    if(!first) {return;}
    sort_list(first, false);
    linked_list* curr = first;
    while (curr) {
        curr->data = f(curr->data);
        curr = curr->next;
    }
}


struct array_list {
    vector<tm> data;
};

array_list* create_arr_empty() {
    array_list* new_list;
    new_list = new array_list;
    return new_list;
}

void add_to_arr_list (array_list** list, tm insert_value) {
    if (*list == nullptr) {*list = create_arr_empty();}
    (*list)->data.push_back(insert_value);
}

void delete_arr_element (array_list* list, tm value_to_delete) {
    for (int i = 0; i < list->data.size(); i++) {
        if (list->data[i] == value_to_delete) {
            list->data.erase(list->data.begin()+i);
            i--;
        }
    }
}

vector<tm*> find_by_date_arr (array_list* list, tm date) {
    vector<tm*> result;
    for (int i = 0; i < list->data.size(); i++) {
        if (list->data[i] == date) {
            result.push_back(&list->data[i]);
        }
    }
    return result;
}

vector<tm*> find_by_interval_arr(array_list* list, tm start_time, tm end_time) {
    vector<tm*> result;
    for (int i = 0; i < list->data.size(); i++) {
        if (list->data[i] > start_time && list->data[i] < end_time) {
            result.push_back(&list->data[i]);
        }
    }
    return result;
}

array_list* create_random_arr_list (int element_amount) {
    array_list* list;
    if (element_amount<1) {return nullptr;}
    list = create_arr_empty();

    for (int i = 0; i < element_amount; i++) {
        add_to_arr_list(&list, random_time());
    }
    return list;
}

void sort_arr_list (array_list* list, bool print = true) {
    sort (list->data.begin(), list->data.end(), [](tm left, tm right){return left < right;});
    if (print) {
        for (int i = 0; i < list->data.size(); i++) {
            cout << list->data[i] << "     ";
        }
        cout << endl;
    }
}

void output_arr_list (array_list* list) {
    for (int i = 0; i < list->data.size(); i++) {
        cout<<list->data[i]<<"     ";
    }
    cout<<endl;
}

void do_some_function_arr(array_list* list, tm (*f)(tm)) {
    if(!list) {return;}
    sort_arr_list(list, false);
    for(int i = 0; i < list->data.size(); i++) {
        list->data[i] = f(list->data[i]);
    }
}

struct btree_node {
    tm data;
    btree_node* left;
    btree_node* right;
};

btree_node* create_empty_btree() {
    btree_node* new_tree;
    new_tree = new btree_node;
    new_tree->left = nullptr;
    new_tree->right = nullptr;
    new_tree->data.tm_year = -1;
    return new_tree;
}

void insert (btree_node** root, tm insert_data) {
    btree_node* input_node = new btree_node;
    input_node->data = insert_data;
    input_node->left = nullptr;
    input_node->right = nullptr;

    if (*root == nullptr) {
        *root = input_node;
        return;
    }

    if (input_node->data < (*root)->data) {
        if ((*root)->left == nullptr) {
            (*root)->left = input_node;
            return;
        }
        insert(&(*root)->left, insert_data);
    } else if (input_node->data > (*root)->data)   {
        if ((*root)->right == nullptr) {
            (*root)->right = input_node;
            return;
        }
        insert(&(*root)->right, insert_data);
    }
}

void delete_by_value (tm deleting_value, btree_node** root, btree_node* rec_root = nullptr) {
    if (!rec_root) {rec_root = *root;}
    if (rec_root->left) { delete_by_value(deleting_value, root, rec_root->left); }
    if (rec_root->right) { delete_by_value(deleting_value, root, rec_root->right); }

    if (rec_root->left || rec_root->right || (rec_root == *root && (*root)->data == deleting_value)) {
        queue<btree_node*> q;

        if (rec_root->left && rec_root->left->data == deleting_value) {
            q.push(rec_root->left);
            rec_root->left = nullptr;
        }
        else if (rec_root->right && rec_root->right->data == deleting_value) {
            q.push(rec_root->right);
            rec_root->right = nullptr;
        } else if (rec_root == *root && (*root)->data == deleting_value) {
            q.push(rec_root);
            (*root) = nullptr;
        } else {return;}

        vector<tm> childs_data;
        while (!q.empty()) {
            btree_node* curr_node = q.front();
            q.pop();
            if(!(curr_node->data == deleting_value)) {childs_data.push_back(curr_node->data);}
            if (curr_node->left) { q.push(curr_node->left); }
            if (curr_node->right) { q.push(curr_node->right); }
            delete curr_node;
        }


        for (int i = 0; i < childs_data.size(); i++) {
            insert(root,childs_data[i]);
        }
    }
}

void binary_tree_output(btree_node *root, bool is_top = true) {
    if (!root) {
        if (is_top) {cout<<"Empty tree"<<endl;}
        return;
    }
    cout<<root->data;
    if (root->left || root->right) { cout<<"("; }
    binary_tree_output(root->left, false);
    if (root->left && root->right) { cout<<","; }
    binary_tree_output(root->right, false);
    if (root->left || root->right) { cout << ")"; }
    if (is_top) {cout<<endl;}
}

btree_node* find_by_date_btree(btree_node* root, tm key) {
    bool found = false;
    while (root && !found) {
        if (key > root->data) {
            root = root->right;
        } else if (key < root->data) {
            root = root->left;
        } else if (root->data == key) {
            found = true;
        }
    }
    if (found) {return root;}
    else {return nullptr;}
}

void find_by_interval_btree(btree_node* root, tm left, tm right, vector<btree_node*>* result) {
    btree_node* curr = root;
    while (curr) {
        if (curr->data > left && curr->data < right) {
            (*result).push_back(root);
            if (curr->left) {find_by_interval_btree(curr->left, left, right, result);}
            if (curr->right) {find_by_interval_btree(curr->right, left, right, result);}
            break;
        } else if (left > curr->data) {
            curr = curr->right;
        } else if (right < curr->data) {
            curr = curr->left;
        }
    }
}

btree_node* create_random_btree (int element_amount) {
    btree_node *first;
    if (element_amount<1) {return nullptr;}
    first = create_empty_btree();
    first->data = random_time();

    for (int i = 1; i < element_amount; i++) {
        insert(&first, random_time());
    }
    return first;
}

void output_sorted_btree(btree_node* root, bool print = true) {
    vector<tm> all_dates;

    queue<btree_node*> q;
    q.push(root);
    while (!q.empty()) {
        btree_node* curr_node = q.front();
        q.pop();
        all_dates.push_back(curr_node->data);
        if (curr_node->left) { q.push(curr_node->left); }
        if (curr_node->right) { q.push(curr_node->right); }
    }

    sort (all_dates.begin(), all_dates.end(), [](tm left, tm right){return left < right;});

    if (print) {
        for (int i = 0; i < all_dates.size(); i++) {
            cout<<all_dates[i]<<"      ";
        }
        cout<<endl;
    }
}

void do_some_function_btree(btree_node* first, tm (*f)(tm)) {
    if(!first) {return;}

    queue<btree_node*> q;
    q.push(first);
    while (!q.empty()) {
        btree_node* curr_node = q.front();
        q.pop();
        curr_node->data = f(curr_node->data);
        if (curr_node->left) { q.push(curr_node->left); }
        if (curr_node->right) { q.push(curr_node->right); }
    }
}

struct avl_node {
    tm data;
    avl_node* left;
    avl_node* right;
};

int find_height (avl_node* root) {
    int high = 1;

    if (!root) {return 0;}
    if (!root->left&&!root->right) { return 1; }

    int max = find_height(root->left);
    if (find_height(root->right) > max) { max = find_height(root->right); }

    high += max;
    return high;
}

avl_node* create_empty_avl() {
    avl_node* new_tree;
    new_tree = new avl_node;
    new_tree->left = nullptr;
    new_tree->right = nullptr;
    new_tree->data.tm_year = -1;
    return new_tree;
}

avl_node* right_rotate(avl_node* right) {
    avl_node* left = right->left;
    avl_node* subtree = left->right;

    left->right = right;
    right->left = subtree;

    return left;
}

avl_node* left_rotate(avl_node* left) {
    avl_node* right = left->right;
    avl_node* subtree = right->left;

    right->left = left;
    left->right = subtree;

    return right;
}

int balance_difference (avl_node* curr_node) {
    if (curr_node == nullptr) { return 0; }
    return (find_height(curr_node->left) - find_height(curr_node->right));
}

avl_node* insert_avl(avl_node* root, tm insert_data, bool need_balance = true) {
    avl_node* input_node = new avl_node;
    input_node->data = insert_data;
    input_node->left = nullptr;
    input_node->right = nullptr;

    if (root == nullptr) {
        root = input_node;
        return root;
    }

    if (input_node->data < (root)->data) {
        if ((root)->left == nullptr) {
            (root)->left = input_node;
        } else { insert_avl((root)->left, insert_data, false);}
    } else if (input_node->data > (root)->data)   {
        if ((root)->right == nullptr) {
            (root)->right = input_node;
        } else { insert_avl((root)->right, insert_data, false);}
    } else {return root;}

    if (need_balance) {
        int balance = balance_difference(root);

        // Left Left Case
        if (balance > 1 && insert_data < root->left->data) { return right_rotate(root); }
        // Right Right Case
        if (balance < -1 && insert_data > root->right->data) { return left_rotate(root); }
        // Left Right Case
        if (balance > 1 && insert_data > root->left->data) {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
        // Right Left Case
        if (balance < -1 && insert_data < root->right->data) {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }

        return root;
    }
}

void delete_by_value_avl (tm deleting_value, avl_node** root, avl_node* rec_root = nullptr) {
    if (!rec_root) {rec_root = *root;}
    if (rec_root->left) { delete_by_value_avl(deleting_value, root, rec_root->left); }
    if (rec_root->right) { delete_by_value_avl(deleting_value, root, rec_root->right); }

    if (rec_root->left || rec_root->right || (rec_root == *root && (*root)->data == deleting_value)) {
        queue<avl_node*> q;

        if (rec_root->left && rec_root->left->data == deleting_value) {
            q.push(rec_root->left);
            rec_root->left = nullptr;
        }
        else if (rec_root->right && rec_root->right->data == deleting_value) {
            q.push(rec_root->right);
            rec_root->right = nullptr;
        } else if (rec_root == *root && (*root)->data == deleting_value) {
            q.push(rec_root);
            (*root) = nullptr;
        } else {return;}

        vector<tm> childs_data;
        while (!q.empty()) {
            avl_node* curr_node = q.front();
            q.pop();
            if(!(curr_node->data == deleting_value)) {childs_data.push_back(curr_node->data);}
            if (curr_node->left) { q.push(curr_node->left); }
            if (curr_node->right) { q.push(curr_node->right); }
            delete curr_node;
        }


        for (int i = 0; i < childs_data.size(); i++) {
            (*root) = insert_avl(*root,childs_data[i]);
        }
    }
}

void avl_tree_output(avl_node *root, bool is_top = true) {
    if (!root) {
        if (is_top) {cout<<"Empty tree"<<endl;}
        return;
    }
    cout<<root->data;
    if (root->left || root->right) { cout<<"("; }
    avl_tree_output(root->left, false);
    if (root->left && root->right) { cout<<","; }
    avl_tree_output(root->right, false);
    if (root->left || root->right) { cout << ")"; }
    if (is_top) {cout<<endl;}
}

avl_node* find_by_date_avl(avl_node* root, tm key) {
    bool found = false;
    while (root && !found) {
        if (key > root->data) {
            root = root->right;
        } else if (key < root->data) {
            root = root->left;
        } else if (root->data == key) {
            found = true;
        }
    }
    if (found) {return root;}
    else {return nullptr;}
}

void find_by_interval_avl(avl_node* root, tm left, tm right, vector<avl_node*>* result) {
    avl_node* curr = root;
    while (curr) {
        if (curr->data > left && curr->data < right) {
            (*result).push_back(curr);
            if (curr->left) {find_by_interval_avl(curr->left, left, right, result);}
            if (curr->right) {find_by_interval_avl(curr->right, left, right, result);}
            break;
        } else if (left > curr->data) {
            curr = curr->right;
        } else if (right < curr->data) {
            curr = curr->left;
        }
    }
}

avl_node* create_random_avl_tree (int element_amount) {
    avl_node *first;
    if (element_amount<1) {return nullptr;}
    first = create_empty_avl();
    first->data = random_time();

    for (int i = 1; i < element_amount; i++) {
        first = insert_avl(first, random_time());
    }
    return first;
}

void output_sorted_avl(avl_node* root, bool print = true) {
    vector<tm> all_dates;

    queue<avl_node*> q;
    q.push(root);
    while (!q.empty()) {
        avl_node* curr_node = q.front();
        q.pop();
        all_dates.push_back(curr_node->data);
        if (curr_node->left) { q.push(curr_node->left); }
        if (curr_node->right) { q.push(curr_node->right); }
    }

    sort (all_dates.begin(), all_dates.end(), [](tm left, tm right){return left < right;});
    if (print) {
        for (int i = 0; i < all_dates.size(); i++) {
            cout << all_dates[i] << "      ";
        }
        cout << endl;
    }
}

void do_some_function_avl(avl_node* first, tm (*f)(tm)) {
    if(!first) {return;}

    queue<avl_node*> q;
    q.push(first);
    while (!q.empty()) {
        avl_node* curr_node = q.front();
        q.pop();
        curr_node->data = f(curr_node->data);
        if (curr_node->left) { q.push(curr_node->left); }
        if (curr_node->right) { q.push(curr_node->right); }
    }
}

struct tt_tree {
    vector<tm> options;
    tt_tree* left;
    tt_tree* middle;
    tt_tree* right;
    tt_tree* parent;
};

tt_tree* create_empty_tt() {
    tt_tree* new_tree = new tt_tree;
    new_tree->left = nullptr;
    new_tree->middle = nullptr;
    new_tree->right = nullptr;
    new_tree->parent = nullptr;
    return new_tree;
}

void insert_tt (tt_tree** root, tm insert_data, tt_tree* main_root = nullptr) {

    if (!main_root) { main_root = *root;}
    if (*root == nullptr) {
        *root = create_empty_tt();
        (*root)->options.push_back(insert_data);
        return;
    }

    if ((*root)->options.empty()) {
        (*root)->options.push_back(insert_data);
        return;
    }

    if ((*root)->left == nullptr && (*root)->middle == nullptr && (*root)->right == nullptr && *root == main_root){
        if ((*root)->options.size() == 1) {
            (*root)->options.push_back(insert_data);
            sort( (*root)->options.begin(),  (*root)->options.end(),[](tm left, tm right){return left < right;});
            return;
        } else {
            if (insert_data < (*root)->options[0]) {
                (*root)->left = create_empty_tt();
                (*root)->left->options.push_back(insert_data);
                (*root)->left->parent = (*root);
                (*root)->middle = create_empty_tt();
                (*root)->middle->options.push_back((*root)->options[1]);
                (*root)->middle->parent = (*root);
                (*root)->options.erase((*root)->options.begin()+1);
                return;
            } else if (insert_data > (*root)->options[0] && insert_data < (*root)->options[1]) {
                (*root)->left = create_empty_tt();
                (*root)->left->options.push_back((*root)->options[0]);
                (*root)->left->parent = (*root);
                (*root)->middle = create_empty_tt();
                (*root)->middle->options.push_back((*root)->options[1]);
                (*root)->middle->parent = (*root);
                (*root)->options.clear();
                (*root)->options.push_back(insert_data);
                return;
            } else {
                (*root)->middle = create_empty_tt();
                (*root)->middle->options.push_back(insert_data);
                (*root)->middle->parent = (*root);
                (*root)->left = create_empty_tt();
                (*root)->left->options.push_back((*root)->options[0]);
                (*root)->left->parent = (*root);
                (*root)->options.erase((*root)->options.begin());
                return;
            }
        }
    }
    if (insert_data < (*root)->options[0]) {
        if ((*root)->left) {
            insert_tt(&(*root)->left, insert_data, main_root);
            return;
        }
    } else if ((*root)->options.size() == 2) {
        if (insert_data > (*root)->options[0] && insert_data < (*root)->options[1]) {
            if ((*root)->middle) {
                insert_tt(&(*root)->middle, insert_data, main_root);
                return;
            }
        } else if (insert_data > (*root)->options[1]) {
            if ((*root)->right) {
                insert_tt(&(*root)->right, insert_data, main_root);
                return;
            }
        }
    } else if (insert_data > (*root)->options[0]) {
        if ((*root)->middle) {
            insert_tt(&(*root)->middle, insert_data, main_root);
            return;
        }
    }
    if ((*root)->options[0] == insert_data || (*root)->options[1] == insert_data) { return; }

    if ((*root)->left == nullptr && (*root)->middle == nullptr && (*root)->right == nullptr) {

        if ((*root)->options.size() == 1) {
            (*root)->options.push_back(insert_data);
            sort( (*root)->options.begin(),  (*root)->options.end(),[](tm left, tm right){return left < right;});
            return;
        } else if ((*root)->parent->options.size() == 1) {
            vector<tm> temp_node =  (*root)->options;
            temp_node.push_back(insert_data);
            sort(temp_node.begin(), temp_node.end(),[](tm left, tm right){return left < right;});
            (*root)->parent->options.push_back(temp_node[1]);
            sort( (*root)->options.begin(),  (*root)->options.end(),[](tm left, tm right){return left < right;});

            if (*root == (*root)->parent->left) {
                (*root)->parent->left->options.clear();
                (*root)->parent->left->options.push_back(temp_node[0]);

                (*root)->parent->right = create_empty_tt();
                ((*root)->parent->right)->parent = (*root)->parent;
                (*root)->parent->right->options = (*root)->parent->middle->options;

                (*root)->parent->middle->options.clear();
                (*root)->parent->middle->options.push_back(temp_node[2]);
            } else if (*root == (*root)->parent->middle) {
                (*root)->parent->right = create_empty_tt();
                ((*root)->parent->right)->parent = (*root)->parent;
                (*root)->parent->right->options.push_back(temp_node[2]);

                (*root)->parent->middle->options.clear();
                (*root)->parent->middle->options.push_back(temp_node[0]);
            }
            return;
        } else {
            pair<vector<tm>,vector<tm>> for_input;
            int side = 0;
            if (*root == (*root)->parent->left) {
                for_input = make_pair((*root)->parent->middle->options,(*root)->parent->right->options);
                side = 0;
            } else if (*root == (*root)->parent->middle) {
                for_input = make_pair((*root)->parent->left->options,(*root)->parent->right->options);
                side = 1;
            } else if (*root == (*root)->parent->right) {
                for_input = make_pair((*root)->parent->left->options,(*root)->parent->middle->options);
                side = 2;
            }

            vector<tm> temp_node = (*root)->options;
            temp_node.push_back(insert_data);
            sort(temp_node.begin(), temp_node.end(),[](tm left, tm right){return left < right;});

            vector<tm> temp_node_parent = (*root)->parent->options;
            temp_node_parent.push_back(temp_node[1]);
            sort(temp_node_parent.begin(), temp_node_parent.end(),[](tm left, tm right){return left < right;});
            tt_tree* parent_node = (*root)->parent;

            parent_node->options.clear();
            parent_node->options.push_back(temp_node_parent[1]);

            parent_node->left->options.clear();
            parent_node->left->options.push_back(temp_node_parent[0]);

            parent_node->middle->options.clear();
            parent_node->middle->options.push_back(temp_node_parent[2]);

            parent_node->right = nullptr;

            parent_node->left->left = create_empty_tt();
            ((parent_node->left)->left)->parent = parent_node->left;

            parent_node->left->middle = create_empty_tt();
            ((parent_node->left)->middle)->parent = parent_node->left;

            parent_node->middle->left = create_empty_tt();
            ((parent_node->middle)->left)->parent = parent_node->middle;

            parent_node->middle->middle = create_empty_tt();
            ((parent_node->middle)->middle)->parent = parent_node->middle;
            if (side == 0) {
                (parent_node->left)->left->options.push_back(temp_node[0]);
                (parent_node->left)->middle->options.push_back(temp_node[2]);

                parent_node->middle->left->options = for_input.first;
                parent_node->middle->middle->options = for_input.second;
            } else if (side == 1) {
                (parent_node->left)->left->options = for_input.first;
                (parent_node->left)->middle->options.push_back(temp_node[0]);

                parent_node->middle->left->options.push_back(temp_node[2]);
                parent_node->middle->middle->options = for_input.second;
            }
            else if (side == 2) {
                (parent_node->left)->left->options = for_input.first;
                (parent_node->left)->middle->options = for_input.second;

                parent_node->middle->left->options.push_back(temp_node[0]);
                parent_node->middle->middle->options.push_back(temp_node[2]);
            }
            return;
        }
    }

}

void delete_by_value_tt (tm deleting_value, tt_tree** root, tt_tree* rec_root = nullptr) {
    if (!rec_root) {rec_root = *root;}
    if (rec_root->left) { delete_by_value_tt(deleting_value, root, rec_root->left); }
    if (rec_root->middle) { delete_by_value_tt(deleting_value, root, rec_root->middle); }
    if (rec_root->right) { delete_by_value_tt(deleting_value, root, rec_root->right); }

    if (rec_root->left || rec_root->middle || rec_root->right || (rec_root == *root && (((*root)->options[0] == deleting_value)||(*root)->options[1] == deleting_value))) {
        queue<tt_tree*> q;

        if (rec_root->left && (rec_root->left->options[0] == deleting_value||rec_root->left->options[1] == deleting_value)) {
            q.push(rec_root->left);
            rec_root->left = nullptr;
            if (rec_root->middle) {
                q.push(rec_root->middle);
                rec_root->middle = nullptr;
            }
            if (rec_root->right) {
                q.push(rec_root->right);
                rec_root->right = nullptr;
            }
        } else if (rec_root->middle && (rec_root->middle->options[0] == deleting_value||rec_root->middle->options[1] == deleting_value)) {
            q.push(rec_root->middle);
            rec_root->middle = nullptr;
            if (rec_root->left) {
                q.push(rec_root->left);
                rec_root->left = nullptr;
            }
            if (rec_root->right) {
                q.push(rec_root->right);
                rec_root->right = nullptr;
            }
        } else if (rec_root->right && (rec_root->right->options[0] == deleting_value||rec_root->right->options[1] == deleting_value)) {
            q.push(rec_root->right);
            rec_root->right = nullptr;
            if (rec_root->left) {
                q.push(rec_root->left);
                rec_root->left = nullptr;
            }
            if (rec_root->middle) {
                q.push(rec_root->middle);
                rec_root->middle = nullptr;
            }
        } else if (rec_root == *root && ((*root)->options[0] == deleting_value||(*root)->options[1] == deleting_value)) {
            q.push(rec_root);
            (*root) = nullptr;
        } else {return;}

        vector<tm> childs_data;
        while (!q.empty()) {
            tt_tree* curr_node = q.front();
            q.pop();
            for (int i = 0; i < curr_node->options.size(); i++) {
                if (!(curr_node->options[i] == deleting_value)) {childs_data.push_back(curr_node->options[i]);}
            }
            if (curr_node->left) { q.push(curr_node->left); }
            if (curr_node->middle) { q.push(curr_node->middle); }
            if (curr_node->right) { q.push(curr_node->right); }
            delete curr_node;
        }


        for (int i = 0; i < childs_data.size(); i++) {
            insert_tt(root,childs_data[i]);
        }
    }
}

tt_tree* create_random_tt(int element_amount) {
    tt_tree* first;
    if (element_amount<1) {return nullptr;}
    first = create_empty_tt();
    first->options.push_back(random_time());

    for (int i = 1; i < element_amount; i++) {
        insert_tt(&first, random_time());
    }
    return first;
}

tt_tree* find_by_date_tt(tt_tree* root, tm key) {
    bool found = false;
    while (root && !found) {
        if (root->options[0] == key || root->options[1] == key) {
            found = true;
            break;
        } else if (key < root->options[0]) {
            root = root->left;
        } else if (root->options.size() == 2) {
            if (key > root->options[0] && key < root->options[1]) {
                root = root->middle;
            } else if (key > root->options[1]) {
                root = root->right;
            }
        } else if (key > root->options[0]) {
            root = root->middle;
        }
    }
    if (found) {return root;}
    else {return nullptr;}
}

void find_by_interval_tt(tt_tree* root, tm left, tm right, vector<tt_tree*>* result) {
    tt_tree* curr = root;
    while (curr) {
        if ((curr->options[0] >= left && curr->options[0] <= right) || (curr->options[1] >= left && curr->options[1] <= right)) {
            (*result).push_back(curr);
            if (curr->left) {find_by_interval_tt(curr->left, left, right, result);}
            if (curr->middle) {find_by_interval_tt(curr->middle, left, right, result);}
            if (curr->right) {find_by_interval_tt(curr->right, left, right, result);}
            break;
        } else if (right < curr->options[0]) {
            curr = curr->left;
        } else if (curr->options.size() == 2) {
            if (left > curr->options[0] && right < curr->options[1]) {
                curr = curr->middle;
            } else if (left > curr->options[1]) {
                curr = curr->right;
            }
        } else if (left > curr->options[0]) {
            curr = curr->middle;
        }
    }
}

void output_sorted_tt(tt_tree* root, bool print = true) {
    vector<tm> all_dates;

    queue<tt_tree*> q;
    q.push(root);
    while (!q.empty()) {
        tt_tree* curr_node = q.front();
        q.pop();

        all_dates.push_back(curr_node->options[0]);
        if (curr_node->options.size() == 2) {all_dates.push_back(curr_node->options[1]);}
        if (curr_node->left) { q.push(curr_node->left); }
        if (curr_node->middle) { q.push(curr_node->middle); }
        if (curr_node->right) { q.push(curr_node->right); }
    }

    sort (all_dates.begin(), all_dates.end(), [](tm left, tm right){return left < right;});
    if (print) {
        for (int i = 0; i < all_dates.size(); i++) {
            cout << all_dates[i] << "      ";
        }
        cout << endl;
    }
}

void do_some_function_tt(tt_tree* root, tm (*f)(tm)) {
    queue<tt_tree*> q;
    q.push(root);
    while (!q.empty()) {
        tt_tree* curr_node = q.front();
        q.pop();
        for (int i = 0; i < root->options.size(); i++) {
            curr_node->options[i] = f(curr_node->options[i]);
        }
        if (curr_node->left) { q.push(curr_node->left); }
        if (curr_node->middle) { q.push(curr_node->middle); }
        if (curr_node->right) { q.push(curr_node->right); }
    }
}

void tt_tree_output(tt_tree* root, bool is_top = true) {
    if (!root) {
        if (is_top) {cout<<"Empty tree"<<endl;}
        return;
    }
    cout<<'[';
    for (int i = 0; i < root->options.size(); i++) {
        cout<<root->options[i];
        if (i+1 != root->options.size()) {cout<<" + ";}
    }
    cout<<']';

    if (root->left || root->right || root->middle) { cout<<"( "; }
    tt_tree_output(root->left, false);
    if (root->left && root->middle) { cout<<","; }
    tt_tree_output(root->middle, false);
    if (root->middle && root->right) { cout<<","; }
    tt_tree_output(root->right, false);
    if (root->left || root->right || root->middle) { cout << " )"; }
    if (is_top) {cout<<endl;}
}

tm some_function (tm date) {
    date.tm_year++;
    return date;
}

void demonstration_linked() {
    cout<<"1. Linked list"<<endl;
    int amount = rand()%10+1;
    cout<<"Fill list with "<<amount<<" random elements: "<<endl;
    linked_list* linked_sample = create_empty();
    linked_sample = create_random_list(amount);
    cout<<"List now: "<<endl;
    output_list(linked_sample);
    tm first_date = random_time(), second_date = random_time();
    cout<<"Add element "<<first_date<<" and "<<second_date<<" to list:"<<endl;
    add_to_list(&linked_sample, first_date);
    add_to_list(&linked_sample, second_date);
    cout<<"List now: "<<endl;
    output_list(linked_sample);
    cout<<"Lets delete element "<<(linked_sample->next)->data<<": "<<endl;
    delete_element(&linked_sample,(linked_sample->next)->data);
    cout<<"List now: "<<endl;
    output_list(linked_sample);
    vector<linked_list*> search_linked;
    cout<<"Lets find element "<<(linked_sample->next)->data<<": "<<endl;
    search_linked = find_by_date(linked_sample, (linked_sample->next)->data);
    if (search_linked.empty()) {cout<<"there is no such date"<<endl;}
    else {
        for (int i = 0; i < search_linked.size(); i++) {
            cout<<search_linked[i]<<"("<<search_linked[i]->data<<")"<<"   ";
        }
        cout<<endl;
    }
    first_date = random_time();
    do {second_date = random_time();} while (first_date>second_date);
    cout<<"Lets find elements in interval "<<first_date<<"  -   "<<second_date<<": "<<endl;
    search_linked = find_by_interval(linked_sample, first_date, second_date);
    if (search_linked.empty()) {cout<<"there is no such date"<<endl;}
    else {
        for (int i = 0; i < search_linked.size(); i++) {
            cout<<search_linked[i]<<"("<<search_linked[i]->data<<")"<<"   ";
        }
        cout<<endl;
    }
    cout<<"Lets sort our list:"<<endl;
    sort_list(linked_sample);
    cout<<"Lets do some function - increment every year in the list:"<<endl;
    do_some_function(linked_sample, some_function);
    output_list(linked_sample);
}
void demonstration_array() {
    cout<<"2. Array list"<<endl;
    int amount = rand()%10+1;
    cout<<"Fill list with "<<amount<<" random elements: "<<endl;
    array_list* array_sample = create_arr_empty();
    array_sample = create_random_arr_list(amount);
    cout<<"List now: "<<endl;
    output_arr_list(array_sample);
    tm first_date = random_time(), second_date = random_time();
    cout<<"Add element "<<first_date<<" and "<<second_date<<" to list:"<<endl;
    add_to_arr_list(&array_sample, first_date);
    add_to_arr_list(&array_sample, second_date);
    cout<<"List now: "<<endl;
    output_arr_list(array_sample);
    cout<<"Lets delete element "<<(array_sample)->data[1]<<": "<<endl;
    delete_arr_element(array_sample,array_sample->data[1]);
    cout<<"List now: "<<endl;
    output_arr_list(array_sample);
    vector<tm*> search_array;
    cout<<"Lets find element "<<array_sample->data[1]<<": "<<endl;
    search_array = find_by_date_arr(array_sample, array_sample->data[1]);
    if (search_array.empty()) {cout<<"there is no such date"<<endl;}
    else {
        for (int i = 0; i < search_array.size(); i++) {
            cout<<search_array[i]<<"("<<*search_array[i]<<")"<<"   ";
        }
        cout<<endl;
    }
    first_date = random_time();
    do {second_date = random_time();} while (first_date>second_date);
    cout<<"Lets find elements in interval "<<first_date<<"  -   "<<second_date<<": "<<endl;
    search_array = find_by_interval_arr(array_sample, first_date, second_date);
    if (search_array.empty()) {cout<<"there is no such date"<<endl;}
    else {
        for (int i = 0; i < search_array.size(); i++) {
            cout<<search_array[i]<<"("<<*search_array[i]<<")"<<"   ";
        }
        cout<<endl;
    }
    cout<<"Lets sort our list:"<<endl;
    sort_arr_list(array_sample);
    cout<<"Lets do some function - increment every year in the list:"<<endl;
    do_some_function_arr(array_sample, some_function);
    output_arr_list(array_sample);
}
void demonstration_btree() {
    cout<<"3. Binary search tree"<<endl;
    int amount = rand()%10+1;
    cout<<"Fill tree with "<<amount<<" random elements: "<<endl;
    btree_node* sample = create_empty_btree();
    sample = create_random_btree(amount);
    cout<<"Tree now: "<<endl;
    binary_tree_output(sample);
    tm first_date = random_time(), second_date = random_time();
    cout<<"Add element "<<first_date<<" and "<<second_date<<" to tree:"<<endl;
    insert(&sample, first_date);
    insert(&sample, second_date);
    cout<<"Tree now: "<<endl;
    binary_tree_output(sample);
    cout<<"Lets delete element "<<(sample)->data<<": "<<endl;
    delete_by_value((sample)->data, &sample);
    cout<<"Tree now: "<<endl;
    binary_tree_output(sample);
    vector<btree_node*> search;
    search.resize(1);
    if ((sample)->right) {
        cout<<"Lets find element "<<(sample)->right->data<<": "<<endl;
        search[0] = find_by_date_btree(sample, (sample)->right->data);
    }
    else {
        cout<<"Lets find element "<<(sample)->left->data<<": "<<endl;
        search[0] = find_by_date_btree(sample, (sample)->left->data);
    }
    if (!search[0]) {cout<<"there is no such date"<<endl;}
    else {
        cout<<search[0]<<"("<<search[0]->data<<")"<<"   "<<endl;
    }
    first_date = random_time();
    do {second_date = random_time();} while (first_date>second_date);
    cout<<"Lets find elements in interval "<<first_date<<"  -   "<<second_date<<": "<<endl;
    search.clear();
    find_by_interval_btree(sample, first_date, second_date, &search);
    if (search.empty()) {cout<<"there is no such date"<<endl;}
    else {
        for (int i = 0; i < search.size(); i++) {
            cout<<search[i]<<"("<<search[i]->data<<")"<<"   ";
        }
        cout<<endl;
    }
    cout<<"Output sorted tree:"<<endl;
    output_sorted_btree(sample);
    cout<<"Lets do some function - increment every year in the tree:"<<endl;
    do_some_function_btree(sample, some_function);
    binary_tree_output(sample);
    output_sorted_btree(sample);
}
void demonstration_avltree() {
    cout<<"3. AVL tree"<<endl;
    int amount = rand()%10+1;
    cout<<"Fill tree with "<<amount<<" random elements: "<<endl;
    avl_node* sample = create_empty_avl();
    sample = create_random_avl_tree(amount);
    cout<<"Tree now: "<<endl;
    avl_tree_output(sample);
    tm first_date = random_time(), second_date = random_time();
    cout<<"Add element "<<first_date<<" and "<<second_date<<" to tree:"<<endl;
    sample = insert_avl(sample, first_date);
    sample = insert_avl(sample, second_date);
    cout<<"Tree now: "<<endl;
    avl_tree_output(sample);
    cout<<"Lets delete element "<<(sample)->data<<": "<<endl;
    delete_by_value_avl((sample)->data, &sample);
    cout<<"Tree now: "<<endl;
    avl_tree_output(sample);
    vector<avl_node*> search;
    search.resize(1);
    if ((sample)->right) {
        cout<<"Lets find element "<<(sample)->right->data<<": "<<endl;
        search[0] = find_by_date_avl(sample, (sample)->right->data);
    }
    else {
        cout<<"Lets find element "<<(sample)->left->data<<": "<<endl;
        search[0] = find_by_date_avl(sample, (sample)->left->data);
    }
    if (!search[0]) {cout<<"there is no such date"<<endl;}
    else {
        cout<<search[0]<<"("<<search[0]->data<<")"<<"   "<<endl;
    }
    first_date = random_time();
    do {second_date = random_time();} while (first_date>second_date);
    cout<<"Lets find elements in interval "<<first_date<<"  -   "<<second_date<<": "<<endl;
    search.clear();
    find_by_interval_avl(sample, first_date, second_date, &search);
    if (search.empty()) {cout<<"there is no such date"<<endl;}
    else {
        for (int i = 0; i < search.size(); i++) {
            cout<<search[i]<<"("<<search[i]->data<<")"<<"   ";
        }
        cout<<endl;
    }
    cout<<"Output sorted tree:"<<endl;
    output_sorted_avl(sample);
    cout<<"Lets do some function - increment every year in the tree:"<<endl;
    do_some_function_avl(sample, some_function);
    avl_tree_output(sample);
    output_sorted_avl(sample);
}
void demonstration_23_tree() {
    cout<<"5. 2-3 tree"<<endl;
    int amount = rand()%10+1;
    cout<<"Fill tree with "<<amount<<" random elements: "<<endl;
    tt_tree* sample = create_empty_tt();
    sample = create_random_tt(amount);
    cout<<"Tree now: "<<endl;
    tt_tree_output(sample);
    tm first_date = random_time(), second_date = random_time();
    cout<<"Add element "<<first_date<<" and "<<second_date<<" to tree:"<<endl;
    insert_tt(&sample, first_date);
    insert_tt(&sample, second_date);
    cout<<"Tree now: "<<endl;
    tt_tree_output(sample);
    cout<<"Lets delete element "<<(sample)->options[0]<<": "<<endl;
    delete_by_value_tt((sample)->options[0], &sample);
    cout<<"Tree now: "<<endl;
    tt_tree_output(sample);
    vector<tt_tree*> search;
    search.resize(1);
    if ((sample)->right) {
        cout<<"Lets find element "<<(sample)->right->options[0]<<": "<<endl;
        search[0] = find_by_date_tt(sample, (sample)->right->options[0]);
    }
    else {
        cout<<"Lets find element "<<(sample)->left->options[0]<<": "<<endl;
        search[0] = find_by_date_tt(sample, (sample)->left->options[0]);
    }
    if (!search[0]) {cout<<"there is no such date"<<endl;}
    else {
        cout<<search[0]<<"("<<search[0]->options[0];
        if (search[0]->options.size() == 2) {cout<<", "<< search[0]->options[1]<<")"<<"   "<<endl;}
        else {cout<<")"<<"   "<<endl;}
    }
    first_date = random_time();
    do {second_date = random_time();} while (first_date>second_date);
    cout<<"Lets find elements in interval "<<first_date<<"  -   "<<second_date<<": "<<endl;
    search.clear();
    find_by_interval_tt(sample, first_date, second_date, &search);
    if (search.empty()) {cout<<"there is no such date"<<endl;}
    else {
        for (int i = 0; i < search.size(); i++) {
            cout<<search[i]<<"("<<search[i]->options[0];
            if (search[i]->options.size() == 2) {cout<<", "<< search[i]->options[1]<<")"<<"   "<<endl;}
            else {cout<<")"<<"   "<<endl;}
        }
        cout<<endl;
    }
    cout<<"Output sorted tree:"<<endl;
    output_sorted_tt(sample);
    cout<<"Lets do some function - increment every year in the tree:"<<endl;
    do_some_function_tt(sample, some_function);
    tt_tree_output(sample);
    output_sorted_tt(sample);
}
void demonstration() {
    demonstration_linked();
    demonstration_array();
    demonstration_btree();
    demonstration_avltree();
    demonstration_23_tree();
}

void interactive();
void interactive_linked (linked_list** sample) {
    int mode = 0;
    tm date;

    cout<<"Create empty list - enter 1"<<endl;
    cout<<"Add date to list - enter 2"<<endl;
    cout<<"Output list - enter 3"<<endl;
    cout<<"Create random list - enter 4"<<endl;
    cout<<"Delete date from list - enter 5"<<endl;
    cout<<"Find by date - enter 6"<<endl;
    cout<<"Find by interval - enter 7"<<endl;
    cout<<"Sort list by ascending order - enter 8"<<endl;
    cout<<"Do some function (increment every date year) - enter 9"<<endl;
    cout<<"Back to main menu - enter 0"<<endl;
    cin>>mode;

    switch(mode) {
        case 0: {
            interactive();
            return;
        }
        case 1: {
            *sample = create_empty();
            break;
        }
        case 2: {
            cout<<"Enter date (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            add_to_list(sample, date);
            break;
        }
        case 3: {
            output_list(*sample);
            break;
        }
        case 4: {
            cout<<"Enter amount of elements"<<endl;
            int amount;
            cin>>amount;
            *sample = create_random_list(amount);
            break;
        }
        case 5: {
            cout<<"Enter date to delete from list (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            delete_element(sample,date);
            break;
        }
        case 6: {
            cout<<"Enter date to find (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            vector<linked_list*>search_linked = find_by_date(*sample, date);
            if (search_linked.empty()) {cout<<"there is no such date"<<endl;}
            else {
                for (int i = 0; i < search_linked.size(); i++) {
                    cout<<search_linked[i]<<"("<<search_linked[i]->data<<")"<<"   ";
                }
                cout<<endl;
            }
            break;
        }
        case 7: {
            cout<<"Enter start date to find by interval (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            tm end_date;
            cout<<"Enter end date to find by interval (day, month, year, hour, minute, second)"<<endl;
            cin>>end_date;
            vector<linked_list*>search_linked = find_by_interval(*sample, date, end_date);
            if (search_linked.empty()) {cout<<"there is no such dates"<<endl;}
            else {
                for (int i = 0; i < search_linked.size(); i++) {
                    cout<<search_linked[i]<<"("<<search_linked[i]->data<<")"<<"   ";
                }
                cout<<endl;
            }
            break;
        }
        case 8: {
            sort_list(*sample);
            break;
        }
        case 9: {
            do_some_function(*sample, some_function);
            break;
        }
        default: {
            cout<<"Wrong number!"<<endl;
            break;
        }
    }
    interactive_linked(sample);
}
void interactive_array (array_list** sample) {
    int mode = 0;
    tm date;

    cout<<"Create empty list - enter 1"<<endl;
    cout<<"Add date to list - enter 2"<<endl;
    cout<<"Output list - enter 3"<<endl;
    cout<<"Create random list - enter 4"<<endl;
    cout<<"Delete date from list - enter 5"<<endl;
    cout<<"Find by date - enter 6"<<endl;
    cout<<"Find by interval - enter 7"<<endl;
    cout<<"Sort list by ascending order - enter 8"<<endl;
    cout<<"Do some function (increment every date year) - enter 9"<<endl;
    cout<<"Back to main menu - enter 0"<<endl;
    cin>>mode;

    switch(mode) {
        case 0: {
            interactive();
            return;
        }
        case 1: {
            *sample = create_arr_empty();
            break;
        }
        case 2: {
            cout<<"Enter date (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            add_to_arr_list(sample, date);
            break;
        }
        case 3: {
            output_arr_list(*sample);
            break;
        }
        case 4: {
            cout<<"Enter amount of elements"<<endl;
            int amount;
            cin>>amount;
            *sample = create_random_arr_list(amount);
            break;
        }
        case 5: {
            cout<<"Enter date to delete from list (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            delete_arr_element(*sample,date);
            break;
        }
        case 6: {
            cout<<"Enter date to find (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            vector<tm*> search_array;
            search_array = find_by_date_arr(*sample, date);
            if (search_array.empty()) {cout<<"there is no such date"<<endl;}
            else {
                for (int i = 0; i < search_array.size(); i++) {
                    cout<<search_array[i]<<"("<<*search_array[i]<<")"<<"   ";
                }
                cout<<endl;
            }
            break;
        }
        case 7: {
            cout<<"Enter start date to find by interval (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            tm end_date;
            cout<<"Enter end date to find by interval (day, month, year, hour, minute, second)"<<endl;
            cin>>end_date;
            vector<tm*> search_array;
            search_array = find_by_interval_arr(*sample, date, end_date);
            if (search_array.empty()) {cout<<"there is no such date"<<endl;}
            else {
                for (int i = 0; i < search_array.size(); i++) {
                    cout<<search_array[i]<<"("<<*search_array[i]<<")"<<"   ";
                }
                cout<<endl;
            }
            break;
        }
        case 8: {
            sort_arr_list(*sample);
            break;
        }
        case 9: {
            do_some_function_arr(*sample, some_function);
            break;
        }
        default: {
            cout<<"Wrong number!"<<endl;
            break;
        }
    }
    interactive_array(sample);
}
void interactive_btree (btree_node** sample) {
    int mode = 0;
    tm date;

    cout<<"Create empty tree - enter 1"<<endl;
    cout<<"Add date to tree - enter 2"<<endl;
    cout<<"Output tree - enter 3"<<endl;
    cout<<"Create random tree - enter 4"<<endl;
    cout<<"Delete date from tree - enter 5"<<endl;
    cout<<"Find by date - enter 6"<<endl;
    cout<<"Find by interval - enter 7"<<endl;
    cout<<"Output tree by ascending order - enter 8"<<endl;
    cout<<"Do some function (increment every date year) - enter 9"<<endl;
    cout<<"Back to main menu - enter 0"<<endl;
    cin>>mode;

    switch(mode) {
        case 0: {
            interactive();
            return;
        }
        case 1: {
            *sample = create_empty_btree();
            break;
        }
        case 2: {
            cout<<"Enter date (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            insert(sample, date);
            break;
        }
        case 3: {
            binary_tree_output(*sample);
            break;
        }
        case 4: {
            cout<<"Enter amount of elements"<<endl;
            int amount;
            cin>>amount;
            *sample = create_random_btree(amount);
            break;
        }
        case 5: {
            cout<<"Enter date to delete from list (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            delete_by_value(date, sample);
            break;
        }
        case 6: {
            cout<<"Enter date to find (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            btree_node* search;

            search = find_by_date_btree(*sample, date);
            if (!search) {cout<<"there is no such date"<<endl;}
            else { cout<<search<<"("<<search->data<<")"<<"   "<<endl; }
            break;
        }
        case 7: {
            cout<<"Enter start date to find by interval (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            tm end_date;
            cout<<"Enter end date to find by interval (day, month, year, hour, minute, second)"<<endl;
            cin>>end_date;
            vector<btree_node*> search;
            find_by_interval_btree(*sample, date, end_date, &search);
            if (search.empty()) {cout<<"there is no such date"<<endl;}
            else {
                for (int i = 0; i < search.size(); i++) {
                    cout<<search[i]<<"("<<search[i]->data<<")"<<"   ";
                }
                cout<<endl;
            }
            break;
        }
        case 8: {
            output_sorted_btree(*sample);
            break;
        }
        case 9: {
            do_some_function_btree(*sample, some_function);
            break;
        }
        default: {
            cout<<"Wrong number!"<<endl;
            break;
        }
    }
    interactive_btree(sample);
}
void interactive_avltree (avl_node** sample) {
    int mode = 0;
    tm date;

    cout<<"Create empty tree - enter 1"<<endl;
    cout<<"Add date to tree - enter 2"<<endl;
    cout<<"Output tree - enter 3"<<endl;
    cout<<"Create random tree - enter 4"<<endl;
    cout<<"Delete date from tree - enter 5"<<endl;
    cout<<"Find by date - enter 6"<<endl;
    cout<<"Find by interval - enter 7"<<endl;
    cout<<"Output tree by ascending order - enter 8"<<endl;
    cout<<"Do some function (increment every date year) - enter 9"<<endl;
    cout<<"Back to main menu - enter 0"<<endl;
    cin>>mode;

    switch(mode) {
        case 0: {
            interactive();
            return;
        }
        case 1: {
            *sample = create_empty_avl();
            break;
        }
        case 2: {
            cout<<"Enter date (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            *sample = insert_avl(*sample, date);
            break;
        }
        case 3: {
            avl_tree_output(*sample);
            break;
        }
        case 4: {
            cout<<"Enter amount of elements"<<endl;
            int amount;
            cin>>amount;
            *sample = create_random_avl_tree(amount);
            break;
        }
        case 5: {
            cout<<"Enter date to delete from list (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            delete_by_value_avl(date, sample);
            break;
        }
        case 6: {
            cout<<"Enter date to find (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            avl_node* search;

            search = find_by_date_avl(*sample, date);
            if (!search) {cout<<"there is no such date"<<endl;}
            else { cout<<search<<"("<<search->data<<")"<<"   "<<endl; }
            break;
        }
        case 7: {
            cout<<"Enter start date to find by interval (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            tm end_date;
            cout<<"Enter end date to find by interval (day, month, year, hour, minute, second)"<<endl;
            cin>>end_date;
            vector<avl_node*> search;
            find_by_interval_avl(*sample, date, end_date, &search);
            if (search.empty()) {cout<<"there is no such date"<<endl;}
            else {
                for (int i = 0; i < search.size(); i++) {
                    cout<<search[i]<<"("<<search[i]->data<<")"<<"   ";
                }
                cout<<endl;
            }
            break;
        }
        case 8: {
            output_sorted_avl(*sample);
            break;
        }
        case 9: {
            do_some_function_avl(*sample, some_function);
            break;
        }
        default: {
            cout<<"Wrong number!"<<endl;
            break;
        }
    }
    interactive_avltree(sample);
}
void interactive_23tree (tt_tree** sample) {
    int mode = 0;
    tm date;

    cout<<"Create empty tree - enter 1"<<endl;
    cout<<"Add date to tree - enter 2"<<endl;
    cout<<"Output tree - enter 3"<<endl;
    cout<<"Create random tree - enter 4"<<endl;
    cout<<"Delete date from tree - enter 5"<<endl;
    cout<<"Find by date - enter 6"<<endl;
    cout<<"Find by interval - enter 7"<<endl;
    cout<<"Output tree by ascending order - enter 8"<<endl;
    cout<<"Do some function (increment every date year) - enter 9"<<endl;
    cout<<"Back to main menu - enter 0"<<endl;
    cin>>mode;

    switch(mode) {
        case 0: {
            interactive();
            return;
        }
        case 1: {
            *sample = create_empty_tt();
            break;
        }
        case 2: {
            cout<<"Enter date (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            insert_tt(sample, date);
            break;
        }
        case 3: {
            tt_tree_output(*sample);
            break;
        }
        case 4: {
            cout<<"Enter amount of elements"<<endl;
            int amount;
            cin>>amount;
            *sample = create_random_tt(amount);
            break;
        }
        case 5: {
            cout<<"Enter date to delete from list (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            delete_by_value_tt(date, sample);
            break;
        }
        case 6: {
            cout<<"Enter date to find (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            tt_tree* search;

            search = find_by_date_tt(*sample, date);
            if (!search) {cout<<"there is no such date"<<endl;}
            else {
                cout<<search<<"("<<search->options[0];
                if (search->options.size() == 2) {cout<<", "<< search->options[1]<<")"<<"   "<<endl;}
                else {cout<<")"<<"   "<<endl;}
            }
            break;
        }
        case 7: {
            cout<<"Enter start date to find by interval (day, month, year, hour, minute, second)"<<endl;
            cin>>date;
            tm end_date;
            cout<<"Enter end date to find by interval (day, month, year, hour, minute, second)"<<endl;
            cin>>end_date;
            vector<tt_tree*> search;
            find_by_interval_tt(*sample, date, end_date, &search);
            if (search.empty()) {cout<<"there is no such date"<<endl;}
            else {
                for (int i = 0; i < search.size(); i++) {
                    cout<<search[i]<<"("<<search[i]->options[0];
                    if (search[i]->options.size() == 2) {cout<<", "<< search[i]->options[1]<<")"<<"   "<<endl;}
                    else {cout<<")"<<"   "<<endl;}
                }
                cout<<endl;
            }
            break;
        }
        case 8: {
            output_sorted_tt(*sample);
            break;
        }
        case 9: {
            do_some_function_tt(*sample, some_function);
            break;
        }
        default: {
            cout<<"Wrong number!"<<endl;
            break;
        }
    }
    interactive_23tree(sample);
}
int interactive_options() {
    int mode = 0;
    cout<<"Work with linked list - enter 1"<<endl;
    cout<<"Work with array list - enter 2"<<endl;
    cout<<"Work with binary search tree - enter 3"<<endl;
    cout<<"Work with AVL tree - enter 4"<<endl;
    cout<<"Work with 2-3 tree - enter 5"<<endl;
    cout<<"Exit - enter 0"<<endl;
    cin>>mode;
    return mode;
}
void interactive() {
    int mode = 0;
    mode = interactive_options();
    switch(mode) {
        case 0: {
            return;
        }
        case 1: {
            linked_list* sample = nullptr;
            interactive_linked(&sample);
            break;
        }
        case 2: {
            array_list* sample = nullptr;
            interactive_array(&sample);
            break;
        }
        case 3: {
            btree_node* sample = nullptr;
            interactive_btree(&sample);
            break;
        }
        case 4: {
            avl_node* sample = nullptr;
            interactive_avltree(&sample);
            break;
        }
        case 5: {
            tt_tree* sample = nullptr;
            interactive_23tree(&sample);
            break;
        }
        default: {
            cout<<"Wrong number!"<<endl;
        }
    }
}

void benchmark() {
    int count, count_sec;
    clock_t benchmark_clock;
    ofstream benchmark_linked_file;
    benchmark_linked_file.open("benchmark_linked.txt");

    tm first_date = random_time(), second_date;
    do { second_date = random_time();} while (first_date>second_date);
    benchmark_linked_file << "Results with linked list:" << "\r\n";
    count = 10;
    while (count) {
        benchmark_clock = clock();

        linked_list* linked_sample = create_empty();
        linked_sample = create_random_list(count);
        vector<linked_list*> search_linked;
        search_linked = find_by_date(linked_sample, first_date);
        search_linked = find_by_interval(linked_sample, first_date, second_date);
        sort_list(linked_sample, false);
        do_some_function(linked_sample, some_function);

        benchmark_linked_file << count << ' ' << ((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) << "\r\n";
        cout << count << ' ' << ((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) << endl;

        if (((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) > 10) { break; }
        if (((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) < 1) {
            count = count * 2;
            count_sec = count;
        } else { count = count_sec/4 + count; }

    }
    ofstream benchmark_array_file;
    benchmark_array_file.open("benchmark_array.txt");
    benchmark_array_file << "Results with array list:" << "\r\n";
    count = 10;
    while (count) {
        benchmark_clock = clock();

        array_list* arr_sample = create_arr_empty();
        arr_sample = create_random_arr_list(count);
        vector<tm*> search;
        search = find_by_date_arr(arr_sample, first_date);
        search = find_by_interval_arr(arr_sample, first_date, second_date);
        sort_arr_list(arr_sample, false);
        do_some_function_arr(arr_sample, some_function);

        benchmark_array_file << count << ' ' << ((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) << "\r\n";
        cout << count << ' ' << ((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) << endl;

        if (((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) > 10) { break; }
        if (((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) < 1) {
            count = count * 2;
            count_sec = count;
        } else { count = count_sec + count; }

    }
    ofstream benchmark_btree_file;
    benchmark_btree_file.open("benchmark_btree.txt");
    benchmark_btree_file << "Results with binary search tree:" << "\r\n";
    count = 10;
    while (count) {
        benchmark_clock = clock();

        btree_node* btree_sample = create_empty_btree();
        btree_sample = create_random_btree(count);
        vector<btree_node*> search;
        find_by_date_btree(btree_sample, first_date);
        find_by_interval_btree(btree_sample, first_date, second_date, &search);
        search.clear();
        output_sorted_btree(btree_sample, false);
        do_some_function_btree(btree_sample, some_function);

        benchmark_btree_file << count << ' ' << ((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) << "\r\n";
        cout << count << ' ' << ((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) << endl;

        if (((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) > 10) { break; }
        if (((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) < 1) {
            count = count * 2;
            count_sec = count;
        } else { count = count_sec + count; }
    }
    ofstream benchmark_avltree_file;
    benchmark_avltree_file.open("benchmark_avltree.txt");
    benchmark_avltree_file << "Results with AVL tree:" << "\r\n";
    count = 10;
    while (count) {
        benchmark_clock = clock();

        avl_node* avl_sample = create_empty_avl();
        avl_sample = create_random_avl_tree(count);
        vector<avl_node*> search;
        find_by_date_avl(avl_sample, first_date);
        find_by_interval_avl(avl_sample, first_date, second_date, &search);
        search.clear();
        output_sorted_avl(avl_sample, false);
        do_some_function_avl(avl_sample, some_function);

        benchmark_avltree_file << count << ' ' << ((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) << "\r\n";
        cout << count << ' ' << ((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) << endl;

        if (((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) > 10) { break; }
        count += 100;
    }
    ofstream benchmark_23tree_file;
    benchmark_23tree_file.open("benchmark_23tree.txt");
    benchmark_23tree_file << "Results with 23 tree:" << "\r\n";
    count = 10;
    while (count) {
        benchmark_clock = clock();

        tt_tree* tt_sample = create_empty_tt();
        tt_sample = create_random_tt(count);
        vector<tt_tree*> search;
        find_by_date_tt(tt_sample, first_date);
        find_by_interval_tt(tt_sample, first_date, second_date, &search);
        search.clear();
        output_sorted_tt(tt_sample, false);
        do_some_function_tt(tt_sample, some_function);

        benchmark_23tree_file << count << ' ' << ((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) << "\r\n";
        cout << count << ' ' << ((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) << endl;

        if (((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) > 10) { break; }
        if (((double) (clock() - benchmark_clock) / CLOCKS_PER_SEC) < 1) {
            count = count * 2;
            count_sec = count;
        } else { count = count_sec + count; }
    }
}

int main() {
    srand(time(0));

    int mode;
    cout << "For interactive mode enter 1" << endl;
    cout << "For demonstration mode enter 2" << endl;
    cout << "For benchmark mode enter 3" << endl;
    cin>>mode;

    if (mode == 1) {interactive();}
    if (mode == 2) {demonstration();}
    if (mode == 3) {benchmark();}

    return 0;
}