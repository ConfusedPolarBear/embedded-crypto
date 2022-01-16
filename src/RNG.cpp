/*
 * Copyright (C) 2015 Southern Storm Software, Pty Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "RNG.h"
#include "ChaCha.h"
#include "Crypto.h"
#include <Arduino.h>
#include "utility/ProgMemUtil.h"

#if defined(ESP8266)
// ESP8266 does not have EEPROM but it does have SPI flash memory.
// It also has a TRNG register for generating "true" random numbers.
// For now we use the TRNG but don't save the seed in flash memory.
#define RNG_WORD_TRNG 1
#define RNG_WORD_TRNG_GET() (ESP8266_DREG(0x20E44))
#elif defined(ESP32)
// ESP32 has a word-based TRNG and an API for Non-Volatile Storage (NVS).
#define RNG_WORD_TRNG 1
#define RNG_WORD_TRNG_GET() (esp_random())
#else
#error "no hardware RNG detected"
#endif

/**
 * \class RNGClass RNG.h <RNG.h>
 * \brief Random number generator suitable for cryptography.
 *
 */

/**
 * \brief Global random number generator instance.
 *
 * \sa RNGClass
 */
RNGClass RNG;

/**
 * \brief Constructs a new random number generator instance.
 *
 * \sa begin()
 */
RNGClass::RNGClass()
{
}

/**
 * \brief Destroys this random number generator instance.
 */
RNGClass::~RNGClass()
{
}

/**
 * \brief Generates random bytes into a caller-supplied buffer.
 *
 * \param data Points to the buffer to fill with random bytes.
 * \param len Number of bytes to generate.
 */
void RNGClass::rand(uint8_t *data, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        data[i] = RNG_WORD_TRNG_GET();
    }
}
