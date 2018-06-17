/*
 * Copyright (C) 2018 Southern Storm Software, Pty Ltd.
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

#include "Noise_XXfallback_25519_ChaChaPoly_SHA256.h"

/**
 * \class NoiseHandshakeState_XXfallback_25519_ChaChaPoly_SHA256 Noise_XXfallback_25519_ChaChaPoly_SHA256.h <Noise_XXfallback_25519_ChaChaPoly_SHA256.h>
 * \brief "XXfallback" Noise handshake, using Curve25519, ChaChaPoly, and SHA256.
 */

/**
 * \class Noise_XXfallback_25519_ChaChaPoly_SHA256 Noise_XXfallback_25519_ChaChaPoly_SHA256.h <Noise_XXfallback_25519_ChaChaPoly_SHA256.h>
 * \brief "XXfallback" Noise descriptor, using Curve25519, ChaChaPoly, and SHA256.
 */

static char const Noise_XXfallback_25519_ChaChaPoly_SHA256_Name[] =
    "Noise_XXfallback_25519_ChaChaPoly_SHA256";

NoiseHandshakeState_XXfallback_25519_ChaChaPoly_SHA256::NoiseHandshakeState_XXfallback_25519_ChaChaPoly_SHA256()
{
    setSymmetricState(&sym);
    setDHState(&dh);
    setProtocolName(Noise_XXfallback_25519_ChaChaPoly_SHA256_Name);
}

NoiseHandshakeState_XXfallback_25519_ChaChaPoly_SHA256::~NoiseHandshakeState_XXfallback_25519_ChaChaPoly_SHA256()
{
}

Noise_XXfallback_25519_ChaChaPoly_SHA256::Noise_XXfallback_25519_ChaChaPoly_SHA256()
    : NoiseProtocolDescriptor(Noise_XXfallback_25519_ChaChaPoly_SHA256_Name)
{
}

Noise_XXfallback_25519_ChaChaPoly_SHA256::~Noise_XXfallback_25519_ChaChaPoly_SHA256()
{
}

NoiseHandshakeState *Noise_XXfallback_25519_ChaChaPoly_SHA256::createHandshake() const
{
    return new NoiseHandshakeState_XXfallback_25519_ChaChaPoly_SHA256();
}