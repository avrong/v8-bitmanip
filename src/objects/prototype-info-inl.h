// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_OBJECTS_PROTOTYPE_INFO_INL_H_
#define V8_OBJECTS_PROTOTYPE_INFO_INL_H_

#include "src/objects/prototype-info.h"

#include "src/heap/heap-write-barrier-inl.h"
#include "src/objects/fixed-array-inl.h"
#include "src/objects/map-inl.h"
#include "src/objects/maybe-object.h"
#include "src/objects/objects-inl.h"
#include "src/objects/struct-inl.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"

namespace v8 {
namespace internal {

#include "torque-generated/src/objects/prototype-info-tq-inl.inc"

TQ_OBJECT_CONSTRUCTORS_IMPL(PrototypeInfo)

DEF_GETTER(PrototypeInfo, derived_maps, Tagged<HeapObject>) {
  return TaggedField<HeapObject, kDerivedMapsOffset>::load(cage_base, *this);
}
RELEASE_ACQUIRE_ACCESSORS(PrototypeInfo, derived_maps, Tagged<HeapObject>,
                          kDerivedMapsOffset)

MaybeObject PrototypeInfo::ObjectCreateMap() {
  auto derived = derived_maps();
  if (IsUndefined(derived)) {
    return MaybeObject();
  }
  // Index 0 is the map for object create
  Tagged<WeakArrayList> derived_list = Tagged<WeakArrayList>::cast(derived);
  DCHECK_GT(derived_list->length(), 0);
  MaybeObject el = derived_list->Get(0);
  DCHECK(el.IsWeakOrCleared());
  return el;
}

MaybeObject PrototypeInfo::ObjectCreateMap(AcquireLoadTag tag) {
  auto derived = derived_maps(tag);
  if (IsUndefined(derived)) {
    return MaybeObject();
  }
  // Index 0 is the map for object create
  Tagged<WeakArrayList> derived_list = Tagged<WeakArrayList>::cast(derived);
  DCHECK_GT(derived_list->length(), 0);
  MaybeObject el = derived_list->Get(0);
  DCHECK(el.IsWeakOrCleared());
  return el;
}

// static
void PrototypeInfo::SetObjectCreateMap(Handle<PrototypeInfo> info,
                                       Handle<Map> map, Isolate* isolate) {
  if (IsUndefined(info->derived_maps())) {
    Tagged<WeakArrayList> derived = *isolate->factory()->NewWeakArrayList(1);
    derived->Set(0, HeapObjectReference::Weak(*map));
    derived->set_length(1);
    info->set_derived_maps(derived, kReleaseStore);
  } else {
    Tagged<WeakArrayList> derived =
        Tagged<WeakArrayList>::cast(info->derived_maps());
    DCHECK(derived->Get(0).IsCleared());
    DCHECK_GT(derived->length(), 0);
    derived->Set(0, HeapObjectReference::Weak(*map));
  }
}

MaybeObject PrototypeInfo::GetDerivedMap(Handle<Map> from) {
  if (IsUndefined(derived_maps())) {
    return MaybeObject();
  }
  auto derived = Tagged<WeakArrayList>::cast(derived_maps());
  // Index 0 is the map for object create
  for (int i = 1; i < derived->length(); ++i) {
    MaybeObject el = derived->Get(i);
    Tagged<Map> map_obj;
    if (el.GetHeapObjectIfWeak(&map_obj)) {
      Tagged<Map> to = Tagged<Map>::cast(map_obj);
      if (to->GetConstructor() == from->GetConstructor() &&
          to->instance_type() == from->instance_type()) {
        return el;
      }
    }
  }
  return MaybeObject();
}

// static
void PrototypeInfo::AddDerivedMap(Handle<PrototypeInfo> info, Handle<Map> to,
                                  Isolate* isolate) {
  if (IsUndefined(info->derived_maps())) {
    // Index 0 is the map for object create
    Tagged<WeakArrayList> derived = *isolate->factory()->NewWeakArrayList(2);
    // GetConstructMap assumes a weak pointer.
    derived->Set(0, HeapObjectReference::ClearedValue(isolate));
    derived->Set(1, HeapObjectReference::Weak(*to));
    derived->set_length(2);
    info->set_derived_maps(derived, kReleaseStore);
    return;
  }
  auto derived = Tagged<WeakArrayList>::cast(info->derived_maps());
  // Index 0 is the map for object create
  int i = 1;
  for (; i < derived->length(); ++i) {
    MaybeObject el = derived->Get(i);
    if (el.IsCleared()) {
      derived->Set(i, HeapObjectReference::Weak(*to));
      return;
    }
  }

  auto bigger =
      WeakArrayList::EnsureSpace(isolate, handle(derived, isolate), i + 1);
  bigger->Set(i, HeapObjectReference::Weak(*to));
  bigger->set_length(i + 1);
  if (*bigger != *derived) {
    info->set_derived_maps(*bigger, kReleaseStore);
  }
}

bool PrototypeInfo::IsPrototypeInfoFast(Tagged<Object> object) {
  bool is_proto_info = object != Smi::zero();
  DCHECK_EQ(is_proto_info, IsPrototypeInfo(object));
  return is_proto_info;
}

BOOL_ACCESSORS(PrototypeInfo, bit_field, should_be_fast_map,
               ShouldBeFastBit::kShift)

void PrototypeUsers::MarkSlotEmpty(Tagged<WeakArrayList> array, int index) {
  DCHECK_GT(index, 0);
  DCHECK_LT(index, array->length());
  // Chain the empty slots into a linked list (each empty slot contains the
  // index of the next empty slot).
  array->Set(index, MaybeObject::FromObject(empty_slot_index(array)));
  set_empty_slot_index(array, index);
}

Tagged<Smi> PrototypeUsers::empty_slot_index(Tagged<WeakArrayList> array) {
  return array->Get(kEmptySlotIndex).ToSmi();
}

void PrototypeUsers::set_empty_slot_index(Tagged<WeakArrayList> array,
                                          int index) {
  array->Set(kEmptySlotIndex, MaybeObject::FromObject(Smi::FromInt(index)));
}

}  // namespace internal
}  // namespace v8

#include "src/objects/object-macros-undef.h"

#endif  // V8_OBJECTS_PROTOTYPE_INFO_INL_H_
