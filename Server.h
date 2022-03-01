#include <iostream>
using namespace std;

class Server{
private:
    string month, hour, ip, serror;
    int day, port;

public:
    Server(string month = "none", int day = 0, string hour = "00:00", string ip = "000.000.000.0000", int port = 0, string serror = "--"){
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->ip = ip;
        this->port = port;
        this->serror = serror;
    }
        
    string getMonth();

    int getDay();

    int getPort();

    string getIP();
    
    string getError();

    int getAttacks();

    string setIp(string ip);

    int setAttacks(int attacks);

    bool operator == (const Server& serv){
        return (this->ip == serv.ip && this->port == serv.port);
    }

    bool operator == (const string& ip){
        return (this->ip == ip);
    }

    bool operator == (const int& port){
        return (this->port == port);
    }
    
    friend ostream& operator << (ostream & salida, const Server& server);
};

ostream& operator << (ostream& salida, const Server& server){
    salida << server.ip << endl;
    salida << server.port << endl;    
    return salida;
}

int Server::getPort(){
    return this->port;
}

string Server::getIP(){
    return this->ip;
}

string Server::getError(){
    return this->serror;
}

string Server::getMonth(){
    return this->month;
}

int Server::getDay(){
    return this->day;
}

