#include "runningManager.h"

RunningManager::RunningManager()
{
    isRunning = true;
}

void RunningManager::Switch()
{
    isRunning = !isRunning;
}

void RunningManager::Set(bool value)
{
    isRunning = value;
}