// Keyglove controller source code - KGAPI "bluetooth" protocol command parser declarations
// 2014-12-07 by Jeff Rowberg <jeff@rowberg.net>

/*
================================================================================
Keyglove source code is placed under the MIT license
Copyright (c) 2014 Jeff Rowberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

================================================================================
*/

/**
 * @file support_protocol_bluetooth.h
 * @brief KGAPI "bluetooth" protocol command parser declarations
 * @author Jeff Rowberg
 * @date 2014-12-07
 *
 * This file implements subsystem-specific command processing functions for the
 * "bluetooth" part of the KGAPI protocol.
 *
 * This file is autogenerated. Normally it is not necessary to edit this file.
 */

#ifndef _SUPPORT_PROTOCOL_BLUETOOTH_H_
#define _SUPPORT_PROTOCOL_BLUETOOTH_H_

/* =========================== */
/* KGAPI CONSTANT DECLARATIONS */
/* =========================== */

#define KG_PACKET_ID_CMD_BLUETOOTH_GET_MODE                 0x01
#define KG_PACKET_ID_CMD_BLUETOOTH_SET_MODE                 0x02
#define KG_PACKET_ID_CMD_BLUETOOTH_RESET                    0x03
#define KG_PACKET_ID_CMD_BLUETOOTH_GET_MAC                  0x04
#define KG_PACKET_ID_CMD_BLUETOOTH_GET_PAIRINGS             0x05
#define KG_PACKET_ID_CMD_BLUETOOTH_DISCOVER                 0x06
#define KG_PACKET_ID_CMD_BLUETOOTH_PAIR                     0x07
#define KG_PACKET_ID_CMD_BLUETOOTH_DELETE_PAIRING           0x08
#define KG_PACKET_ID_CMD_BLUETOOTH_CLEAR_PAIRINGS           0x09
#define KG_PACKET_ID_CMD_BLUETOOTH_GET_CONNECTIONS          0x0A
#define KG_PACKET_ID_CMD_BLUETOOTH_CONNECT                  0x0B
#define KG_PACKET_ID_CMD_BLUETOOTH_DISCONNECT               0x0C
// -- command/event split --
#define KG_PACKET_ID_EVT_BLUETOOTH_MODE                     0x01
#define KG_PACKET_ID_EVT_BLUETOOTH_READY                    0x02
#define KG_PACKET_ID_EVT_BLUETOOTH_INQUIRY_RESPONSE         0x03
#define KG_PACKET_ID_EVT_BLUETOOTH_INQUIRY_COMPLETE         0x04
#define KG_PACKET_ID_EVT_BLUETOOTH_PAIRING_STATUS           0x05
#define KG_PACKET_ID_EVT_BLUETOOTH_PAIRING_FAILED           0x06
#define KG_PACKET_ID_EVT_BLUETOOTH_PAIRINGS_CLEARED         0x07
#define KG_PACKET_ID_EVT_BLUETOOTH_CONNECTION_STATUS        0x08
#define KG_PACKET_ID_EVT_BLUETOOTH_CONNECTION_CLOSED        0x09

/* ================================ */
/* KGAPI COMMAND/EVENT DECLARATIONS */
/* ================================ */

/* 0x01 */ uint16_t kg_cmd_bluetooth_get_mode(uint8_t *mode);
/* 0x02 */ uint16_t kg_cmd_bluetooth_set_mode(uint8_t mode);
/* 0x03 */ uint16_t kg_cmd_bluetooth_reset();
/* 0x04 */ uint16_t kg_cmd_bluetooth_get_mac(uint8_t *address);
/* 0x05 */ uint16_t kg_cmd_bluetooth_get_pairings(uint8_t *count);
/* 0x06 */ uint16_t kg_cmd_bluetooth_discover(uint8_t duration);
/* 0x07 */ uint16_t kg_cmd_bluetooth_pair(uint8_t *address);
/* 0x08 */ uint16_t kg_cmd_bluetooth_delete_pairing(uint8_t pairing);
/* 0x09 */ uint16_t kg_cmd_bluetooth_clear_pairings();
/* 0x0A */ uint16_t kg_cmd_bluetooth_get_connections(uint8_t *count);
/* 0x0B */ uint16_t kg_cmd_bluetooth_connect(uint8_t pairing, uint8_t profile);
/* 0x0C */ uint16_t kg_cmd_bluetooth_disconnect(uint8_t handle);
// -- command/event split --
/* 0x01 */ extern uint8_t (*kg_evt_bluetooth_mode)(uint8_t mode);
/* 0x02 */ extern uint8_t (*kg_evt_bluetooth_ready)();
/* 0x03 */ extern uint8_t (*kg_evt_bluetooth_inquiry_response)(uint8_t *address, uint8_t *cod, int8_t rssi, uint8_t status, uint8_t pairing, uint8_t name_len, uint8_t *name_data);
/* 0x04 */ extern uint8_t (*kg_evt_bluetooth_inquiry_complete)(uint8_t count);
/* 0x05 */ extern uint8_t (*kg_evt_bluetooth_pairing_status)(uint8_t pairing, uint8_t *address, uint8_t priority, uint8_t profiles_supported, uint8_t profiles_active, uint8_t handle_list_len, uint8_t *handle_list_data);
/* 0x06 */ extern uint8_t (*kg_evt_bluetooth_pairing_failed)(uint8_t *address);
/* 0x07 */ extern uint8_t (*kg_evt_bluetooth_pairings_cleared)();
/* 0x08 */ extern uint8_t (*kg_evt_bluetooth_connection_status)(uint8_t handle, uint8_t *address, uint8_t pairing, uint8_t profile, uint8_t status);
/* 0x09 */ extern uint8_t (*kg_evt_bluetooth_connection_closed)(uint8_t handle, uint16_t reason);

uint8_t process_protocol_command_bluetooth(uint8_t *rxPacket);

#endif // _SUPPORT_PROTOCOL_BLUETOOTH_H_
