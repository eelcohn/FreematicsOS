#include <esp_log.h>	// Arduino ESP logging

#include "src/hardware/Accelerometer/Accelerometer.h"



void Accelerometer::begin() {

	if (!myIMU.init()) {
		Serial.println("ICM20948 does not respond");
	} else {
		Serial.println("ICM20948 is connected");
	}

	/*  This is a method to calibrate. You have to determine the minimum and maximum 
	 *  raw acceleration values of the axes determined in the range +/- 2 g. 
	 *  You call the function as follows: setAccOffsets(xMin,xMax,yMin,yMax,zMin,zMax);
	 *  The parameters are floats. 
	 *  The calibration changes the slope / ratio of raw acceleration vs g. The zero point is 
	 *  set as (min + max)/2.
	 */
	//myIMU.setAccOffsets(-16330.0, 16450.0, -16600.0, 16180.0, -16520.0, 16690.0);
    
	/* The starting point, if you position the ICM20948 flat, is not necessarily 0g/0g/1g for x/y/z. 
	 * The autoOffset function measures offset. It assumes your ICM20948 is positioned flat with its 
	 * x,y-plane. The more you deviate from this, the less accurate will be your results.
	 * It overwrites the zero points of setAccOffsets, but keeps the correction of the slope.
	 * The function also measures the offset of the gyroscope data. The gyroscope offset does not   
	 * depend on the positioning.
	 * This function needs to be called after setAccOffsets but before other settings since 
	 * it will overwrite settings!
	 * You can query the offsets with the function:
	 * xyzFloat getAccOffsets()
	 * You can apply the offset using:
	 * setAccOffsets(xyzFloat yourOffsets)
	 */
	Serial.print("Position your ICM20948 flat and don't move it - calibrating... ");
	delay(1000);
	myIMU.autoOffsets();
	Serial.println("done!"); 
  
	/* enables or disables the acceleration sensor, default: enabled */
	myIMU.enableAcc(true);

	// Set full scale range for the accelerometer to 2 g
	myIMU.setAccRange(ICM20948_ACC_RANGE_2G);
  
	/* Set the acceleration Digital Low Pass Filter */
	myIMU.setAccDLPF(ICM20948_DLPF_6);    
  
	/*  Set the acceleration sample rate divider */
	myIMU.setAccSampleRateDivider(10);

	/* Set the magnetometer mode to continuous measurements, 100Hz rate */
	myIMU.setMagOpMode(AK09916_CONT_MODE_20HZ);
 
	/* Set the gyroscope Digital Low Pass Filter */
	myIMU.setGyrDLPF(ICM20948_DLPF_6);  
 
	/* Set the temperature Digital Low Pass Filter */
	myIMU.setTempDLPF(ICM20948_DLPF_6);

}

void Accelerometer::update() {

	myIMU.readSensor();
	myIMU.getAngles(&angle);
	myIMU.getMagValues(&flux);
	myIMU.getGyrValues(&gyroscope);
	myIMU.getGValues(&g);
	myIMU.getAccRawValues(&acceleration_raw);
	myIMU.getCorrectedAccRawValues(&acceleration);
	acceleration_resultant = myIMU.getResultantG(&g);
	pitch = myIMU.getPitch();
	roll = myIMU.getRoll();
	temperature = myIMU.getTemperature();
}

void Accelerometer::calibrate() {

	myIMU.setAccOffsets(-16330.0, 16450.0, -16600.0, 16180.0, -16520.0, 16690.0);
	myIMU.setGyrOffsets(-115.0, 130.0, 105.0);
	myIMU.setAccRange(ICM20948_ACC_RANGE_2G); // highest res for calibration
	myIMU.setAccDLPF(ICM20948_DLPF_6); // lowest noise for calibration
	myIMU.setGyrRange(ICM20948_GYRO_RANGE_250); //highest resolution for calibration
	myIMU.setGyrDLPF(ICM20948_DLPF_6); // lowest noise for calibration
	myIMU.setTempDLPF(ICM20948_DLPF_6); // lowest noise for calibration
}
void Accelerometer::sleep() {

	/* Set the magnetometer to sleep mode */
	myIMU.setMagOpMode(AK09916_PWR_DOWN);
	delay(200);

	/* Set the ICM20948 to sleep mode */
	myIMU.sleep(true);
}

void Accelerometer::wakeup() {

	/* Wake up the ICM20948 */
	myIMU.sleep(false);
	delay(10);

	/* Wake up the magnetometer */
	myIMU.setMagOpMode(AK09916_CONT_MODE_20HZ);
	delay(200);
}
