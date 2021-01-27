// automatically generated by the FlatBuffers compiler, do not modify
// invocattion: ./flatc -c -b --bfbs-gen-embed
// ~/src/vast/libvast/vast/fbs/partition.fbs

#ifndef FLATBUFFERS_GENERATED_PARTITION_VAST_FBS_BFBS_H_
#define FLATBUFFERS_GENERATED_PARTITION_VAST_FBS_BFBS_H_

namespace vast {
namespace fbs {

struct PartitionBinarySchema {
  static const uint8_t* data() {
    // Buffer containing the binary schema.
    static const uint8_t bfbsData[2272]
      = {0x1C, 0x00, 0x00, 0x00, 0x42, 0x46, 0x42, 0x53, 0x00, 0x00, 0x00, 0x00,
         0x10, 0x00, 0x1C, 0x00, 0x04, 0x00, 0x08, 0x00, 0x0C, 0x00, 0x10, 0x00,
         0x14, 0x00, 0x18, 0x00, 0x10, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00,
         0x2C, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
         0x18, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
         0x56, 0x53, 0x54, 0x70, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
         0x40, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0xEC, 0x00, 0x00, 0x00,
         0x5C, 0x06, 0x00, 0x00, 0x9C, 0x07, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00,
         0x6C, 0x04, 0x00, 0x00, 0x78, 0x03, 0x00, 0x00, 0xF4, 0x04, 0x00, 0x00,
         0xE8, 0x06, 0x00, 0x00, 0xEC, 0x02, 0x00, 0x00, 0xE8, 0x07, 0x00, 0x00,
         0xFC, 0x03, 0x00, 0x00, 0x0C, 0x00, 0x14, 0x00, 0x08, 0x00, 0x0C, 0x00,
         0x07, 0x00, 0x10, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
         0x24, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
         0x4A, 0xFA, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
         0x02, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00,
         0x1C, 0x00, 0x00, 0x00, 0x76, 0x61, 0x73, 0x74, 0x2E, 0x66, 0x62, 0x73,
         0x2E, 0x70, 0x61, 0x72, 0x74, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x2E, 0x50,
         0x61, 0x72, 0x74, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x00, 0x00, 0x00, 0x00,
         0x0C, 0x00, 0x18, 0x00, 0x04, 0x00, 0x10, 0x00, 0x08, 0x00, 0x0C, 0x00,
         0x0C, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00,
         0x0C, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0xAA, 0xFA, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0F, 0x03, 0x00, 0x00, 0x00,
         0x02, 0x00, 0x00, 0x00, 0x76, 0x30, 0x00, 0x00, 0x0C, 0x00, 0x0C, 0x00,
         0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0C, 0x00, 0x00, 0x00,
         0x10, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00,
         0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x4E, 0x4F, 0x4E, 0x45,
         0x00, 0x00, 0x00, 0x00, 0xEC, 0xF8, 0xFF, 0xFF, 0x18, 0x00, 0x00, 0x00,
         0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
         0x20, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00,
         0x76, 0x61, 0x73, 0x74, 0x2E, 0x66, 0x62, 0x73, 0x2E, 0x50, 0x61, 0x72,
         0x74, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x00, 0x00, 0xA0, 0xFB, 0xFF, 0xFF,
         0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x06, 0x00, 0x14, 0x00, 0x00, 0x00,
         0x04, 0x00, 0x00, 0x00, 0x32, 0xFB, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x10,
         0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x70, 0x61, 0x72, 0x74,
         0x69, 0x74, 0x69, 0x6F, 0x6E, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x10, 0x00,
         0x08, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x06, 0x00, 0x0C, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
         0x6A, 0xFB, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
         0x0E, 0x00, 0x00, 0x00, 0x70, 0x61, 0x72, 0x74, 0x69, 0x74, 0x69, 0x6F,
         0x6E, 0x5F, 0x74, 0x79, 0x70, 0x65, 0x00, 0x00, 0x8C, 0xF9, 0xFF, 0xFF,
         0x2C, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
         0x07, 0x00, 0x00, 0x00, 0xCC, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00,
         0x30, 0x00, 0x00, 0x00, 0x14, 0x01, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00,
         0x88, 0x00, 0x00, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00,
         0x76, 0x61, 0x73, 0x74, 0x2E, 0x66, 0x62, 0x73, 0x2E, 0x70, 0x61, 0x72,
         0x74, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x2E, 0x76, 0x30, 0x00, 0x00, 0x00,
         0x58, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x06, 0x00, 0x10, 0x00,
         0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x06, 0xFD, 0xFF, 0xFF,
         0x00, 0x00, 0x0E, 0x0F, 0x05, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
         0x69, 0x6E, 0x64, 0x65, 0x78, 0x65, 0x73, 0x00, 0x84, 0xFC, 0xFF, 0xFF,
         0x00, 0x00, 0x00, 0x01, 0x05, 0x00, 0x0E, 0x00, 0x14, 0x00, 0x00, 0x00,
         0x04, 0x00, 0x00, 0x00, 0x16, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0F,
         0x04, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x70, 0x61, 0x72, 0x74,
         0x69, 0x74, 0x69, 0x6F, 0x6E, 0x5F, 0x73, 0x79, 0x6E, 0x6F, 0x70, 0x73,
         0x69, 0x73, 0x00, 0x00, 0xBC, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01,
         0x04, 0x00, 0x0C, 0x00, 0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
         0x6A, 0xFD, 0xFF, 0xFF, 0x00, 0x00, 0x0E, 0x0F, 0x08, 0x00, 0x00, 0x00,
         0x08, 0x00, 0x00, 0x00, 0x74, 0x79, 0x70, 0x65, 0x5F, 0x69, 0x64, 0x73,
         0x00, 0x00, 0x00, 0x00, 0xEC, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01,
         0x03, 0x00, 0x0A, 0x00, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
         0x18, 0xFA, 0xFF, 0xFF, 0x00, 0x00, 0x0E, 0x04, 0x0F, 0x00, 0x00, 0x00,
         0x63, 0x6F, 0x6D, 0x62, 0x69, 0x6E, 0x65, 0x64, 0x5F, 0x6C, 0x61, 0x79,
         0x6F, 0x75, 0x74, 0x00, 0x54, 0xFB, 0xFF, 0xFF, 0x02, 0x00, 0x08, 0x00,
         0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x22, 0xFB, 0xFF, 0xFF,
         0x00, 0x00, 0x00, 0x0A, 0x06, 0x00, 0x00, 0x00, 0x65, 0x76, 0x65, 0x6E,
         0x74, 0x73, 0x00, 0x00, 0x78, 0xFB, 0xFF, 0xFF, 0x01, 0x00, 0x06, 0x00,
         0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x46, 0xFB, 0xFF, 0xFF,
         0x00, 0x00, 0x00, 0x0A, 0x06, 0x00, 0x00, 0x00, 0x6F, 0x66, 0x66, 0x73,
         0x65, 0x74, 0x00, 0x00, 0xA8, 0xFA, 0xFF, 0xFF, 0x00, 0x01, 0x04, 0x00,
         0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xF2, 0xFC, 0xFF, 0xFF,
         0x00, 0x00, 0x00, 0x0F, 0x09, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
         0x75, 0x75, 0x69, 0x64, 0x00, 0x00, 0x00, 0x00, 0x0C, 0xFB, 0xFF, 0xFF,
         0x18, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
         0x02, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00,
         0x14, 0x00, 0x00, 0x00, 0x76, 0x61, 0x73, 0x74, 0x2E, 0x66, 0x62, 0x73,
         0x2E, 0x74, 0x79, 0x70, 0x65, 0x5F, 0x69, 0x64, 0x73, 0x2E, 0x76, 0x30,
         0x00, 0x00, 0x00, 0x00, 0xC4, 0xFD, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01,
         0x01, 0x00, 0x06, 0x00, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
         0xF0, 0xFA, 0xFF, 0xFF, 0x00, 0x00, 0x0E, 0x04, 0x03, 0x00, 0x00, 0x00,
         0x69, 0x64, 0x73, 0x00, 0x2C, 0xFB, 0xFF, 0xFF, 0x00, 0x01, 0x04, 0x00,
         0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xEE, 0xFB, 0xFF, 0xFF,
         0x00, 0x00, 0x00, 0x0D, 0x04, 0x00, 0x00, 0x00, 0x6E, 0x61, 0x6D, 0x65,
         0x00, 0x00, 0x00, 0x00, 0x8C, 0xFB, 0xFF, 0xFF, 0x18, 0x00, 0x00, 0x00,
         0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
         0x5C, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00,
         0x76, 0x61, 0x73, 0x74, 0x2E, 0x66, 0x62, 0x73, 0x2E, 0x71, 0x75, 0x61,
         0x6C, 0x69, 0x66, 0x69, 0x65, 0x64, 0x5F, 0x76, 0x61, 0x6C, 0x75, 0x65,
         0x5F, 0x69, 0x6E, 0x64, 0x65, 0x78, 0x2E, 0x76, 0x30, 0x00, 0x00, 0x00,
         0x50, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x06, 0x00,
         0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xE2, 0xFD, 0xFF, 0xFF,
         0x00, 0x00, 0x00, 0x0F, 0x0A, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
         0x69, 0x6E, 0x64, 0x65, 0x78, 0x00, 0x00, 0x00, 0xC0, 0xFB, 0xFF, 0xFF,
         0x00, 0x01, 0x04, 0x00, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
         0x82, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0D, 0x0A, 0x00, 0x00, 0x00,
         0x66, 0x69, 0x65, 0x6C, 0x64, 0x5F, 0x6E, 0x61, 0x6D, 0x65, 0x00, 0x00,
         0x24, 0xFC, 0xFF, 0xFF, 0x14, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
         0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
         0x17, 0x00, 0x00, 0x00, 0x76, 0x61, 0x73, 0x74, 0x2E, 0x66, 0x62, 0x73,
         0x2E, 0x76, 0x61, 0x6C, 0x75, 0x65, 0x5F, 0x69, 0x6E, 0x64, 0x65, 0x78,
         0x2E, 0x76, 0x30, 0x00, 0x1C, 0xFC, 0xFF, 0xFF, 0x00, 0x01, 0x04, 0x00,
         0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF,
         0x00, 0x00, 0x0E, 0x04, 0x04, 0x00, 0x00, 0x00, 0x64, 0x61, 0x74, 0x61,
         0x00, 0x00, 0x00, 0x00, 0x7C, 0xFC, 0xFF, 0xFF, 0x14, 0x00, 0x00, 0x00,
         0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
         0x44, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x76, 0x61, 0x73, 0x74,
         0x2E, 0x66, 0x62, 0x73, 0x2E, 0x70, 0x61, 0x72, 0x74, 0x69, 0x74, 0x69,
         0x6F, 0x6E, 0x5F, 0x73, 0x79, 0x6E, 0x6F, 0x70, 0x73, 0x69, 0x73, 0x2E,
         0x76, 0x30, 0x00, 0x00, 0x1C, 0x00, 0x12, 0x00, 0x08, 0x00, 0x0C, 0x00,
         0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x1C, 0x00, 0x00, 0x00,
         0x00, 0x01, 0x04, 0x00, 0x20, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00,
         0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0F, 0x06, 0x00, 0x00, 0x00,
         0x08, 0x00, 0x00, 0x00, 0x73, 0x79, 0x6E, 0x6F, 0x70, 0x73, 0x65, 0x73,
         0x00, 0x00, 0x00, 0x00, 0x0C, 0xFD, 0xFF, 0xFF, 0x20, 0x00, 0x00, 0x00,
         0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
         0xCC, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00,
         0x70, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x76, 0x61, 0x73, 0x74,
         0x2E, 0x66, 0x62, 0x73, 0x2E, 0x73, 0x79, 0x6E, 0x6F, 0x70, 0x73, 0x69,
         0x73, 0x2E, 0x76, 0x30, 0x00, 0x00, 0x00, 0x00, 0xCC, 0xFF, 0xFF, 0xFF,
         0x00, 0x00, 0x00, 0x01, 0x03, 0x00, 0x0A, 0x00, 0x14, 0x00, 0x00, 0x00,
         0x04, 0x00, 0x00, 0x00, 0x5E, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0F,
         0x02, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x6F, 0x70, 0x61, 0x71,
         0x75, 0x65, 0x5F, 0x73, 0x79, 0x6E, 0x6F, 0x70, 0x73, 0x69, 0x73, 0x00,
         0x1C, 0x00, 0x14, 0x00, 0x0C, 0x00, 0x10, 0x00, 0x08, 0x00, 0x0A, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x07, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
         0x02, 0x00, 0x08, 0x00, 0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
         0xAE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0F, 0x07, 0x00, 0x00, 0x00,
         0x0D, 0x00, 0x00, 0x00, 0x74, 0x69, 0x6D, 0x65, 0x5F, 0x73, 0x79, 0x6E,
         0x6F, 0x70, 0x73, 0x69, 0x73, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x16, 0x00,
         0x0C, 0x00, 0x10, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
         0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x06, 0x00,
         0x20, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00,
         0x0C, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00,
         0x62, 0x6F, 0x6F, 0x6C, 0x5F, 0x73, 0x79, 0x6E, 0x6F, 0x70, 0x73, 0x69,
         0x73, 0x00, 0x00, 0x00, 0xF0, 0xFD, 0xFF, 0xFF, 0x00, 0x01, 0x04, 0x00,
         0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xD4, 0xFD, 0xFF, 0xFF,
         0x00, 0x00, 0x0E, 0x04, 0x16, 0x00, 0x00, 0x00, 0x71, 0x75, 0x61, 0x6C,
         0x69, 0x66, 0x69, 0x65, 0x64, 0x5F, 0x72, 0x65, 0x63, 0x6F, 0x72, 0x64,
         0x5F, 0x66, 0x69, 0x65, 0x6C, 0x64, 0x00, 0x00, 0x6A, 0xFF, 0xFF, 0xFF,
         0x00, 0x00, 0x00, 0x01, 0x1C, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
         0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
         0x28, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00,
         0x76, 0x61, 0x73, 0x74, 0x2E, 0x66, 0x62, 0x73, 0x2E, 0x62, 0x6F, 0x6F,
         0x6C, 0x5F, 0x73, 0x79, 0x6E, 0x6F, 0x70, 0x73, 0x69, 0x73, 0x2E, 0x76,
         0x30, 0x00, 0x00, 0x00, 0x5C, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x01, 0x00,
         0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x2A, 0xFF, 0xFF, 0xFF,
         0x00, 0x00, 0x00, 0x02, 0x09, 0x00, 0x00, 0x00, 0x61, 0x6E, 0x79, 0x5F,
         0x66, 0x61, 0x6C, 0x73, 0x65, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0C, 0x00,
         0x04, 0x00, 0x08, 0x00, 0x08, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
         0x04, 0x00, 0x00, 0x00, 0x56, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x02,
         0x08, 0x00, 0x00, 0x00, 0x61, 0x6E, 0x79, 0x5F, 0x74, 0x72, 0x75, 0x65,
         0x00, 0x00, 0x0E, 0x00, 0x18, 0x00, 0x08, 0x00, 0x0C, 0x00, 0x07, 0x00,
         0x10, 0x00, 0x14, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
         0x1C, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
         0x10, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00,
         0x58, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x76, 0x61, 0x73, 0x74,
         0x2E, 0x66, 0x62, 0x73, 0x2E, 0x74, 0x69, 0x6D, 0x65, 0x5F, 0x73, 0x79,
         0x6E, 0x6F, 0x70, 0x73, 0x69, 0x73, 0x2E, 0x76, 0x30, 0x00, 0x00, 0x00,
         0x0C, 0x00, 0x10, 0x00, 0x08, 0x00, 0x0C, 0x00, 0x04, 0x00, 0x06, 0x00,
         0x0C, 0x00, 0x00, 0x00, 0x01, 0x00, 0x08, 0x00, 0x10, 0x00, 0x00, 0x00,
         0x04, 0x00, 0x00, 0x00, 0xDA, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x09,
         0x03, 0x00, 0x00, 0x00, 0x65, 0x6E, 0x64, 0x00, 0x08, 0x00, 0x0E, 0x00,
         0x04, 0x00, 0x08, 0x00, 0x08, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
         0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x08, 0x00, 0x07, 0x00,
         0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x05, 0x00, 0x00, 0x00,
         0x73, 0x74, 0x61, 0x72, 0x74, 0x00, 0x00, 0x00, 0xA4, 0xFF, 0xFF, 0xFF,
         0x14, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
         0x01, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00,
         0x76, 0x61, 0x73, 0x74, 0x2E, 0x66, 0x62, 0x73, 0x2E, 0x6F, 0x70, 0x61,
         0x71, 0x75, 0x65, 0x5F, 0x73, 0x79, 0x6E, 0x6F, 0x70, 0x73, 0x69, 0x73,
         0x2E, 0x76, 0x30, 0x00, 0xA0, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x04, 0x00,
         0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x84, 0xFF, 0xFF, 0xFF,
         0x00, 0x00, 0x0E, 0x04, 0x04, 0x00, 0x00, 0x00, 0x64, 0x61, 0x74, 0x61,
         0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x10, 0x00, 0x04, 0x00, 0x08, 0x00,
         0x00, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
         0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
         0x38, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x76, 0x61, 0x73, 0x74,
         0x2E, 0x66, 0x62, 0x73, 0x2E, 0x75, 0x75, 0x69, 0x64, 0x2E, 0x76, 0x30,
         0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x10, 0x00, 0x08, 0x00, 0x0C, 0x00,
         0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x1C, 0x00, 0x00, 0x00,
         0x00, 0x01, 0x04, 0x00, 0x18, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
         0x08, 0x00, 0x08, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x0E, 0x04, 0x04, 0x00, 0x00, 0x00, 0x64, 0x61, 0x74, 0x61,
         0x00, 0x00, 0x00, 0x00};
    return bfbsData;
  }
  static size_t size() {
    return 2272;
  }
  const uint8_t* begin() {
    return data();
  }
  const uint8_t* end() {
    return data() + size();
  }
};

} // namespace fbs
} // namespace vast

#endif // FLATBUFFERS_GENERATED_PARTITION_VAST_FBS_BFBS_H_
