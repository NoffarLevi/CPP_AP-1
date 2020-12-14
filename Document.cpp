#include "Document.h" 
    
int Document::get_last_line(){

   return (text.size());

}
int Document::add_to_Doc(int p, int l){
    cout << "in add to doc" << endl;
    string rows;
    int count=0;
    if(p == 1){ 
        while(true){
    	cout << "in while add to doc" << endl;
        getline(cin,rows);
        if (rows != ".")
        {
           count++;
           cout << "in if" << endl;
           this->text.insert(text.begin()+l,rows+"\n");
           cout << "after insert" << endl;
           l+=1;
        }
        else{return count;}       
    }
    }
    else{
        l-=1;
        while(true){
        getline(cin,rows);
        if (rows != ".")
        {
           count++;
           this->text.insert(this->text.begin() + l,rows+"\n");
           l+=1;
        }
        else{return count;}
    }
}
}
int Document::change_rows(int l){

    this->text.erase(text.begin() + l - 1);
    return (add_to_Doc(-1,l));
}

void Document::delete_row(int l){
    this->text.erase(text.begin()+(l-1));
}

void Document::swap_text(string s, int l){
    vector<string> tmp;
    s.erase(s.begin(),s.begin()+2);  
    string delimiter = "/";

    size_t pos = 0;
    while ((pos = s.find(delimiter)) != string::npos) {
    tmp.push_back(s.substr(0, pos));
    s.erase(0, pos + delimiter.length());
} 
       string stnce = text.at(l-1);
       pos = 0;
       if(pos == (stnce.find(tmp.at(0))!= string::npos)){

           stnce.replace(pos, tmp.at(0).length(), tmp.at(1));
           text.at(l-1) = stnce;

       }else{

           cout << "Replacement word not found" << endl;
       }

}

void Document::join_rows(int l){

        if(l == text.size()){

            cout << "Error: Current is last line" << endl;
            return;

        }

        string addTo = text.at(l-1);
        addTo.erase(addTo.end()-1);
        string lineToJoin = text.at(l);

        string joinedLines = addTo + " " + lineToJoin;

        this->text.at(l-1) = joinedLines;
        this->text.erase(text.begin()+l);
}
