#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Document
{
private:

public:
    vector<string> text;
    
    Document() : text() { cout << "created text" << endl;}
    Document(vector<string> d) : text(d){}
    ~Document() {}
    int get_last_line();
    int add_to_Doc(int p, int l);
    int change_rows(int l);
    void delete_row(int l);
    void swap_text(string string, int l);
    void join_rows(int l);

};
