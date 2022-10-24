// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRunnable.h"

MyRunnable::MyRunnable()
{
	MyThread = FRunnableThread::Create(this, TEXT("Newtwork Thread"));
}

MyRunnable::~MyRunnable()
{

}

bool MyRunnable::Init()
{
	return false;
}

uint32 MyRunnable::Run()
{
	return uint32();
}

void MyRunnable::Exit()
{

}

void MyRunnable::Stop()
{

}
