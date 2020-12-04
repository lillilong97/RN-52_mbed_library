#include "mbed.h"

class RN52 {
    public:
        void setPWREN(int pin); 
        void setSerial(int TX, int RX);
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

RN52::RN52() {
    //default serial pins are TX p9 RX p10
    //default PWREN is p11
    Serial rn52_serial(p9,p10);
    DigitalOut PWREN(p11);

}
RN52::RN52(int TX, int RX, int PWREN) {
    

}
//ascii commands
char play[] = "AP\r\n";
char vol_up[] = "AV+\r\n";
char vol_dn[] = "AV-\r\n";
char next[] = "AT+\r\n";
char last[] = "AT-\r\n";
char accept_call[] = "C\r\n";
char reject_call[] = "E\r\n";

void send_buff (char *buff, Serial rn52) {
    for(int i = 0; i < sizeof(buff); i++) {
            rn52.putc(buff[i]); 
    }
}


