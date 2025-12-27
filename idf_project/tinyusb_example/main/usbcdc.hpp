#ifndef USBCDC_HPP
#define USBCDC_HPP

#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "tinyusb.h"
#include "tinyusb_default_config.h"
#include "tinyusb_cdc_acm.h"

class USBCDC {
public:
    USBCDC();
    ~USBCDC();
    void init();
    void run();

private:
    static const char *TAG;
    static uint8_t rx_buf[];
    static QueueHandle_t app_queue;
    static USBCDC *instance;

    typedef struct {
        uint8_t buf[CONFIG_TINYUSB_CDC_RX_BUFSIZE + 1];     // Data buffer
        size_t buf_len;                                     // Number of bytes received
        tinyusb_cdcacm_itf_t itf;                            // Index of CDC device interface
    } app_message_t;

    static void tinyusb_cdc_rx_callback(int itf, cdcacm_event_t *event);
    static void tinyusb_cdc_line_state_changed_callback(int itf, cdcacm_event_t *event);
};

#endif // USBCDC_HPP
