#ifndef RASPBERRY_GPIO_H
#define RASPBERRY_GPIO_H

// WiringPi-Pin  BCM_GPIO  Name        Header   Name         BCM_GPIO WiringPi-Pin
//                         3.3V        1 | 2    5V    
// 8             2         SDA         3 | 4    5V
// 9             3         SCL         5 | 6    GND
// 7             4         GPIO07      7 | 8    TXD          14       15
//                         GND         9 | 10   RXD          15       16
// 0             17        GPIO0      11 | 12   GPIO1        18       1
// 2             27        GPIO2      13 | 14   GND
// 3             22        GPIO3      15 | 16   GPIO4        23       4
//                         3.3 V      17 | 18   GPIO5        24       5
// 12            10        MOSI       19 | 20   GND       
// 13            9         MISO       21 | 22   GPIO6        25       6
// 14            11        SCLK       23 | 24   CE0          8        10
//                         GND        25 | 26   CE1          7        11


// see http://images.google.de/imgres?imgurl=http://developer-blog.net/wp-content/uploads/2013/09/raspberry-pi-rev2-gpio-pinout.jpg&imgrefurl=https://developer-blog.net/raspberry-pi-gpio-schnittstelle-teil-1/&h=733&w=1050&tbnid=wABf20duBnHfxM:&vet=1&tbnh=90&tbnw=129&docid=xbe0QdcV74lIaM&client=ubuntu&usg=__zpQO9wqsJY58O4tgCed1OaoknLI=&sa=X&ved=0ahUKEwiMv86BvJrRAhUFjSwKHajFAOoQ9QEIKDAA

//      BCM_GPIO     WiringPi-Pin
#define BCM_GPIO_2   8             // GPIO 2
#define BCM_GPIO_3   9             // GPIO 3
#define BCM_GPIO_4   7             // GPIO 4
#define BCM_GPIO_17  0             // GPIO 17
#define BCM_GPIO_27  2             // GPIO 27
#define BCM_GPIO_22  3             // GPIO 3
#define BCM_GPIO_10  12            // GPIO 10
#define BCM_GPIO_9   13            // GPIO 9
#define BCM_GPIO_11  14            // GPIO 11
                                   
#define BCM_GPIO_14  15            // GPIO 14
#define BCM_GPIO_15  16            // GPIO 15
#define BCM_GPIO_18  1             // GPIO 18
#define BCM_GPIO_23  4             // GPIO 23
#define BCM_GPIO_24  5             // GPIO 24
#define BCM_GPIO_25  6             // GPIO 25
#define BCM_GPIO_8   10            // GPIO 8
#define BCM_GPIO_7   11            // GPIO 7

#endif