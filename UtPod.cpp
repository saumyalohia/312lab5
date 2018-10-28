//
// Created by Saumya Lohia on 10/26/18.
//

#include "UtPod.h"

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

    if(songs == nullptr){
        // No songs in UtPod
        return NO_MEMORY;
    }else {
        // Song is there can delete last song added

        memSize += s.getSize();         // Update memory size

        SongNode *temp = songs;
        songs = songs->next; // Skip previous node
        delete temp;

        return SUCCESS;
    }
}


void UtPod::shuffle(){}


void UtPod::showSongList(){}


void UtPod::sortSongList(){}


void UtPod::clearMemory(){}


int UtPod::getTotalMemory() {
    return memSize;
}

int UtPod::getRemainingMemory(){
    return MAX_MEMORY - memSize;
}


