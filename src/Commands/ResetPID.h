#ifndef ResetPID_H
#define ResetPID_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetPID: public CommandBase
{
public:
	ResetPID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
