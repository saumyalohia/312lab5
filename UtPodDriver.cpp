//
// Created by Saumya Lohia and Vignesh Ravindranath on 10/26/18.
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
    // Create UtPods
    UtPod t;        // Playlist 1 // memSize = 512
    UtPod u(150);   // Playlist 2 //memSIze = 150

    //--------------------------------------------------------------------------------------//
    //--------------------------------------------------------------------------------------//

    // Song List: artist, title, size
    Song s1("Atlas Genius", "Molecules", 51);
    Song s2("Bad Suns", "Salt     ", 5);
    Song s3("Bad Suns", "Salt     ", 8);     // Extended version
    Song s4("Britney Spears", "Toxic    ", 5);
    Song s5("Coldplay", "Viva la Vida", 6);
    Song s6("HONNE", "Day 1    ", 496);
    Song s7("Maroon 5", "Payphone", 6);
    Song s8("Maroon 5", "Payphone", 12);     // Same song again


    Song s9("HuManiSmMMM");       // Testing other song functions
    s9.setArtist("Stay Human");
    s9.setSize(8);

    Song s10("Maroon 5", "Wait     ", 13);
    Song s11("Coldplay", "Clocks   ", 14);
    Song s12("Coldplay", "Technicolor", 5);

    //--------------------------------------------------------------------------------------//
    //--------------------------------------------------------------------------------------//

    int result;
    cout << "-------------------------------------------" << endl;

    //----------------------------------------TEST 1----------------------------------------//
    // Print out the total memory of the first

    result = t.getTotalMemory();
    cout << "Total Memory of first UtPod : " << result << "MB" << endl;
    result = u.getTotalMemory();
    cout << "Total Memory of second UtPod : " << result << "MB" << endl;
    cout << "-------------------------------------------" << endl;


    //----------------------------------------TEST 2----------------------------------------//
    // Add songs

    t.addSong(s1);  u.addSong(s3);
    t.addSong(s2);  u.addSong(s4);
    t.addSong(s3);  u.addSong(s7);
    t.addSong(s4);  u.addSong(s8);
    t.addSong(s5);  u.addSong(s9);

    cout << "Song list for Playlist1" << endl;
    cout << " " << endl;
    t.showSongList();
    cout << "-------------------------------------------" << endl;


    //----------------------------------------TEST 3----------------------------------------//
    // Remove song

    cout << "Remove the song 'Molecules' from Playlist1:" << endl;

    cout << "Updated playlist: " << endl;
    cout << " " << endl;
    result = t.removeSong(s1);
    t.showSongList();
    cout << " " << endl;
    cout << "Result: " << result << endl;

    cout << "\t-----------------" << endl;

    cout << "Try to remove song again: " << endl;
    cout << " " << endl;
    result = t.removeSong(s1);
    t.showSongList();
    cout << " " << endl;
    cout << "Result: " << result << endl;

    cout << "-------------------------------------------" << endl;


    //----------------------------------------TEST 4----------------------------------------//
    // Get remaining memory

    cout << "Get remaining memory of Playlist 1" << endl;
    result = t.getRemainingMemory();
    cout << "Remaining Memory: " << result << " MB left" << endl;

    cout << "-------------------------------------------" << endl;


    //----------------------------------------TEST 5----------------------------------------//
    // Add a very large song - should show error

    cout << "Add a large size song to Playlist1:" << endl;
    cout << " " << endl;
    t.showSongList();
    cout << " " << endl;
    result = t.addSong(s6);
    cout << "Result: " << result << endl;

    cout << "-------------------------------------------" << endl;


    //----------------------------------------TEST 6----------------------------------------//
    //add remaining songs

    cout << "Add more songs to Playlist1" << endl;
    cout << " " << endl;
    result = t.addSong(s7);
    result = t.addSong(s8);
    result = t.addSong(s9);
    result = t.addSong(s10);
    result = t.addSong(s11);
    result = t.addSong(s12);

    t.showSongList();

    cout << "-------------------------------------------" << endl;


    //----------------------------------------TEST 7----------------------------------------//
    // Sort

    cout << "Sorted playlist" << endl;
    cout << " " << endl;
    t.sortSongList();
    t.showSongList();

    cout << "-------------------------------------------" << endl;


    //----------------------------------------TEST 8----------------------------------------//
    // Shuffle

    cout << "Shuffled playlist" << endl;
    cout << " " << endl;
    t.shuffle();
    t.showSongList();

    cout << "\t-----------------" << endl;

    cout << "Shuffled playlist again" << endl;
    cout << " " << endl;
    t.shuffle();
    t.showSongList();

    cout << "-------------------------------------------" << endl;


    //----------------------------------------TEST 9----------------------------------------//
    // Add large song to Playlist 2

    cout << "Add large song to Playlist2 (150 MB)" << endl;
    cout << " " << endl;
    result = u.addSong(s6);
    cout << "Result: " << result << endl;


    //--------------------------------------------------------------------------------------//
    //--------------------------------------------------------------------------------------//
}