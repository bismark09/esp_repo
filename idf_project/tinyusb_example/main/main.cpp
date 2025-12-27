#include "usbcdc.hpp"

extern "C" void app_main(void) {
    USBCDC usbcdc;
    usbcdc.init();
    usbcdc.run();
}
