# esp32-firebase-mitAppInventor-Valve-Control
This is a valve control project made using ESP32, firebase and MIT App Inventor

This is a valve control project made using ESP32, firebase and MIT App Inventor.
IOXhop firebase, Ticker and WiFi libraries were used in the project.
When the Open (1) command for a valve comes from the application, the valve_status value in the Realtime Database we created in firebase becomes 1 and the value of the GPIO pin we defined to open in Esp32 becomes HIGH and after remaining the same for the time we define, it becomes LOW. However, in Firebased, it continues to keep the valve_status value as 1. Thus, we see the status of the relevant valve as Open in the application.
Likewise, when we give the Close (0) command, the valve_status value in the firebase section becomes 0. The value of the GPIO pin we define to turn it off first becomes HIGH and after a certain period of time it becomes LOW. Firebased continues to keep the valve_status value at 0. And in the application, we see the status of the relevant valve as closed.

In order to examine the status of the ESP32's network connection and to prevent network failure, we send a true value for the connection every 1 second with the help of the ticker library. The test button I defined in the application changes the connection status to false and it says there is no connection in the application. If there is a connection, the data is updated to true in 1 second and it says there is a connection. If there is no connection, the value remains false.

MIT App Inventor Block Schema:
![block-schme-valve-control](https://github.com/tunahantatli/esp32-firebase-mitAppInventor-Valve-Control/assets/99608830/7ee668d9-f1c1-445a-8298-2676e4d7648d)

Mobil App User Interfaces:

![esp-32-valve-control-app](https://github.com/tunahantatli/esp32-firebase-mitAppInventor-Valve-Control/assets/99608830/51e97da5-4776-4315-9fb1-caff43d0dd9d)

This application is designed for a user in Turkey so its language is Turkish.
Vana 1,2 = Valve 1,2
Vanalar = Valves
Pompa = Pomp
Sıcaklık = Temperature
Nem = Humidity
Debi = Flow Rate
Su Seviye = Water Level ( For users using Irrigation Pool)
Bağlantı Testi = Network Test 
Bağlantı = Network
Cihaz Bağlantısı Yok = No Device Connection
Cihaz Bağlandı = Device Connected

You can develop your own valve control application using this code.
Do not hesitate to contact us with any problems.
https://tunahantatli.com
