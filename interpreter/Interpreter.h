#include <iostream>
#include <string>
#include <regex>

//1. Множественные пробелы;
//2. Использование дефиса вместо тире;
//3. Использование в качестве кавычек символов “”, тогда как стандартом является использование «»;
//4. Неправильное использование табуляторов
//5. Наличие «лишнего» пробела после открывающей скобки, перед закрывающей скобкой, перед запятой, перед точкой;
//6. Наличие множественных символов перевода строки


using namespace std;

class Spaces;
class Dashes;
class Quotes;
class Brackets;
class PunctuationAndSpaces;
class SlashNs;
class Tabs;


class TextInterpreter {
private:
    TextInterpreter *spaces;
    TextInterpreter *dashes;
    TextInterpreter *quotes;
    TextInterpreter *brackets;
    TextInterpreter *punctuationAndSpaces;
    TextInterpreter *slashNs;
    TextInterpreter *tabs;

protected:
    TextInterpreter(int i) {};

    virtual regex pattern_for_search() {
        return regex("");
    }
    virtual string pattern_for_replace() {
        return "";
    }

    virtual string true_interpret(string input) {
        string result;
        regex_replace (std::back_inserter(result), input.begin(), input.end(), pattern_for_search(), pattern_for_replace());
        return result;
    }

public:
    TextInterpreter();

    string interpret(string input) {
        input = slashNs->true_interpret(input);
        input = tabs->true_interpret(input);
        input = spaces->true_interpret(input);
        input = dashes->true_interpret(input);
        input = quotes->true_interpret(input);
        input = brackets->true_interpret(input);
        input = punctuationAndSpaces->true_interpret(input);
        return input;
    }
};

class Spaces : public TextInterpreter {
public:
    Spaces() : TextInterpreter(1) {}

protected:
    regex pattern_for_search() {
        return regex(" +");
    }

    string pattern_for_replace() {
        return " ";
    }
};

class Dashes : public TextInterpreter {
public:
    Dashes() : TextInterpreter(1) {}

protected:
    regex pattern_for_search() {
        return regex("\\s-\\s");
    }
    string pattern_for_replace() {
        return "—";
    }
};

class Quotes : public TextInterpreter {
public:
    Quotes() : TextInterpreter(1) {}

protected:
    virtual string true_interpret(string input) {
        string result1, result2;
        regex_replace (std::back_inserter(result1), input.begin(), input.end(), regex("„"), "«");
        regex_replace (std::back_inserter(result2), result1.begin(), result1.end(), regex("“"), "»");
        return result2;
    }
};

class Brackets : public TextInterpreter {
public:
    Brackets() : TextInterpreter(1) {}

protected:
    virtual string true_interpret(string input) {
        string result1, result2;
        regex_replace (std::back_inserter(result1), input.begin(), input.end(), regex("\\( "), "(");
        regex_replace (std::back_inserter(result2), result1.begin(), result1.end(), regex(" \\)"), ")");
        return result2;
    }
};


class PunctuationAndSpaces : public TextInterpreter {
public:
    PunctuationAndSpaces() : TextInterpreter(1) {}

protected:
    regex pattern_for_search() {
        return regex(" +([.,;:])");
    }
    string pattern_for_replace() {
        return "$1";
    }
};


class SlashNs : public TextInterpreter {
public:
    SlashNs() : TextInterpreter(1) {}

protected:
    regex pattern_for_search() {
        return regex("\\n+");
    }
    string pattern_for_replace() {
        return "\n";
    }
};


class Tabs : public TextInterpreter {
public:
    Tabs() : TextInterpreter(1) {}

protected:
    regex pattern_for_search() {
        return regex("\\t+");
    }
    string pattern_for_replace() {
        return "\t";
    }
};


TextInterpreter::TextInterpreter() {
    this->spaces = new Spaces();
    this->dashes = new Dashes();
    this->quotes = new Quotes();
    this->brackets = new Brackets();
    this->punctuationAndSpaces = new PunctuationAndSpaces();
    this->slashNs = new SlashNs();
    this->tabs = new Tabs();
}; // ctor for client
