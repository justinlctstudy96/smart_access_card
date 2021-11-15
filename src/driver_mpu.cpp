#include "driver_mpu.h"

MPU9250 mpu(Wire, 0x69);

int16_t x, y, z;

void mpu_init()
{
    Serial.print("MPU9250 Init : ");
    Serial.println(mpu.begin2());

    // mpu.setAccelRange(MPU9250::ACCEL_RANGE_8G);
    // mpu.setGyroRange(MPU9250::GYRO_RANGE_500DPS);
    // mpu.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
    // mpu.setSrd(19);

    //mpu.enableWakeOnMotion(500, MPU9250::LP_ACCEL_ODR_15_63HZ);
    mpu.enableWakeOnMotion(980, MPU9250::LP_ACCEL_ODR_7_81HZ);

    pinMode(PIN_MPU_INT, INPUT);
    delay(100);
}

void mpu_show()
{
    // mpu.getAcceleration(&x, &y, &z);
    mpu.getMotion9(&ax, &ay, &ax, &gx, &gy, &az, &mx, &my, &mz);
    Serial.println("acceleration: ");
    Serial.println(ax);
    Serial.println(ay);
    Serial.println(az);
    Serial.println("gyro: ");
    Serial.println(gx);
    Serial.println(gy);
    Serial.println(gz);
    Serial.println("magnetic: ");
    Serial.println(mx);
    Serial.println(my);
    Serial.println(mz);
    Serial.println(mpu.getIntFreefallStatus());
    Serial.println(digitalRead(PIN_MPU_INT));
}

