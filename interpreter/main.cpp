#include <iostream>
#include <string>
#include "Interpreter.h"

using namespace std;

int main() {
    TextInterpreter* interpreter = new TextInterpreter();
    string new_text = interpreter->interpret(
        "Sentence with     extra  symbols  of separation   . Correct-dash : toch'-v-toch' , wrong dash : "
        "ychenie - svet. Wrong „quotes“\n\n\t\t\t1. New line.\n\t\t\t\t\t2 . Second\n"
        "( Wrong Brackets )"
    );
    cout << new_text;
}
