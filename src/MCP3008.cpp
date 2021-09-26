// MIT License
//
// Copyright (c) 2021 Daniel Robertson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "../include/MCP3008.h"
#include <cstdint>
#include <lgpio.h>
#include <stdexcept>

namespace MCP3008 {

MCP3008::MCP3008(
    const int dev,
    const int channel,
    const int baud,
    const int flags) noexcept :
        _handle(-1),
        _dev(dev),
        _channel(channel),
        _baud(baud),
        _flags(flags) {
}

MCP3008::~MCP3008() {
    this->disconnect();
}

void MCP3008::connect() {

    if(this->_handle >= 0) {
        return;
    }

    const int handle = ::lgSpiOpen(
        this->_dev,
        this->_channel,
        this->_baud,
        this->_flags);

    if(handle < 0) {
        throw std::runtime_error("failed to open spi device");
    }

    this->_handle = handle;

}

void MCP3008::disconnect() {

    if(this->_handle < 0) {
        return;
    }

    ::lgSpiClose(this->_handle);

    this->_handle = -1;

}

unsigned short MCP3008::read(const std::uint8_t channel) const {

    const int count = 3;

    const std::uint8_t txData[count] = {
        1,
        static_cast<std::uint8_t>(0b10000000) | (channel << 4),
        0 };

    std::uint8_t rxData[count]{0};

    const int bytesTransferred = ::lgSpiXfer(
        this->_handle,
        static_cast<const char*>(txData),
        static_cast<char*>(rxData),
        count);

    if(bytesTransferred < 0) {
        throw std::runtime_error("spi transfer failed");
    }

    return ((rxData[1] << 8) | rxData[2]) & 0x3ff;

}

};
