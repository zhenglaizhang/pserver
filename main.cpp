//
// Created by darinzh on 10/27/2015.
//

#include <iostream>
#include <string>
#include "my/str_algo.h"
#include "server/message_server.h"

using namespace std;
using namespace my;

int main(int argc, char *argv[]) {
    cout << my::to_upper_copy("hello world") << endl;
    cout << my::to_upper_copy("hello World") << endl;
}

