//
// Created by Saumya Lohia on 10/26/18.
//

#include "song.h"

using namespace std;

Song::Song()
{
    title = "";
    artist = "";
    size = MAX_SIZE;
}

Song::Song(string title)
{
    this->title = title;
    artist = "";
    size = MAX_SIZE;
}

Song::Song(string _title, string _artist, int _size)
{
    title = _title;
    artist = _artist;
    size = _size;
}

string Song::getTitle() const
{
    return title;
}

void Song::setTitle(string t)
{
    title = t;
}

string Song::getArtist() const
{
    return artist;
}

void Song::setArtist(string a)
{
    artist = a;
}

int Song::getSize() const
{
    return size;
}

void Song::setSize(int s)
{
    this->size = s;
}

bool Song::operator >(Song const &rhs)
{
    return (size < rhs.size);
}

bool Song::operator ==(Song const &rhs)
{
    return(title == rhs.title &&
            artist == rhs.artist &&
            size == rhs.size);
}

bool Song::operator >(Song const &rhs)
{
    if(artist == rhs.artist)
    {
        if(title == rhs.title)
        { return (size > rhs.size); }
        else
        { return (title > rhs.title); }
    }
    else
    { return (artist > rhs.artist); }
}

bool Song::operator <(Song const &rhs)
{
    if(artist == rhs.artist)
    {
        if(title == rhs.title)
        { return (size < rhs.size); }
        else
        { return (title < rhs.title); }
    }
    else
    { return (artist < rhs.artist); }
}