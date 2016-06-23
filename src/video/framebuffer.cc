#include "framebuffer.h"

FrameBuffer::FrameBuffer() {
    /* Set the whole framebuffer to be black */
    for (unsigned x = 0; x < GAMEBOY_WIDTH; x++) {
        for (unsigned y = 0; y < GAMEBOY_HEIGHT; y++) {
            set_pixel(x, y, Color::Color0);
        }
    }
}

void FrameBuffer::set_pixel(uint x, uint y, Color color) {
    buffer[pixel_index(x, y)] = color;
}

Color FrameBuffer::get_pixel(uint x, uint y) const {
    return buffer[pixel_index(x, y)];
}

inline uint FrameBuffer::pixel_index(uint x, uint y) const {
    return (y * GAMEBOY_HEIGHT) + x;
}