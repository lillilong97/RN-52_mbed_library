#include "mbed.h"
#include "RN52.h"
#include "PinDetect.h"

RN52 bt;

PinDetect playButton(p12);
PinDetect nextButton(p13);
PinDetect lastButton(p14);

void play_int() {
    bt.play_pause();
    wait(0.01);
}

void next_int() {
    bt.next();
    wait(0.01);
}

void last_int() {
    bt.last();
    wait(0.01);
}


int main() {
    
    bt.init();
    
    playButton.mode(PullUp);
    nextButton.mode(PullUp);
    lastButton.mode(PullUp);

    wait(0.01);

    playButton.attach_deasserted(&play_int);
    nextButton.attach_deasserted(&next_int);
    lastButton.attach_deasserted(&last_int);

    playButton.setSampleFrequency();
    nextButton.setSampleFrequency();
    lastButton.setSampleFrequency();


    while(1) {
        

    }


}
