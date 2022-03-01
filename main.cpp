/*
A través de la función main, se recibe como argumento el nombre de un archivo de texto con registros de errores y ataques a una red.
El código analiza los archivos y extrae cierta información importante.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "hashTable.h"
#include "Server.h"
#include "ip.h"

using namespace std;

//O(n^2)
// Se imprimen las ip con más accessos ilegales
void topFive(vector<Server> Servidores){
  LinkedList<string> ipAttacks;
  LinkedList<string> complete;
  vector<ip> top;

	//O(n)
  for(int i = 0; i < Servidores.size(); i++){
    if(Servidores[i].getError() != "Failed password for admin"){
      ipAttacks.queue(Servidores[i].getIP());
      complete.queue(Servidores[i].getIP());
    }
  }

  //O(n^2)
  ipAttacks.remove_duplicates();

	//O(n^2) 
  for(int i = 0; i < ipAttacks.size(); i++){
    int count = complete.count(ipAttacks.get(i));
    top.push_back(ip(ipAttacks.get(i), count));
  }

  cout << "\n";

  //O(n^2)
  // Imitando bubble sort
  for (int i = 0; i < top.size(); i++){
    for (int j = 0; j < top.size() - 1; j++){
        if ((top[j].getAttacks() < top[j+1].getAttacks())){ 
            swap(top[j], top[j+1]);
        }
    }
  }

  //O(n)
  for(int k = 0 ; k < 5; k++){
    cout << top[k] << endl;
  }
}
//O(n^2)
// Se imprime la frecuencia con la que aparecen los mensajes de error
void frequencyMsg(vector<Server> Servidores){
  //LinkedList<string> ips;
  HashTable<string, int> errorMsg;

  for (int i = 0; i < Servidores.size(); i++){
    errorMsg.put(Servidores[i].getError());
  }

  for (int i = 0; i < Servidores.size(); i++){
    errorMsg.put(Servidores[i].getError(), errorMsg.get(Servidores[i].getError()) + 1);
  }

  errorMsg.printMessage();
	cout << "\n";
}

//O(n)
// Imprime el número de puertos diferentes atacados
void totalPorts(vector<Server> Servidores){
  vector<int> ports;
  for(int i = 0; i < Servidores.size(); i++){
      ports.push_back(Servidores[i].getPort());
  }

  LinkedList<int> duplicate;
  sort(ports.begin(), ports.end());
  for(int i = 1; i < ports.size(); i++){
      if(ports[i - 1] == ports[i]){
          duplicate.addLast(ports[i]);
      }
  }
	cout << "Total different attacked ports: " << ports.size() - duplicate.size() << endl;
}

// O(n^2)
void weekB(vector<Server> Servidores){
  string semanaMar1 = "Mar01";
	string semanaMar2 = "Mar02";
	string semanaMar3 = "Mar03";
	string semanaMar4 = "Mar04";

  string semanaAbr1 = "Abr01";
	string semanaAbr2 = "Abr02";
	string semanaAbr3 = "Abr03";
	string semanaAbr4 = "Abr04";

  string semanaMay1 = "May01";
	string semanaMay2 = "May02";
	string semanaMay3 = "May03";
	string semanaMay4 = "May04";
  string semanaMay5 = "May05";


  string semanaJun1 = "Jun01";
	string semanaJun2 = "Jun02";
	string semanaJun3 = "Jun03";
	string semanaJun4 = "Jun04";

  string semanaJul1 = "Jul01";
	string semanaJul2 = "Jul02";
	string semanaJul3 = "Jul03";
	string semanaJul4 = "Jul04";

  string semanaAug1 = "Aug01";
	string semanaAug2 = "Aug02";
	string semanaAug3 = "Aug03";
	string semanaAug4 = "Aug04";
  string semanaAug5 = "Aug05";

  string semanaSep1 = "Sep01";
	string semanaSep2 = "Sep02";
	string semanaSep3 = "Sep03";
	string semanaSep4 = "Sep04";
  string semanaSep5 = "Sep05";

	string semanaOct1 = "Oct01";
	string semanaOct2 = "Oct02";
	string semanaOct3 = "Oct03";
	string semanaOct4 = "Oct04";

	HashTable<string, int> weeks(1000);

  weeks.put(semanaMar1);
	weeks.put(semanaMar2);
	weeks.put(semanaMar3);
	weeks.put(semanaMar4);
  
  weeks.put(semanaAbr1);
	weeks.put(semanaAbr2);
	weeks.put(semanaAbr3);
	weeks.put(semanaAbr4);

  weeks.put(semanaMay1);
	weeks.put(semanaMay2);
	weeks.put(semanaMay3);
	weeks.put(semanaMay4);
  weeks.put(semanaMay5);

  weeks.put(semanaJun1);
	weeks.put(semanaJun2);
	weeks.put(semanaJun3);
	weeks.put(semanaJun4);

  weeks.put(semanaJul1);
	weeks.put(semanaJul2);
	weeks.put(semanaJul3);
	weeks.put(semanaJul4);

  weeks.put(semanaAug1);
	weeks.put(semanaAug2);
	weeks.put(semanaAug3);
	weeks.put(semanaAug4);
  weeks.put(semanaAug5);

  weeks.put(semanaSep1);
	weeks.put(semanaSep2);
	weeks.put(semanaSep3);
	weeks.put(semanaSep4);
  weeks.put(semanaSep5);

	weeks.put(semanaOct1);
	weeks.put(semanaOct2);
	weeks.put(semanaOct3);
	weeks.put(semanaOct4);

	int mar1 = 0;
  int mar2 = 0;
  int mar3 = 0;
  int mar4 = 0;

  int abr1 = 0;
  int abr2 = 0;
  int abr3 = 0;
  int abr4 = 0;

  int may1 = 0;
  int may2 = 0;
  int may3 = 0;
  int may4 = 0;
  int may5 = 0;

  int jun1 = 0;
  int jun2 = 0;
  int jun3 = 0;
  int jun4 = 0;

  int jul1 = 0;
  int jul2 = 0;
  int jul3 = 0;
  int jul4 = 0;

  int aug1 = 0;
  int aug2 = 0;
  int aug3 = 0;
  int aug4 = 0;
  int aug5 = 0;

  int sep1 = 0;
  int sep2 = 0;
  int sep3 = 0;
  int sep4 = 0;
  int sep5 = 0;

  int oct1 = 0;
  int oct2 = 0;
  int oct3 = 0;
  int oct4 = 0;


	for(int i = 0; i < Servidores.size(); i++){
    //<---------------Marzo--------------->
    if(Servidores[i].getMonth() == "Mar" && (2 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 8) && (Servidores[i].getError() != "Failed password for admin")){
      weeks.put(semanaMar1, mar1++);
    }
    if(Servidores[i].getMonth() == "Mar" && (9 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 15) && (Servidores[i].getError() != "Failed password for admin")){
      weeks.put(semanaMar2, mar2++);
    }
    if(Servidores[i].getMonth() == "Mar" && (16 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 22)&& (Servidores[i].getError() != "Failed password for admin")){
      weeks.put(semanaMar3, mar3++);
    }
    if(Servidores[i].getMonth() == "Mar" && (23 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 29) && (Servidores[i].getError() != "Failed password for admin")){
      weeks.put(semanaMar4, mar4++);
    }

    //<=---------------Abril--------------->
    if(Servidores[i].getMonth() == "Apr" && (1 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 5) || Servidores[i].getMonth() == "Mar" && (30 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 31) && (Servidores[i].getError() != "Failed password for admin")){
      weeks.put(semanaAbr1, abr1++);
    }
    if(Servidores[i].getMonth() == "Apr" && (6 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 12) && (Servidores[i].getError() != "Failed password for admin")){
      weeks.put(semanaAbr2, abr2++);
    }
    if(Servidores[i].getMonth() == "Apr" && (13 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 19) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaAbr3, abr3++);
    }
    if(Servidores[i].getMonth() == "Apr" && (20 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 26) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaAbr4, abr4++);
    }

    //<=---------------Mayo--------------->
    if(Servidores[i].getMonth() == "Apr" && (27 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 30) || Servidores[i].getMonth() == "May" && (1 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 3) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaMay1, may1++);
    }
    if(Servidores[i].getMonth() == "May" && (4 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 10) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaMay2, may2++);
    }
    if(Servidores[i].getMonth() == "May" && (11 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 17) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaMay3, may3++);
    }
    if(Servidores[i].getMonth() == "May" && (18 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 24) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaMay4, may4++);
    }
    if(Servidores[i].getMonth() == "May" && (25 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 31) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaMay5, may5++);
    }

    //<=---------------Junio--------------->
     if(Servidores[i].getMonth() == "Jun" && (1 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 7) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaJun1, jun1++);
    }
    if(Servidores[i].getMonth() == "Jun" && (8 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 14) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaJun2, jun2++);
    }
    if(Servidores[i].getMonth() == "Jun" && (15 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 21) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaJun3, jun3++);
    }
    if(Servidores[i].getMonth() == "Jun" && (22 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 28) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaJun4, jun4++);
    }

    //<=---------------Julio--------------->
    if(Servidores[i].getMonth() == "Jun" && (29 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 30) || Servidores[i].getMonth() == "Jul" && (1 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 5) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaJul1, jul1++);
    }
    if(Servidores[i].getMonth() == "Jul" && (6 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 12) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaJul2, jul2++);
    }
    if(Servidores[i].getMonth() == "Jul" && (13 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 19) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaJul3, jul3++);
    }
    if(Servidores[i].getMonth() == "Jul" && (20 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 26) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaJul4, jul4++);
    }

    //<=---------------Agosto--------------->
    if(Servidores[i].getMonth() == "Jul" && (27 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 30) || Servidores[i].getMonth() == "Aug" && (1 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 2) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaAug1, aug1++);
    }
    if(Servidores[i].getMonth() == "Aug" && (3 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 9) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaAug2, aug2++);
    }
    if(Servidores[i].getMonth() == "Aug" && (10 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 16) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaAug3, aug3++);
    }
    if(Servidores[i].getMonth() == "Aug" && (17 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 23) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaAug4, aug4++);
    }
    if(Servidores[i].getMonth() == "Aug" && (24 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 30)  && (Servidores[i].getError() != "Failed password for admin")){
      weeks.put(semanaAug5, aug5++);
    }

    //<=---------------Septiembre--------------->
    if(Servidores[i].getMonth() == "Aug" && (31 == Servidores[i].getDay()) || Servidores[i].getMonth() == "Sep" && (1 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 6) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaSep1, sep1++);
    }
    if(Servidores[i].getMonth() == "Sep" && (7 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 13) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaSep2, sep2++);
    }
    if(Servidores[i].getMonth() == "Sep" && (14 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 20) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaSep3, sep3++);
    }
    if(Servidores[i].getMonth() == "Sep" && (21 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 27) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaSep4, sep4++);
    }
    if(Servidores[i].getMonth() == "Sep" && (28 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 30) || Servidores[i].getMonth() == "Oct" && (1 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 4) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaSep5, sep5++);
    }

    //<=---------------Octubre--------------->
    if(Servidores[i].getMonth() == "Oct" && (5 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 11) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaOct1, oct1++);
    }
    if(Servidores[i].getMonth() == "Oct" && (12 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 18) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaOct2, oct2++);
    }
    if(Servidores[i].getMonth() == "Oct" && (19 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 25) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaOct3, oct3++);
    }
    if(Servidores[i].getMonth() == "Oct" && (26 <= Servidores[i].getDay()) && (Servidores[i].getDay() <= 31) && (Servidores[i].getError() != "Failed password for admin") ){
      weeks.put(semanaOct4, oct4++);
    }
  }

	vector<int> values = weeks.values();
  sort(values.begin(), values.end(), greater<int>());
  int max = values.front();

  weeks.printMaxByValue(max);
}

int main(int narguments, char * argumentos[] ) {

  if(narguments < 2){
    cerr << "Error por número de argumentos." << endl;
    exit(1);
  }

  string month, hour, ipPort, serror, line;
  int day, port, size = 0, tam = 0;

  string characterFileName(argumentos[1]);

  ifstream files(characterFileName);

  vector<Server> Servidores;

  while(getline(files, line)){
      stringstream iss(line);
      getline(iss,month, ' ');

      stringstream streamDay;
      streamDay << day;
      string strDay;
      streamDay >> strDay;

      getline(iss, strDay, ' ');
      getline(iss, hour, ' ');
      getline(iss, ipPort, ' ');
      getline(iss, serror);

      string ip(ipPort.substr(0, ipPort.find(":")));
      string strPort(ipPort.substr(ipPort.find(":")+1));
      day = stoi(strDay);
      port = stoi(strPort);

      Servidores.push_back(Server(month,day,hour,ip, port, serror));

  }
  files.close();


  //<----------Pregunta 1---------->
  cout << "Top 5 ip directions with most attacks: " << endl;
  cout << "\n";

	topFive(Servidores);
	
   //<----------Pregunta 2---------->
  cout << "Frequency of error messages: " << endl;
  cout << "\n";
  
  frequencyMsg(Servidores);

  //<----------Pregunta 3---------->
  cout << "How many different ports were attacked in total?" << endl;
 
  totalPorts(Servidores);

   //<----------Pregunta 4---------->
	cout << "\n";
  cout << "Week with the biggest illegal accesses: " << endl;
  cout << "\n";

  weekB(Servidores);

  return 0;

}