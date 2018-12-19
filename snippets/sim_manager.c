#include "sim_manager.h"
#include "gsm/gsm.h"

/**
 * \brief           SIM card pin code
 */
const char *
pin_code = "1234";

/**
 * \brief           SIM card puk code
 */
const char *
puk_code = "";

/**
 * \brief           Configure and enable SIM card
 * \return          `1` on success, `0` otherwise
 */
uint8_t
configure_sim_card(void) {
    if (pin_code != NULL && strlen(pin_code)==4) {
        if (gsm_sim_pin_enter(pin_code, 1) == gsmOK) {
            return 1;
        }
        return 0;
    }
    return 1;
}
