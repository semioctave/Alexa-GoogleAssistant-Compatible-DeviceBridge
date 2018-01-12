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

___
