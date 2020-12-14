#pragma once

#include <string>
#include <stdbool.h>
#include <iterator>
#include <iostream>
#include <fstream> 
#include "Document.h"


class Editor{

private:

public: 
    Document document;
    int curr_line;

    Editor() : curr_line(1), document() { cout << "creating editor" << endl; }
    Editor(string file_name) : curr_line(1) {
        string line;
        vector<string> tmp;
        ifstream myfile (file_name);
         if (myfile.is_open())
        {
         while ( getline (myfile,line) )
        {

            tmp.push_back(line+"\n");
        }
        if(tmp.size() > 0){
            document = tmp;
        }
        }
    } 
    ~Editor(){}
    void set_curr_line(int l){
        curr_line = l;
    }
    void loop(); 
    void jump_to_line(int line);
    void jump_to_last_line();
    void find_text(string txt, int l);
    void write_to_file(string file_name);
    void exit_editor();
};