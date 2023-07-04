#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int savefile(int* player_hp, int* player_atk, int* player_level, int* player_gold, int* excalibur, int* necklace, int* stage) {
    
    ofstream fout;
    fout.open("save.txt");
    
    fout << *player_hp << " " << *player_atk << " " << *player_level << " " << *player_gold << " " << *excalibur << " " << *necklace << " " << *stage << endl;
    
    fout.close();
    
    if (fout.fail()){
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    

    return 0;
}
