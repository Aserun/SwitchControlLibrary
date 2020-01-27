#include "SwitchControlLibrary.h"

#if defined(_USING_HID)

static const uint8_t _hidReportDescriptor[] PROGMEM = {
    0x05, 0x01,       //   USAGE_PAGE (Generic Desktop)
    0x09, 0x05,       //   USAGE (Game Pad)
    0xa1, 0x01,       //   COLLECTION (Application)
    0x15, 0x00,       //   LOGICAL_MINIMUM (0)
    0x25, 0x01,       //   LOGICAL_MAXIMUM (1)
    0x35, 0x00,       //   PHYSICAL_MINIMUM (0)
    0x45, 0x01,       //   PHYSICAL_MAXIMUM (1)
    0x75, 0x01,       //   REPORT_SIZE (1)
    0x95, 0x10,       //   REPORT_COUNT (16)
    0x05, 0x09,       //   USAGE_PAGE (Button)
    0x19, 0x01,       //   USAGE_MINIMUM (1)
    0x29, 0x10,       //   USAGE_MAXIMUM (16)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x05, 0x01,       //   USAGE_PAGE (Generic Desktop)
    0x25, 0x07,       //   LOGICAL_MAXIMUM (7)
    0x46, 0x3b, 0x01, //   PHYSICAL_MAXIMUM (315)
    0x75, 0x04,       //   REPORT_SIZE (4)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x65, 0x14,       //   UNIT (20)
    0x09, 0x39,       //   USAGE (Hat Switch)
    0x81, 0x42,       //   INPUT (Data,Var,Abs)
    0x65, 0x00,       //   UNIT (0)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x81, 0x01,       //   INPUT (Cnst,Arr,Abs)
    0x26, 0xff, 0x00, //   LOGICAL_MAXIMUM (255)
    0x46, 0xff, 0x00, //   PHYSICAL_MAXIMUM (255)
    0x09, 0x30,       //   USAGE (X)
    0x09, 0x31,       //   USAGE (Y)
    0x09, 0x32,       //   USAGE (Z)
    0x09, 0x35,       //   USAGE (Rz)
    0x75, 0x08,       //   REPORT_SIZE (8)
    0x95, 0x04,       //   REPORT_COUNT (4)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x06, 0x00, 0xff, //   USAGE_PAGE (Vendor Defined 65280)
    0x09, 0x20,       //   USAGE (32)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x0a, 0x21, 0x26, //   USAGE (9761)
    0x95, 0x08,       //   REPORT_COUNT (8)
    0x91, 0x02,       //   OUTPUT (Data,Var,Abs)
    0xc0              // END_COLLECTION
};

SwitchControlLibrary_::SwitchControlLibrary_()
{
    static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
    CustomHID().AppendDescriptor(&node);

    memset(&_joystickInputData, 0, sizeof(USB_JoystickReport_Input_t));
    _joystickInputData.LX = Stick::CENTER;
    _joystickInputData.LY = Stick::CENTER;
    _joystickInputData.RX = Stick::CENTER;
    _joystickInputData.RY = Stick::CENTER;
    _joystickInputData.Hat = Hat::CENTER;
}

void SwitchControlLibrary_::SendReport()
{
    CustomHID().SendReport(&_joystickInputData, sizeof(USB_JoystickReport_Input_t));
}

void SwitchControlLibrary_::PressButton(uint16_t button)
{
    _joystickInputData.Button |= button;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButton(uint16_t button)
{
    _joystickInputData.Button &= (button ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonY()
{
    PressButton(Button::Y);
}

void SwitchControlLibrary_::ReleaseButtonY()
{
    ReleaseButton(Button::Y);
}

void SwitchControlLibrary_::PressButtonB()
{
    PressButton(Button::B);
}

void SwitchControlLibrary_::ReleaseButtonB()
{
    ReleaseButton(Button::B);
}

void SwitchControlLibrary_::PressButtonA()
{
    PressButton(Button::A);
}

void SwitchControlLibrary_::ReleaseButtonA()
{
    ReleaseButton(Button::A);
}

void SwitchControlLibrary_::PressButtonX()
{
    PressButton(Button::X);
}

void SwitchControlLibrary_::ReleaseButtonX()
{
    ReleaseButton(Button::X);
}

void SwitchControlLibrary_::PressButtonL()
{
    PressButton(Button::L);
}

void SwitchControlLibrary_::ReleaseButtonL()
{
    ReleaseButton(Button::L);
}

void SwitchControlLibrary_::PressButtonR()
{
    PressButton(Button::R);
}

void SwitchControlLibrary_::ReleaseButtonR()
{
    ReleaseButton(Button::R);
}

void SwitchControlLibrary_::PressButtonZL()
{
    PressButton(Button::ZL);
}

void SwitchControlLibrary_::ReleaseButtonZL()
{
    ReleaseButton(Button::ZL);
}

void SwitchControlLibrary_::PressButtonZR()
{
    PressButton(Button::ZR);
}

void SwitchControlLibrary_::ReleaseButtonZR()
{
    ReleaseButton(Button::ZR);
}

void SwitchControlLibrary_::PressButtonMinus()
{
    PressButton(Button::MINUS);
}

void SwitchControlLibrary_::ReleaseButtonMinus()
{
    ReleaseButton(Button::MINUS);
}

void SwitchControlLibrary_::PressButtonPlus()
{
    PressButton(Button::PLUS);
}

void SwitchControlLibrary_::ReleaseButtonPlus()
{
    ReleaseButton(Button::PLUS);
}

void SwitchControlLibrary_::PressButtonLClick()
{
    PressButton(Button::LCLICK);
}

void SwitchControlLibrary_::ReleaseButtonLClick()
{
    ReleaseButton(Button::LCLICK);
}

void SwitchControlLibrary_::PressButtonRClick()
{
    PressButton(Button::RCLICK);
}

void SwitchControlLibrary_::ReleaseButtonRClick()
{
    ReleaseButton(Button::RCLICK);
}

void SwitchControlLibrary_::PressButtonHome()
{
    PressButton(Button::HOME);
}

void SwitchControlLibrary_::ReleaseButtonHome()
{
    ReleaseButton(Button::HOME);
}

void SwitchControlLibrary_::PressButtonCapture()
{
    PressButton(Button::CAPTURE);
}

void SwitchControlLibrary_::ReleaseButtonCapture()
{
    ReleaseButton(Button::CAPTURE);
}

void SwitchControlLibrary_::MoveHat(uint8_t hat)
{
    _joystickInputData.Hat = hat;
    SendReport();
}

void SwitchControlLibrary_::MoveLeftStick(uint8_t lx, uint8_t ly)
{
    _joystickInputData.LX = lx;
    _joystickInputData.LY = ly;
    SendReport();
}

void SwitchControlLibrary_::MoveRightStick(uint8_t rx, uint8_t ry)
{
    _joystickInputData.RX = rx;
    _joystickInputData.RY = ry;
    SendReport();
}

SwitchControlLibrary_ &SwitchControlLibrary()
{
    static SwitchControlLibrary_ obj;
    return obj;
}

#endif
