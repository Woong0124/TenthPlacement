// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DATA_API MySocket :public FRunnable
{
public:
	MySocket();
	MySocket(class ADataGameModeBase* a);
	~MySocket();

	bool Init() override;
	uint32 Run() override;
	void Stop() override;

public:
	
	FRunnableThread* Thread;

	class ADataGameModeBase* MyGameModeBase;
	bool bRunThread;
};
