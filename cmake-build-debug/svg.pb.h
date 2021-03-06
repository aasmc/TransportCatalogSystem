// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: svg.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_svg_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_svg_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_svg_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_svg_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_svg_2eproto;
namespace Serialization {
class Color;
struct ColorDefaultTypeInternal;
extern ColorDefaultTypeInternal _Color_default_instance_;
class Point;
struct PointDefaultTypeInternal;
extern PointDefaultTypeInternal _Point_default_instance_;
class Rgba;
struct RgbaDefaultTypeInternal;
extern RgbaDefaultTypeInternal _Rgba_default_instance_;
}  // namespace Serialization
PROTOBUF_NAMESPACE_OPEN
template<> ::Serialization::Color* Arena::CreateMaybeMessage<::Serialization::Color>(Arena*);
template<> ::Serialization::Point* Arena::CreateMaybeMessage<::Serialization::Point>(Arena*);
template<> ::Serialization::Rgba* Arena::CreateMaybeMessage<::Serialization::Rgba>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Serialization {

// ===================================================================

class Point final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Serialization.Point) */ {
 public:
  inline Point() : Point(nullptr) {}
  ~Point() override;
  explicit constexpr Point(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Point(const Point& from);
  Point(Point&& from) noexcept
    : Point() {
    *this = ::std::move(from);
  }

  inline Point& operator=(const Point& from) {
    CopyFrom(from);
    return *this;
  }
  inline Point& operator=(Point&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Point& default_instance() {
    return *internal_default_instance();
  }
  static inline const Point* internal_default_instance() {
    return reinterpret_cast<const Point*>(
               &_Point_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Point& a, Point& b) {
    a.Swap(&b);
  }
  inline void Swap(Point* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Point* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Point* New() const final {
    return new Point();
  }

  Point* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Point>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Point& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Point& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Point* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Serialization.Point";
  }
  protected:
  explicit Point(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // @@protoc_insertion_point(class_scope:Serialization.Point)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double y_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// -------------------------------------------------------------------

class Rgba final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Serialization.Rgba) */ {
 public:
  inline Rgba() : Rgba(nullptr) {}
  ~Rgba() override;
  explicit constexpr Rgba(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Rgba(const Rgba& from);
  Rgba(Rgba&& from) noexcept
    : Rgba() {
    *this = ::std::move(from);
  }

  inline Rgba& operator=(const Rgba& from) {
    CopyFrom(from);
    return *this;
  }
  inline Rgba& operator=(Rgba&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Rgba& default_instance() {
    return *internal_default_instance();
  }
  static inline const Rgba* internal_default_instance() {
    return reinterpret_cast<const Rgba*>(
               &_Rgba_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Rgba& a, Rgba& b) {
    a.Swap(&b);
  }
  inline void Swap(Rgba* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Rgba* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Rgba* New() const final {
    return new Rgba();
  }

  Rgba* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Rgba>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Rgba& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Rgba& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Rgba* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Serialization.Rgba";
  }
  protected:
  explicit Rgba(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRedFieldNumber = 1,
    kBlueFieldNumber = 2,
    kGreenFieldNumber = 3,
    kHasAlphaFieldNumber = 4,
    kAlphaFieldNumber = 5,
  };
  // uint32 red = 1;
  void clear_red();
  ::PROTOBUF_NAMESPACE_ID::uint32 red() const;
  void set_red(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_red() const;
  void _internal_set_red(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 blue = 2;
  void clear_blue();
  ::PROTOBUF_NAMESPACE_ID::uint32 blue() const;
  void set_blue(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_blue() const;
  void _internal_set_blue(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 green = 3;
  void clear_green();
  ::PROTOBUF_NAMESPACE_ID::uint32 green() const;
  void set_green(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_green() const;
  void _internal_set_green(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // bool hasAlpha = 4;
  void clear_hasalpha();
  bool hasalpha() const;
  void set_hasalpha(bool value);
  private:
  bool _internal_hasalpha() const;
  void _internal_set_hasalpha(bool value);
  public:

  // double alpha = 5;
  void clear_alpha();
  double alpha() const;
  void set_alpha(double value);
  private:
  double _internal_alpha() const;
  void _internal_set_alpha(double value);
  public:

  // @@protoc_insertion_point(class_scope:Serialization.Rgba)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::uint32 red_;
  ::PROTOBUF_NAMESPACE_ID::uint32 blue_;
  ::PROTOBUF_NAMESPACE_ID::uint32 green_;
  bool hasalpha_;
  double alpha_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_svg_2eproto;
};
// -------------------------------------------------------------------

class Color final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Serialization.Color) */ {
 public:
  inline Color() : Color(nullptr) {}
  ~Color() override;
  explicit constexpr Color(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Color(const Color& from);
  Color(Color&& from) noexcept
    : Color() {
    *this = ::std::move(from);
  }

  inline Color& operator=(const Color& from) {
    CopyFrom(from);
    return *this;
  }
  inline Color& operator=(Color&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Color& default_instance() {
    return *internal_default_instance();
  }
  enum PossibleColorCase {
    kNoColor = 1,
    kStringColor = 2,
    kRgba = 3,
    POSSIBLECOLOR_NOT_SET = 0,
  };

  static inline const Color* internal_default_instance() {
    return reinterpret_cast<const Color*>(
               &_Color_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Color& a, Color& b) {
    a.Swap(&b);
  }
  inline void Swap(Color* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Color* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Color* New() const final {
    return new Color();
  }

  Color* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Color>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Color& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Color& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Color* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Serialization.Color";
  }
  protected:
  explicit Color(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNoColorFieldNumber = 1,
    kStringColorFieldNumber = 2,
    kRgbaFieldNumber = 3,
  };
  // bool noColor = 1;
  bool has_nocolor() const;
  private:
  bool _internal_has_nocolor() const;
  public:
  void clear_nocolor();
  bool nocolor() const;
  void set_nocolor(bool value);
  private:
  bool _internal_nocolor() const;
  void _internal_set_nocolor(bool value);
  public:

  // string stringColor = 2;
  bool has_stringcolor() const;
  private:
  bool _internal_has_stringcolor() const;
  public:
  void clear_stringcolor();
  const std::string& stringcolor() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_stringcolor(ArgT0&& arg0, ArgT... args);
  std::string* mutable_stringcolor();
  PROTOBUF_MUST_USE_RESULT std::string* release_stringcolor();
  void set_allocated_stringcolor(std::string* stringcolor);
  private:
  const std::string& _internal_stringcolor() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_stringcolor(const std::string& value);
  std::string* _internal_mutable_stringcolor();
  public:

  // .Serialization.Rgba rgba = 3;
  bool has_rgba() const;
  private:
  bool _internal_has_rgba() const;
  public:
  void clear_rgba();
  const ::Serialization::Rgba& rgba() const;
  PROTOBUF_MUST_USE_RESULT ::Serialization::Rgba* release_rgba();
  ::Serialization::Rgba* mutable_rgba();
  void set_allocated_rgba(::Serialization::Rgba* rgba);
  private:
  const ::Serialization::Rgba& _internal_rgba() const;
  ::Serialization::Rgba* _internal_mutable_rgba();
  public:
  void unsafe_arena_set_allocated_rgba(
      ::Serialization::Rgba* rgba);
  ::Serialization::Rgba* unsafe_arena_release_rgba();

  void clear_possibleColor();
  PossibleColorCase possibleColor_case() const;
  // @@protoc_insertion_point(class_scope:Serialization.Color)
 private:
  class _Internal;
  void set_has_nocolor();
  void set_has_stringcolor();
  void set_has_rgba();

  inline bool has_possibleColor() const;
  inline void clear_has_possibleColor();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  union PossibleColorUnion {
    constexpr PossibleColorUnion() : _constinit_{} {}
      ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized _constinit_;
    bool nocolor_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr stringcolor_;
    ::Serialization::Rgba* rgba_;
  } possibleColor_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 _oneof_case_[1];

  friend struct ::TableStruct_svg_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Point

// double x = 1;
inline void Point::clear_x() {
  x_ = 0;
}
inline double Point::_internal_x() const {
  return x_;
}
inline double Point::x() const {
  // @@protoc_insertion_point(field_get:Serialization.Point.x)
  return _internal_x();
}
inline void Point::_internal_set_x(double value) {
  
  x_ = value;
}
inline void Point::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:Serialization.Point.x)
}

// double y = 2;
inline void Point::clear_y() {
  y_ = 0;
}
inline double Point::_internal_y() const {
  return y_;
}
inline double Point::y() const {
  // @@protoc_insertion_point(field_get:Serialization.Point.y)
  return _internal_y();
}
inline void Point::_internal_set_y(double value) {
  
  y_ = value;
}
inline void Point::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:Serialization.Point.y)
}

// -------------------------------------------------------------------

// Rgba

// uint32 red = 1;
inline void Rgba::clear_red() {
  red_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::_internal_red() const {
  return red_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::red() const {
  // @@protoc_insertion_point(field_get:Serialization.Rgba.red)
  return _internal_red();
}
inline void Rgba::_internal_set_red(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  red_ = value;
}
inline void Rgba::set_red(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_red(value);
  // @@protoc_insertion_point(field_set:Serialization.Rgba.red)
}

// uint32 blue = 2;
inline void Rgba::clear_blue() {
  blue_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::_internal_blue() const {
  return blue_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::blue() const {
  // @@protoc_insertion_point(field_get:Serialization.Rgba.blue)
  return _internal_blue();
}
inline void Rgba::_internal_set_blue(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  blue_ = value;
}
inline void Rgba::set_blue(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_blue(value);
  // @@protoc_insertion_point(field_set:Serialization.Rgba.blue)
}

// uint32 green = 3;
inline void Rgba::clear_green() {
  green_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::_internal_green() const {
  return green_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Rgba::green() const {
  // @@protoc_insertion_point(field_get:Serialization.Rgba.green)
  return _internal_green();
}
inline void Rgba::_internal_set_green(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  green_ = value;
}
inline void Rgba::set_green(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_green(value);
  // @@protoc_insertion_point(field_set:Serialization.Rgba.green)
}

// bool hasAlpha = 4;
inline void Rgba::clear_hasalpha() {
  hasalpha_ = false;
}
inline bool Rgba::_internal_hasalpha() const {
  return hasalpha_;
}
inline bool Rgba::hasalpha() const {
  // @@protoc_insertion_point(field_get:Serialization.Rgba.hasAlpha)
  return _internal_hasalpha();
}
inline void Rgba::_internal_set_hasalpha(bool value) {
  
  hasalpha_ = value;
}
inline void Rgba::set_hasalpha(bool value) {
  _internal_set_hasalpha(value);
  // @@protoc_insertion_point(field_set:Serialization.Rgba.hasAlpha)
}

// double alpha = 5;
inline void Rgba::clear_alpha() {
  alpha_ = 0;
}
inline double Rgba::_internal_alpha() const {
  return alpha_;
}
inline double Rgba::alpha() const {
  // @@protoc_insertion_point(field_get:Serialization.Rgba.alpha)
  return _internal_alpha();
}
inline void Rgba::_internal_set_alpha(double value) {
  
  alpha_ = value;
}
inline void Rgba::set_alpha(double value) {
  _internal_set_alpha(value);
  // @@protoc_insertion_point(field_set:Serialization.Rgba.alpha)
}

// -------------------------------------------------------------------

// Color

// bool noColor = 1;
inline bool Color::_internal_has_nocolor() const {
  return possibleColor_case() == kNoColor;
}
inline bool Color::has_nocolor() const {
  return _internal_has_nocolor();
}
inline void Color::set_has_nocolor() {
  _oneof_case_[0] = kNoColor;
}
inline void Color::clear_nocolor() {
  if (_internal_has_nocolor()) {
    possibleColor_.nocolor_ = false;
    clear_has_possibleColor();
  }
}
inline bool Color::_internal_nocolor() const {
  if (_internal_has_nocolor()) {
    return possibleColor_.nocolor_;
  }
  return false;
}
inline void Color::_internal_set_nocolor(bool value) {
  if (!_internal_has_nocolor()) {
    clear_possibleColor();
    set_has_nocolor();
  }
  possibleColor_.nocolor_ = value;
}
inline bool Color::nocolor() const {
  // @@protoc_insertion_point(field_get:Serialization.Color.noColor)
  return _internal_nocolor();
}
inline void Color::set_nocolor(bool value) {
  _internal_set_nocolor(value);
  // @@protoc_insertion_point(field_set:Serialization.Color.noColor)
}

// string stringColor = 2;
inline bool Color::_internal_has_stringcolor() const {
  return possibleColor_case() == kStringColor;
}
inline bool Color::has_stringcolor() const {
  return _internal_has_stringcolor();
}
inline void Color::set_has_stringcolor() {
  _oneof_case_[0] = kStringColor;
}
inline void Color::clear_stringcolor() {
  if (_internal_has_stringcolor()) {
    possibleColor_.stringcolor_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
    clear_has_possibleColor();
  }
}
inline const std::string& Color::stringcolor() const {
  // @@protoc_insertion_point(field_get:Serialization.Color.stringColor)
  return _internal_stringcolor();
}
template <typename ArgT0, typename... ArgT>
inline void Color::set_stringcolor(ArgT0&& arg0, ArgT... args) {
  if (!_internal_has_stringcolor()) {
    clear_possibleColor();
    set_has_stringcolor();
    possibleColor_.stringcolor_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  possibleColor_.stringcolor_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Serialization.Color.stringColor)
}
inline std::string* Color::mutable_stringcolor() {
  std::string* _s = _internal_mutable_stringcolor();
  // @@protoc_insertion_point(field_mutable:Serialization.Color.stringColor)
  return _s;
}
inline const std::string& Color::_internal_stringcolor() const {
  if (_internal_has_stringcolor()) {
    return possibleColor_.stringcolor_.Get();
  }
  return ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void Color::_internal_set_stringcolor(const std::string& value) {
  if (!_internal_has_stringcolor()) {
    clear_possibleColor();
    set_has_stringcolor();
    possibleColor_.stringcolor_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  possibleColor_.stringcolor_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Color::_internal_mutable_stringcolor() {
  if (!_internal_has_stringcolor()) {
    clear_possibleColor();
    set_has_stringcolor();
    possibleColor_.stringcolor_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  return possibleColor_.stringcolor_.Mutable(
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Color::release_stringcolor() {
  // @@protoc_insertion_point(field_release:Serialization.Color.stringColor)
  if (_internal_has_stringcolor()) {
    clear_has_possibleColor();
    return possibleColor_.stringcolor_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
  } else {
    return nullptr;
  }
}
inline void Color::set_allocated_stringcolor(std::string* stringcolor) {
  if (has_possibleColor()) {
    clear_possibleColor();
  }
  if (stringcolor != nullptr) {
    set_has_stringcolor();
    possibleColor_.stringcolor_.UnsafeSetDefault(stringcolor);
    ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArenaForAllocation();
    if (arena != nullptr) {
      arena->Own(stringcolor);
    }
  }
  // @@protoc_insertion_point(field_set_allocated:Serialization.Color.stringColor)
}

// .Serialization.Rgba rgba = 3;
inline bool Color::_internal_has_rgba() const {
  return possibleColor_case() == kRgba;
}
inline bool Color::has_rgba() const {
  return _internal_has_rgba();
}
inline void Color::set_has_rgba() {
  _oneof_case_[0] = kRgba;
}
inline void Color::clear_rgba() {
  if (_internal_has_rgba()) {
    if (GetArenaForAllocation() == nullptr) {
      delete possibleColor_.rgba_;
    }
    clear_has_possibleColor();
  }
}
inline ::Serialization::Rgba* Color::release_rgba() {
  // @@protoc_insertion_point(field_release:Serialization.Color.rgba)
  if (_internal_has_rgba()) {
    clear_has_possibleColor();
      ::Serialization::Rgba* temp = possibleColor_.rgba_;
    if (GetArenaForAllocation() != nullptr) {
      temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
    }
    possibleColor_.rgba_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::Serialization::Rgba& Color::_internal_rgba() const {
  return _internal_has_rgba()
      ? *possibleColor_.rgba_
      : reinterpret_cast< ::Serialization::Rgba&>(::Serialization::_Rgba_default_instance_);
}
inline const ::Serialization::Rgba& Color::rgba() const {
  // @@protoc_insertion_point(field_get:Serialization.Color.rgba)
  return _internal_rgba();
}
inline ::Serialization::Rgba* Color::unsafe_arena_release_rgba() {
  // @@protoc_insertion_point(field_unsafe_arena_release:Serialization.Color.rgba)
  if (_internal_has_rgba()) {
    clear_has_possibleColor();
    ::Serialization::Rgba* temp = possibleColor_.rgba_;
    possibleColor_.rgba_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Color::unsafe_arena_set_allocated_rgba(::Serialization::Rgba* rgba) {
  clear_possibleColor();
  if (rgba) {
    set_has_rgba();
    possibleColor_.rgba_ = rgba;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Serialization.Color.rgba)
}
inline ::Serialization::Rgba* Color::_internal_mutable_rgba() {
  if (!_internal_has_rgba()) {
    clear_possibleColor();
    set_has_rgba();
    possibleColor_.rgba_ = CreateMaybeMessage< ::Serialization::Rgba >(GetArenaForAllocation());
  }
  return possibleColor_.rgba_;
}
inline ::Serialization::Rgba* Color::mutable_rgba() {
  ::Serialization::Rgba* _msg = _internal_mutable_rgba();
  // @@protoc_insertion_point(field_mutable:Serialization.Color.rgba)
  return _msg;
}

inline bool Color::has_possibleColor() const {
  return possibleColor_case() != POSSIBLECOLOR_NOT_SET;
}
inline void Color::clear_has_possibleColor() {
  _oneof_case_[0] = POSSIBLECOLOR_NOT_SET;
}
inline Color::PossibleColorCase Color::possibleColor_case() const {
  return Color::PossibleColorCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Serialization

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_svg_2eproto
