#pragma once

// auto-generated by cxsdk.py
#define _NR_cx_aes_dec_block                         0x00
#define _NR_cx_aes_enc_block                         0x01
#define _NR_cx_aes_gcm_check_tag                     0x02
#define _NR_cx_aes_gcm_decrypt_and_auth              0x03
#define _NR_cx_aes_gcm_encrypt_and_tag               0x04
#define _NR_cx_aes_gcm_finish                        0x05
#define _NR_cx_aes_gcm_init                          0x06
#define _NR_cx_aes_gcm_set_key                       0x07
#define _NR_cx_aes_gcm_start                         0x08
#define _NR_cx_aes_gcm_update_aad                    0x09
#define _NR_cx_aes_gcm_update                        0x0a
#define _NR_cx_aes_init_key_no_throw                 0x0b
#define _NR_cx_aes_iv_no_throw                       0x0c
#define _NR_cx_aes_no_throw                          0x0d
#define _NR_cx_aes_siv_encrypt                       0x0e
#define _NR_cx_aes_siv_decrypt                       0x0f
#define _NR_cx_aes_siv_init                          0x10
#define _NR_cx_aes_siv_set_key                       0x11
#define _NR_cx_aes_siv_start                         0x12
#define _NR_cx_aes_siv_update_aad                    0x13
#define _NR_cx_aes_siv_finish                        0x14
#define _NR_cx_aes_siv_update                        0x15
#define _NR_cx_blake2b                               0x16
#define _NR_cx_blake2b_final                         0x17
#define _NR_cx_blake2b_get_output_size               0x18
#define _NR_cx_blake2b_init2_no_throw                0x19
#define _NR_cx_blake2b_init_no_throw                 0x1a
#define _NR_cx_blake2b_update                        0x1b
#define _NR_cx_cipher_enc_dec                        0x1c
#define _NR_cx_cipher_finish                         0x1d
#define _NR_cx_cipher_init                           0x1e
#define _NR_cx_cipher_setiv                          0x1f
#define _NR_cx_cipher_setkey                         0x20
#define _NR_cx_cipher_setup                          0x21
#define _NR_cx_cipher_set_padding                    0x22
#define _NR_cx_cipher_update                         0x23
#define _NR_cx_cmac                                  0x24
#define _NR_cx_constant_time_eq                      0x25
#define _NR_cx_crc16                                 0x26
#define _NR_cx_crc16_update                          0x27
#define _NR_cx_crc32                                 0x28
#define _NR_cx_decode_coord                          0x29
#define _NR_cx_des_dec_block                         0x2a
#define _NR_cx_des_enc_block                         0x2b
#define _NR_cx_des_init_key_no_throw                 0x2c
#define _NR_cx_des_iv_no_throw                       0x2d
#define _NR_cx_des_no_throw                          0x2e
#define _NR_cx_ecdh_no_throw                         0x2f
#define _NR_cx_ecdsa_sign_no_throw                   0x30
#define _NR_cx_ecdsa_verify_no_throw                 0x31
#define _NR_cx_ecfp_add_point_no_throw               0x32
#define _NR_cx_ecfp_decode_sig_der                   0x33
#define _NR_cx_ecfp_encode_sig_der                   0x34
#define _NR_cx_ecfp_generate_pair2_no_throw          0x35
#define _NR_cx_ecfp_generate_pair_no_throw           0x36
#define _NR_cx_ecfp_init_private_key_no_throw        0x37
#define _NR_cx_ecfp_init_public_key_no_throw         0x38
#define _NR_cx_ecfp_scalar_mult_no_throw             0x39
#define _NR_cx_ecschnorr_sign_no_throw               0x3a
#define _NR_cx_ecschnorr_verify                      0x3b
#define _NR_cx_eddsa_get_public_key_internal         0x3c
#define _NR_cx_eddsa_get_public_key_no_throw         0x3d
#define _NR_cx_eddsa_sign_no_throw                   0x3e
#define _NR_cx_eddsa_verify_no_throw                 0x3f
#define _NR_cx_edwards_compress_point_no_throw       0x40
#define _NR_cx_edwards_decompress_point_no_throw     0x41
#define _NR_cx_encode_coord                          0x42
#define _NR_cx_hash_final                            0x43
#define _NR_cx_hash_get_info                         0x44
#define _NR_cx_hash_get_size                         0x45
#define _NR_cx_hash_init                             0x46
#define _NR_cx_hash_init_ex                          0x47
#define _NR_cx_hash_no_throw                         0x48
#define _NR_cx_hash_ripemd160                        0x49
#define _NR_cx_hash_sha256                           0x4a
#define _NR_cx_hash_sha512                           0x4b
#define _NR_cx_hash_update                           0x4c
#define _NR_cx_hkdf_expand                           0x4d
#define _NR_cx_hkdf_extract                          0x4e
#define _NR_cx_hmac_final                            0x4f
#define _NR_cx_hmac_init                             0x50
#define _NR_cx_hmac_no_throw                         0x51
#define _NR_cx_hmac_ripemd160_init_no_throw          0x52
#define _NR_cx_hmac_sha224_init                      0x53
#define _NR_cx_hmac_sha256                           0x54
#define _NR_cx_hmac_sha256_init_no_throw             0x55
#define _NR_cx_hmac_sha384_init                      0x56
#define _NR_cx_hmac_sha512                           0x57
#define _NR_cx_hmac_sha512_init_no_throw             0x58
#define _NR_cx_hmac_update                           0x59
#define _NR_cx_keccak_init_no_throw                  0x5a
#define _NR_cx_math_addm_no_throw                    0x5b
#define _NR_cx_math_add_no_throw                     0x5c
#define _NR_cx_math_cmp_no_throw                     0x5d
#define _NR_cx_math_invintm_no_throw                 0x5e
#define _NR_cx_math_invprimem_no_throw               0x5f
#define _NR_cx_math_is_prime_no_throw                0x60
#define _NR_cx_math_modm_no_throw                    0x61
#define _NR_cx_math_multm_no_throw                   0x62
#define _NR_cx_math_mult_no_throw                    0x63
#define _NR_cx_math_next_prime_no_throw              0x64
#define _NR_cx_math_powm_no_throw                    0x65
#define _NR_cx_math_subm_no_throw                    0x66
#define _NR_cx_math_sub_no_throw                     0x67
#define _NR_cx_memxor                                0x68
#define _NR_cx_pbkdf2_hmac                           0x69
#define _NR_cx_pbkdf2_no_throw                       0x6a
#define _NR_cx_ripemd160_final                       0x6b
#define _NR_cx_ripemd160_init_no_throw               0x6c
#define _NR_cx_ripemd160_update                      0x6d
#define _NR_cx_rng_no_throw                          0x6e
#define _NR_cx_rng_rfc6979                           0x6f
#define _NR_cx_rng_rfc6979_init                      0x70
#define _NR_cx_rng_rfc6979_next                      0x71
#define _NR_cx_rng_u32_range_func                    0x72
#define _NR_cx_sha224_init_no_throw                  0x73
#define _NR_cx_sha256_final                          0x74
#define _NR_cx_sha256_init_no_throw                  0x75
#define _NR_cx_sha256_update                         0x76
#define _NR_cx_sha384_init_no_throw                  0x77
#define _NR_cx_sha3_final                            0x78
#define _NR_cx_sha3_get_output_size                  0x79
#define _NR_cx_sha3_init_no_throw                    0x7a
#define _NR_cx_sha3_update                           0x7b
#define _NR_cx_sha3_xof_init_no_throw                0x7c
#define _NR_cx_sha512_final                          0x7d
#define _NR_cx_sha512_init_no_throw                  0x7e
#define _NR_cx_sha512_update                         0x7f
#define _NR_cx_shake128_init_no_throw                0x80
#define _NR_cx_shake256_init_no_throw                0x81
#define _NR_cx_swap_buffer32                         0x82
#define _NR_cx_swap_buffer64                         0x83
#define _NR_cx_swap_uint32                           0x84
#define _NR_cx_swap_uint64                           0x85
#define _NR_cx_x25519                                0x86
#define _NR_cx_x448                                  0x87
