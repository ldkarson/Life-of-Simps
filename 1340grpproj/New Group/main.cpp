/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <inputcheck.h>
#include <newgame.h>
#include <normalend1.h>
#include <palace.h>

using namespace std;

int menu(){
    
    string Line = "============================================================";
    int gamemode;
    
    cout << Line << endl;
    cout << "               " << "Welcome to Life of Simps" << endl;
    cout << Line << endl;
  
    cout << "1. New Game" << endl;
    cout << "2. Load Saves" << endl;
    cout << "3. Exit game" << endl;
    cout << endl;
    
    cin >> gamemode;
    
    return gamemode;

}

int main()
{
    int gamemode;
    char quit;
    gamemode = menu();
    
    if (gamemode == 1){
        newgame();
        cin >> flag;
        fresult = inputcheck(flag);
    
        if (fresult == 1){
            palace();
        }
    
        if (fresult == 0){
            normalend1();
        }
    }
    
    //if (gamemode == 2){
      //  loadsaves();
    //}
    //cout << "Gamemode : " << gamemode << endl;
    if (gamemode == 3){
        cout << "Are you sure to quit the game? - y/n?" << endl;
        cin >> quit;
        int result = inputcheck(quit);
        if (result == 1){
            return 0;
        }
        if (result == 0){
            main();
        }
        
    }
    
    return 0;
}
