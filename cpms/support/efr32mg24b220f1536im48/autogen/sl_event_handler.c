#include "sl_event_handler.h"

#include "em_chip.h"
#include "sl_device_init_nvic.h"
#include "sl_device_init_dcdc.h"
#include "sl_device_init_clocks.h"
#include "sl_device_init_emu.h"
#include "sl_iostream_rtt.h"
#include "sl_mbedtls.h"
#include "nvm3_default.h"
#include "psa/crypto.h"
#include "sl_iostream_init_instances.h"

void sl_platform_init(void)
{
  CHIP_Init();
  sl_device_init_nvic();
  sl_device_init_dcdc();
  sl_device_init_clocks();
  sl_device_init_emu();
  nvm3_initDefault();
}

void sl_driver_init(void)
{
}

void sl_service_init(void)
{
  sl_mbedtls_init();
  psa_crypto_init();
  sl_iostream_init_instances();
}

void sl_stack_init(void)
{
}

void sl_internal_app_init(void)
{
}

void sl_platform_process_action(void)
{
}

void sl_service_process_action(void)
{
}

void sl_stack_process_action(void)
{
}

void sl_internal_app_process_action(void)
{
}

void sl_iostream_init_instances(void)
{
  sl_iostream_rtt_init();
}
