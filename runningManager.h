#pragma once

public ref class RunningManager
{
public:
    bool isRunning;

    RunningManager();

    void Switch();

    void Set(bool value);
};
