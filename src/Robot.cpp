#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/DriveWithJoystick.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;


	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new DriveWithJoystick();
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		Log();
	}

	void TestPeriodic()
	{
		lw->Run();
	}

	void Log(){
		SmartDashboard::PutNumber("Ultrasonic", CommandBase::driveTrain->GetFrontUltra());
		SmartDashboard::PutNumber("Left Motor Speed", CommandBase::driveTrain->GetSpeed(1));
		SmartDashboard::PutNumber("Right Motor Speed", CommandBase::driveTrain->GetSpeed(2));
		std::vector<double> v = CommandBase::driveTrain->GetPID();
		SmartDashboard::PutNumber("PID_P", v[0]); //P
		SmartDashboard::PutNumber("PID_I", v[1]); //I
		SmartDashboard::PutNumber("PID_D", v[2]); //D
	}
};

START_ROBOT_CLASS(Robot);

