#include "nu2api/nucore/NuInputDevice.h"
#include "nu2api/nucore/NuInputManager.h"
#include "nu2api/nucore/nupad.h"

NuInputManager *inputManager;

i32 NuPad_Interface_GetMaxDevices() {
    return inputManager->GetMaxDevices();
}

void NuPad_Interface_InputManagerUpdate(f32 delta_time) {
    inputManager->UpdateAll(delta_time);
}

u32 NuPad_Interface_NuPadRead(i32 port, u8 *analog_left_x, u8 *analog_left_y, u8 *analog_right_x, u8 *analog_right_y,
                              u8 *analog_l1, u8 *analog_l2, u8 *analog_r1, u8 *analog_r2, u32 *digital_buttons,
                              u8 *unknown, i32 *analog_button_flags) {
    NuInputDevice *device;

    device = inputManager->GetDevice(port);

    if (device == NULL) {
        return 0;
    }

    *analog_left_x = (device->GetAnalogValue(NUPADANALOGVALUE_LEFT_X) + 1.0f) * 127.0f;
    *analog_left_y = (device->GetAnalogValue(NUPADANALOGVALUE_LEFT_Y) + 1.0f) * 127.0f;
    *analog_right_x = (device->GetAnalogValue(NUPADANALOGVALUE_RIGHT_X) + 1.0f) * 127.0f;
    *analog_right_y = (device->GetAnalogValue(NUPADANALOGVALUE_RIGHT_Y) + 1.0f) * 127.0f;

    *analog_l1 = device->GetAnalogValue(NUPADANALOGVALUE_L1) * 127.0f;
    *analog_l2 = device->GetAnalogValue(NUPADANALOGVALUE_L2) * 127.0f;
    *analog_r1 = device->GetAnalogValue(NUPADANALOGVALUE_R1) * 127.0f;
    *analog_r2 = device->GetAnalogValue(NUPADANALOGVALUE_R2) * 127.0f;

    *digital_buttons = device->GetButtons();

    return device->IsConnected();
}

void NuPad_UpdateTouchScreenData() {
}
