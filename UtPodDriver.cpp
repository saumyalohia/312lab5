//
// Created by Saumya Lohia on 10/26/18.
//

/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
//#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World" << endl;

    UtPod t;

    Song s1("Beatles", "Hey Jude1", 4);
    Song s2("Beatles", "Hey Jude2", 5);
    Song s3("Beatles", "Hey Jude3", 6);
    Song s4("Beatles", "Hey Jude4", 7);
    Song s5("Beatles", "Hey Jude5", 241);
    Song s6("Beatles", "Hey Jude1", 6);

    t.addSong(s5);
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s1);
    t.addSong(s4);
    t.addSong(s6);

    cout << "-------------------------------------------" << endl;

    t.showSongList();

    t.sortSongList();
    cout << "-------------------------------------------" << endl;

    t.showSongList();

    cout << "-------------------------------------------" << endl;

    //t.clearMemory();
    //t.showSongList();
}
