// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
class DATA_API MultiThread :public FRunnable
{
public:
	MultiThread();
	~MultiThread();

	// Overriden from FRunnable
	// Do not call these functions youself, that will happen automatically

	bool Init() override; // Do your setup here, allocate memory, ect.
	uint32 Run() override; // Main data processing happens here
	void Stop() override; // Clean up any memory you allocated here


private:

	// Thread handle. Control the thread using this, with operators like Kill and Suspend
	FRunnableThread* Thread;

	// Used to know when the thread should exit, changed in Stop(), read in Run()
	bool bRunThread;
};
