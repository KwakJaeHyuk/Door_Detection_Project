// Auto-generated. Do not edit!

// (in-package darknet_ros_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class pose_info {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.rvec_x = null;
      this.rvec_y = null;
      this.rvec_z = null;
      this.trans_x = null;
      this.trans_y = null;
      this.trans_z = null;
    }
    else {
      if (initObj.hasOwnProperty('rvec_x')) {
        this.rvec_x = initObj.rvec_x
      }
      else {
        this.rvec_x = 0.0;
      }
      if (initObj.hasOwnProperty('rvec_y')) {
        this.rvec_y = initObj.rvec_y
      }
      else {
        this.rvec_y = 0.0;
      }
      if (initObj.hasOwnProperty('rvec_z')) {
        this.rvec_z = initObj.rvec_z
      }
      else {
        this.rvec_z = 0.0;
      }
      if (initObj.hasOwnProperty('trans_x')) {
        this.trans_x = initObj.trans_x
      }
      else {
        this.trans_x = 0.0;
      }
      if (initObj.hasOwnProperty('trans_y')) {
        this.trans_y = initObj.trans_y
      }
      else {
        this.trans_y = 0.0;
      }
      if (initObj.hasOwnProperty('trans_z')) {
        this.trans_z = initObj.trans_z
      }
      else {
        this.trans_z = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type pose_info
    // Serialize message field [rvec_x]
    bufferOffset = _serializer.float64(obj.rvec_x, buffer, bufferOffset);
    // Serialize message field [rvec_y]
    bufferOffset = _serializer.float64(obj.rvec_y, buffer, bufferOffset);
    // Serialize message field [rvec_z]
    bufferOffset = _serializer.float64(obj.rvec_z, buffer, bufferOffset);
    // Serialize message field [trans_x]
    bufferOffset = _serializer.float64(obj.trans_x, buffer, bufferOffset);
    // Serialize message field [trans_y]
    bufferOffset = _serializer.float64(obj.trans_y, buffer, bufferOffset);
    // Serialize message field [trans_z]
    bufferOffset = _serializer.float64(obj.trans_z, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type pose_info
    let len;
    let data = new pose_info(null);
    // Deserialize message field [rvec_x]
    data.rvec_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [rvec_y]
    data.rvec_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [rvec_z]
    data.rvec_z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [trans_x]
    data.trans_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [trans_y]
    data.trans_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [trans_z]
    data.trans_z = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'darknet_ros_msgs/pose_info';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '03971dbefaf1ae5a8bc19cc37c05b54e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 rvec_x
    float64 rvec_y
    float64 rvec_z
    float64 trans_x
    float64 trans_y
    float64 trans_z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new pose_info(null);
    if (msg.rvec_x !== undefined) {
      resolved.rvec_x = msg.rvec_x;
    }
    else {
      resolved.rvec_x = 0.0
    }

    if (msg.rvec_y !== undefined) {
      resolved.rvec_y = msg.rvec_y;
    }
    else {
      resolved.rvec_y = 0.0
    }

    if (msg.rvec_z !== undefined) {
      resolved.rvec_z = msg.rvec_z;
    }
    else {
      resolved.rvec_z = 0.0
    }

    if (msg.trans_x !== undefined) {
      resolved.trans_x = msg.trans_x;
    }
    else {
      resolved.trans_x = 0.0
    }

    if (msg.trans_y !== undefined) {
      resolved.trans_y = msg.trans_y;
    }
    else {
      resolved.trans_y = 0.0
    }

    if (msg.trans_z !== undefined) {
      resolved.trans_z = msg.trans_z;
    }
    else {
      resolved.trans_z = 0.0
    }

    return resolved;
    }
};

module.exports = pose_info;
