/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2020-2025 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 */

#if defined(__ARM_EABI__)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#if defined(MICRO_OS_PLUS_INCLUDE_STARTUP)

#include <micro-os-plus/device.h>
#include <micro-os-plus/startup/hooks.h>

#if !defined(MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS)

/**
 * @details
 * This function resets the MCU core.
 * Redefine it in your application if you need to do more,
 * like powering down devices, saving state, etc.
 */
void __attribute__ ((noreturn, weak))
micro_os_plus_terminate (int code __attribute__ ((unused)))
{
  NVIC_SystemReset ();

  /* NOTREACHED */
}

#endif // !defined(MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS)

#endif // defined(MICRO_OS_PLUS_INCLUDE_STARTUP)

// ----------------------------------------------------------------------------

#endif // defined(__ARM_EABI__)

// ----------------------------------------------------------------------------
