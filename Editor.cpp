#include "Editor.h"
using namespace std;


void Editor::loop(){

string command;
bool flag = true;
int t;
    while(flag){
        cout << "beginning of loop" << endl;
    getline(cin, command);

        switch(command[0]){

        case 1 ... 9: 

            this->curr_line = ((int)command[0]-48);
            break;
        
        case '+': 
            this->curr_line = (Editor::curr_line + ((int)command[1]-48));
            break;
        
        case '-': 
             this->curr_line = (Editor::curr_line - ((int)command[1]-48));
            break;
                
        case '$':
            this->curr_line = (this->document.get_last_line());
            break;

        case 'a':
        cout<< "in a" << " current line = " << this->curr_line << endl;
           t =  this->document.add_to_Doc(1, this->curr_line);
           this->curr_line += t;
            break;

        case '.':
            break;
        
        case 'i':
            t = this->document.add_to_Doc(-1, this->curr_line);
            this->curr_line += t - 1;
            break;
        
        case 'c':
            t = this->document.change_rows(this->curr_line);
            this->curr_line += t - 1;
            break;
        
        case 'd':
            this->document.delete_row(this->curr_line);
            this->curr_line = curr_line - 1;
            break;
        
        case '/':
            command.erase(command.begin());
            command.erase(command.end()-1); 
            this->find_text(command, this->curr_line);
            break;
        
        case 's': 
            command.erase(command.begin(),command.begin()+2);
            this->document.swap_text(command, this->curr_line);
            break;
        
        case 'j':
            this->document.join_rows(this->curr_line);
            break;
        
        case 'w': 
            command.erase(command.begin(), command.begin()+2);
            this->write_to_file(command);
            break;
        
        case 'q':
            flag = false;
            break;
        
        default:
            cout << "? Invalid Command" << endl ;
            break;
    }


}

}

    void jump_to_line(int line);
    void jump_to_last_line();

    void Editor::find_text(string txt, int l){

        if(l==1){

            for(int i=0; i<this->document.text.size(); i++){
                string row = this->document.text.at(i);
                if( row.find(txt)!= string::npos){
                    this->curr_line = i+1;
                    return;
                }            
            }
        }else{
            for(int i=l; i<this->document.text.size(); i++){
                string row = this->document.text.at(i);
                if( row.find(txt)!= string::npos){
                    this->curr_line = i+1;
                    return;
                }              
        }
            for(int i=0; i<l; i++){
                string row = this->document.text.at(i);
                if( row.find(txt)!= string::npos){
                    this->curr_line = i+1;
                    return;
                }              
        }       
    }
            cout << "Word not found" << endl;
}
    void Editor::write_to_file(string file_name){

        ofstream outfile(file_name);
        for(int i=0; i<this->document.text.size(); i++){
            outfile << this->document.text.at(i);
        }

        outfile.close();

    }
