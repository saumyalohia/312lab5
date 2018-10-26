//
// Created by Saumya Lohia on 10/26/18.
//

#include "UtPod.h"

using namespace std;

UtPod(int size){
    if (size > MAX_MEMORY || size < 0) {
        memSize = MAX_MEMORY;
    }
    else {
        memSize = size;
    }
}

int UtPod::addSong(Song const &s) {}


int UtPod::removeSong(Song const &s) {}


void UtPod::shuffle(){}


void UtPod::showSongList(){}


void UtPod::sortSongList(){}


void UtPod::clearMemory(){}


int UtPod::getTotalMemory() {
    return memSize;
}

int UtPod::getRemainingMemory{}