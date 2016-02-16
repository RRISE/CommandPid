#ifndef DriveForward_H
#define DriveForward_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveForward: public CommandBase
{
public:
	DriveForward(double displacement);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double displacement;
};

#endif
