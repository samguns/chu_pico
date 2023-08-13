/*
 * GP2Y0E Distance measurement sensor
 * WHowe <github.com/whowechina>
 */

#ifndef GP2Y0E_H
#define GP2Y0E_H

#define GP2Y0E_DEF_ADDR 0x40
#include "hardware/i2c.h"

static inline uint16_t gp2y0e_write(i2c_inst_t *i2c_port, uint8_t addr, uint8_t val)
{
    uint8_t cmd[] = {addr, val};
    i2c_write_blocking(i2c_port, GP2Y0E_DEF_ADDR, cmd, 2, false);
}

static inline uint8_t gp2y0e_dist(i2c_inst_t *i2c_port)
{
    uint8_t cmd[] = {0x5e};
    i2c_write_blocking(i2c_port, GP2Y0E_DEF_ADDR, cmd, 1, true);
    uint8_t data;
    i2c_read_blocking(i2c_port, GP2Y0E_DEF_ADDR, &data, 1, false);

    return data;
}


static inline uint16_t gp2y0e_dist16(i2c_inst_t *i2c_port)
{
    uint8_t cmd[] = {0x5e};
    i2c_write_blocking(i2c_port, GP2Y0E_DEF_ADDR, cmd, 1, true);
    uint8_t data[2];
    i2c_read_blocking(i2c_port, GP2Y0E_DEF_ADDR, data, 2, false);

    return (data[0] << 4) | data[1];
}

#endif