; ModuleID = 'out'
source_filename = "out"

%_Z8Settings = type { i64, ptr, i64, i64 }

@0 = private unnamed_addr constant [25 x i8] c"Hello From Friday World!\00", align 1
@1 = private unnamed_addr constant [19 x i8] c"Hello From Friday!\00", align 1

declare i32 @printf(ptr, ...)

declare i64 @_Zpl3int(i64)

declare i64 @_Zpl3int3int(i64, i64)

declare i8 @_Zpl4byte(i8)

declare i8 @_Zpl4byte4byte(i8, i8)

declare double @_Zpl5float(double)

declare double @_Zpl5float5float(double, double)

declare ptr @_ZplP4void3int(ptr, i64)

declare i64 @_Zmi3int(i64)

declare i64 @_Zmi3int3int(i64, i64)

declare i8 @_Zmi4byte(i8)

declare i8 @_Zmi4byte4byte(i8, i8)

declare double @_Zmi5float(double)

declare double @_Zmi5float5float(double, double)

declare ptr @_ZmiP4void3int(ptr, i64)

declare i64 @_ZmiP4voidP4void(ptr, ptr)

declare i64 @_Zml3int3int(i64, i64)

declare i8 @_Zml4byte4byte(i8, i8)

declare double @_Zml5float5float(double, double)

declare i64 @_Zdv3int3int(i64, i64)

declare i8 @_Zdv4byte4byte(i8, i8)

declare double @_Zdv5float5float(double, double)

declare i64 @_Zrm3int3int(i64, i64)

declare i8 @_Zrm4byte4byte(i8, i8)

declare double @_Zrm5float5float(double, double)

declare i1 @_Zeq3int3int(i64, i64)

declare i1 @_Zeq4byte4byte(i8, i8)

declare i1 @_Zeq4bool4bool(i1, i1)

declare i1 @_Zeq5float5float(double, double)

declare i1 @_ZeqP4voidP4void(ptr, ptr)

declare i1 @_Zne3int3int(i64, i64)

declare i1 @_Zne4byte4byte(i8, i8)

declare i1 @_Zne4bool4bool(i1, i1)

declare i1 @_Zne5float5float(double, double)

declare i1 @_ZneP4voidP4void(ptr, ptr)

declare i1 @_Zlt3int3int(i64, i64)

declare i1 @_Zlt4byte4byte(i8, i8)

declare i1 @_Zlt5float5float(double, double)

declare i1 @_ZltP4voidP4void(ptr, ptr)

declare i1 @_Zgt3int3int(i64, i64)

declare i1 @_Zgt4byte4byte(i8, i8)

declare i1 @_Zgt5float5float(double, double)

declare i1 @_ZgtP4voidP4void(ptr, ptr)

declare i1 @_Zle3int3int(i64, i64)

declare i1 @_Zle4byte4byte(i8, i8)

declare i1 @_Zle5float5float(double, double)

declare i1 @_ZleP4voidP4void(ptr, ptr)

declare i1 @_Zge3int3int(i64, i64)

declare i1 @_Zge4byte4byte(i8, i8)

declare i1 @_Zge5float5float(double, double)

declare i1 @_ZgeP4voidP4void(ptr, ptr)

declare i64 @_Zan3int3int(i64, i64)

declare i8 @_Zan4byte4byte(i8, i8)

declare i1 @_Zan4bool4bool(i1, i1)

declare i64 @_Zor3int3int(i64, i64)

declare i8 @_Zor4byte4byte(i8, i8)

declare i1 @_Zor4bool4bool(i1, i1)

declare i64 @_Zco3int(i64)

declare i8 @_Zco4byte(i8)

declare i1 @_Zco4bool(i1)

declare i64 @_Zpp3int(i64)

declare double @_Zpp5float(double)

declare i64 @_Zmm3int(i64)

declare double @_Zmm5float(double)

declare i1 @_Zaa4bool4bool(i1, i1)

declare i1 @_Zoo4bool4bool(i1, i1)

declare i1 @_Znt4bool(i1)

declare i64 @sum(i64, i64)

declare ptr @malloc(i64)

declare void @free(ptr)

declare void @InitWindow(i64, i64, ptr)

declare void @CloseWindow()

declare i1 @WindowShouldClose()

declare void @BeginDrawing()

declare void @EndDrawing()

declare void @SetTargetFPS(i64)

declare void @WaitTime(double)

define i64 @_Z8getWidth() {
.alloca-block:
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  ret i64 1200
}

define i64 @_Z9getHeight() {
.alloca-block:
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  ret i64 800
}

define ptr @_Z8getTitle() {
.alloca-block:
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  ret ptr @0
}

define %_Z8Settings @_Z11getSettings() {
.alloca-block:
  %0 = alloca %_Z8Settings, align 8
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  %1 = getelementptr inbounds nuw %_Z8Settings, ptr %0, i32 0, i32 2
  store ptr @1, ptr %1, align 8
  %2 = getelementptr inbounds nuw %_Z8Settings, ptr %0, i32 0, i32 3
  store i64 60, ptr %2, align 4
  %3 = getelementptr inbounds nuw %_Z8Settings, ptr %0, i32 0, i32 1
  store i64 800, ptr %3, align 4
  %4 = getelementptr inbounds nuw %_Z8Settings, ptr %0, i32 0, i32 0
  store i64 1200, ptr %4, align 4
  %5 = load %_Z8Settings, ptr %0, align 8
  ret %_Z8Settings %5
}

define void @_Z4main() {
.alloca-block:
  %0 = alloca i64, align 8
  %1 = alloca i64, align 8
  %2 = alloca ptr, align 8
  %3 = alloca i64, align 8
  %4 = alloca %_Z8Settings, align 8
  %5 = alloca ptr, align 8
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  %6 = call i64 @_Z8getWidth()
  store i64 %6, ptr %0, align 4
  %7 = call i64 @_Z9getHeight()
  store i64 %7, ptr %1, align 4
  %8 = call ptr @_Z8getTitle()
  store ptr %8, ptr %2, align 8
  store i64 60, ptr %3, align 4
  %9 = call %_Z8Settings @_Z11getSettings()
  store %_Z8Settings %9, ptr %4, align 8
  %10 = load i64, ptr %0, align 4
  %11 = load i64, ptr %1, align 4
  %12 = load ptr, ptr %2, align 8
  call void @InitWindow(i64 %10, i64 %11, ptr %12)
  %13 = load i64, ptr %3, align 4
  call void @SetTargetFPS(i64 %13)
  br label %.while-condition

.while-condition:                                 ; preds = %.while-body, %.entry-block
  %14 = call i1 @WindowShouldClose()
  %15 = call i1 @_Znt4bool(i1 %14)
  br i1 %15, label %.while-body, label %.while-after

.while-body:                                      ; preds = %.while-condition
  call void @BeginDrawing()
  call void @EndDrawing()
  br label %.while-condition

.while-after:                                     ; preds = %.while-condition
  %16 = call ptr @malloc(i64 32)
  store ptr %16, ptr %5, align 8
  %17 = load ptr, ptr %5, align 8
  call void @free(ptr %17)
  call void @CloseWindow()
  ret void
}
