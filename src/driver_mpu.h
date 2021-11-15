#ifndef _DRIVER_MPU_H_
#define _DRIVER_MPU_H_

#include "pin_define.h"

#include "MPU9250.h"

extern int16_t x, y, z;
extern int16_t ax, ay, az, gx, gy, gz, mx, my, mz;

void mpu_init();
void mpu_show();

#endif
