#include "OI.h"
#include "Commands/DriveForward.h"
#include "Commands/ResetPID.h"

OI::OI()
{
	joy = new Joystick(0);
	b1 = new JoystickButton(joy, 1);
	b1->WhenPressed(new DriveForward(10));
	b2 = new JoystickButton(joy, 2);
	b2->WhenPressed(new ResetPID());
}

Joystick* OI::GetJoy(){
	return joy;
}
