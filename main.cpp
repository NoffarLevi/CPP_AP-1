#include <iostream>
#include "Editor.h"


int main(int argc, char *argv[]) {

    Editor editor;

        if(argc > 1){
        cout << "blah" << endl;
            editor = Editor(argv[1]);
        }

        editor.loop();

    return 0;
}