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
    mpu.readSensor();

    Serial.println("---------------------");
    Serial.println(mpu.getAccelX_mss(),3);
    Serial.println(mpu.getAccelY_mss(),3);
    Serial.println(mpu.getAccelZ_mss(),3);
    // Serial.println(mpu.whoAmI());
}

