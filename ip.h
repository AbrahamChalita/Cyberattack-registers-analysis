#include <iostream>
using namespace std;

class ip{

private:
    string label;
    int attacks;
public:
    ip(string label = "none", int attacks = 0){
        this->label = label;
        this->attacks = attacks;
    }

    string getLabel();

    int getAttacks();

    bool operator == (const string& label){
        return (this->label == label);
    }

    bool operator == (const int& attack){
        return (this->attacks == attack);
    }

    friend ostream& operator << (ostream & salida, const ip& ip);
};

ostream& operator << (ostream& salida, const ip& ip){
        salida << "Ip address: " << ip.label << endl;
		salida << "Total attacks: " << ip.attacks << endl;
    return salida;
}

string ip::getLabel(){
    return this->label;
}

int ip::getAttacks(){
    return this->attacks;
}