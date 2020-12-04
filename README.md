# RN-52 Bluetooth Module MBED Library

## Class Definition
```
class RN52 {
    public:
        void init();
        void setPWREN(int val);
        void setSerial(PinName TX, PinName RX);
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

```

## Constructors

### Default Constructor

`RN52 bt;`

By default, TX is set to p9, RX is set to p10, and PWREN is set to p11.
When the RN52 class is invoked without input arguments, these are the pins that will be set. 

### Constructor

`RN52 bt(TX,RX,PWREN);`

When the RN52 class is invoked with the above inputs (TX, RX, and PWREN being PinName variables),
the given TX and RX pins are used for Serial communications and the given PWREN pin will be
configured as the DigitalOut PWREN. 

### Member Data

`DigitalOut PWREN`

_PWREN_ 

PWREN is the Power Enable pin that must be held high to enable the RN52 module. If PWREN is not held
high, the module will not power on, even if it is being supplied with VDD.

`Serial rn52_serial`

_rn52\_serial_

rn52\_serial is a Serial object that controls the interface between the MBED and the RN-52 module.
This is configured with the TX and RX pins given in the constructor. 
The baud rate is set to 115200 baud, which is the given baud rate of the module in the data sheet. 

## Member Functions

### Initialize 

`void init()`

Initializes PWREN to 1 and sets the baud rate of the Serial object rn52\_serial. Should be invoked in
the main loop before any other commands are used.

### Set PWREN

`setPWREN(int val)`

Change value of PWREN. Useful if you need to put the module into hibernation without power cycling. 

**Note:** val should be either 0 or 1.

### Send Buffer

`send_buff(char* buff)`

Send a char[] buffer over UART to the RN-52. Useful to send commands that are not predefined
functions. 
More commands avaiable [here](https://ww1.microchip.com/downloads/en/DeviceDoc/50002154A.pdf). 

**Note:** All commands must end with `\r\n`, given by the `endcmd_s` variable in the header file. This
communicates the Carriage Return (`<CR>`) and the new line character. 

### Play/Pause

`play_pause()`

Sends the play/pause command to the RN-52 module.
This should play or pause the current track on the connected device. 

### Volume Up

`vol_up()`

Sends the volume up command to the RN-52 module.

**Note:** This command does not seem to be compatible with iOS devices, but works as expected with
Windows 10 computers. 

### Volume Down 

`vol_down()`

Sends the volume down command to the RN-52 module. 

**Note:** This command does not seem to be compatible with iOS devices, but works as expected with
Windows 10 computers. 

### Next Track

`next()`

Sends the next track command to the RN-52 module. 
This will skip to the next track on the connected device. 

### Last Track

`last()`

Sends the last track command to the RN-52 module.
This will skip to the previous track on the connected device.

### Set Name

`set_name(char name)`

Sets the name of the device to the desired char array. 
This is useful to more easily identify the module when pairing and connecting to the device. 

The default name is RN52-XXXX, where XXXX is the last four digits of the MAC address of the module. 


# RN-52 Bluetooth Daughter Board

## Module Description
The RN-52 Bluetooth Module ([data sheet](https://ww1.microchip.com/downloads/en/DeviceDoc/70005120A.pdf)) is an audio specific application Bluetooth trans-ceiver. The module uses the Bluetooth 3.0 protocol, but this does not pose compatibility issues as Bluetooth protocols are required to be backwards compatible. The module is optimized for audio transmission and outputs stereo audio, i.e. Left and Right channels. 

## Breakout Board Description

### Schematic of the RN-52 Breakout Board

<img src="https://i.imgur.com/FjV9205.png" width="800" title="RN-52 Breakout Board Schematic">


Shown here is the EAGLE schematic of the RN-52 breakout board. 
This breakout board makes use of the "Command Mode" of the RN-52 module, allowing it to be controlled over a UART connection by sending ASCII commands. 

### Pins Used but not Output 

<table>
  <tr>
    <th>Pin #</th>
    <th>Pin Name</th>
    <th>Description</th>
  </tr>
  <tr>
    <td>P2</td>
    <td>GPIO3</td>
    <td>Must be tied to GND through a 47k Resistor if not using USB interface
  <tr>
    <td>P11</td>
    <td>GPIO9</td>
    <td>Pull low to activate Command Mode</td>
  </tr>
  <tr>
    <td>P40,P41</td>
    <td>SPK_L-,SPK_R-</td>
    <td>Left and Right speaker reference lines tied to GND </td>
  </tr>
  <tr>
    <td>P37,P38</td>
    <td>MIC_L-,MIC_R-</td>
    <td>Microphone negative output, tied to GND (mistakenly)</td>
  </tr>
  <tr>
    <td>P32,P33</td>
    <td>LED1,LED2</td>
    <td>Indicator LEDS Blue and Red (respectively)</td>
  </tr>

  
</table>

### Pins Used by the Breakout Board
<table>
  <tr>
    <th>Pin #</th>
    <th>Pin Name</th>
    <th>Description</th>
  <tr> 
    <td>P3</td>
    <td>GPIO2</td>
    <td>Event Indicator (Active Low Output)</td>
  </tr>
  <tr>
    <td>P5</td>
    <td>GPIO4</td>
    <td>Reset Pin (Active Low Input)</td>
  </tr>
  <tr>
    <td>P14</td>
    <td>UART_RTS</td>
    <td>UART Ready to Send control flow (Active Low)</td>
  </tr>
  <tr>
    <td>P15</td>
    <td>UART_CTS</td>
    <td>UART Clear to Send control flow (Active Low)</td>
  </tr>
  <tr>
    <td>P16</td>
    <td>UART_TX</td>
    <td>UART Transmit (MISO)</td>
  </tr>
  <tr>
    <td>P17</td>
    <td>UART_RX</td>
    <td>UART Receive (MOSI)</td>
  </tr>
  <tr>
    <td>P21</td>
    <td>PWREN</td>
    <td>Power Enable (Active High)</td>
  </tr>
  <tr>
    <td>P22</td>
    <td>VDD</td>
    <td>3.3 V Power In</td>
  </tr>
  <tr>
    <td>P42,P43</td>
    <td>SPK_L+, SPK_R+</td>
    <td>Left and Right positive speaker outputs</td>
  </tr>
 
</table>

### Breakout Board Layout

<img src="https://i.imgur.com/liXEvN5.png" width="800" title="RN-52 Breakout Board Layout">

### Connector Pin Layout

![connector pinout](https://i.imgur.com/acJiQiz.png)

The connectors populated on the board are Molex Microfit 3.0 connectors, but the pin pitch is
compatible with standard header pins. 

The tables below show the pinout of each connector. The connectors are oriented such that the notch
on top is pointing toward the center of the board.

## Breakout Board Pinout

### Input (LEFT SIDE)

<table>
  <tr>
    <th>Pin #</th>
    <th>Pin Name</th>
  </tr>
  <tr>
    <td>1</td>
    <td>3V3</td>
  </tr>
  <tr>
    <td>2</td>
    <td>GND</td>
  </tr>
  <tr>
    <td>3</td>
    <td>RESET</td>
  </tr>
  <tr>
    <td>4</td>
    <td>PWREN</td>
  </tr>
  <tr>
    <td>5</td>
    <td>UART_RX</td>
  </tr>
  <tr>
    <td>6</td>
    <td>UART_TX</td>
  </tr>

</table>



### Output (RIGHT SIDE)

<table>
  <tr>
    <th>Pin #</th>
    <th>Pin Name</th>
  </tr>
  <tr>
    <td>1</td>
    <td>EVENT_IND</td>
  </tr>
  <tr>
    <td>2</td>
    <td>UART_TX</td>
  </tr>
  <tr>
    <td>3</td>
    <td>SPK_L+</td>
  </tr>
  <tr>
    <td>4</td>
    <td>SPK_R+</td>
  </tr>
  <tr>
    <td>5</td>
    <td>UART_RTS</td>
  </tr>
  <tr>
    <td>6</td>
    <td>MIC</td>
  </tr>

</table>


## Known Issues
1. Microphone output DOES NOT work. This is due to a misunderstanding of the microphone configuration based on unclear documentation.

2. R4 is unnecessary and the pads should be shorted together when assembled. 

3. UART Control Flow (RTS, CTS) pins are available, but I have been unable to figure out how to best utilize them with the MBED Serial library. 

4. LED indicators are included on the layout, but in the first prototype they did not work. It is unclear what the cause of this issue is at this time. 

5. Audio quality is not ideal because this board does not supply a differential output. Both channels, Left and Right, are referenced to ground instead of their differential counterparts. This was done for layout simplicity, but will likely be changed in future revisions. 


# Getting Started

## Hello World

```
#include "mbed.h"
#include "RN52.h"

RN52 bt;

int main() {

    bt.init();

    while (1) {

    }

}
```

This "Hello World" program will power on the RN-52 and allow you to connect to it from your device.
The while(1) loop is to prevent the MBED from doing weird things when the code is finished
executing. 

When you control the module from your device, the EVENT\_IND line will be pulled low every time it
executes a command. It's useful to connect an LED to this line. 
