#ifndef DRIVE_TRAIN_H
#define	DRIVE_TRAIN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include <vector>

class DriveTrain: public PIDSubsystem
{
private:
	RobotDrive* robot;
	CANTalon* leftMotor1;
	CANTalon* rightMotor1;
	AnalogInput* frontUltra;

public:
	DriveTrain();
	void InitDefaultCommand();

	/* PID */
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	bool IsTargetApproached(double err);
	void ResetPID();
	std::vector<double> GetPID();

	/* control */
	void Drive(Joystick* joy);
	void Drive(double displacement);

	/* sensors */
	double GetEncoderValRight();
	double GetEncoderValLeft();
	double GetFrontUltra();
	// motor 1 = left, 2 = right
	double GetSpeed(int motor);
};

#endif
