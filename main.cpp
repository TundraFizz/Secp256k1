// #include <secp256k1.h>
#include "secp256k1.h"
#include <iostream> // cout
#include <iomanip> // setfill, setw

static const uint8_t PRIVKEY[32] = {0xab, 0xcd, 0xef, 0x12, 0x03, 0x40, 0x56, 0x00,
                                    0x78, 0x90, 0x01, 0x11, 0x22, 0x33, 0xaa, 0xbb,
                                    0xcc, 0x24, 0x68, 0x0a, 0xbc, 0xde, 0xf0, 0x00,
                                    0x01, 0x23, 0x45, 0x67, 0x89, 0x0a, 0xbc, 0xde};

int main() {
  secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
  secp256k1_pubkey pubkey;

  // The public key must:
  // 1. Be uncompressed
  // 2. Be 64 bytes long OR 65 bytes long with the constant 0x04 prefix

  int i = secp256k1_ec_pubkey_create(ctx, &pubkey, PRIVKEY);

  uint8_t pubkey_serialized[65];
  size_t pubkeylen = sizeof(pubkey_serialized);

  // Create an uncompressed public key that's 64 bytes long
  secp256k1_ec_pubkey_serialize(ctx, pubkey_serialized, &pubkeylen, &pubkey, SECP256K1_EC_UNCOMPRESSED);

  // For a public key that's 65 bytes, skip the first byte because it's the constant 0x04 prefix
  for(int i = 1; i < 65; i++){
    std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)pubkey_serialized[i];
  }
  std::cout << "\n";

  secp256k1_context_destroy(ctx);
  return 0;
}
