#ifndef loadfile_h
#define loadfile_h
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int loadfile(int* player_hp, int* player_atk, int* player_level, int* player_gold, int* excalibur, int* necklace, int* stage){
   char filename[100] = "save.txt";
   ifstream fin;
   fin.open(filename);

   fin >> *player_hp >> *player_atk >> *player_level >> *player_gold >> *excalibur >> *necklace >> *stage;
    fin.close();
    
    cout << "Loaded data: HP: " << *player_hp << " ATK: " << *player_atk << " Level: " << *player_level << " Gold: " << *player_gold << "G" << " Stage: " << *stage << endl;
    
   return 0;
 }


#endif /* loadfile_h */


