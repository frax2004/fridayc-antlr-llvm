; ModuleID = 'out'
source_filename = "out"

%_ZN11collections9ArrayListE = type { i64, ptr, i64 }
%_ZN11collections9ArrayListE.6 = type { i64, ptr, i64 }

declare i1 @_Znt4bool(i1)

declare i1 @_Zoo4bool4bool(i1, i1)

declare i1 @_Zaa4bool4bool(i1, i1)

declare i64 @_Zmm3int(i64)

declare double @_Zmm5float(double)

declare i64 @_Zpp3int(i64)

declare double @_Zpp5float(double)

declare i8 @_Zor4byte4byte(i8, i8)

declare i1 @_Zor4bool4bool(i1, i1)

declare i64 @_Zor3int3int(i64, i64)

declare i8 @_Zan4byte4byte(i8, i8)

declare i1 @_Zan4bool4bool(i1, i1)

declare i64 @_Zan3int3int(i64, i64)

declare i1 @_Zle4byte4byte(i8, i8)

declare i1 @_Zle3int3int(i64, i64)

declare i1 @_Zle5float5float(double, double)

declare i1 @_ZleP4voidP4void(ptr, ptr)

declare i1 @_Zgt4byte4byte(i8, i8)

declare i1 @_Zgt3int3int(i64, i64)

declare i1 @_Zgt5float5float(double, double)

declare i1 @_ZgtP4voidP4void(ptr, ptr)

declare i1 @_Zge4byte4byte(i8, i8)

declare i1 @_Zge3int3int(i64, i64)

declare i1 @_Zge5float5float(double, double)

declare i1 @_ZgeP4voidP4void(ptr, ptr)

declare i8 @_Zpl4byte(i8)

declare i8 @_Zpl4byte4byte(i8, i8)

declare i64 @_Zpl3int(i64)

declare i64 @_Zpl3int3int(i64, i64)

declare double @_Zpl5float(double)

declare double @_Zpl5float5float(double, double)

declare ptr @_ZplP4void3int(ptr, i64)

declare i1 @_Zeq4byte4byte(i8, i8)

declare i1 @_Zeq4bool4bool(i1, i1)

declare i1 @_Zeq3int3int(i64, i64)

declare i1 @_Zeq5float5float(double, double)

declare i1 @_ZeqP4voidP4void(ptr, ptr)

declare i8 @_Zml4byte4byte(i8, i8)

declare i64 @_Zml3int3int(i64, i64)

declare double @_Zml5float5float(double, double)

declare i8 @_Zmi4byte(i8)

declare i8 @_Zmi4byte4byte(i8, i8)

declare i64 @_Zmi3int(i64)

declare i64 @_Zmi3int3int(i64, i64)

declare double @_Zmi5float(double)

declare double @_Zmi5float5float(double, double)

declare ptr @_ZmiP4void3int(ptr, i64)

declare i64 @_ZmiP4voidP4void(ptr, ptr)

declare i8 @_Zdv4byte4byte(i8, i8)

declare i64 @_Zdv3int3int(i64, i64)

declare double @_Zdv5float5float(double, double)

declare i8 @_Zrm4byte4byte(i8, i8)

declare i64 @_Zrm3int3int(i64, i64)

declare double @_Zrm5float5float(double, double)

declare i8 @_Zco4byte(i8)

declare i1 @_Zco4bool(i1)

declare i64 @_Zco3int(i64)

declare i1 @_Zne4byte4byte(i8, i8)

declare i1 @_Zne4bool4bool(i1, i1)

declare i1 @_Zne3int3int(i64, i64)

declare i1 @_Zne5float5float(double, double)

declare i1 @_ZneP4voidP4void(ptr, ptr)

declare i1 @_Zlt4byte4byte(i8, i8)

declare i1 @_Zlt3int3int(i64, i64)

declare i1 @_Zlt5float5float(double, double)

declare i1 @_ZltP4voidP4void(ptr, ptr)

declare %_ZN11collections9ArrayListE @_Z3get()

declare ptr @_Z11get_pointer()

define void @_Z4main() {
  %printf = call i32 (ptr, ...) @printf(<null operand!>)
  ret void
}

declare i32 @printf(ptr, ...)

define ptr @_ZN11collections9ArrayList3getEP9ArrayList3int(ptr %this, i64 %index) {
  ret void
}

define void @_ZN11collections9ArrayList3setEP9ArrayList3intP4void(ptr %this, i64 %index, ptr %element) {
  ret void
}

define i64 @_ZN11collections9ArrayList4sizeEP9ArrayList(ptr %this) {
  ret void
}

define i64 @_ZN11collections9ArrayList8max_sizeEP9ArrayList(ptr %this) {
  ret void
}

define void @_ZN11collections9ArrayList3popEP9ArrayList(ptr %this) {
  ret void
}

define %_ZN11collections9ArrayListE.6 @_ZN11collections9ArrayList6createE() {
  ret void
}

define void @_ZN11collections9ArrayList4pushEP9ArrayListP4void(ptr %this, ptr %obj) {
  ret void
}

define void @_ZN11collections9ArrayList7destroyEP9ArrayList(ptr %this) {
  ret void
}

define void @_ZN11collections9ArrayList4growEP9ArrayList(ptr %this) {
  ret void
}

declare ptr @_ZN1C6mallocE3int(i64)

declare ptr @_ZN1C7reallocEP4void3int(ptr, i64)

declare void @_ZN1C4freeEP4void(ptr)
