/*
    SyrDB/Binary - Library for working with binary
    [binary.cpp] - Main file
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
*/

#include <vector>
#include "binary.h"

namespace TheStngularity::SyrDB {
    BinaryBuffer::BinaryBuffer() {
        this->buffer = {};
        this->pos = 0;
    }

    BinaryBuffer::BinaryBuffer(std::vector<byte> binary) {
        this->buffer = binary;
        this->pos = 0;
    }

    // Read the specified size of bytes
    std::vector<byte> BinaryBuffer::read(unsigned int size) {
        std::vector<byte> output;
        for(unsigned int i = 0; i < size && this->pos < this->size(); i++) {
            output.push_back(this->buffer[this->pos + i]);
            this->pos++;
        } return output;
    }

    // Write any bytes to buffer
    void BinaryBuffer::write(std::vector<byte> binary) {
        for(unsigned int i = 0; i <= binary.size(); i++)
            this->buffer.push_back(binary[i]);
    }

    // Insert any bytes to buffer by specified index
    void BinaryBuffer::insert(unsigned int index, std::vector<byte> binary) {
        for(unsigned int i = 0; i <= binary.size(); i++)
            this->buffer.emplace(this->buffer.cbegin()+index-1+i, binary[i]);
    }

    // Get value from buffer
    std::vector<byte> BinaryBuffer::getValue() {
        return this->buffer;
    }

    // Get size of buffer
    inline std::size_t BinaryBuffer::size() {
        return this->buffer.size();
    }

    // Is a cursor on the buffer end or no
    bool BinaryBuffer::isOnEnd() {
        return this->pos >= this->size();
    }

    // Reset cursor position
    void BinaryBuffer::reset() {
        this->pos = 0;
    }
}