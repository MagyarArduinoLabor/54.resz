#include <Wire.h>
#include<I2Cdev.h>
#include<MPU6050.h>
 
MPU6050 mpu;
 
int16_t ax, ay, az;
int16_t gx, gy, gz;
 
#define pin1 3
#define pin2 5
 
void setup(){
 Serial.begin(9600);
 Serial.println("Initialize MPU");
 mpu.initialize();
 //Serial.println(mpu.testConnection() ? "Connected" : "Connection failed"); 
 pinMode(pin1,OUTPUT);
 pinMode(pin2,OUTPUT);
 
}
 
void loop(){
  
 mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
 
 ax = map(ax, -17000, 17000, -1500, 1500);
 
 //Serial.println(ax);
 if(ax > 0)
 {
   if(ax<255)
   {
    Serial.println(ax);
    analogWrite(pin2,ax);
   }
   else
   {
    Serial.println("+255");
    analogWrite(pin2,255);
   }
 }
 
 if(ax < 0)
 {
   if(ax>-255)
   {
    Serial.println(ax);
    analogWrite(pin1, ax-ax-ax);    
   }
   else
   {
    Serial.println("-255");
    analogWrite(pin1, 255);
   }
 }
 
 delay(1000);
}
