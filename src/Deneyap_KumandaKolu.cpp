/*
*******************************************************************************
@file         Deneyap_KumandaKolu.cpp
@mainpage     Deneyap Joystick Arduino library source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.0.0
@date         June 22, 2022
@brief        Includes functions to control Deneyap Joystick  Arduino library

Library includes: 
--> Configuration functions
--> Data manipulation functions
--> I2C communication functions
*******************************************************************************
*/

#include "Deneyap_KumandaKolu.h"

/* Device Status Functions ---------------------------------------------------*/

/**
 * @brief  Configures I2C connection with user defined address and port
 * @param  address: I2C address of the device, port: I2C port number (0 or 1)
 * @retval connection status (1 --> connected, 0 --> not connected)
 */
bool Joystick::begin(uint8_t address, TwoWire &port) {
    Wire.begin();
#if defined(ARDUINO_DYM)
    Wire.setClock(100000);
#else
    Wire.setClock(50000);
#endif
    _address = address;
    _i2cPort = &port;
    _dataPacket = {0};

    return isConnected();
}

/**
 * @brief  Checks whether I2C connection established
 * @param  None
 * @retval connection status (1 --> connected, 0 --> not connected)
 */
bool Joystick::isConnected() {
    _i2cPort->beginTransmission(_address);

    if (_i2cPort->endTransmission() == 0)
        return true;
    return false;
}

/**
 * @brief  Requests firmware version of the device
 * @param  None
 * @retval Device firmware version
 */
uint16_t Joystick::getFwVersion() {
    _dataPacket.command = JOYSTICK_REQUEST_FW_VERSION;
    _dataPacket.dataSize = 0;
    return I2C_ReadFirmwareData16bit(&_dataPacket);
}

/**
 * @brief  Sets (changes) I2C address of the device
 * @param  address: I2C address to be set
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */

bool Joystick::setI2Caddress(uint8_t newAddress) {
    _dataPacket.command = JOYSTICK_CHANGE_ADDR;
    _dataPacket.dataSize = 1;
    _dataPacket.data[0] = newAddress;

    bool status = I2C_SendDataPacket(&_dataPacket);

    if (status == true) {
        _address = newAddress;
        return true;
    }
    else {
        return false;
    }
}

/* I2C Data Manipulation Functions -------------------------------------------*/

/**
 * @brief  Reads the OUT_SW pin
 * @param  None
 * @retval BitStatus : OUT_SW pin status
 */
bool Joystick::swRead() {
    _dataPacket.command = (uint8_t)READ_SW;
    _dataPacket.dataSize = 0;
    return I2C_ReadData8bit(&_dataPacket);
}

/**
 * @brief  Reads the OUT_X pin
 * @param  None
 * @retval uint16_t : OUT_X pin value
 */
uint16_t Joystick::xRead() {
    _dataPacket.command = (uint8_t)READ_X;
    _dataPacket.dataSize = 0;
    return I2C_ReadData16bit(&_dataPacket);
}

/**
 * @brief  Reads the OUT_Y pin
 * @param  None
 * @retval uint16_t : OUT_Y pin value
 */
uint16_t Joystick::yRead() {
    _dataPacket.command = (uint8_t)READ_Y;
    _dataPacket.dataSize = 0;
    return I2C_ReadData16bit(&_dataPacket);
}

/* I2C Data Transaction Funstions --------------------------------------------*/

/**
 * @brief  Reads 8bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 8bit data
 */
uint8_t Joystick::I2C_ReadData8bit(Joystick_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_address);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_address, static_cast<uint8_t>(1)) != 0)
        return _i2cPort->read();
    return 0;
}

/**
 * @brief  Reads 16bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 16bit data
 */
uint16_t Joystick::I2C_ReadData16bit(Joystick_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_address);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_address, static_cast<uint8_t>(2)) != 0) {
        uint16_t i2cData = _i2cPort->read();
        i2cData |= (_i2cPort->read() << 8);
        return i2cData;
    }
    return 0;
}

/**
 * @brief  Reads 16bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 16bit data
 */
uint16_t Joystick::I2C_ReadFirmwareData16bit(Joystick_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_address);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_address, static_cast<uint8_t>(2)) != 0) {
        i2cData2 = _i2cPort->read();
        i2cData1 = _i2cPort->read();
        Serial.printf("\nv%x.%x", i2cData1, i2cData2);
    }
    return 0;
}

/**
 * @brief  Sends data packet based on a custom defined protocol
 * @param  dataPacket: includes all related data
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */
bool Joystick::I2C_SendDataPacket(Joystick_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_address);
    _i2cPort->write(dataPacket->command);
    _i2cPort->write(dataPacket->dataSize);

    for (uint8_t i = 0; i < _dataPacket.dataSize; i++)
        _i2cPort->write(_dataPacket.data[i]);

    if (_i2cPort->endTransmission() == 0)
        return true;
    return false;
}
