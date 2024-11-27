typedef struct {
                    i2c_inst_t *i2c;
                    uint8_t addr;
                    uint8_t sda_pin;
                    uint8_t scl_pin;
                    uint32_t clock;
                    float _current_lsb;
                } ina219_t;