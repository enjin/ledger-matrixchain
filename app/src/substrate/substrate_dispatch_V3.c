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

#include "substrate_dispatch_V3.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V3(
        parser_context_t* c, pd_balances_transfer_allow_death_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V3(
        parser_context_t* c, pd_balances_force_transfer_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V3(
        parser_context_t* c, pd_balances_transfer_keep_alive_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V3(
        parser_context_t* c, pd_balances_transfer_all_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V3(
        parser_context_t* c, pd_balances_transfer_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_cancel_listing_V3(
        parser_context_t* c, pd_marketplace_cancel_listing_V3_t* m)
{
    CHECK_ERROR(_readListingIdOf(c, &m->listing_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_create_listing_V3(
        parser_context_t* c, pd_marketplace_create_listing_V3_t* m)
{
    CHECK_ERROR(_readTokenAssetId(c, &m->make_asset_id))
    CHECK_ERROR(_readTokenAssetId(c, &m->take_asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readCompactu128(c, &m->price))
    CHECK_ERROR(_readBytes(c, &m->salt))
    CHECK_ERROR(_readOptionAuctionDataOfT(c, &m->auction_data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_fill_listing_V3(
        parser_context_t* c, pd_marketplace_fill_listing_V3_t* m)
{
    CHECK_ERROR(_readListingIdOf(c, &m->listing_id))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_finalize_auction_V3(
        parser_context_t* c, pd_marketplace_finalize_auction_V3_t* m)
{
    CHECK_ERROR(_readListingIdOf(c, &m->listing_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_place_bid_V3(
        parser_context_t* c, pd_marketplace_place_bid_V3_t* m)
{
    CHECK_ERROR(_readListingIdOf(c, &m->listing_id))
    CHECK_ERROR(_readCompactu128(c, &m->price))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_approve_collection_V3(
        parser_context_t* c, pd_multitokens_approve_collection_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    CHECK_ERROR(_readOptionu32(c, &m->expiration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_approve_token_V3(
        parser_context_t* c, pd_multitokens_approve_token_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readOptionu32(c, &m->expiration))
    CHECK_ERROR(_readCompactBalance(c, &m->current_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_batch_set_attribute_V3(
        parser_context_t* c, pd_multitokens_batch_set_attribute_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
    CHECK_ERROR(_readVecAttributeKeyValuePair(c, &m->attributes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_batch_transfer_V3(
        parser_context_t* c, pd_multitokens_batch_transfer_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readVecTransferRecipientsOf(c, &m->recipients))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_burn_V3(
        parser_context_t* c, pd_multitokens_burn_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readBurnParamsOfT(c, &m->params))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_claim_collections_V3(
        parser_context_t* c, pd_multitokens_claim_collections_V3_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->destination))
    CHECK_ERROR(_readEcdsaSignature(c, &m->ethereum_signature))
    CHECK_ERROR(_readEthereumAddress(c, &m->ethereum_address))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_claim_tokens_V3(
        parser_context_t* c, pd_multitokens_claim_tokens_V3_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->destination))
    CHECK_ERROR(_readEcdsaSignature(c, &m->ethereum_signature))
    CHECK_ERROR(_readEthereumAddress(c, &m->ethereum_address))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_create_collection_V3(
        parser_context_t* c, pd_multitokens_create_collection_V3_t* m)
{
    CHECK_ERROR(_readCollectionDescriptor(c, &m->descriptor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_destroy_collection_V3(
        parser_context_t* c, pd_multitokens_destroy_collection_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_freeze_V3(
        parser_context_t* c, pd_multitokens_freeze_V3_t* m)
{
    CHECK_ERROR(_readFreezeOf(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_mutate_collection_V3(
        parser_context_t* c, pd_multitokens_mutate_collection_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCollectionMutation(c, &m->mutation))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_remove_all_attributes_V3(
        parser_context_t* c, pd_multitokens_remove_all_attributes_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
    CHECK_ERROR(_readu32(c, &m->attribute_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_remove_attribute_V3(
        parser_context_t* c, pd_multitokens_remove_attribute_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
    CHECK_ERROR(_readBytes(c, &m->key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_set_attribute_V3(
        parser_context_t* c, pd_multitokens_set_attribute_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
    CHECK_ERROR(_readBytes(c, &m->key))
    CHECK_ERROR(_readBytes(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_thaw_V3(
        parser_context_t* c, pd_multitokens_thaw_V3_t* m)
{
    CHECK_ERROR(_readFreezeOf(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_transfer_V3(
        parser_context_t* c, pd_multitokens_transfer_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->recipient))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readTransferParamsOfT(c, &m->params))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_unapprove_collection_V3(
        parser_context_t* c, pd_multitokens_unapprove_collection_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_unapprove_token_V3(
        parser_context_t* c, pd_multitokens_unapprove_token_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
__Z_INLINE parser_error_t _readMethod_marketplace_force_create_listing_V3(
        parser_context_t* c, pd_marketplace_force_create_listing_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->seller))
    CHECK_ERROR(_readTokenAssetId(c, &m->make_asset_id))
    CHECK_ERROR(_readTokenAssetId(c, &m->take_asset_id))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readCompactu128(c, &m->price))
    CHECK_ERROR(_readBytes(c, &m->salt))
    CHECK_ERROR(_readOptionAuctionDataOfT(c, &m->auction_data))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->deposit_backer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_force_place_bid_V3(
        parser_context_t* c, pd_marketplace_force_place_bid_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->bidder))
    CHECK_ERROR(_readListingIdOf(c, &m->listing_id))
    CHECK_ERROR(_readCompactu128(c, &m->price))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->funds_backer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_marketplace_set_protocol_fee_V3(
        parser_context_t* c, pd_marketplace_set_protocol_fee_V3_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->protocol_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_batch_mint_V3(
        parser_context_t* c, pd_multitokens_batch_mint_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readVecMintRecipientsOf(c, &m->recipients))
    return parser_ok;
}


__Z_INLINE parser_error_t _readMethod_multitokens_mint_V3(
        parser_context_t* c, pd_multitokens_mint_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->recipient))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readMintParamsOf(c, &m->params))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_mutate_token_V3(
        parser_context_t* c, pd_multitokens_mutate_token_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readTokenMutation(c, &m->mutation))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V3(
        parser_context_t* c, pd_balances_force_unreserve_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V3(
        parser_context_t* c, pd_balances_upgrade_accounts_V3_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V3(
        parser_context_t* c, pd_balances_force_set_balance_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_approve_collection_V3(
        parser_context_t* c, pd_multitokens_force_approve_collection_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->caller))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    CHECK_ERROR(_readOptionu32(c, &m->expiration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_burn_V3(
        parser_context_t* c, pd_multitokens_force_burn_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->caller))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readBurnParamsOfT(c, &m->params))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_create_collection_V3(
        parser_context_t* c, pd_multitokens_force_create_collection_V3_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->owner))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCollectionDescriptor(c, &m->descriptor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_freeze_V3(
        parser_context_t* c, pd_multitokens_force_freeze_V3_t* m)
{
    CHECK_ERROR(_readFreezeOf(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_mint_V3(
        parser_context_t* c, pd_multitokens_force_mint_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->caller))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->recipient))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readMintParamsOf(c, &m->params))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->deposit_backer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_mutate_collection_V3(
        parser_context_t* c, pd_multitokens_force_mutate_collection_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCollectionMutation(c, &m->mutation))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_attribute_V3(
        parser_context_t* c, pd_multitokens_force_set_attribute_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
    CHECK_ERROR(_readBytes(c, &m->key))
    CHECK_ERROR(_readOptionAttributeOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_collection_V3(
        parser_context_t* c, pd_multitokens_force_set_collection_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readOptionCollectionOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_collection_account_V3(
        parser_context_t* c, pd_multitokens_force_set_collection_account_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account_id))
    CHECK_ERROR(_readOptionCollectionAccountOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_next_collection_id_V3(
        parser_context_t* c, pd_multitokens_force_set_next_collection_id_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_token_V3(
        parser_context_t* c, pd_multitokens_force_set_token_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readOptionTokenOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_set_token_account_V3(
        parser_context_t* c, pd_multitokens_force_set_token_account_V3_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account_id))
    CHECK_ERROR(_readOptionTokenAccountOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_force_transfer_V3(
        parser_context_t* c, pd_multitokens_force_transfer_V3_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->destination))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readTransferParamsOfT(c, &m->params))
    return parser_ok;
}
#endif
#endif

parser_error_t _readMethod_V3(
        parser_context_t* c,
        uint8_t moduleIdx,
        uint8_t callIdx,
        pd_Method_V3_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

        case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_allow_death_V3(c, &method->basic.balances_transfer_allow_death_V3))
            break;
        case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V3(c, &method->basic.balances_force_transfer_V3))
            break;
        case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V3(c, &method->basic.balances_transfer_keep_alive_V3))
            break;
        case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V3(c, &method->basic.balances_transfer_all_V3))
            break;
        case 2567: /* module 10 call 7 */
        CHECK_ERROR(_readMethod_balances_transfer_V3(c, &method->basic.balances_transfer_V3))
            break;
        case 12800: /* module 50 call 0 */
        CHECK_ERROR(_readMethod_marketplace_create_listing_V3(c, &method->basic.marketplace_create_listing_V3))
            break;
        case 12801: /* module 50 call 1 */
        CHECK_ERROR(_readMethod_marketplace_cancel_listing_V3(c, &method->basic.marketplace_cancel_listing_V3))
            break;
        case 12802: /* module 50 call 2 */
        CHECK_ERROR(_readMethod_marketplace_fill_listing_V3(c, &method->basic.marketplace_fill_listing_V3))
            break;
        case 12803: /* module 50 call 3 */
        CHECK_ERROR(_readMethod_marketplace_place_bid_V3(c, &method->basic.marketplace_place_bid_V3))
            break;
        case 12804: /* module 50 call 4 */
        CHECK_ERROR(_readMethod_marketplace_finalize_auction_V3(c, &method->basic.marketplace_finalize_auction_V3))
            break;
        case 64768: /* module 253 call 0 */
        CHECK_ERROR(_readMethod_multitokens_create_collection_V3(c, &method->basic.multitokens_create_collection_V3))
            break;
        case 64769: /* module 253 call 1 */
        CHECK_ERROR(_readMethod_multitokens_destroy_collection_V3(c, &method->basic.multitokens_destroy_collection_V3))
            break;
        case 64770: /* module 253 call 2 */
        CHECK_ERROR(_readMethod_multitokens_mutate_collection_V3(c, &method->basic.multitokens_mutate_collection_V3))
            break;
        case 64773: /* module 253 call 5 */
        CHECK_ERROR(_readMethod_multitokens_burn_V3(c, &method->basic.multitokens_burn_V3))
            break;
        case 64774: /* module 253 call 6 */
        CHECK_ERROR(_readMethod_multitokens_transfer_V3(c, &method->basic.multitokens_transfer_V3))
            break;
        case 64775: /* module 253 call 7 */
        CHECK_ERROR(_readMethod_multitokens_freeze_V3(c, &method->basic.multitokens_freeze_V3))
            break;
        case 64776: /* module 253 call 8 */
        CHECK_ERROR(_readMethod_multitokens_thaw_V3(c, &method->basic.multitokens_thaw_V3))
            break;
        case 64777: /* module 253 call 9 */
        CHECK_ERROR(_readMethod_multitokens_set_attribute_V3(c, &method->basic.multitokens_set_attribute_V3))
            break;
        case 64778: /* module 253 call 10 */
        CHECK_ERROR(_readMethod_multitokens_remove_attribute_V3(c, &method->basic.multitokens_remove_attribute_V3))
            break;
        case 64779: /* module 253 call 11 */
        CHECK_ERROR(_readMethod_multitokens_remove_all_attributes_V3(c, &method->basic.multitokens_remove_all_attributes_V3))
            break;
        case 64780: /* module 253 call 12 */
        CHECK_ERROR(_readMethod_multitokens_batch_transfer_V3(c, &method->basic.multitokens_batch_transfer_V3))
            break;
        case 64782: /* module 253 call 14 */
        CHECK_ERROR(_readMethod_multitokens_batch_set_attribute_V3(c, &method->basic.multitokens_batch_set_attribute_V3))
            break;
        case 64783: /* module 253 call 15 */
        CHECK_ERROR(_readMethod_multitokens_approve_collection_V3(c, &method->basic.multitokens_approve_collection_V3))
            break;
        case 64784: /* module 253 call 16 */
        CHECK_ERROR(_readMethod_multitokens_unapprove_collection_V3(c, &method->basic.multitokens_unapprove_collection_V3))
            break;
        case 64785: /* module 253 call 17 */
        CHECK_ERROR(_readMethod_multitokens_approve_token_V3(c, &method->basic.multitokens_approve_token_V3))
            break;
        case 64786: /* module 253 call 18 */
        CHECK_ERROR(_readMethod_multitokens_unapprove_token_V3(c, &method->basic.multitokens_unapprove_token_V3))
            break;
        case 64800: /* module 253 call 32 */
        CHECK_ERROR(_readMethod_multitokens_claim_collections_V3(c, &method->basic.multitokens_claim_collections_V3))
            break;
        case 64801: /* module 253 call 33 */
        CHECK_ERROR(_readMethod_multitokens_claim_tokens_V3(c, &method->basic.multitokens_claim_tokens_V3))
            break;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
        case 12805: /* module 50 call 5 */
        CHECK_ERROR(_readMethod_marketplace_set_protocol_fee_V3(c, &method->basic.marketplace_set_protocol_fee_V3))
            break;
        case 12806: /* module 50 call 6 */
        CHECK_ERROR(_readMethod_marketplace_force_create_listing_V3(c, &method->basic.marketplace_force_create_listing_V3))
            break;
        case 12807: /* module 50 call 7 */
        CHECK_ERROR(_readMethod_marketplace_force_place_bid_V3(c, &method->basic.marketplace_force_place_bid_V3))
            break;
        case 64771: /* module 253 call 3 */
        CHECK_ERROR(_readMethod_multitokens_mutate_token_V3(c, &method->basic.multitokens_mutate_token_V3))
            break;
        case 64772: /* module 253 call 4 */
        CHECK_ERROR(_readMethod_multitokens_mint_V3(c, &method->basic.multitokens_mint_V3))
            break;
        case 64781: /* module 253 call 13 */
        CHECK_ERROR(_readMethod_multitokens_batch_mint_V3(c, &method->basic.multitokens_batch_mint_V3))
            break;
        case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V3(c, &method->basic.balances_force_transfer_V3))
            break;
        case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V3(c, &method->basic.balances_force_unreserve_V3))
            break;
        case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_balances_upgrade_accounts_V3(c, &method->basic.balances_upgrade_accounts_V3))
            break;
        case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_balances_force_set_balance_V3(c, &method->basic.balances_force_set_balance_V3))
            break;
        case 64787: /* module 253 call 19 */
        CHECK_ERROR(_readMethod_multitokens_force_mutate_collection_V3(c, &method->basic.multitokens_force_mutate_collection_V3))
            break;
        case 64788: /* module 253 call 20 */
        CHECK_ERROR(_readMethod_multitokens_force_transfer_V3(c, &method->basic.multitokens_force_transfer_V3))
            break;
        case 64789: /* module 253 call 21 */
        CHECK_ERROR(_readMethod_multitokens_force_set_collection_V3(c, &method->basic.multitokens_force_set_collection_V3))
            break;
        case 64790: /* module 253 call 22 */
        CHECK_ERROR(_readMethod_multitokens_force_set_token_V3(c, &method->basic.multitokens_force_set_token_V3))
            break;
        case 64791: /* module 253 call 23 */
        CHECK_ERROR(_readMethod_multitokens_force_set_attribute_V3(c, &method->basic.multitokens_force_set_attribute_V3))
            break;
        case 64792: /* module 253 call 24 */
        CHECK_ERROR(_readMethod_multitokens_force_set_collection_account_V3(c, &method->basic.multitokens_force_set_collection_account_V3))
            break;
        case 64793: /* module 253 call 25 */
        CHECK_ERROR(_readMethod_multitokens_force_set_token_account_V3(c, &method->basic.multitokens_force_set_token_account_V3))
            break;
        case 64794: /* module 253 call 26 */
        CHECK_ERROR(_readMethod_multitokens_force_create_collection_V3(c, &method->basic.multitokens_force_create_collection_V3))
            break;
        case 64795: /* module 253 call 27 */
        CHECK_ERROR(_readMethod_multitokens_force_mint_V3(c, &method->basic.multitokens_force_mint_V3))
            break;
        case 64796: /* module 253 call 28 */
        CHECK_ERROR(_readMethod_multitokens_force_burn_V3(c, &method->basic.multitokens_force_burn_V3))
            break;
        case 64797: /* module 253 call 29 */
        CHECK_ERROR(_readMethod_multitokens_force_approve_collection_V3(c, &method->basic.multitokens_force_approve_collection_V3))
            break;
        case 64798: /* module 253 call 30 */
        CHECK_ERROR(_readMethod_multitokens_force_freeze_V3(c, &method->basic.multitokens_force_freeze_V3))
            break;
        case 64799: /* module 253 call 31 */
        CHECK_ERROR(_readMethod_multitokens_force_set_next_collection_id_V3(c, &method->basic.multitokens_force_set_next_collection_id_V3))
            break;
#endif
#endif
        default:
            return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V3(uint8_t moduleIdx)
{
    switch (moduleIdx) {
        case 10:
            return STR_MO_BALANCES;
        case 50:
            return STR_MO_MARKETPLACE;
        case 253:
            return STR_MO_MULTITOKENS;
        default:
            return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V3(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 2560: /* module 10 call 0 */
            return STR_ME_TRANSFER_ALLOW_DEATH;
        case 2562: /* module 10 call 2 */
            return STR_ME_FORCE_TRANSFER;
        case 2563: /* module 10 call 3 */
            return STR_ME_TRANSFER_KEEP_ALIVE;
        case 2564: /* module 10 call 4 */
            return STR_ME_TRANSFER_ALL;
        case 2567: /* module 10 call 7 */
            return STR_ME_TRANSFER;
        case 12800: /* module 50 call 0 */
            return STR_ME_CREATE_LISTING;
        case 12801: /* module 50 call 1 */
            return STR_ME_CANCEL_LISTING;
        case 12802: /* module 50 call 2 */
            return STR_ME_FILL_LISTING;
        case 12803: /* module 50 call 3 */
            return STR_ME_PLACE_BID;
        case 12804: /* module 50 call 4 */
            return STR_ME_FINALIZE_AUCTION;
        case 12805: /* module 50 call 5 */
            return STR_ME_SET_PROTOCOL_FEE;
        case 12806: /* module 50 call 6 */
            return STR_ME_FORCE_CREATE_LISTING;
        case 12807: /* module 50 call 7 */
            return STR_ME_FORCE_PLACE_BID;
        case 64768: /* module 253 call 0 */
            return STR_ME_CREATE_COLLECTION;
        case 64769: /* module 253 call 1 */
            return STR_ME_DESTROY_COLLECTION;
        case 64770: /* module 253 call 2 */
            return STR_ME_MUTATE_COLLECTION;
        case 64771: /* module 253 call 3 */
            return STR_ME_MUTATE_TOKEN;
        case 64772: /* module 253 call 4 */
            return STR_ME_MINT;
        case 64773: /* module 253 call 5 */
            return STR_ME_BURN;
        case 64774: /* module 253 call 6 */
            return STR_ME_TRANSFER;
        case 64775: /* module 253 call 7 */
            return STR_ME_FREEZE;
        case 64776: /* module 253 call 8 */
            return STR_ME_THAW;
        case 64777: /* module 253 call 9 */
            return STR_ME_SET_ATTRIBUTE;
        case 64778: /* module 253 call 10 */
            return STR_ME_REMOVE_ATTRIBUTE;
        case 64779: /* module 253 call 11 */
            return STR_ME_REMOVE_ALL_ATTRIBUTES;
        case 64780: /* module 253 call 12 */
            return STR_ME_BATCH_TRANSFER;
        case 64781: /* module 253 call 13 */
            return STR_ME_BATCH_MINT;
        case 64782: /* module 253 call 14 */
            return STR_ME_BATCH_SET_ATTRIBUTE;
        case 64783: /* module 253 call 15 */
            return STR_ME_APPROVE_COLLECTION;
        case 64784: /* module 253 call 16 */
            return STR_ME_UNAPPROVE_COLLECTION;
        case 64785: /* module 253 call 17 */
            return STR_ME_APPROVE_TOKEN;
        case 64786: /* module 253 call 18 */
            return STR_ME_UNAPPROVE_TOKEN;
        case 64787: /* module 253 call 19 */
            return STR_ME_FORCE_MUTATE_COLLECTION;
        case 64788: /* module 253 call 20 */
            return STR_ME_FORCE_TRANSFER;
        case 64789: /* module 253 call 21 */
            return STR_ME_FORCE_SET_COLLECTION;
        case 64790: /* module 253 call 22 */
            return STR_ME_FORCE_SET_TOKEN;
        case 64791: /* module 253 call 23 */
            return STR_ME_FORCE_SET_ATTRIBUTE;
        case 64792: /* module 253 call 24 */
            return STR_ME_FORCE_SET_COLLECTION_ACCOUNT;
        case 64793: /* module 253 call 25 */
            return STR_ME_FORCE_SET_TOKEN_ACCOUNT;
        case 64794: /* module 253 call 26 */
            return STR_ME_FORCE_CREATE_COLLECTION;
        case 64795: /* module 253 call 27 */
            return STR_ME_FORCE_MINT;
        case 64796: /* module 253 call 28 */
            return STR_ME_FORCE_BURN;
        case 64797: /* module 253 call 29 */
            return STR_ME_FORCE_APPROVE_COLLECTION;
        case 64798: /* module 253 call 30 */
            return STR_ME_FORCE_FREEZE;
        case 64799: /* module 253 call 31 */
            return STR_ME_FORCE_SET_NEXT_COLLECTION_ID;
        case 64800: /* module 253 call 32 */
            return STR_ME_CLAIM_COLLECTIONS;
        case 64801: /* module 253 call 33 */
            return STR_ME_CLAIM_TOKENS;
        default:
            return _getMethod_Name_V3_ParserFull(callPrivIdx);
    }

    return NULL;
}


const char* _getMethod_Name_V3_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
        case 1541: /* module 6 call 5 */
            return STR_ME_FORCE_UNRESERVE;
        case 1542: /* module 6 call 6 */
            return STR_ME_UPGRADE_ACCOUNTS;
        case 1544: /* module 6 call 8 */
            return STR_ME_FORCE_SET_BALANCE;
#endif
        default:
            return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V3(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 2560: /* module 10 call 0 */
            return 2;
        case 2562: /* module 10 call 2 */
            return 3;
        case 2563: /* module 10 call 3 */
            return 2;
        case 2564: /* module 10 call 4 */
            return 2;
        case 2567: /* module 10 call 7 */
            return 2;
        case 12800: /* module 50 call 0 */
            return 6;
        case 12801: /* module 50 call 1 */
            return 1;
        case 12802: /* module 50 call 2 */
            return 2;
        case 12803: /* module 50 call 3 */
            return 2;
        case 12804: /* module 50 call 4 */
            return 1;
        case 12805: /* module 50 call 5 */
            return 1;
        case 12806: /* module 50 call 6 */
            return 8;
        case 12807: /* module 50 call 7 */
            return 4;
        case 64768: /* module 253 call 0 */
            return 1;
        case 64769: /* module 253 call 1 */
            return 1;
        case 64770: /* module 253 call 2 */
            return 2;
        case 64771: /* module 253 call 3 */
            return 3;
        case 64772: /* module 253 call 4 */
            return 3;
        case 64773: /* module 253 call 5 */
            return 2;
        case 64774: /* module 253 call 6 */
            return 3;
        case 64775: /* module 253 call 7 */
            return 1;
        case 64776: /* module 253 call 8 */
            return 1;
        case 64777: /* module 253 call 9 */
            return 4;
        case 64778: /* module 253 call 10 */
            return 3;
        case 64779: /* module 253 call 11 */
            return 3;
        case 64780: /* module 253 call 12 */
            return 2;
        case 64781: /* module 253 call 13 */
            return 2;
        case 64782: /* module 253 call 14 */
            return 3;
        case 64783: /* module 253 call 15 */
            return 3;
        case 64784: /* module 253 call 16 */
            return 2;
        case 64785: /* module 253 call 17 */
            return 6;
        case 64786: /* module 253 call 18 */
            return 3;
        case 64787: /* module 253 call 19 */
            return 2;
        case 64788: /* module 253 call 20 */
            return 4;
        case 64789: /* module 253 call 21 */
            return 2;
        case 64790: /* module 253 call 22 */
            return 3;
        case 64791: /* module 253 call 23 */
            return 4;
        case 64792: /* module 253 call 24 */
            return 3;
        case 64793: /* module 253 call 25 */
            return 4;
        case 64794: /* module 253 call 26 */
            return 3;
        case 64795: /* module 253 call 27 */
            return 5;
        case 64796: /* module 253 call 28 */
            return 3;
        case 64797: /* module 253 call 29 */
            return 4;
        case 64798: /* module 253 call 30 */
            return 1;
        case 64799: /* module 253 call 31 */
            return 1;
        case 64800: /* module 253 call 32 */
            return 3;
        case 64801: /* module 253 call 33 */
            return 3;
#ifdef SUBSTRATE_PARSER_FULL
        case 1541: /* module 6 call 5 */
            return 2;
        case 1542: /* module 6 call 6 */
            return 1;
        case 1544: /* module 6 call 8 */
            return 2;
#endif
        default:
            return 0;
    }
}

const char* _getMethod_ItemName_V3(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 2560: /* module 10 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 2562: /* module 10 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_source;
                case 1:
                    return STR_IT_dest;
                case 2:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 2563: /* module 10 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 2564: /* module 10 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_keep_alive;
                default:
                    return NULL;
            }
        case 2567: /* module 10 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 12800: /* module 50 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_make_asset_id;
                case 1:
                    return STR_IT_take_asset_id;
                case 2:
                    return STR_IT_amount;
                case 3:
                    return STR_IT_price;
                case 4:
                    return STR_IT_salt;
                case 5:
                    return STR_IT_auction_data;
                default:
                    return NULL;
            }
        case 12801: /* module 50 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_listing_id;
                default:
                    return NULL;
            }
        case 12802: /* module 50 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_listing_id;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 12803: /* module 50 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_listing_id;
                case 1:
                    return STR_IT_price;
                default:
                    return NULL;
            }
        case 12804: /* module 50 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_listing_id;
                default:
                    return NULL;
            }
        case 12805: /* module 50 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_protocol_fee;
                default:
                    return NULL;
            }
        case 12806: /* module 50 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_seller;
                case 1:
                    return STR_IT_make_asset_id;
                case 2:
                    return STR_IT_take_asset_id;
                case 3:
                    return STR_IT_amount;
                case 4:
                    return STR_IT_price;
                case 5:
                    return STR_IT_salt;
                case 6:
                    return STR_IT_auction_data;
                case 7:
                    return STR_IT_deposit_backer;
                default:
                    return NULL;
            }
        case 12807: /* module 50 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
            return STR_ME_FORCE_PLACE_BID;
        case 64768: /* module 253 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_descriptor;
                default:
                    return NULL;
            }
        case 64769: /* module 253 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                default:
                    return NULL;
            }
        case 64770: /* module 253 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_mutation;
                default:
                    return NULL;
            }
        case 64771: /* module 253 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_mutation;
                default:
                    return NULL;
            }
        case 64772: /* module 253 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_recipient;
                case 1:
                    return STR_IT_collection_id;
                case 2:
                    return STR_IT_params;
                default:
                    return NULL;
            }
        case 64773: /* module 253 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_params;
                default:
                    return NULL;
            }
        case 64774: /* module 253 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_recipient;
                case 1:
                    return STR_IT_collection_id;
                case 2:
                    return STR_IT_params;
                default:
                    return NULL;
            }
        case 64775: /* module 253 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_info;
                default:
                    return NULL;
            }
        case 64776: /* module 253 call 8 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_info;
                default:
                    return NULL;
            }
        case 64777: /* module 253 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_key;
                case 3:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64778: /* module 253 call 10 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_key;
                default:
                    return NULL;
            }
        case 64779: /* module 253 call 11 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_attribute_count;
                default:
                    return NULL;
            }
        case 64780: /* module 253 call 12 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_recipients;
                default:
                    return NULL;
            }
        case 64781: /* module 253 call 13 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_recipients;
                default:
                    return NULL;
            }
        case 64782: /* module 253 call 14 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_attributes;
                default:
                    return NULL;
            }
        case 64783: /* module 253 call 15 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_operator;
                case 2:
                    return STR_IT_expiration;
                default:
                    return NULL;
            }
        case 64784: /* module 253 call 16 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_operator;
                default:
                    return NULL;
            }
        case 64785: /* module 253 call 17 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_operator;
                case 3:
                    return STR_IT_amount;
                case 4:
                    return STR_IT_expiration;
                case 5:
                    return STR_IT_current_amount;
                default:
                    return NULL;
            }
        case 64786: /* module 253 call 18 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_operator;
                default:
                    return NULL;
            }
        case 64787: /* module 253 call 19 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_mutation;
                default:
                    return NULL;
            }
        case 64788: /* module 253 call 20 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_source;
                case 1:
                    return STR_IT_destination;
                case 2:
                    return STR_IT_collection_id;
                case 3:
                    return STR_IT_params;
                default:
                    return NULL;
            }
        case 64789: /* module 253 call 21 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64790: /* module 253 call 22 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64791: /* module 253 call 23 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_key;
                case 3:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64792: /* module 253 call 24 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_account_id;
                case 2:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64793: /* module 253 call 25 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_account_id;
                case 3:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64794: /* module 253 call 26 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_owner;
                case 1:
                    return STR_IT_collection_id;
                case 2:
                    return STR_IT_descriptor;
                default:
                    return NULL;
            }
        case 64795: /* module 253 call 27 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_caller;
                case 1:
                    return STR_IT_recipient;
                case 2:
                    return STR_IT_collection_id;
                case 3:
                    return STR_IT_params;
                case 4:
                    return STR_IT_deposit_backer;
                default:
                    return NULL;
            }
        case 64796: /* module 253 call 28 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_caller;
                case 1:
                    return STR_IT_collection_id;
                case 2:
                    return STR_IT_params;
                default:
                    return NULL;
            }
        case 64797: /* module 253 call 29 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_caller;
                case 1:
                    return STR_IT_collection_id;
                case 2:
                    return STR_IT_operator;
                case 3:
                    return STR_IT_expiration;
                default:
                    return NULL;
            }
        case 64798: /* module 253 call 30 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_info;
                default:
                    return NULL;
            }
        case 64799: /* module 253 call 31 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64800: /* module 253 call 32 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_destination;
                case 1:
                    return STR_IT_ethereum_signature;
                case 2:
                    return STR_IT_ethereum_address;
                default:
                    return NULL;
            }
        case 64801: /* module 253 call 33 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_destination;
                case 1:
                    return STR_IT_ethereum_signature;
                case 2:
                    return STR_IT_ethereum_address;
                default:
                    return NULL;
            }
#ifdef SUBSTRATE_PARSER_FULL
        case 1541: /* module 6 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1542: /* module 6 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                default:
                    return NULL;
            }
        case 1544: /* module 6 call 8 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                case 1:
                    return STR_IT_new_free;
                default:
                    return NULL;
            }
#endif
        default:
            return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V3(
        pd_Method_V3_t* m,
        uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
        char* outValue, uint16_t outValueLen,
        uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 2560: /* module 10 call 0 */
            switch (itemIdx) {
                case 0: /* balances_transfer_allow_death_V3 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_transfer_allow_death_V3.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_transfer_allow_death_V3 - amount */;
                    return _toStringCompactBalance(
                            &m->basic.balances_transfer_allow_death_V3.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2562: /* module 10 call 2 */
            switch (itemIdx) {
                case 0: /* balances_force_transfer_V3 - source */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_force_transfer_V3.source,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_force_transfer_V3 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_force_transfer_V3.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* balances_force_transfer_V3 - amount */;
                    return _toStringCompactBalance(
                            &m->basic.balances_force_transfer_V3.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2563: /* module 10 call 3 */
            switch (itemIdx) {
                case 0: /* balances_transfer_keep_alive_V3 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_transfer_keep_alive_V3.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_transfer_keep_alive_V3 - amount */;
                    return _toStringCompactBalance(
                            &m->basic.balances_transfer_keep_alive_V3.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2564: /* module 10 call 4 */
            switch (itemIdx) {
                case 0: /* balances_transfer_all_V3 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_transfer_all_V3.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_transfer_all_V3 - keep_alive */;
                    return _toStringbool(
                            &m->basic.balances_transfer_all_V3.keep_alive,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2567: /* module 10 call 7 */
            switch (itemIdx) {
                case 0: /* balances_transfer_V3 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_transfer_V3.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_transfer_V3 - amount */;
                    return _toStringCompactBalance(
                            &m->basic.balances_transfer_V3.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12800: /* module 50 call 0 */
            switch (itemIdx) {
                case 0: /* marketplace_create_listing_V3 - make_asset_id */;
                    return _toStringTokenAssetId(
                            &m->basic.marketplace_create_listing_V3.make_asset_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* marketplace_create_listing_V3 - take_asset_id */;
                    return _toStringTokenAssetId(
                            &m->basic.marketplace_create_listing_V3.take_asset_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* marketplace_create_listing_V3 - amount */;
                    return _toStringCompactu128(
                            &m->basic.marketplace_create_listing_V3.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* marketplace_create_listing_V3 - price */;
                    return _toStringCompactu128(
                            &m->basic.marketplace_create_listing_V3.price,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 4: /* marketplace_create_listing_V3 - salt */;
                    return _toStringBytes(
                            &m->basic.marketplace_create_listing_V3.salt,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 5: /* marketplace_create_listing_V3 - auction_data */;
                    return _toStringOptionAuctionDataOfT(
                            &m->basic.marketplace_create_listing_V3.auction_data,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12801: /* module 50 call 1 */
            switch (itemIdx) {
                case 0: /* marketplace_cancel_listing_V3 - listing_id */;
                    return _toStringListingId(
                            &m->basic.marketplace_cancel_listing_V3.listing_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12802: /* module 50 call 2 */
            switch (itemIdx) {
                case 0: /* marketplace_fill_listing_V3 - listing_id */;
                    return _toStringListingId(
                            &m->basic.marketplace_fill_listing_V3.listing_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* marketplace_fill_listing_V3 - amount */;
                    return _toStringCompactu128(
                            &m->basic.marketplace_fill_listing_V3.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12803: /* module 50 call 3 */
            switch (itemIdx) {
                case 0: /* marketplace_place_bid_V3 - listing_id */;
                    return _toStringListingId(
                            &m->basic.marketplace_place_bid_V3.listing_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* marketplace_place_bid_V3 - price */;
                    return _toStringCompactu128(
                            &m->basic.marketplace_place_bid_V3.price,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12804: /* module 50 call 4 */
            switch (itemIdx) {
                case 0: /* marketplace_finalize_auction_V3 - listing_id */;
                    return _toStringListingId(
                            &m->basic.marketplace_finalize_auction_V3.listing_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12805: /* module 50 call 5 */
            switch (itemIdx) {
                case 0: /* marketplace_set_protocol_fee_V3 - protocol_fee */;
                    return _toStringPerbill(
                            &m->basic.marketplace_set_protocol_fee_V3.protocol_fee,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12806: /* module 50 call 6 */
            switch (itemIdx) {
                case 0: /* marketplace_force_create_listing_V3 - seller */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.marketplace_force_create_listing_V3.seller,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* marketplace_force_create_listing_V3 - make_asset_id */;
                    return _toStringTokenAssetId(
                            &m->basic.marketplace_force_create_listing_V3.make_asset_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* marketplace_force_create_listing_V3 - take_asset_id */;
                    return _toStringTokenAssetId(
                            &m->basic.marketplace_force_create_listing_V3.take_asset_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* marketplace_force_create_listing_V3 - amount */;
                    return _toStringCompactu128(
                            &m->basic.marketplace_force_create_listing_V3.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 4: /* marketplace_force_create_listing_V3 - price */;
                    return _toStringCompactu128(
                            &m->basic.marketplace_force_create_listing_V3.price,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 5: /* marketplace_force_create_listing_V3 - salt */;
                    return _toStringBytes(
                            &m->basic.marketplace_force_create_listing_V3.salt,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 6: /* marketplace_force_create_listing_V3 - auction_data */;
                    return _toStringOptionAuctionDataOfT(
                            &m->basic.marketplace_force_create_listing_V3.auction_data,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 7: /* marketplace_force_create_listing_V3 - deposit_backer */;
                    return _toStringOptionAccountIdLookupOfT(
                            &m->basic.marketplace_force_create_listing_V3.deposit_backer,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12807: /* module 50 call 7 */
            switch (itemIdx) {
                case 0: /* marketplace_force_place_bid_V3 - bidder */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.marketplace_force_place_bid_V3.bidder,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* marketplace_force_place_bid_V3 - listing_id */;
                    return _toStringListingId(
                            &m->basic.marketplace_force_place_bid_V3.listing_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* marketplace_force_place_bid_V3 - price */;
                    return _toStringCompactu128(
                            &m->basic.marketplace_force_place_bid_V3.price,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* marketplace_force_place_bid_V3 - funds_backer */;
                    return _toStringOptionAccountIdLookupOfT(
                            &m->basic.marketplace_force_place_bid_V3.funds_backer,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64768: /* module 253 call 0 */
            switch (itemIdx) {
                case 0: /* multitokens_create_collection_V3 - descriptor */;
                    return _toStringCollectionDescriptor(
                            &m->basic.multitokens_create_collection_V3.descriptor,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64769: /* module 253 call 1 */
            switch (itemIdx) {
                case 0: /* multitokens_destroy_collection_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_destroy_collection_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64770: /* module 253 call 2 */
            switch (itemIdx) {
                case 0: /* multitokens_mutate_collection_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_mutate_collection_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_mutate_collection_V3 - mutation */;
                    return _toStringCollectionMutation(
                            &m->basic.multitokens_mutate_collection_V3.mutation,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64773: /* module 253 call 5 */
            switch (itemIdx) {
                case 0: /* multitokens_burn_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_burn_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_burn_V3 - params */;
                    return _toStringBurnParamsOfT(
                            &m->basic.multitokens_burn_V3.params,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64774: /* module 253 call 6 */
            switch (itemIdx) {
                case 0: /* multitokens_transfer_V3 - recipient */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_transfer_V3.recipient,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_transfer_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_transfer_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_transfer_V3 - params */;
                    return _toStringTransferParamsOfT(
                            &m->basic.multitokens_transfer_V3.params,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64775: /* module 253 call 7 */
            switch (itemIdx) {
                case 0: /* multitokens_freeze_V3 - info */;
                    return _toStringFreezeOf(
                            &m->basic.multitokens_freeze_V3.info,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64776: /* module 253 call 8 */
            switch (itemIdx) {
                case 0: /* multitokens_thaw_V3 - info */;
                    return _toStringFreezeOf(
                            &m->basic.multitokens_thaw_V3.info,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64777: /* module 253 call 9 */
            switch (itemIdx) {
                case 0: /* multitokens_set_attribute_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_set_attribute_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_set_attribute_V3 - token_id */;
                    return _toStringOptionTokenId(
                            &m->basic.multitokens_set_attribute_V3.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_set_attribute_V3 - key */;
                    return _toStringBytes(
                            &m->basic.multitokens_set_attribute_V3.key,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_set_attribute_V3 - value */;
                    return _toStringBytes(
                            &m->basic.multitokens_set_attribute_V3.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64778: /* module 253 call 10 */
            switch (itemIdx) {
                case 0: /* multitokens_remove_attribute_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_remove_attribute_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_remove_attribute_V3 - token_id */;
                    return _toStringOptionTokenId(
                            &m->basic.multitokens_remove_attribute_V3.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_remove_attribute_V3 - key */;
                    return _toStringBytes(
                            &m->basic.multitokens_remove_attribute_V3.key,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64779: /* module 253 call 11 */
            switch (itemIdx) {
                case 0: /* multitokens_remove_all_attributes_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_remove_all_attributes_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_remove_all_attributes_V3 - token_id */;
                    return _toStringOptionTokenId(
                            &m->basic.multitokens_remove_all_attributes_V3.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_remove_all_attributes_V3 - attribute_count */;
                    return _toStringu32(
                            &m->basic.multitokens_remove_all_attributes_V3.attribute_count,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64780: /* module 253 call 12 */
            switch (itemIdx) {
                case 0: /* multitokens_batch_transfer_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_batch_transfer_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_batch_transfer_V3 - recipients */;
                    return _toStringVecTransferRecipientsOf(
                            &m->basic.multitokens_batch_transfer_V3.recipients,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64782: /* module 253 call 14 */
            switch (itemIdx) {
                case 0: /* multitokens_batch_set_attribute_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_batch_set_attribute_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_batch_set_attribute_V3 - token_id */;
                    return _toStringOptionTokenId(
                            &m->basic.multitokens_batch_set_attribute_V3.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_batch_set_attribute_V3 - attributes */;
                    return _toStringVecAttributeKeyValuePair(
                            &m->basic.multitokens_batch_set_attribute_V3.attributes,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64783: /* module 253 call 15 */
            switch (itemIdx) {
                case 0: /* multitokens_approve_collection_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_approve_collection_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_approve_collection_V3 - operator */;
                    return _toStringAccountId(
                            &m->basic.multitokens_approve_collection_V3.operator_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_approve_collection_V3 - expiration */;
                    return _toStringOptionu32(
                            &m->basic.multitokens_approve_collection_V3.expiration,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64784: /* module 253 call 16 */
            switch (itemIdx) {
                case 0: /* multitokens_unapprove_collection_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_unapprove_collection_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_unapprove_collection_V3 - operator */;
                    return _toStringAccountId(
                            &m->basic.multitokens_unapprove_collection_V3.operator_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64785: /* module 253 call 17 */
            switch (itemIdx) {
                case 0: /* multitokens_approve_token_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_approve_token_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_approve_token_V3 - token_id */;
                    return _toStringCompactTokenId(
                            &m->basic.multitokens_approve_token_V3.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_approve_token_V3 - operator */;
                    return _toStringAccountId(
                            &m->basic.multitokens_approve_token_V3.operator_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_approve_token_V3 - amount */;
                    return _toStringCompactBalance(
                            &m->basic.multitokens_approve_token_V3.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 4: /* multitokens_approve_token_V3 - expiration */;
                    return _toStringOptionu32(
                            &m->basic.multitokens_approve_token_V3.expiration,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 5: /* multitokens_approve_token_V3 - current_amount */;
                    return _toStringCompactBalance(
                            &m->basic.multitokens_approve_token_V3.current_amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64786: /* module 253 call 18 */
            switch (itemIdx) {
                case 0: /* multitokens_unapprove_token_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_unapprove_token_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_unapprove_token_V3 - token_id */;
                    return _toStringCompactTokenId(
                            &m->basic.multitokens_unapprove_token_V3.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_unapprove_token_V3 - operator */;
                    return _toStringAccountId(
                            &m->basic.multitokens_unapprove_token_V3.operator_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64800: /* module 253 call 32 */
            switch (itemIdx) {
                case 0: /* multitokens_claim_collections_V3 - destination */;
                    return _toStringAccountId(
                            &m->basic.multitokens_claim_collections_V3.destination,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_claim_collections_V3 - ethereum_signature */;
                    return _toStringEcdsaSignature(
                            &m->basic.multitokens_claim_collections_V3.ethereum_signature,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_claim_collections_V3 - ethereum_address */;
                    return _toStringEthereumAddress(
                            &m->basic.multitokens_claim_collections_V3.ethereum_address,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64801: /* module 253 call 33 */
            switch (itemIdx) {
                case 0: /* multitokens_claim_tokens_V3 - destination */;
                    return _toStringAccountId(
                            &m->basic.multitokens_claim_tokens_V3.destination,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_claim_tokens_V3 - ethereum_signature */;
                    return _toStringEcdsaSignature(
                            &m->basic.multitokens_claim_tokens_V3.ethereum_signature,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_claim_tokens_V3 - ethereum_address */;
                    return _toStringEthereumAddress(
                            &m->basic.multitokens_claim_tokens_V3.ethereum_address,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
        case 64771: /* module 253 call 3 */
            switch (itemIdx) {
                case 0: /* multitokens_mutate_token_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_mutate_token_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_mutate_token_V3 - token_id */;
                    return _toStringCompactTokenId(
                            &m->basic.multitokens_mutate_token_V3.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_mutate_token_V3 - mutation */;
                    return _toStringTokenMutation(
                            &m->basic.multitokens_mutate_token_V3.mutation,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64772: /* module 253 call 4 */
            switch (itemIdx) {
                case 0: /* multitokens_mint_V3 - recipient */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_mint_V3.recipient,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_mint_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_mint_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_mint_V3 - params */;
                    return _toStringMintParamsOf(
                            &m->basic.multitokens_mint_V3.params,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64781: /* module 253 call 13 */
            switch (itemIdx) {
                case 0: /* multitokens_batch_mint_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_batch_mint_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_batch_mint_V3 - recipients */;
                    return _toStringVecMintRecipientsOf(
                            &m->basic.multitokens_batch_mint_V3.recipients,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1538: /* module 6 call 2 */
            switch (itemIdx) {
                case 0: /* balances_force_transfer_V3 - source */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_force_transfer_V3.source,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_force_transfer_V3 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_force_transfer_V3.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* balances_force_transfer_V3 - amount */;
                    return _toStringCompactBalance(
                            &m->basic.balances_force_transfer_V3.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1541: /* module 6 call 5 */
            switch (itemIdx) {
                case 0: /* balances_force_unreserve_V34 - who */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_force_unreserve_V3.who,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_force_unreserve_V34 - amount */;
                    return _toStringBalance(
                            &m->basic.balances_force_unreserve_V3.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1542: /* module 6 call 6 */
            switch (itemIdx) {
                case 0: /* balances_upgrade_accounts_V34 - who */;
                    return _toStringVecAccountId(
                            &m->basic.balances_upgrade_accounts_V3.who,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1544: /* module 6 call 8 */
            switch (itemIdx) {
                case 0: /* balances_force_set_balance_V34 - who */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_force_set_balance_V3.who,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_force_set_balance_V34 - new_free */;
                    return _toStringCompactBalance(
                            &m->basic.balances_force_set_balance_V3.new_free,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64787: /* module 253 call 19 */
            switch (itemIdx) {
                case 0: /* multitokens_force_mutate_collection_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_mutate_collection_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_mutate_collection_V3 - mutation */;
                    return _toStringCollectionMutation(
                            &m->basic.multitokens_force_mutate_collection_V3.mutation,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64788: /* module 253 call 20 */
            switch (itemIdx) {
                case 0: /* multitokens_force_transfer_V3 - source */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_force_transfer_V3.source,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_transfer_V3 - destination */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_force_transfer_V3.destination,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_transfer_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_transfer_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_force_transfer_V3 - params */;
                    return _toStringTransferParamsOfT(
                            &m->basic.multitokens_force_transfer_V3.params,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64789: /* module 253 call 21 */
            switch (itemIdx) {
                case 0: /* multitokens_force_set_collection_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_set_collection_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_set_collection_V3 - value */;
                    return _toStringOptionCollectionOf(
                            &m->basic.multitokens_force_set_collection_V3.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64790: /* module 253 call 22 */
            switch (itemIdx) {
                case 0: /* multitokens_force_set_token_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_set_token_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_set_token_V3 - token_id */;
                    return _toStringCompactTokenId(
                            &m->basic.multitokens_force_set_token_V3.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_set_token_V3 - value */;
                    return _toStringOptionTokenOf(
                            &m->basic.multitokens_force_set_token_V3.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64791: /* module 253 call 23 */
            switch (itemIdx) {
                case 0: /* multitokens_force_set_attribute_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_set_attribute_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_set_attribute_V3 - token_id */;
                    return _toStringOptionTokenId(
                            &m->basic.multitokens_force_set_attribute_V3.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_set_attribute_V3 - key */;
                    return _toStringBytes(
                            &m->basic.multitokens_force_set_attribute_V3.key,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_force_set_attribute_V3 - value */;
                    return _toStringOptionAttributeOf(
                            &m->basic.multitokens_force_set_attribute_V3.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64792: /* module 253 call 24 */
            switch (itemIdx) {
                case 0: /* multitokens_force_set_collection_account_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_set_collection_account_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_set_collection_account_V3 - account_id */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_force_set_collection_account_V3.account_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_set_collection_account_V3 - value */;
                    return _toStringOptionCollectionAccountOf(
                            &m->basic.multitokens_force_set_collection_account_V3.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64793: /* module 253 call 25 */
            switch (itemIdx) {
                case 0: /* multitokens_force_set_token_account_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_set_token_account_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_set_token_account_V3 - token_id */;
                    return _toStringCompactTokenId(
                            &m->basic.multitokens_force_set_token_account_V3.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_set_token_account_V3 - account_id */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_force_set_token_account_V3.account_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_force_set_token_account_V3 - value */;
                    return _toStringOptionTokenAccountOf(
                            &m->basic.multitokens_force_set_token_account_V3.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64794: /* module 253 call 26 */
            switch (itemIdx) {
                case 0: /* multitokens_force_create_collection_V3 - owner */;
                    return _toStringAccountId(
                            &m->basic.multitokens_force_create_collection_V3.owner,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_create_collection_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_create_collection_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_create_collection_V3 - descriptor */;
                    return _toStringCollectionDescriptor(
                            &m->basic.multitokens_force_create_collection_V3.descriptor,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64795: /* module 253 call 27 */
            switch (itemIdx) {
                case 0: /* multitokens_force_mint_V3 - caller */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_force_mint_V3.caller,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_mint_V3 - recipient */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_force_mint_V3.recipient,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_mint_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_mint_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_force_mint_V3 - params */;
                    return _toStringMintParamsOf(
                            &m->basic.multitokens_force_mint_V3.params,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 4: /* multitokens_force_mint_V3 - deposit_backer */;
                    return _toStringOptionAccountIdLookupOfT(
                            &m->basic.multitokens_force_mint_V3.deposit_backer,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64796: /* module 253 call 28 */
            switch (itemIdx) {
                case 0: /* multitokens_force_burn_V3 - caller */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_force_burn_V3.caller,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_burn_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_burn_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_burn_V3 - params */;
                    return _toStringBurnParamsOfT(
                            &m->basic.multitokens_force_burn_V3.params,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64797: /* module 253 call 29 */
            switch (itemIdx) {
                case 0: /* multitokens_force_approve_collection_V3 - caller */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_force_approve_collection_V3.caller,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_approve_collection_V3 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_approve_collection_V3.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_approve_collection_V3 - operator */;
                    return _toStringAccountId(
                            &m->basic.multitokens_force_approve_collection_V3.operator_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_force_approve_collection_V3 - expiration */;
                    return _toStringOptionu32(
                            &m->basic.multitokens_force_approve_collection_V3.expiration,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64798: /* module 253 call 30 */
            switch (itemIdx) {
                case 0: /* multitokens_force_freeze_V3 - info */;
                    return _toStringFreezeOf(
                            &m->basic.multitokens_force_freeze_V3.info,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64799: /* module 253 call 31 */
            switch (itemIdx) {
                case 0: /* multitokens_force_set_next_collection_id_V3 - value */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_set_next_collection_id_V3.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
#endif
#endif
        default:
            return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V3(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        default:
            return false;
    }
}