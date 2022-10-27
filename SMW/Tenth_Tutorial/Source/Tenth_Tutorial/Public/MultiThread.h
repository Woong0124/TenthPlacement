// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TENTH_TUTORIAL_API MultiThread : public FRunnable
{
public:
	MultiThread();
	MultiThread(class ATenth_TutlrialGameModeBase* a);
	~MultiThread();

	bool Init() override;
	uint32 Run() override;
	void Stop() override;

private:
	FRunnableThread* Thread;

	class ATenth_TutlrialGameModeBase* MyGameModeBase;
	bool bRunThread;
};
