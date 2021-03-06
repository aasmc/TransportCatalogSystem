// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: router.proto

#include "router.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Serialization {
constexpr RoutesInternalData::RoutesInternalData(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : weight_(0)
  , exists_(false)
  , hasprevedge_(false)
  , prevedge_(0u){}
struct RoutesInternalDataDefaultTypeInternal {
  constexpr RoutesInternalDataDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RoutesInternalDataDefaultTypeInternal() {}
  union {
    RoutesInternalData _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RoutesInternalDataDefaultTypeInternal _RoutesInternalData_default_instance_;
constexpr VectorRoutesInternalData::VectorRoutesInternalData(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : routesinternaldata_(){}
struct VectorRoutesInternalDataDefaultTypeInternal {
  constexpr VectorRoutesInternalDataDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~VectorRoutesInternalDataDefaultTypeInternal() {}
  union {
    VectorRoutesInternalData _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT VectorRoutesInternalDataDefaultTypeInternal _VectorRoutesInternalData_default_instance_;
constexpr Router::Router(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : vectorroutesinternaldata_(){}
struct RouterDefaultTypeInternal {
  constexpr RouterDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RouterDefaultTypeInternal() {}
  union {
    Router _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RouterDefaultTypeInternal _Router_default_instance_;
}  // namespace Serialization
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_router_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_router_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_router_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_router_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Serialization::RoutesInternalData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Serialization::RoutesInternalData, exists_),
  PROTOBUF_FIELD_OFFSET(::Serialization::RoutesInternalData, weight_),
  PROTOBUF_FIELD_OFFSET(::Serialization::RoutesInternalData, hasprevedge_),
  PROTOBUF_FIELD_OFFSET(::Serialization::RoutesInternalData, prevedge_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Serialization::VectorRoutesInternalData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Serialization::VectorRoutesInternalData, routesinternaldata_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Serialization::Router, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Serialization::Router, vectorroutesinternaldata_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Serialization::RoutesInternalData)},
  { 9, -1, sizeof(::Serialization::VectorRoutesInternalData)},
  { 15, -1, sizeof(::Serialization::Router)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Serialization::_RoutesInternalData_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Serialization::_VectorRoutesInternalData_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Serialization::_Router_default_instance_),
};

const char descriptor_table_protodef_router_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014router.proto\022\rSerialization\"[\n\022RoutesI"
  "nternalData\022\016\n\006exists\030\001 \001(\010\022\016\n\006weight\030\002 "
  "\001(\001\022\023\n\013hasPrevEdge\030\003 \001(\010\022\020\n\010prevEdge\030\004 \001"
  "(\r\"Y\n\030VectorRoutesInternalData\022=\n\022routes"
  "InternalData\030\001 \003(\0132!.Serialization.Route"
  "sInternalData\"S\n\006Router\022I\n\030vectorRoutesI"
  "nternalData\030\001 \003(\0132\'.Serialization.Vector"
  "RoutesInternalDatab\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_router_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_router_2eproto = {
  false, false, 306, descriptor_table_protodef_router_2eproto, "router.proto", 
  &descriptor_table_router_2eproto_once, nullptr, 0, 3,
  schemas, file_default_instances, TableStruct_router_2eproto::offsets,
  file_level_metadata_router_2eproto, file_level_enum_descriptors_router_2eproto, file_level_service_descriptors_router_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_router_2eproto_getter() {
  return &descriptor_table_router_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_router_2eproto(&descriptor_table_router_2eproto);
namespace Serialization {

// ===================================================================

class RoutesInternalData::_Internal {
 public:
};

RoutesInternalData::RoutesInternalData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Serialization.RoutesInternalData)
}
RoutesInternalData::RoutesInternalData(const RoutesInternalData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&weight_, &from.weight_,
    static_cast<size_t>(reinterpret_cast<char*>(&prevedge_) -
    reinterpret_cast<char*>(&weight_)) + sizeof(prevedge_));
  // @@protoc_insertion_point(copy_constructor:Serialization.RoutesInternalData)
}

inline void RoutesInternalData::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&weight_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&prevedge_) -
    reinterpret_cast<char*>(&weight_)) + sizeof(prevedge_));
}

RoutesInternalData::~RoutesInternalData() {
  // @@protoc_insertion_point(destructor:Serialization.RoutesInternalData)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void RoutesInternalData::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void RoutesInternalData::ArenaDtor(void* object) {
  RoutesInternalData* _this = reinterpret_cast< RoutesInternalData* >(object);
  (void)_this;
}
void RoutesInternalData::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RoutesInternalData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void RoutesInternalData::Clear() {
// @@protoc_insertion_point(message_clear_start:Serialization.RoutesInternalData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&weight_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&prevedge_) -
      reinterpret_cast<char*>(&weight_)) + sizeof(prevedge_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RoutesInternalData::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool exists = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          exists_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double weight = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 17)) {
          weight_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      // bool hasPrevEdge = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          hasprevedge_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 prevEdge = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          prevedge_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RoutesInternalData::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Serialization.RoutesInternalData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool exists = 1;
  if (this->_internal_exists() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_exists(), target);
  }

  // double weight = 2;
  if (!(this->_internal_weight() <= 0 && this->_internal_weight() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(2, this->_internal_weight(), target);
  }

  // bool hasPrevEdge = 3;
  if (this->_internal_hasprevedge() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(3, this->_internal_hasprevedge(), target);
  }

  // uint32 prevEdge = 4;
  if (this->_internal_prevedge() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(4, this->_internal_prevedge(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Serialization.RoutesInternalData)
  return target;
}

size_t RoutesInternalData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Serialization.RoutesInternalData)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // double weight = 2;
  if (!(this->_internal_weight() <= 0 && this->_internal_weight() >= 0)) {
    total_size += 1 + 8;
  }

  // bool exists = 1;
  if (this->_internal_exists() != 0) {
    total_size += 1 + 1;
  }

  // bool hasPrevEdge = 3;
  if (this->_internal_hasprevedge() != 0) {
    total_size += 1 + 1;
  }

  // uint32 prevEdge = 4;
  if (this->_internal_prevedge() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_prevedge());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData RoutesInternalData::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    RoutesInternalData::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*RoutesInternalData::GetClassData() const { return &_class_data_; }

void RoutesInternalData::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<RoutesInternalData *>(to)->MergeFrom(
      static_cast<const RoutesInternalData &>(from));
}


void RoutesInternalData::MergeFrom(const RoutesInternalData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Serialization.RoutesInternalData)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from._internal_weight() <= 0 && from._internal_weight() >= 0)) {
    _internal_set_weight(from._internal_weight());
  }
  if (from._internal_exists() != 0) {
    _internal_set_exists(from._internal_exists());
  }
  if (from._internal_hasprevedge() != 0) {
    _internal_set_hasprevedge(from._internal_hasprevedge());
  }
  if (from._internal_prevedge() != 0) {
    _internal_set_prevedge(from._internal_prevedge());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void RoutesInternalData::CopyFrom(const RoutesInternalData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Serialization.RoutesInternalData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RoutesInternalData::IsInitialized() const {
  return true;
}

void RoutesInternalData::InternalSwap(RoutesInternalData* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(RoutesInternalData, prevedge_)
      + sizeof(RoutesInternalData::prevedge_)
      - PROTOBUF_FIELD_OFFSET(RoutesInternalData, weight_)>(
          reinterpret_cast<char*>(&weight_),
          reinterpret_cast<char*>(&other->weight_));
}

::PROTOBUF_NAMESPACE_ID::Metadata RoutesInternalData::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_router_2eproto_getter, &descriptor_table_router_2eproto_once,
      file_level_metadata_router_2eproto[0]);
}

// ===================================================================

class VectorRoutesInternalData::_Internal {
 public:
};

VectorRoutesInternalData::VectorRoutesInternalData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  routesinternaldata_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Serialization.VectorRoutesInternalData)
}
VectorRoutesInternalData::VectorRoutesInternalData(const VectorRoutesInternalData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      routesinternaldata_(from.routesinternaldata_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Serialization.VectorRoutesInternalData)
}

inline void VectorRoutesInternalData::SharedCtor() {
}

VectorRoutesInternalData::~VectorRoutesInternalData() {
  // @@protoc_insertion_point(destructor:Serialization.VectorRoutesInternalData)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void VectorRoutesInternalData::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void VectorRoutesInternalData::ArenaDtor(void* object) {
  VectorRoutesInternalData* _this = reinterpret_cast< VectorRoutesInternalData* >(object);
  (void)_this;
}
void VectorRoutesInternalData::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void VectorRoutesInternalData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void VectorRoutesInternalData::Clear() {
// @@protoc_insertion_point(message_clear_start:Serialization.VectorRoutesInternalData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  routesinternaldata_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* VectorRoutesInternalData::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .Serialization.RoutesInternalData routesInternalData = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_routesinternaldata(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* VectorRoutesInternalData::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Serialization.VectorRoutesInternalData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .Serialization.RoutesInternalData routesInternalData = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_routesinternaldata_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_routesinternaldata(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Serialization.VectorRoutesInternalData)
  return target;
}

size_t VectorRoutesInternalData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Serialization.VectorRoutesInternalData)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .Serialization.RoutesInternalData routesInternalData = 1;
  total_size += 1UL * this->_internal_routesinternaldata_size();
  for (const auto& msg : this->routesinternaldata_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData VectorRoutesInternalData::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    VectorRoutesInternalData::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*VectorRoutesInternalData::GetClassData() const { return &_class_data_; }

void VectorRoutesInternalData::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<VectorRoutesInternalData *>(to)->MergeFrom(
      static_cast<const VectorRoutesInternalData &>(from));
}


void VectorRoutesInternalData::MergeFrom(const VectorRoutesInternalData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Serialization.VectorRoutesInternalData)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  routesinternaldata_.MergeFrom(from.routesinternaldata_);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void VectorRoutesInternalData::CopyFrom(const VectorRoutesInternalData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Serialization.VectorRoutesInternalData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VectorRoutesInternalData::IsInitialized() const {
  return true;
}

void VectorRoutesInternalData::InternalSwap(VectorRoutesInternalData* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  routesinternaldata_.InternalSwap(&other->routesinternaldata_);
}

::PROTOBUF_NAMESPACE_ID::Metadata VectorRoutesInternalData::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_router_2eproto_getter, &descriptor_table_router_2eproto_once,
      file_level_metadata_router_2eproto[1]);
}

// ===================================================================

class Router::_Internal {
 public:
};

Router::Router(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  vectorroutesinternaldata_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Serialization.Router)
}
Router::Router(const Router& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      vectorroutesinternaldata_(from.vectorroutesinternaldata_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Serialization.Router)
}

inline void Router::SharedCtor() {
}

Router::~Router() {
  // @@protoc_insertion_point(destructor:Serialization.Router)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Router::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Router::ArenaDtor(void* object) {
  Router* _this = reinterpret_cast< Router* >(object);
  (void)_this;
}
void Router::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Router::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Router::Clear() {
// @@protoc_insertion_point(message_clear_start:Serialization.Router)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  vectorroutesinternaldata_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Router::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .Serialization.VectorRoutesInternalData vectorRoutesInternalData = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_vectorroutesinternaldata(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Router::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Serialization.Router)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .Serialization.VectorRoutesInternalData vectorRoutesInternalData = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_vectorroutesinternaldata_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_vectorroutesinternaldata(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Serialization.Router)
  return target;
}

size_t Router::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Serialization.Router)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .Serialization.VectorRoutesInternalData vectorRoutesInternalData = 1;
  total_size += 1UL * this->_internal_vectorroutesinternaldata_size();
  for (const auto& msg : this->vectorroutesinternaldata_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Router::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Router::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Router::GetClassData() const { return &_class_data_; }

void Router::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Router *>(to)->MergeFrom(
      static_cast<const Router &>(from));
}


void Router::MergeFrom(const Router& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Serialization.Router)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  vectorroutesinternaldata_.MergeFrom(from.vectorroutesinternaldata_);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Router::CopyFrom(const Router& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Serialization.Router)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Router::IsInitialized() const {
  return true;
}

void Router::InternalSwap(Router* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  vectorroutesinternaldata_.InternalSwap(&other->vectorroutesinternaldata_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Router::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_router_2eproto_getter, &descriptor_table_router_2eproto_once,
      file_level_metadata_router_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Serialization
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Serialization::RoutesInternalData* Arena::CreateMaybeMessage< ::Serialization::RoutesInternalData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Serialization::RoutesInternalData >(arena);
}
template<> PROTOBUF_NOINLINE ::Serialization::VectorRoutesInternalData* Arena::CreateMaybeMessage< ::Serialization::VectorRoutesInternalData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Serialization::VectorRoutesInternalData >(arena);
}
template<> PROTOBUF_NOINLINE ::Serialization::Router* Arena::CreateMaybeMessage< ::Serialization::Router >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Serialization::Router >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
