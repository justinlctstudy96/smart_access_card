#include "driver_mpu.h"

MPU9250 mpu(0x69);

int16_t x, y, z;

void mpu_init()
{
    //INIT
    Wire.begin();
    mpu.initialize();

    //INT
    //set Interrupt Logic: 0 High  1 Low
    //set Interrupt Drive Output Mode: 0 push-pull  1 open-drain
    pinMode(PIN_MPU_INT, INPUT);
    mpu.setInterruptMode(0);
    mpu.setInterruptDrive(0);
    mpu.setInterruptLatch(1);

    mpu.setIntEnabled(B01000000);
    mpu.setIntMotionEnabled(true);
    mpu.setMotionDetectionThreshold(1);
    mpu.setMotionDetectionDuration(1);
}

void mpu_show()
{
    mpu.getAcceleration(&x, &y, &z);

    Serial.println(x);
    Serial.println(y);
    Serial.println(z);
    Serial.println(mpu.getIntFreefallStatus());
    Serial.println(digitalRead(PIN_MPU_INT));
}

void mpu_int_clear()
{
    mpu.setInterruptLatchClear(1);
}