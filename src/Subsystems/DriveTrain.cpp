#include "DriveTrain.h"
#include "Commands/DriveWithJoystick.h"


DriveTrain::DriveTrain() :
PIDSubsystem("DriveTrain", 1.0, 0.0, 0.0)
{
	GetPIDController()->SetAbsoluteTolerance(0.05);
	GetPIDController()->SetContinuous(false);

	leftMotor1 = new CANTalon(LEFTMOTOR);
	rightMotor1 = new CANTalon(RIGHTMOTOR);
	robot = new RobotDrive(leftMotor1, rightMotor1);
	frontUltra = new AnalogInput(0);

	// initiate the PID, probs not needed
	SetSetpoint(0.0);
	Enable();
}

void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystick());
}


//PID
double DriveTrain::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	return GetEncoderValLeft();
}

void DriveTrain::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	//robot->Drive(output, 0.0);
	leftMotor1->PIDWrite(output);
	rightMotor1->PIDWrite(output);
}

void DriveTrain::ResetPID(){
	float p = Preferences::GetInstance()->GetDouble("PID_P", 1.0);
	float i = Preferences::GetInstance()->GetDouble("PID_I", 0.0);
	float d = Preferences::GetInstance()->GetDouble("PID_D", 0.0);
	GetPIDController()->SetPID(p, i, d);
}

std::vector<double> DriveTrain::GetPID(){
	std::vector<double> output(3);
	output[0] =	GetPIDController()->GetP();
	output[1] =	GetPIDController()->GetI();
	output[2] =	GetPIDController()->GetD();
	return output;
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::Drive(Joystick* joy){
	robot->ArcadeDrive(joy);
}

//get ultrasonic range in inches
double DriveTrain::GetFrontUltra(){
	return frontUltra->GetAverageVoltage() * ULTRASONIC_READING_TO_INCH / ULTRASONIC_SCALEFACTOR;
}


void DriveTrain::Drive(double displacement){
	SetSetpointRelative(displacement);
}

bool DriveTrain::IsTargetApproached(double err){
	return ((GetSetpoint() - ReturnPIDInput()) <= err);
}


//Encoders
double DriveTrain::GetEncoderValLeft(){
	double data = leftMotor1->GetPosition();
	double equation =2.0 * 3.141 * 3.0;

	return data * equation;
}

double DriveTrain::GetEncoderValRight(){
	double data = rightMotor1->GetPosition();
	double equation =2.0 * 3.141 * 3.0;

	return data * equation;
}


double DriveTrain::GetSpeed(int motor){
	switch(motor){
	case 1:
		return leftMotor1->GetSpeed();
		break;
	case 2:
		return rightMotor1->GetSpeed();
		break;
	default:
		return 999.99;//impossible value
	}
}

