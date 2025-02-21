#include <raylib.h>
#include "../include/baseCommands.h"

void ToggleFullscreenWindow(int windowWidth, int windowHeight) {

    if(!IsWindowFullscreen()) {
        int monitor = GetCurrentMonitor();
        SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
        ToggleFullscreen();
    } else {
        ToggleFullscreen();
        SetWindowSize(windowWidth, windowHeight);
    }
}

int GetDisplayWidth() {
    if (IsWindowFullscreen()) {
        int monitor = GetCurrentMonitor();
        return GetMonitorWidth(monitor);
    } else {
        return GetScreenWidth();
    }
}

int GetDisplayHeight() {
    if (IsWindowFullscreen()) {
        int monitor = GetCurrentMonitor();
        return GetMonitorHeight(monitor);
    } else {
        return GetScreenHeight();
    }
}