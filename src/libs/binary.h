/*
    SyrDB/Binary - Library for working with binary
    [binary.h] - Main file (Annotation)
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
*/

#ifndef BINARY_H_
#define BINARY_H_

#include <iostream>
#include <vector>

typedef unsigned char byte;

namespace TheStngularity::SyrDB {
    /**
     * @brief Binary (Bytes) buffer class
     */
    class BinaryBuffer {
        private:
            std::vector<byte> buffer;  // Reader buffer
            int pos;  // Cursor position

        public:
            /**
             * @brief Construct a new Binary Buffer object
             * @param binary Content of this buffer
             */
            BinaryBuffer(std::vector<byte> binary = {});

            /**
             * @brief Read the specified size of bytes
             * @param size Number of bytes to read
             * @return Readed bytes
             */
            std::vector<byte> read(unsigned short size);

            /**
             * @brief Read the specified size of bytes
             * @param size Number of bytes to read
             * @return Readed bytes
             */
            std::vector<byte> read(unsigned int size);

            /**
             * @brief Write any bytes to buffer
             * @param binary Bytes to write
             */
            void write(std::vector<byte> binary);

            /**
             * @brief Insert any bytes to buffer by specified index
             * @param index Index of bytes insert
             * @param binary Bytes to insert
             */
            void insert(unsigned short index, std::vector<byte> binary);

            /**
             * @brief Insert any bytes to buffer by specified index
             * @param index Index of bytes insert
             * @param binary Bytes to insert
             */
            void insert(unsigned int index, std::vector<byte> binary);

            /**
             * @brief Get value from buffer
             * @return Buffer content
             */
            std::vector<byte> getValue();

            /**
             * @brief Get size of buffer
             * @return Buffer size
             */
            inline size_t size();

            /**
             * @brief Is a cursor on the buffer end or no
             * @return Whether cursor on the buffer end
             */
            bool isOnEnd();

            /**
             * @brief Reset cursor position
             */
            void reset();
    }
}

#endif