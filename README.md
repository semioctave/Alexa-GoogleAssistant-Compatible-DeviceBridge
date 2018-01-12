# Alexa-GoogleAssistant-Compatible-Multidevice

___
## Introduction
Making Smart-home IoT devices which can be controlled by both Alexa as well as Google home Assistant.
IoT device in this case will be made using NodeMCU

![maxresdefault](https://user-images.githubusercontent.com/34485667/34891764-cbb3a17e-f7fc-11e7-86fa-cc6db5132ce9.jpg)

Our Device will Communicate using MQTT Protocol , which is light message transfer protocol used for communication 
of various IoT devices we see is Market.

Those who don't know much about Mqtt Protocol can refer the PDF uploaded above to get basic insight of ,how the Protocol
works.

We will use Adafruit io as our Broker in Mqtt system ,which provides free Mqtt cloud based Broker Service and NodeMCU based
IoT device as client.

Further we will build Applets using IFTTT to Make Alexa & Google Assistant to control our IoT device

___

## Configuring Arduino IDE for ESP8266 based Dev Boards

Initially Arduino IDE dosen't have Addon by default ,so we have to install the Addons for Esp8266 based Boards using Arduino Board Manager.To begin, we’ll need to update the board manager with a custom URL. Open up Arduino, then go to the Preferences 
<b>(File > Preferences)</b>. Then, towards the bottom of the window, copy this URL into the “Additional Board Manager URLs” text box:

<pre> http://arduino.esp8266.com/stable/package_esp8266com_index.json </pre>


![arduino-board-manager-link](https://user-images.githubusercontent.com/34485667/34893687-62adaa8c-f804-11e7-9b83-b9fb8b594853.png)


Hit OK. Then navigate to the Board Manager by going to <b>Tools > Boards > Boards Manager</b>.There should be a couple new entries in addition to the standard Arduino boards. Look for <b>esp8266</b>. Click on that entry, then select <b>Install</b>.


![arduino-board-install](https://user-images.githubusercontent.com/34485667/34894102-0d901fc4-f806-11e7-8a04-c6e0be9259ae.png)

The board definitions and tools for the ESP8266 Thing include a whole new set of gcc, g++, and other reasonably large, compiled binaries, so it may take a few minutes to download and install (the archived file is ~110MB). Once the installation has completed, an Arduino-blue “INSTALLED” will appear next to the entry.

Now go on <b> Tools > Boards </b> and Scroll down and select <b> NodeMCU 1.0 (ESP 12-E Module) </b> .  


___

## Burning Code On Node MCU

First take above two libraries file provided by vendors itself which are Arduino & Adafruit and put them in the <b>Libraries</b>
folder inside your Arduino folder. 

Open mqtt.ino and Connect your NodeMCU to your computer and go to <b>tools > Port</b> 
and select COM port and compile & load the code to your dev. board

___
