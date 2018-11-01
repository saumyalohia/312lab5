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

    //cout << "Hello World" << endl;

    UtPod t;

    Song s1("Panic! at the Disco", "Hey Look Ma I Made It", 51);
    Song s2("Bad Suns", "Salt", 5);
    Song s3("Coldplay", "Viva la Vida", 6);
    Song s4("Britney Spears", "Toxic", 5);
    Song s5("HONNE", "Day 1", 456);
    Song s6("Panic! at the Disco", "Old Fashioned", 6);


    //total memory
    int mem = t.getTotalMemory();
    cout << "Total Memory: " << mem << endl;

    // add 4 songs
    t.addSong(s1);
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s4);
    t.showSongList();
    cout << "-------------------------------------------" << endl;

    //remove 1 song
    t.removeSong(s4);
    t.showSongList();
    cout << "-------------------------------------------" << endl;

    //get remaining memory
    mem = t.getRemainingMemory();
    cout << "Remaining Memory: " << mem << endl;

    //try to add song 5 - should show error
    int result = t.addSong(s5);
    cout << "Result: " << result << endl;

    //add song 6
    result = t.addSong(s6);
    cout << "Result: " << result << endl;
    t.showSongList();
    cout << "-------------------------------------------" << endl;

    //sort
    t.sortSongList();

    //show song list
    t.showSongList();
    cout << "-------------------------------------------" << endl;

    //shuffle
    t.shuffle();

    //show song list
    t.showSongList();
    cout << "-------------------------------------------" << endl;

}
