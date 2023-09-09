/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V3.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_BALANCES_V3 10

#define PD_CALL_BALANCES_TRANSFER_ALL_V3 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V3_t;

typedef union {
    pd_balances_transfer_all_V3_t balances_transfer_all_V3;
} pd_MethodBasic_V3_t;

#define PD_CALL_BALANCES_TRANSFER_ALLOW_DEATH_V3 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_V3_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V3 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V3_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V3 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V3_t;

#define PD_CALL_BALANCES_TRANSFER_V3 7
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V3_t;

typedef union {
    pd_balances_transfer_allow_death_V3_t balances_transfer_allow_death_V3;
    pd_balances_force_transfer_V3_t balances_force_transfer_V3;
    pd_balances_transfer_keep_alive_V3_t balances_transfer_keep_alive_V3;
    pd_balances_transfer_V3_t balances_transfer_V3;
} pd_MethodNested_V3_t;

typedef union {
    pd_MethodBasic_V3_t basic;
    pd_MethodNested_V3_t nested;
} pd_Method_V3_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
