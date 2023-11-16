# Enjin Matrixchain 3.605.x

## Balances

| Name                   | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                               |
| ---------------------- | ------------------ | ------------------ | ------------------ |---------|-----------------------------------------------------------------------------------------|
| Transfer allow death   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Force transfer         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/> |
| Transfer keep alive    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Transfer all           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                      |
| Transfer               | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Force unreserve        |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                        |
| Upgrade accounts       |                    | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`who<br/>                                                                  |
| Force set balance      |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>                               |

## FuelTanks

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
|------------------------------|--------|-----------|------------------|---------|-----------|
| Add account                  |        |           |                  |         |           |
| Batch add account            |        |           |                  |         |           |
| Batch remove account         |        |           |                  |         |           |
| Create fuel tank             |        |           |                  |         |           |
| Destroy fuel tank            |        |           |                  |         |           |
| Dispatch                     |        |           |                  |         |           |
| Dispatch and touch           |        |           |                  |         |           |
| Force batch add account      |        |           |                  |         |           |
| Force create fuel tank       |        |           |                  |         |           |
| Force set consumption        |        |           |                  |         |           |
| Insert rule set              |        |           |                  |         |           |
| Mutate fuel tank             |        |           |                  |         |           |
| Remove account               |        |           |                  |         |           |
| Remove account rule data     |        |           |                  |         |           |
| Remove rule set              |        |           |                  |         |           |
| Schedule mutate freeze state |        |           |                  |         |           |

## Marketplace

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
|------------------------------|--------|-----------|------------------|---------|-----------|
| Cancel listing               |        |           |                  |         |           |
| Create listing               |        |           |                  |         |           |
| Fill listing                 |        |           |                  |         |           |
| Finalize auction             |        |           |                  |         |           |
| Force create listing         |        |           |                  |         |           |
| Force place bid              |        |           |                  |         |           |
| Place bid                    |        |           |                  |         |           |
| Set protocol fee             |        |           |                  |         |           |

## MultiTokens

| Name                         | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                           |
|------------------------------|--------------------|--------------------|--------------------|---------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Approve collection           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`AccountId`operator<br/>`Expiration`expiration<br/>                                                                                 |
| Approve token                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`AccountId`operator<br/>`TokenBalance`amount<br/>`Expiration`expiration<br/>`TokenBalance`current_amount<br/> |
| Batch mint                   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`VecMintRecipientsOf`recipients<br/>                                                                                                |
| Batch set attribute          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`VecAttributesOf`attributes<br/>                                                                              |
| Batch transfer               | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`VecTransferRecipientsOf`recipients<br/>                                                                                            |
| Burn                         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`BurnParamsOf`params<br/>                                                                                                           |
| Claim collections            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`destination<br/>`SpCoreEcdsaSignature`ethereum_signature<br/>`H160`ethereum_address<br/>                                                                 |
| Claim tokens                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`destination<br/>`SpCoreEcdsaSignature`ethereum_signature<br/>`H160`ethereum_address<br/>                                                                 |
| Create collection            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionDescriptor`descriptor<br/>                                                                                                                               |
| Destroy collection           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>                                                                                                                                    |
| Force approve collection     |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`AccountId`operator<br/>`Expiration`expiration<br/>                                                                                 |
| Force burn                   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`BurnParamsOf`params<br/>                                                                                                           |
| Force create collection      |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionDescriptor`descriptor<br/>                                                                                                                               |
| Force freeze                 |                    | :heavy_check_mark: | :heavy_check_mark: |         | `FreezeOf`info                                                                                                                                                      |
| Force mint                   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`recipient<br/>`CollectionId`collectionId<br/>`MintParamsOf`params<br/>                                                                         |
| Force mutate collection      |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`CollectionMutation`mutation<br/>                                                                                                   |
| Force set attribute          |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`Bytes`key<br/>`Bytes`value<br/>                                                                              |
| Force set collection         |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`CollectionOf`value<br/>                                                                                                            |
| Force set collection account |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`AccountIdLookupOfT`account_id<br/>`CollectionAccountOf`value<br/>                                                                  |
| Force set next collection id |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`value<br/>                                                                                                                                            |
| Force set token              |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`TokenOf`value<br/>                                                                                           |
| Force set token account      |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`AccountIdLookupOfT`account_id<br/>`TokenAccountOf`value<br/>                                                 |
| Force transfer               |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`destination<br/>`CollectionId`collectionId<br/>`TransferParamsOf`params<br/>                                    |
| Freeze                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `FreezeOf`info                                                                                                                                                      |
| Mint                         |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`recipient<br/>`CollectionId`collectionId<br/>`MintParamsOf`params<br/>                                                                         |
| Mutate collection            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`CollectionMutation`mutation<br/>                                                                                                   |
| Mutate token                 |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`TokenMutation`mutation<br/>                                                                                  |
| Remove all attributes        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`u32`attribute_count<br/>                                                                                     |
| Remove attribute             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`Bytes`key<br/>                                                                                               |
| Set attribute                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`Bytes`key<br/>`Bytes`value<br/>                                                                              |
| Thaw                         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `FreezeOf`info<br/>                                                                                                                                                 |
| Transfer                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`recipient<br/>`CollectionId`collectionId<br/>`TransferParamsOf`params<br/>                                                                     |
| Unapprove collection         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`AccountId`operator<br/>                                                                                                            |
| Unapprove token              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`AccountId`operator<br/>                                                                                      |


