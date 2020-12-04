#include "mbed.h"
//ascii commands
char play_pause_s[] = "AP\r\n";
char vol_up_s[] = "AV+\r\n";
char vol_dn_s[] = "AV-\r\n";
char next_s[] = "AT+\r\n";
char last_s[] = "AT-\r\n";
char name_s[] = "SN,";
char endcmd_s[] = "\r\n";

class RN52 {
    public:
        void init();
        void setPWREN(int val);
        void send_buff(char* buff);
        void play_pause();
        void vol_up();
        void vol_down();
        void next();
        void last();
        void set_name(char name);
        RN52();
        RN52(PinName TX, PinName RX, PinName PWREN_pin);
    private:
        DigitalOut PWREN;
        Serial rn52_serial;

};



// DEFAULT CONSTRUCTOR
RN52::RN52() : PWREN(p11), rn52_serial(p9, p10) { 
    //default serial pins are TX p9 RX p10
    //default PWREN is p11
    }

// CONSTRUCTOR
RN52::RN52(PinName PWREN_pin, PinName TX, PinName RX) : PWREN(PWREN_pin), rn52_serial(TX,RX) {
    
}
// SET PWREN VALUE
// Sets value of PWREN
// takes values of 0 [OFF] and 1 [ON]
void RN52::setPWREN(int val) {
    this->PWREN.write(val);
}

// INITIALIZATION FUNCTION
// Sets Power Enable to 1, Sets baud rate of serial object to 115200
void RN52::init() {
    PWREN.write(1);
    rn52_serial.baud(115200);
}

// SEND BUFFER FUNCTION
// Sends char buffer over serial using the putc() function of the Serial object
void RN52::send_buff (char *buff) {
    for(int i = 0; i < sizeof(buff); i++) {
            rn52_serial.putc(buff[i]); 
    }
}

// PLAY/PAUSE FUNCTION
// Sends "play/pause" ascii command over serial
// will toggle play/pause state
void RN52::play_pause() {
    this->send_buff(play_pause_s);
}



// VOLUME UP FUNCTION
// Sends "vol_up" ascii command over serial
void RN52::vol_up() {
    this->send_buff(vol_up_s);    
}

// VOLUME DOWN FUNCTION
// Sends "vol_dn" ascii command over serial
void RN52::vol_dn() {
    this->send_buff(vol_dn_s);
}

// NEXT TRACK FUNCTION
// Sends "next" ascii command over serial
void RN52::next() {
    this->send_buff(next_s);
}

// LAST TRACK FUNCTION
// Sends "last" ascii command over serial
void RN52::last() {
    this->send_buff(last_s);
}

// SET NAME FUNCTION
// sets the name of the bluetooth module that will show when pairing/connecting
void RN52::setname(char name) {
  this->send_buff(name_s);
  this->send_buff(name);
  this->send_buff(endcmd_s);
}
