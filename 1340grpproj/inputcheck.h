//
//  inputcheck.h
//  1340grpproj
//
//  Created by Karson Yip on 30/4/2022.
//

#ifndef inputcheck_h
#define inputcheck_h

#include <iostream>
#include <string>

using namespace std;

int inputcheck(char flag){
    int check = 0;
    while(check == 0){
        if (flag == 'y'){
            check = 1;
            return 1;
        }
        if (flag == 'n'){
            check = 1;
            return 0;
        }
        cout << "Invalid input, please input again! " << endl;
        cin >> flag;
    }
    return 0;
}



#endif /* inputcheck_h */
