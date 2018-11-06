//
// Created by Saumya Lohia on 10/26/18.
//

#include "UtPod.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

UtPod::UtPod()
{
    memSize = MAX_MEMORY;
    totSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size)
{
    if (size > MAX_MEMORY || size < 0) {
        memSize = MAX_MEMORY;
        totSize = MAX_MEMORY;
    }
    else {
        memSize = size;
        totSize = size;
    }

    songs = NULL;
}



int UtPod::numSongs()
{
    SongNode *temp = songs;
    int count = 1;
    if(temp == NULL)
    {
        return 0;
    }
    while(temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void Song::swap(Song &s2)
{
    Song temp = s2;
    s2 = *this;
    *this = temp;
}


int UtPod::addSong(Song const &s) {

    if(( memSize - s.getSize() ) <= 0){
        // Not enough memory
        return NO_MEMORY;
    }else{
        // Enough memory, so we can add song

        SongNode *temp = new SongNode();    // create temporary node
        temp->s = s;
        temp->next = songs;
        songs = temp;

        memSize -= s.getSize();             // update memory size left
        //printf("%d\n", memSize);
        return SUCCESS;
    }
}


int UtPod::removeSong(Song const &s) {

    // When song to delete is the head node
    if(songs->s == s)
    {
        // True so update memory
        memSize += s.getSize();
        SongNode *temp = songs;

        // When song to delete is the only node in the list
        if(songs->next == NULL)
        {
            songs = NULL;        // set next to NULL
            delete temp;

            return SUCCESS;
        }

        // When song to delete is not the only node in the list
        songs = songs->next;        // skip over node to delete
        delete temp;

        return SUCCESS;
    }


    // When song to delete is not the head node
    SongNode *curr = songs;
    SongNode *prev = new SongNode();

    // while the song to delete has not been found...
    while(!(curr->s == s))
    {
        // keep incrementing curr and prev until found
        if(curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        else
        {
            // All songs in the list do not equal input song to delete (or has already been deleted)
            return NO_MEMORY;
        }
    }

    // When song to delete is found...
    // update memory
    memSize += s.getSize();

    // If the node to delete is the tail node (points to null)
    if(curr->next == NULL)
    {
        prev->next = NULL;       // set the prev node to null (skip over tail node)
        delete curr;

        return SUCCESS;
    }
    // If the node to delete is another node (points to something)
    else
    {
        prev->next = curr->next;    // skip over node to delete
        delete curr;

        return SUCCESS;
    }
}

void UtPod::shuffle(){

    if (numSongs() < 2) {
        return;
    }

    unsigned int currentTime =  (unsigned)time(0);
    //unsigned int currentTime =  16;
    SongNode *head;
    //cout << "current time " << currentTime << endl;

    srand(currentTime);  //seed the random number generator

    //showSongList();

    for (int i = 0; i < 2*numSongs(); i++) {

        long song1 = (rand() % numSongs()) + 1;
        long song2 = (rand() % numSongs()) + 1;
        //long song1 = 1;
        //long song2 = 3;
        //cout << song1 << " + " << song2 << " = " << song1+song2 <<endl;

        SongNode *p1;
        SongNode *p2;

        head = this->songs;

        for (int i = 1; i < song1; i++) {
            head = head->next;
        }

        p1 = head;

        //cout << p1->s.getTitle() << endl;

        head = this->songs;

        for (int i = 1; i < song2; i++) {
            head = head->next;
        }

        p2 = head;

        //cout << p2->s.getTitle() << endl;

        p1->s.swap(p2->s);

    }

    //cout << "Hello world" << endl;

}


void UtPod::showSongList()
{
    SongNode *pointer = songs;
    while(pointer != NULL)
    {
        cout << pointer->s.getArtist() << " " << pointer->s.getTitle() << " " << pointer->s.getSize() << endl;
        pointer = pointer->next;
    }
}


void UtPod::sortSongList(){

    if (numSongs() < 2) {
        return;
    }
    SongNode *head = this->songs;


    // Sort function
    SongNode *compare;      // everything of the unsorted section except for the top
    while(head->next != NULL)
    {
        compare = head->next;
        while(compare != NULL)
        {
            if(head->s > compare->s)        // if top of unsorted list > any node below it, swap
            { head->s.swap(compare->s); }
            compare = compare->next;
        }
        // after while loop is finished, head is now a sorted item
        head = head->next;                  // update sorted section of list
    }

    // Have original UtPod point to sorted list
}


void UtPod::clearMemory(){
    SongNode *temp;

    if (songs == NULL) {
        return;
    }
    while(songs->next != NULL)
    {
        temp = songs;
        songs = songs->next;
        delete temp;
    }

    if(songs->next == NULL)
    {
        temp = songs;
        songs = NULL;
        delete temp;
    }
}


int UtPod::getTotalMemory() {
    return totSize;
}

int UtPod::getRemainingMemory(){
    return memSize;
}

UtPod::~UtPod(){
    clearMemory();
}
