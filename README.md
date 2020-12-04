# RN-52 Bluetooth Module MBED Library

## Module Description
The RN-52 Bluetooth Module ([data sheet](https://ww1.microchip.com/downloads/en/DeviceDoc/70005120A.pdf)) is an audio specific application Bluetooth trans-ceiver. The module uses the Bluetooth 3.0 protocol, but this does not pose compatibility issues as Bluetooth protocols are required to be backwards compatible. The module is optimized for audio transmission and outputs stereo audio, i.e. Left and Right channels. 

## Breakout Board Description

**Schematic of the RN-52 Breakout Board**

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

## Breakout Board Layout

<img src="https://i.imgur.com/liXEvN5.png" width="800" title="RN-52 Breakout Board Layout">

## Connector Pin Layout

![connector pinout](https://i.imgur.com/acJiQiz.png)

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


