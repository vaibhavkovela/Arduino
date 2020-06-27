#include<Wire.h>
#include<MPU6050.h>
MPU6050 mpu;
unsigned long timer =0;
float timeStep=0.01;
float pitch =0;
float yaw =0;
float roll =0;
void setup()
{
  Serial.begin(115200);
  while(!mpu.begin(MPU6050_2000DPS,MPU6050_RANGE_2G))
  {
    Serial.println("could not find sensor!!");
    delay(1000);
  }
    Serial.println("Initialize MPU6050");
  mpu.calibrateGyro();
  mpu.setThreshold(3);
}
void loop()
{
  Vector normgyro =mpu.readNormalizeGyro();
  Vector normaccel =mpu.readNormalizeAccel();
  
}
