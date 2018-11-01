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
    songs = nullptr;
}

UtPod::UtPod(int size)
{
    if (size > MAX_MEMORY || size < 0) {
        memSize = MAX_MEMORY;
    }
    else {
        memSize = size;
    }

    songs = nullptr;
}



int UtPod::numSongs()
{
    SongNode *temp = songs;
    int count = 1;
    if(temp == nullptr)
    {
        return 0;
    }
    while(temp->next != nullptr)
    {
        count++;
        temp = temp->next;
    }
    delete temp;
    return count;
}


int UtPod::addSong(Song const &s) {

    if(( memSize - s.getSize() ) < 0){
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
        if(songs->next == nullptr)
        {
            songs = nullptr;        // set next to nullptr
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
        if(curr->next != nullptr)
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
    if(curr->next == nullptr)
    {
        prev->next = nullptr;       // set the prev node to null (skip over tail node)
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
    unsigned int currentTime =  (unsigned)time(0);
    //
    cout << "current time " << currentTime << endl;

    srand(currentTime);  //seed the random number generator

    for (int i = 0; i < 2*numSongs(); i++) {
        long song1 = (rand());
        long song2 = (rand());
        cout << song1 << " + " << song2 << " = " << song1+song2 <<endl;

    }

}


void UtPod::showSongList()
{
    SongNode *pointer = songs;
    while(pointer != nullptr)
    {
        cout << pointer->s.getArtist() << " " << pointer->s.getTitle() << " " << pointer->s.getSize() << endl;
        pointer = pointer->next;
    }
}


void UtPod::sortSongList(){
        // Create new UtPod
        UtPod sorted;

        SongNode *head = this->songs;

        // Copy content of original UtPod to sorted UtPod
        while(head != nullptr)
        {
            sorted.addSong(head->s);
            head = head->next;
        }

        // Sort function
        head = sorted.songs;    // top of unsorted section of list
        SongNode *compare;      // everything of the unsorted section except for the top
        while(head->next != nullptr)
        {
            compare = head->next;
            while(compare != nullptr)
            {
                if(head->s > compare->s)        // if top of unsorted list > any node below it, swap
                { head->s.swap(compare->s); }
                compare = compare->next;
            }
            // after while loop is finished, head is now a sorted item
            head = head->next;                  // update sorted section of list
        }

        // Have original UtPod point to sorted list
        *this = sorted;
}


void UtPod::clearMemory(){}


int UtPod::getTotalMemory() {
    return memSize;
}

int UtPod::getRemainingMemory(){
    return MAX_MEMORY - memSize;
}

//UtPod::~UtPod(){}
