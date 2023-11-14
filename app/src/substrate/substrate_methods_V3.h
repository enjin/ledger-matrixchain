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
#define PD_CALL_MARKETPLACE_V3 50
#define PD_CALL_MULTITOKENS_V3 253

#define PD_CALL_BALANCES_TRANSFER_ALL_V3 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V3_t;

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

#define PD_CALL_MARKETPLACE_CREATE_LISTING_V3 0
typedef struct {
    pd_TokenAssetId_t make_asset_id;
    pd_TokenAssetId_t take_asset_id;
    pd_Compactu128_t amount;
    pd_Compactu128_t price;
    pd_Bytes_t salt;
    pd_OptionAuctionDataOfT_t auction_data;
} pd_marketplace_create_listing_V3_t;

#define PD_CALL_MARKETPLACE_CANCEL_LISTING_V3 1
typedef struct {
    pd_ListingIdOfT_t listing_id;
} pd_marketplace_cancel_listing_V3_t;

#define PD_CALL_MARKETPLACE_FILL_LISTING_V3 2
typedef struct {
    pd_ListingIdOfT_t listing_id;
    pd_Compactu128_t amount;
} pd_marketplace_fill_listing_V3_t;

#define PD_CALL_MARKETPLACE_PLACE_BID_V3 3
typedef struct {
    pd_ListingIdOfT_t listing_id;
    pd_Compactu128_t price;
} pd_marketplace_place_bid_V3_t;

#define PD_CALL_MARKETPLACE_FINALIZE_AUCTION_V3 4
typedef struct {
    pd_ListingIdOfT_t listing_id;
} pd_marketplace_finalize_auction_V3_t;

#define PD_CALL_MARKETPLACE_SET_PROTOCOL_FEE_V3 5
typedef struct {
    pd_Perbill_t protocol_fee;
} pd_marketplace_set_protocol_fee_V3_t;

#define PD_CALL_MARKETPLACE_FORCE_CREATE_LISTING_V3 6
typedef struct {
    pd_AccountIdLookupOfT_t seller;
    pd_TokenAssetId_t make_asset_id;
    pd_TokenAssetId_t take_asset_id;
    pd_Compactu128_t amount;
    pd_Compactu128_t price;
    pd_Bytes_t salt;
    pd_OptionAuctionDataOfT_t auction_data;
    pd_OptionAccountIdLookupOfT_t deposit_backer;
} pd_marketplace_force_create_listing_V3_t;

#define PD_CALL_MARKETPLACE_FORCE_PLACE_BID_V3 7
typedef struct {
    pd_AccountIdLookupOfT_t bidder;
    pd_ListingIdOfT_t listing_id;
    pd_Compactu128_t price;
    pd_OptionAccountIdLookupOfT_t funds_backer;
} pd_marketplace_force_place_bid_V3_t;

#define PD_CALL_MULTITOKENS_CREATE_COLLECTION_V3 0
typedef struct {
    pd_CollectionDescriptor_t descriptor;
} pd_multitokens_create_collection_V3_t;

#define PD_CALL_MULTITOKENS_DESTROY_COLLECTION_V3 1
typedef struct {
    pd_CompactCollectionId_t collection_id;
} pd_multitokens_destroy_collection_V3_t;

#define PD_CALL_MULTITOKENS_MUTATE_COLLECTION_V3 2
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CollectionMutation_t mutation;
} pd_multitokens_mutate_collection_V3_t;

#define PD_CALL_MULTITOKENS_BURN_V3 5
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_BurnParamsOfT_t params;
} pd_multitokens_burn_V3_t;

#define PD_CALL_MULTITOKENS_TRANSFER_V3 6
typedef struct {
    pd_AccountIdLookupOfT_t recipient;
    pd_CompactCollectionId_t collection_id;
    pd_TransferParamsOfT_t params;
} pd_multitokens_transfer_V3_t;

#define PD_CALL_MULTITOKENS_FREEZE_V3 7
typedef struct {
    pd_FreezeOf_t info;
} pd_multitokens_freeze_V3_t;

#define PD_CALL_MULTITOKENS_THAW_V3 8
typedef struct {
    pd_FreezeOf_t info;
} pd_multitokens_thaw_V3_t;

#define PD_CALL_MULTITOKENS_SET_ATTRIBUTE_V3 9
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t token_id;
    pd_Bytes_t key;
    pd_Bytes_t value;
} pd_multitokens_set_attribute_V3_t;

#define PD_CALL_MULTITOKENS_REMOVE_ATTRIBUTE_V3 10
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t token_id;
    pd_Bytes_t key;
} pd_multitokens_remove_attribute_V3_t;

#define PD_CALL_MULTITOKENS_REMOVE_ALL_ATTRIBUTES_V3 11
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t token_id;
    pd_u32_t attribute_count;
} pd_multitokens_remove_all_attributes_V3_t;

#define PD_CALL_MULTITOKENS_BATCH_TRANSFER_V3 12
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_VecTransferRecipientsOf_t recipients;
} pd_multitokens_batch_transfer_V3_t;

#define PD_CALL_MULTITOKENS_BATCH_SET_ATTRIBUTE_V3 14
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t  token_id;
    pd_VecAttributeKeyValuePair_t attributes;
} pd_multitokens_batch_set_attribute_V3_t;

#define PD_CALL_MULTITOKENS_APPROVE_COLLECTION_V3 15
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_AccountId_t operator_;
    pd_Optionu32_t expiration;
} pd_multitokens_approve_collection_V3_t;

#define PD_CALL_MULTITOKENS_UNAPPROVE_COLLECTION_V3 16
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_AccountId_t operator_;
} pd_multitokens_unapprove_collection_V3_t;

#define PD_CALL_MULTITOKENS_APPROVE_TOKEN_V3 17
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CompactTokenId_t token_id;
    pd_AccountId_t operator_;
    pd_CompactBalance_t amount;
    pd_Optionu32_t expiration;
    pd_CompactBalance_t current_amount;
} pd_multitokens_approve_token_V3_t;

#define PD_CALL_MULTITOKENS_UNAPPROVE_TOKEN_V3 18
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CompactTokenId_t token_id;
    pd_AccountId_t operator_;
} pd_multitokens_unapprove_token_V3_t;

#define PD_CALL_MULTITOKENS_CLAIM_COLLECTIONS_V3 32
typedef struct {
    pd_AccountId_t destination;
    pd_EcdsaSignature_t ethereum_signature;
    pd_EthereumAddress_t ethereum_address;
} pd_multitokens_claim_collections_V3_t;

#define PD_CALL_MULTITOKENS_CLAIM_TOKENS_V3 33
typedef struct {
    pd_AccountId_t destination;
    pd_EcdsaSignature_t ethereum_signature;
    pd_EthereumAddress_t ethereum_address;
} pd_multitokens_claim_tokens_V3_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS

#define PD_CALL_MULTITOKENS_MUTATE_TOKEN_V3 3
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CompactTokenId_t token_id;
    pd_TokenMutation_t mutation;
} pd_multitokens_mutate_token_V3_t;

#define PD_CALL_MULTITOKENS_MINT_V3 4
typedef struct {
    pd_AccountIdLookupOfT_t recipient;
    pd_CompactCollectionId_t collection_id;
    pd_MintParamsOf_t params;
} pd_multitokens_mint_V3_t;

#define PD_CALL_MULTITOKENS_BATCH_MINT_V3 13
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_VecMintRecipientsOf_t recipients;
} pd_multitokens_batch_mint_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_MUTATE_COLLECTION_V3 19
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CollectionMutation_t mutation;
} pd_multitokens_force_mutate_collection_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_TRANSFER_V3 20
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t destination;
    pd_CompactCollectionId_t collection_id;
    pd_TransferParamsOfT_t params;
} pd_multitokens_force_transfer_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_COLLECTION_V3 21
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionCollectionOf_t value;
} pd_multitokens_force_set_collection_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_TOKEN_V3 22
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CompactTokenId_t token_id;
    pd_OptionTokenOf_t value;
} pd_multitokens_force_set_token_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_ATTRIBUTE_V3 23
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t token_id;
    pd_Bytes_t key;
    pd_OptionAttributeOf_t value;
} pd_multitokens_force_set_attribute_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_COLLECTION_ACCOUNT_V3 24
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_AccountIdLookupOfT_t account_id;
    pd_OptionCollectionAccountOf_t value;
} pd_multitokens_force_set_collection_account_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_TOKEN_ACCOUNT_V3 25
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CompactTokenId_t token_id;
    pd_AccountIdLookupOfT_t account_id;
    pd_OptionTokenAccountOf_t value;
} pd_multitokens_force_set_token_account_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_CREATE_COLLECTION_V3 26
typedef struct {
    pd_AccountId_t owner;
    pd_CompactCollectionId_t collection_id;
    pd_CollectionDescriptor_t descriptor;
} pd_multitokens_force_create_collection_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_MINT_V3 27
typedef struct {
    pd_AccountIdLookupOfT_t caller;
    pd_AccountIdLookupOfT_t recipient;
    pd_CompactCollectionId_t collection_id;
    pd_MintParamsOf_t params;
    pd_OptionAccountIdLookupOfT_t deposit_backer;
} pd_multitokens_force_mint_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_BURN_V3 28
typedef struct {
    pd_AccountIdLookupOfT_t caller;
    pd_CompactCollectionId_t collection_id;
    pd_BurnParamsOfT_t params;
} pd_multitokens_force_burn_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_APPROVE_COLLECTION_V3 29
typedef struct {
    pd_AccountIdLookupOfT_t caller;
    pd_CompactCollectionId_t collection_id;
    pd_AccountId_t operator_;
    pd_Optionu32_t expiration;
} pd_multitokens_force_approve_collection_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_FREEZE_V3 30
typedef struct {
    pd_FreezeOf_t info;
} pd_multitokens_force_freeze_V3_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_NEXT_COLLECTION_ID_V3 31
typedef struct {
    pd_CompactCollectionId_t value;
} pd_multitokens_force_set_next_collection_id_V3_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V3 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V3_t;

#define PD_CALL_BALANCES_UPGRADE_ACCOUNTS_V3 6
typedef struct {
    pd_VecAccountId_t who;
} pd_balances_upgrade_accounts_V3_t;

#define PD_CALL_BALANCES_FORCE_SET_BALANCE_V3 8
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
} pd_balances_force_set_balance_V3_t;

#endif
#endif

typedef union {
    pd_balances_transfer_all_V3_t balances_transfer_all_V3;
    pd_balances_transfer_allow_death_V3_t balances_transfer_allow_death_V3;
    pd_balances_force_transfer_V3_t balances_force_transfer_V3;
    pd_balances_transfer_keep_alive_V3_t balances_transfer_keep_alive_V3;
    pd_balances_transfer_V3_t balances_transfer_V3;
    pd_marketplace_cancel_listing_V3_t marketplace_cancel_listing_V3;
    pd_marketplace_create_listing_V3_t marketplace_create_listing_V3;
    pd_marketplace_fill_listing_V3_t marketplace_fill_listing_V3;
    pd_marketplace_place_bid_V3_t marketplace_place_bid_V3;
    pd_marketplace_finalize_auction_V3_t marketplace_finalize_auction_V3;
    pd_marketplace_set_protocol_fee_V3_t marketplace_set_protocol_fee_V3;
    pd_marketplace_force_create_listing_V3_t marketplace_force_create_listing_V3;
    pd_marketplace_force_place_bid_V3_t marketplace_force_place_bid_V3;
    pd_multitokens_create_collection_V3_t multitokens_create_collection_V3;
    pd_multitokens_destroy_collection_V3_t multitokens_destroy_collection_V3;
    pd_multitokens_mutate_collection_V3_t multitokens_mutate_collection_V3;
    pd_multitokens_burn_V3_t multitokens_burn_V3;
    pd_multitokens_transfer_V3_t multitokens_transfer_V3;
    pd_multitokens_freeze_V3_t multitokens_freeze_V3;
    pd_multitokens_thaw_V3_t multitokens_thaw_V3;
    pd_multitokens_set_attribute_V3_t multitokens_set_attribute_V3;
    pd_multitokens_remove_attribute_V3_t multitokens_remove_attribute_V3;
    pd_multitokens_remove_all_attributes_V3_t multitokens_remove_all_attributes_V3;
    pd_multitokens_batch_transfer_V3_t multitokens_batch_transfer_V3;
    pd_multitokens_batch_set_attribute_V3_t multitokens_batch_set_attribute_V3;
    pd_multitokens_approve_collection_V3_t multitokens_approve_collection_V3;
    pd_multitokens_unapprove_collection_V3_t multitokens_unapprove_collection_V3;
    pd_multitokens_approve_token_V3_t multitokens_approve_token_V3;
    pd_multitokens_unapprove_token_V3_t multitokens_unapprove_token_V3;
    pd_multitokens_claim_collections_V3_t multitokens_claim_collections_V3;
    pd_multitokens_claim_tokens_V3_t multitokens_claim_tokens_V3;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    pd_multitokens_mutate_token_V3_t multitokens_mutate_token_V3;
    pd_multitokens_mint_V3_t multitokens_mint_V3;
    pd_multitokens_batch_mint_V3_t multitokens_batch_mint_V3;
    pd_balances_force_unreserve_V3_t balances_force_unreserve_V3;
    pd_balances_upgrade_accounts_V3_t balances_upgrade_accounts_V3;
    pd_balances_force_set_balance_V3_t balances_force_set_balance_V3;
    pd_multitokens_force_mutate_collection_V3_t multitokens_force_mutate_collection_V3;
    pd_multitokens_force_transfer_V3_t multitokens_force_transfer_V3;
    pd_multitokens_force_set_collection_V3_t multitokens_force_set_collection_V3;
    pd_multitokens_force_set_token_V3_t multitokens_force_set_token_V3;
    pd_multitokens_force_set_attribute_V3_t multitokens_force_set_attribute_V3;
    pd_multitokens_force_set_collection_account_V3_t multitokens_force_set_collection_account_V3;
    pd_multitokens_force_set_token_account_V3_t multitokens_force_set_token_account_V3;
    pd_multitokens_force_create_collection_V3_t multitokens_force_create_collection_V3;
    pd_multitokens_force_mint_V3_t multitokens_force_mint_V3;
    pd_multitokens_force_burn_V3_t multitokens_force_burn_V3;
    pd_multitokens_force_approve_collection_V3_t multitokens_force_approve_collection_V3;
    pd_multitokens_force_freeze_V3_t multitokens_force_freeze_V3;
    pd_multitokens_force_set_next_collection_id_V3_t multitokens_force_set_next_collection_id_V3;
#endif
#endif
} pd_MethodBasic_V3_t;

typedef union {
    pd_MethodBasic_V3_t basic;
} pd_Method_V3_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
