/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Dan Halbert for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_SHARED_MODULE_AUDIOIO__INIT__H
#define MICROPY_INCLUDED_SHARED_MODULE_AUDIOIO__INIT__H

#include <stdbool.h>
#include <stdint.h>

#include "py/obj.h"

typedef enum {
    GET_BUFFER_DONE,            // No more data to read
    GET_BUFFER_MORE_DATA,       // More data to read.
    GET_BUFFER_ERROR,           // Error while reading data.
} audioio_get_buffer_result_t;

uint32_t audiosample_sample_rate(mp_obj_t sample_obj);
uint8_t audiosample_bits_per_sample(mp_obj_t sample_obj);
uint8_t audiosample_channel_count(mp_obj_t sample_obj);
void audiosample_reset_buffer(mp_obj_t sample_obj, bool single_channel, uint8_t audio_channel);
audioio_get_buffer_result_t audiosample_get_buffer(mp_obj_t sample_obj,
                                                   bool single_channel,
                                                   uint8_t channel,
                                                   uint8_t** buffer, uint32_t* buffer_length);
void audiosample_get_buffer_structure(mp_obj_t sample_obj, bool single_channel,
                                      bool* single_buffer, bool* samples_signed,
                                      uint32_t* max_buffer_length, uint8_t* spacing);

#endif  // MICROPY_INCLUDED_SHARED_MODULE_AUDIOIO__INIT__H
