Embedded Cryptography Library
=============================

This repository contains cryptographic algorithms for the ESP8266 and ESP32.

The [documentation](http://rweather.github.io/arduinolibs/crypto.html)
contains more information on the libraries and examples.

This library was [originally created](https://github.com/rweather/arduinolibs)
by Rhys Weatherley.

Changes in this fork
--------------------

* Support for the following has been removed:
  * AES
  * OMAC
  * SHA224
  * SHA3
  * SHA384
* The RNG code has been significantly simplified

Recent significant changes to the library
-----------------------------------------

Jan 2022:

* All-in-one hmac() function in Hash.h for simplified HMAC computations.
* New API for the HKDF hash-based key derivation function.
* Make the ESP32 version of AES less dependent on include file locations.

Apr 2018:

* Acorn128 and Ascon128 authenticated ciphers (finalists in the CAESAR AEAD
  competition in the light-weight category).
* Split the library into Crypto (core), CryptoLW (light-weight), and
  CryptoLegacy (deprecated algorithms).
* Tiny and small versions of AES for reducing memory requirements.
* Port the library to ESP8266 and ESP32.
* Make the RNG class more robust if the app doesn't call begin() or loop().

Nov 2017:

* Fix the AVR assembly version of Speck and speed it up a little.
* API improvements to the RNG class.
