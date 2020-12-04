#include "mbed.h"

//ascii commands
char play_s[] = "AP\r\n";
char vol_up_s[] = "AV+\r\n";
char vol_dn_s[] = "AV-\r\n";
char next_s[] = "AT+\r\n";
char last_s[] = "AT-\r\n";
char accept_call_s[] = "C\r\n";
char reject_call_s[] = "E\r\n";


class RN52 {
    public:
        void setPWREN(int pin); 
        void setSerial(int TX, int RX);
        void send_buff();
        void play();
        void pause();
        void vol_up();
        void vol_down();
        void next();
        void last();
        void accept_call();
        void reject_call();
        void end_call();
        RN52();
        RN52(int TX, int RX, int PWREN_pin);
    private:
        DigitalOut PWREN(int PWREN_pin);
        Serial rn52_serial(int TX, int RX);

};

// DEFAULT CONSTRUCTOR
RN52::RN52() {
    //default serial pins are TX p9 RX p10
    //default PWREN is p11
    Serial rn52_serial(p9,p10);
    DigitalOut PWREN(p11);

}

// CONSTRUCTOR
RN52::RN52(int TX, int RX, int PWREN_pin) {
    Serial rn52_serial(TX,RX);
    DigitalOut PWREN(PWREN_pin);

}

void RN52::send_buff (char *buff, Serial rn52) {
    for(int i = 0; i < sizeof(buff); i++) {
            rn52_serial.putc(buff[i]); 
    }
}

void RN52::play() {
    rn52_serial.send_buff(play)

}

