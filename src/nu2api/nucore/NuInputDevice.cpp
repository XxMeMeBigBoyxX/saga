#include "nu2api/nucore/NuInputDevice.h"

#include <string.h>

#include "nu2api/numath/nufloat.h"

NuInputDevice::NuInputDevice(u32 port) {
    this->port = port;
    this->is_rumble_killed = false;

    this->prev_valid_type = NUPADTYPE_UNKNOWN_7;
    this->prev_valid_idx_by_type = 7;

    this->translators[0] = NULL;
    this->translators[1] = NULL;

    this->translator_count = 0;

    memset(&this->unknown_touch_data, 0, sizeof(NuInputTouchData));

    SetDisconnected();
    Clear();
}

void NuInputDevice::Update(f32 delta_time, bool emulate_touch) {
    u32 i;
    f32 raw_analog_values[12];
    f32 raw_motion_values[20];
    NuInputTouchData raw_touch_data;
    NuInputMouseData raw_mouse_data;

    this->is_connected = NuInputDevicePS::IsConnectedPS(this->port);
    if (!this->is_connected) {
        SetDisconnected();

        return;
    }

    this->type = NuInputDevicePS::GetTypePS(this->port);
    this->attch_type = NuInputDevicePS::GetAttachmentTypePS(this->port);

    this->caps = NuInputDevicePS::GetCapsPS(this->port);

    this->is_intercepted = NuInputDevicePS::IsInterceptedPS(this->port);

    if (!this->is_intercepted) {
        NuInputDevicePS::ReadButtonsPS(this->port, &this->button_states);
        NuInputDevicePS::ReadAnalogValuesPS(this->port, this->analog_values);
        NuInputDevicePS::ReadMotionValuesPS(this->port, this->motion_values);
        NuInputDevicePS::ReadTouchDataPS(this->port, &this->touch_data);
        NuInputDevicePS::ReadMouseDataPS(this->port, &this->mouse_data);

        DeadZone(NUPADANALOGVALUE_UNKNOWN_0, 0.2f);
        DeadZone(NUPADANALOGVALUE_UNKNOWN_1, 0.2f);
        DeadZone(NUPADANALOGVALUE_UNKNOWN_2, 0.2f);
        DeadZone(NUPADANALOGVALUE_UNKNOWN_3, 0.2f);

        DeadZone(NUPADANALOGVALUE_L1, 0.2f);
        DeadZone(NUPADANALOGVALUE_R1, 0.2f);
        DeadZone(NUPADANALOGVALUE_L2, 0.2f);
        DeadZone(NUPADANALOGVALUE_R2, 0.2f);

        DeadZone(NUPADANALOGVALUE_LEFT_X, 0.2f);
        DeadZone(NUPADANALOGVALUE_LEFT_Y, 0.2f);
        DeadZone(NUPADANALOGVALUE_RIGHT_X, 0.2f);
        DeadZone(NUPADANALOGVALUE_RIGHT_Y, 0.2f);

        if (emulate_touch && this->type == NUPADTYPE_MOUSE) {
            ConvertToEmulatedTouchFromMouse();
        }

        memcpy(&this->unknown_touch_data, &this->touch_data, sizeof(NuInputTouchData));

        memcpy(raw_analog_values, this->analog_values, sizeof(this->analog_values));
        memcpy(raw_motion_values, this->motion_values, sizeof(this->motion_values));
        memcpy(&raw_touch_data, &this->touch_data, sizeof(NuInputTouchData));
        memcpy(&raw_mouse_data, &this->mouse_data, sizeof(NuInputMouseData));

        if (this->type == NUPADTYPE_TOUCH) {
            for (i = 0; i < this->translator_count; i++) {
                this->translators[i]->Execute(this->port, this->type, this->attch_type, this->caps, this->button_states,
                                              raw_analog_values, raw_motion_values, &raw_touch_data, &raw_mouse_data,
                                              this->type, this->attch_type, this->caps, this->button_states,
                                              this->analog_values, this->motion_values, &this->touch_data,
                                              &this->mouse_data);
            }
        } else if (this->type == NUPADTYPE_UNKNOWN_6) {
            NUPADTYPE out_type;
            NUPADATTACHMENTTYPE out_attch_type;
            f32 out_analog_values[12];
            f32 out_motion_values[20];
            u32 out_caps;
            u32 out_button_states;

            for (i = 0; i < this->translator_count; i++) {
                this->translators[i]->Execute(this->port, this->type, this->attch_type, this->caps, this->button_states,
                                              raw_analog_values, raw_motion_values, &raw_touch_data, &raw_mouse_data,
                                              out_type, out_attch_type, out_caps, out_button_states, out_analog_values,
                                              out_motion_values, &this->touch_data, &this->mouse_data);
            }
        }
    } else {
        Clear();
    }

    this->prev_valid_type = this->type;

    if (this->motor_1 > 0.0f || this->motor_2 > 0.0f) {
        this->rumble_time_elapsed += delta_time;

        if (this->rumble_time_elapsed > 7.0f && this->rumble_cooldown == 0.0f) {
            this->rumble_cooldown = 2.0f;
            this->rumble_time_elapsed = 0.0f;
        }
    } else {
        this->rumble_time_elapsed -= NuFmax(delta_time, 0.5f);
        if (this->rumble_time_elapsed < 0.0f) {
            this->rumble_time_elapsed = 0.0f;
        }
    }

    if (this->rumble_cooldown > 0.0f || this->is_rumble_killed || this->is_intercepted) {
        NuInputDevicePS::SetMotorsPS(this->port, 0.0f, 0.0f);

        this->rumble_cooldown -= delta_time;
        if (this->rumble_cooldown < 0.0f) {
            this->rumble_cooldown = 0.0f;
        }

        this->is_rumble_killed = false;
    } else {
        NuInputDevicePS::SetMotorsPS(this->port, this->motor_1, this->motor_2);
    }

    this->has_headphones_connected = NuInputDevicePS::HasHeadphonesConnectedPS(this->port);
    this->volume = NuInputDevicePS::GetVolumePS(this->port);
}

void NuInputDevice::AddTranslator(NuInputDeviceTranslator *translator) {
    this->translators[this->translator_count] = translator;
    this->translator_count++;
}

bool NuInputDevice::IsConnected(void) const {
    return this->is_connected;
}

f32 NuInputDevice::GetAnalogValue(NUPADANALOGVALUE input) const {
    if (IsConnected()) {
        return this->analog_values[input];
    }

    return 0.0f;
}

u32 NuInputDevice::GetButtons(void) const {
    if (IsConnected()) {
        return this->button_states;
    }

    return 0;
}

NUPADTYPE NuInputDevice::GetType(void) const {
    return this->type;
}

void NuInputDevice::SetIndexByType(u32 idx_by_type) {
    this->idx_by_type = idx_by_type;
    this->prev_valid_idx_by_type = idx_by_type;
}

void NuInputDevice::SetDisconnected(void) {
    this->motor_1 = 0.0f;
    this->motor_2 = 0.0f;

    this->rumble_time_elapsed = 0.0f;

    this->is_connected = false;
    this->type = NUPADTYPE_UNKNOWN_7;
    this->idx_by_type = 0;

    this->caps = 0;

    this->is_intercepted = false;
    this->has_headphones_connected = false;

    this->rumble_cooldown = 0.0f;

    this->volume = 0.0f;
}

void NuInputDevice::Clear(void) {
    i32 i;

    this->button_states = 0;

    // ORIG_BUG: The full arrays are not zeroed. Mistaken division by
    // `sizeof(f32)` is a plausible explanation.
    memset(this->analog_values, 0, sizeof(this->analog_values) / sizeof(f32));
    memset(this->motion_values, 0, sizeof(this->motion_values) / sizeof(f32));

    memset(&this->touch_data, 0, sizeof(NuInputTouchData));
    memset(&this->mouse_data, 0, sizeof(NuInputMouseData));
}

void NuInputDevice::DeadZone(NUPADANALOGVALUE input, f32 dead_zone) {
    f32 value;
    f32 new_value;

    value = this->analog_values[input];

    if (value > dead_zone) {
        new_value = (value - dead_zone) / (1.0f - dead_zone);
    } else if (!(value < -dead_zone)) {
        new_value = 0.0f;
    } else {
        new_value = (value + dead_zone) / (1.0f - dead_zone);
    }

    this->analog_values[input] = new_value;
}

void NuInputDevice::ConvertToEmulatedTouchFromMouse(void) {
}
