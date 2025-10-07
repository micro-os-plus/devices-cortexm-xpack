/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2017-2025 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 */

#ifndef MICRO_OS_PLUS_ARCHITECTURE_CORTEXM_STARTUP_HOOKS_H_
#define MICRO_OS_PLUS_ARCHITECTURE_CORTEXM_STARTUP_HOOKS_H_

// ----------------------------------------------------------------------------

#include <stddef.h>
#include <stdbool.h>

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

  /**
   * @addtogroup micro-os-plus-app-hooks
   * @{
   */

  /**
   * @name Startup Routines
   * @{
   */

  /**
   * @brief Initialise hardware early.
   * @par Parameters
   *  None.
   * @par Returns
   *  Nothing.
   */
  void
  micro_os_plus_startup_initialize_hardware_early (void);

  /**
   * @brief Initialise hardware.
   * @par Parameters
   *  None.
   * @par Returns
   *  Nothing.
   */
  void
  micro_os_plus_startup_initialize_hardware (void);

  /**
   * @brief Initialise the free store.
   * @param heap_address The first unallocated RAM address (after the BSS).
   * @param heap_size_bytes The free store size.
   * @par Returns
   *  Nothing.
   */
  void
  micro_os_plus_startup_initialize_free_store (void* heap_address,
                                               size_t heap_size_bytes);

  /**
   * @brief Initialise the interrupts stack.
   * @param stack_begin_address The stack bottom address.
   * @param stack_size_bytes The stack size.
   * @par Returns
   *  Nothing.
   */
  void
  micro_os_plus_startup_initialize_interrupts_stack (void* stack_begin_address,
                                                     size_t stack_size_bytes);

  /**
   * @}
   */

  /**
   * @}
   */

#if defined(__cplusplus)
}
#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_ARCHITECTURE_CORTEXM_STARTUP_HOOKS_H_

// ----------------------------------------------------------------------------
