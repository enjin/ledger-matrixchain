# Enjin Matrixchain 3.603.x

## Balances

| Name                   | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                  |
| ---------------------- | ------------------ | ------------------ | ------------------ |---------| ------------------------------------------------------------------------------------------ |
| Transfer allow death   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Force transfer         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Transfer               | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
