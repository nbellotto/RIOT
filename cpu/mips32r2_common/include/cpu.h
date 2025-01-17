/*
 * Copyright(C) 2017, 2016, Imagination Technologies Limited and/or its
 *                 affiliated group companies.
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 *
 */

/**
 * @defgroup    cpu_mips32r2_common Imagination Technologies MIPS32R2 Common
 * @ingroup     cpu
 * @brief       CPU definitions for MIPS32R2 devices.
 * @{
 *
 * @file
 * @brief       CPU definitions for MIPS32R2 devices.
 *
 * @author      Neil Jones <neil.jones@imgtec.com>
 */

#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "cpu_conf.h"
#include "thread.h"
#include "irq.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Select fastest bitarithm_lsb implementation
 * @{
 */
#define BITARITHM_LSB_BUILTIN
#define BITARITHM_HAS_CLZ
/** @} */

/**
 * @brief   Gets the last instruction's address
 *
 * @todo:   Not supported
 */
static inline uintptr_t cpu_get_caller_pc(void)
{
    /* This function must exist else RIOT won't compile */
    return 0;
}

/**
 * @brief   Trigger a conditional context scheduler run / context switch
 *
 * This function is supposed to be called in the end of each ISR.
 */
static inline void mips32r2_isr_end(void)
{
    if (sched_context_switch_request) {
        thread_yield_higher();
    }
}

#ifdef __cplusplus
}
#endif

#endif /* CPU_H */
/** @} */
