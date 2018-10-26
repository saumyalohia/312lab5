//
// Created by Saumya Lohia on 10/26/18.
//

#ifndef UNTITLED3_SONG_H
#define UNTITLED3_SONG_H

#endif //UNTITLED3_SONG_H

#include <string>

using namespace std;

class Song {

private:
    string title;
    string artist;
    int size;

    static const int MAX_SIZE = 512;

public:
    Song();
    Song(string title);
    Song(string title, string artist, int size);

    string getTitle() const;
    void setTitle(string t);
    string getArtist() const;
    void setArtist(string a);
    int getSize() const;
    void setSize(int s);

    bool operator ==(Song const &rhs);
    /*
    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    */
};