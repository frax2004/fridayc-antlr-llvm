; ModuleID = 'out'
source_filename = "out"

%_ZN6Raylib5ImageE = type { i32, i32, i32, i32, ptr }
%_ZN6Raylib8Camera2DE = type { float, float, %_ZN6Raylib7Vector2E, %_ZN6Raylib7Vector2E }
%_ZN6Raylib7Vector2E = type { float, float }
%_ZN6Raylib8Camera3DE = type { float, i32, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E }
%_ZN6Raylib7Vector3E = type { float, float, float }
%_ZN6Raylib13RenderTextureE = type { %_ZN6Raylib7TextureE, %_ZN6Raylib7TextureE, i32 }
%_ZN6Raylib7TextureE = type { i32, i32, i32, i32, i32 }
%_ZN6Raylib6ShaderE = type { ptr, i32 }
%_ZN6Raylib14VrStereoConfigE = type { %_ZN6Raylib6Float2E, %_ZN6Raylib6Float2E, %_ZN6Raylib6Float2E, %_ZN6Raylib6Float2E, %_ZN6Raylib6MatrixE, %_ZN6Raylib6Float2E, %_ZN6Raylib6Float2E, %_ZN6Raylib6MatrixE, %_ZN6Raylib6MatrixE, %_ZN6Raylib6MatrixE }
%_ZN6Raylib6Float2E = type { float, float }
%_ZN6Raylib6MatrixE = type { float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float }
%_ZN6Raylib12VrDeviceInfoE = type { %_ZN6Raylib6Float4E, float, %_ZN6Raylib6Float4E, float, float, float, float, i32, i32 }
%_ZN6Raylib6Float4E = type { float, float, float, float }
%_ZN6Raylib3RayE = type { %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E }
%_ZN6Raylib12FilePathListE = type { ptr, i32, i32 }
%_ZN6Raylib19AutomationEventListE = type { ptr, i32, i32 }
%_ZN6Raylib15AutomationEventE = type { %_ZN6Raylib4Int4E, i32, i32 }
%_ZN6Raylib4Int4E = type { i32, i32, i32, i32 }
%_ZN6Raylib9RectangleE = type { float, float, float, float }
%_ZN6Raylib4FontE = type { ptr, ptr, %_ZN6Raylib7TextureE, i32, i32, i32 }
%_ZN6Raylib10NPatchInfoE = type { i32, i32, i32, i32, i32, %_ZN6Raylib9RectangleE }
%_ZN6Raylib7Vector4E = type { float, float, float, float }
%_ZN6Raylib9GlyphInfoE = type { i32, %_ZN6Raylib5ImageE, i32, i32, i32 }
%_ZN6Raylib5ModelE = type { ptr, ptr, ptr, ptr, i32, ptr, i32, i32, %_ZN6Raylib6MatrixE }
%_ZN6Raylib4MeshE = type { ptr, i32, i32, ptr, i32, i32, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr }
%_ZN6Raylib11BoundingBoxE = type { %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E }
%_ZN6Raylib8MaterialE = type { %_ZN6Raylib6Float4E, ptr, %_ZN6Raylib6ShaderE }
%_ZN6Raylib14ModelAnimationE = type { ptr, ptr, %_ZN6Raylib6Byte32E, i32, i32 }
%_ZN6Raylib6Byte32E = type { i64, i64, i64, i64 }
%_ZN6Raylib12RayCollisionE = type { %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, float, i1 }
%_ZN6Raylib4WaveE = type { ptr, i32, i32, i32, i32 }
%_ZN6Raylib5SoundE = type { i32, %_ZN6Raylib11AudioStreamE }
%_ZN6Raylib11AudioStreamE = type { i32, i32, i32, ptr, ptr }
%_ZN6Raylib5MusicE = type { ptr, i32, i1, i32, %_ZN6Raylib11AudioStreamE }
%"_Z6[]bool" = type { i64, ptr }
%"_Z7[]*byte" = type { i64, ptr }
%_ZN6Raylib5ColorE = type { i8, i8, i8, i8 }

@0 = private unnamed_addr constant [20 x i8] c"Friday - GameOfLife\00", align 1

declare i32 @printf(ptr, ...)

declare double @_Zpl5float(double)

declare double @_Zpl5float5float(double, double)

declare i64 @_Zpl3int(i64)

declare i64 @_Zpl3int3int(i64, i64)

declare i8 @_Zpl4byte(i8)

declare i8 @_Zpl4byte4byte(i8, i8)

declare ptr @_ZplP4void3int(ptr, i64)

declare double @_Zmi5float(double)

declare double @_Zmi5float5float(double, double)

declare i64 @_Zmi3int(i64)

declare i64 @_Zmi3int3int(i64, i64)

declare i8 @_Zmi4byte(i8)

declare i8 @_Zmi4byte4byte(i8, i8)

declare ptr @_ZmiP4void3int(ptr, i64)

declare i64 @_ZmiP4voidP4void(ptr, ptr)

declare double @_Zml5float5float(double, double)

declare i64 @_Zml3int3int(i64, i64)

declare i8 @_Zml4byte4byte(i8, i8)

declare double @_Zdv5float5float(double, double)

declare i64 @_Zdv3int3int(i64, i64)

declare i8 @_Zdv4byte4byte(i8, i8)

declare double @_Zrm5float5float(double, double)

declare i64 @_Zrm3int3int(i64, i64)

declare i8 @_Zrm4byte4byte(i8, i8)

declare i1 @_Zeq5float5float(double, double)

declare i1 @_Zeq3int3int(i64, i64)

declare i1 @_Zeq4byte4byte(i8, i8)

declare i1 @_Zeq4bool4bool(i1, i1)

declare i1 @_ZeqP4voidP4void(ptr, ptr)

declare i1 @_Zne5float5float(double, double)

declare i1 @_Zne3int3int(i64, i64)

declare i1 @_Zne4byte4byte(i8, i8)

declare i1 @_Zne4bool4bool(i1, i1)

declare i1 @_ZneP4voidP4void(ptr, ptr)

declare i1 @_Zlt5float5float(double, double)

declare i1 @_Zlt3int3int(i64, i64)

declare i1 @_Zlt4byte4byte(i8, i8)

declare i1 @_ZltP4voidP4void(ptr, ptr)

declare i1 @_Zgt5float5float(double, double)

declare i1 @_Zgt3int3int(i64, i64)

declare i1 @_Zgt4byte4byte(i8, i8)

declare i1 @_ZgtP4voidP4void(ptr, ptr)

declare i1 @_Zle5float5float(double, double)

declare i1 @_Zle3int3int(i64, i64)

declare i1 @_Zle4byte4byte(i8, i8)

declare i1 @_ZleP4voidP4void(ptr, ptr)

declare i1 @_Zge5float5float(double, double)

declare i1 @_Zge3int3int(i64, i64)

declare i1 @_Zge4byte4byte(i8, i8)

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

declare double @_Zpp5float(double)

declare i64 @_Zpp3int(i64)

declare double @_Zmm5float(double)

declare i64 @_Zmm3int(i64)

declare i1 @_Zaa4bool4bool(i1, i1)

declare i1 @_Zoo4bool4bool(i1, i1)

declare i1 @_Znt4bool(i1)

declare ptr @calloc(i64, i64)

declare ptr @malloc(i64)

declare ptr @realloc(ptr, i64)

declare void @free(ptr)

declare double @atof(ptr)

declare i64 @atoi(ptr)

declare ptr @strdup(ptr)

declare i64 @strlen(ptr)

declare void @memset(ptr, i64, i64)

declare void @InitWindow(i32, i32, ptr)

declare void @CloseWindow()

declare i1 @WindowShouldClose()

declare i1 @IsWindowReady()

declare i1 @IsWindowFullscreen()

declare i1 @IsWindowHidden()

declare i1 @IsWindowMinimized()

declare i1 @IsWindowMaximized()

declare i1 @IsWindowFocused()

declare i1 @IsWindowResized()

declare i1 @IsWindowState(i32)

declare void @SetWindowState(i32)

declare void @ClearWindowState(i32)

declare void @ToggleFullscreen()

declare void @ToggleBorderlessWindowed()

declare void @MaximizeWindow()

declare void @MinimizeWindow()

declare void @RestoreWindow()

declare void @SetWindowIcon(%_ZN6Raylib5ImageE)

declare void @SetWindowIcons(ptr, i32)

declare void @SetWindowTitle(ptr)

declare void @SetWindowPosition(i32, i32)

declare void @SetWindowMonitor(i32)

declare void @SetWindowMinSize(i32, i32)

declare void @SetWindowMaxSize(i32, i32)

declare void @SetWindowSize(i32, i32)

declare void @SetWindowOpacity(float)

declare void @SetWindowFocused()

declare ptr @GetWindowHandle()

declare i32 @GetScreenWidth()

declare i32 @GetScreenHeight()

declare i32 @GetRenderWidth()

declare i32 @GetRenderHeight()

declare i32 @GetMonitorCount()

declare i32 @GetCurrentMonitor()

declare i64 @GetMonitorPosition(i32)

declare i32 @GetMonitorWidth(i32)

declare i32 @GetMonitorHeight(i32)

declare i32 @GetMonitorPhysicalWidth(i32)

declare i32 @GetMonitorPhysicalHeight(i32)

declare i32 @GetMonitorRefreshRate(i32)

declare i64 @GetWindowPosition()

declare i64 @GetWindowScaleDPI()

declare ptr @GetMonitorName(i32)

declare void @SetClipboardText(ptr)

declare ptr @GetClipboardText()

declare %_ZN6Raylib5ImageE @GetClipboardImage()

declare void @EnableEventWaiting()

declare void @DisableEventWaiting()

declare void @ShowCursor()

declare void @HideCursor()

declare i1 @IsCursorHidden()

declare void @EnableCursor()

declare void @DisableCursor()

declare i1 @IsCursorOnScreen()

declare void @ClearBackground(i32)

declare void @BeginDrawing()

declare void @EndDrawing()

declare void @BeginMode2D(%_ZN6Raylib8Camera2DE)

declare void @EndMode2D()

declare void @BeginMode3D(%_ZN6Raylib8Camera3DE)

declare void @EndMode3D()

declare void @BeginTextureMode(%_ZN6Raylib13RenderTextureE)

declare void @EndTextureMode()

declare void @BeginShaderMode(%_ZN6Raylib6ShaderE)

declare void @EndShaderMode()

declare void @BeginBlendMode(i32)

declare void @EndBlendMode()

declare void @BeginScissorMode(i32, i32, i32, i32)

declare void @EndScissorMode()

declare void @BeginVrStereoMode(%_ZN6Raylib14VrStereoConfigE)

declare void @EndVrStereoMode()

declare %_ZN6Raylib14VrStereoConfigE @LoadVrStereoConfig(%_ZN6Raylib12VrDeviceInfoE)

declare void @UnloadVrStereoConfig(%_ZN6Raylib14VrStereoConfigE)

declare %_ZN6Raylib6ShaderE @LoadShader(ptr, ptr)

declare %_ZN6Raylib6ShaderE @LoadShaderFromMemory(ptr, ptr)

declare i1 @IsShaderValid(%_ZN6Raylib6ShaderE)

declare i32 @GetShaderLocation(%_ZN6Raylib6ShaderE, ptr)

declare i32 @GetShaderLocationAttrib(%_ZN6Raylib6ShaderE, ptr)

declare void @SetShaderValue(%_ZN6Raylib6ShaderE, i32, ptr, i32)

declare void @SetShaderValueV(%_ZN6Raylib6ShaderE, i32, ptr, i32, i32)

declare void @SetShaderValueMatrix(%_ZN6Raylib6ShaderE, i32, %_ZN6Raylib6MatrixE)

declare void @SetShaderValueTexture(%_ZN6Raylib6ShaderE, i32, %_ZN6Raylib7TextureE)

declare void @UnloadShader(%_ZN6Raylib6ShaderE)

declare %_ZN6Raylib3RayE @GetScreenToWorldRay(i64, %_ZN6Raylib8Camera3DE)

declare %_ZN6Raylib3RayE @GetScreenToWorldRayEx(i64, %_ZN6Raylib8Camera3DE, i32, i32)

declare i64 @GetWorldToScreen(%_ZN6Raylib7Vector3E, %_ZN6Raylib8Camera3DE)

declare i64 @GetWorldToScreenEx(%_ZN6Raylib7Vector3E, %_ZN6Raylib8Camera3DE, i32, i32)

declare i64 @GetWorldToScreen2D(i64, %_ZN6Raylib8Camera2DE)

declare i64 @GetScreenToWorld2D(i64, %_ZN6Raylib8Camera2DE)

declare %_ZN6Raylib6MatrixE @GetCameraMatrix(%_ZN6Raylib8Camera3DE)

declare %_ZN6Raylib6MatrixE @GetCameraMatrix2D(%_ZN6Raylib8Camera2DE)

declare void @SetTargetFPS(i32)

declare float @GetFrameTime()

declare double @GetTime()

declare i32 @GetFPS()

declare void @SwapScreenBuffer()

declare void @PollInputEvents()

declare void @WaitTime(double)

declare void @SetRandomSeed(i32)

declare i32 @GetRandomValue(i32, i32)

declare ptr @LoadRandomSequence(i32, i32, i32)

declare void @UnloadRandomSequence(ptr)

declare void @TakeScreenshot(ptr)

declare void @SetConfigFlags(i32)

declare void @OpenURL(ptr)

declare void @SetTraceLogLevel(i32)

declare void @TraceLog(i32, ptr)

declare void @SetTraceLogCallback(ptr)

declare ptr @MemAlloc(i32)

declare ptr @MemRealloc(ptr, i32)

declare void @MemFree(ptr)

declare ptr @LoadFileData(ptr, ptr)

declare void @UnloadFileData(ptr)

declare i1 @SaveFileData(ptr, ptr, i32)

declare i1 @ExportDataAsCode(ptr, i32, ptr)

declare ptr @LoadFileText(ptr)

declare void @UnloadFileText(ptr)

declare i1 @SaveFileText(ptr, ptr)

declare void @SetLoadFileDataCallback(ptr)

declare void @SetSaveFileDataCallback(ptr)

declare void @SetLoadFileTextCallback(ptr)

declare void @SetSaveFileTextCallback(ptr)

declare i32 @FileRename(ptr, ptr)

declare i32 @FileRemove(ptr)

declare i32 @FileCopy(ptr, ptr)

declare i32 @FileMove(ptr, ptr)

declare i32 @FileTextReplace(ptr, ptr, ptr)

declare i32 @FileTextFindIndex(ptr, ptr)

declare i1 @FileExists(ptr)

declare i1 @DirectoryExists(ptr)

declare i1 @IsFileExtension(ptr, ptr)

declare i32 @GetFileLength(ptr)

declare i32 @GetFileModTime(ptr)

declare ptr @GetFileExtension(ptr)

declare ptr @GetFileName(ptr)

declare ptr @GetFileNameWithoutExt(ptr)

declare ptr @GetDirectoryPath(ptr)

declare ptr @GetPrevDirectoryPath(ptr)

declare ptr @GetWorkingDirectory()

declare ptr @GetApplicationDirectory()

declare i32 @MakeDirectory(ptr)

declare i1 @ChangeDirectory(ptr)

declare i1 @IsPathFile(ptr)

declare i1 @IsFileNameValid(ptr)

declare %_ZN6Raylib12FilePathListE @LoadDirectoryFiles(ptr)

declare %_ZN6Raylib12FilePathListE @LoadDirectoryFilesEx(ptr, ptr, i1)

declare void @UnloadDirectoryFiles(%_ZN6Raylib12FilePathListE)

declare i1 @IsFileDropped()

declare %_ZN6Raylib12FilePathListE @LoadDroppedFiles()

declare void @UnloadDroppedFiles(%_ZN6Raylib12FilePathListE)

declare i32 @GetDirectoryFileCount(ptr)

declare i32 @GetDirectoryFileCountEx(ptr, ptr, i1)

declare ptr @CompressData(ptr, i32, ptr)

declare ptr @DecompressData(ptr, i32, ptr)

declare ptr @EncodeDataBase64(ptr, i32, ptr)

declare ptr @DecodeDataBase64(ptr, ptr)

declare i32 @ComputeCRC32(ptr, i32)

declare ptr @ComputeMD5(ptr, i32)

declare ptr @ComputeSHA1(ptr, i32)

declare ptr @ComputeSHA256(ptr, i32)

declare %_ZN6Raylib19AutomationEventListE @LoadAutomationEventList(ptr)

declare void @UnloadAutomationEventList(%_ZN6Raylib19AutomationEventListE)

declare i1 @ExportAutomationEventList(%_ZN6Raylib19AutomationEventListE, ptr)

declare void @SetAutomationEventList(ptr)

declare void @SetAutomationEventBaseFrame(i32)

declare void @StartAutomationEventRecording()

declare void @StopAutomationEventRecording()

declare void @PlayAutomationEvent(%_ZN6Raylib15AutomationEventE)

declare i1 @IsKeyPressed(i32)

declare i1 @IsKeyPressedRepeat(i32)

declare i1 @IsKeyDown(i32)

declare i1 @IsKeyReleased(i32)

declare i1 @IsKeyUp(i32)

declare i32 @GetKeyPressed()

declare i32 @GetCharPressed()

declare ptr @GetKeyName(i32)

declare void @SetExitKey(i32)

declare i1 @IsGamepadAvailable(i32)

declare ptr @GetGamepadName(i32)

declare i1 @IsGamepadButtonPressed(i32, i32)

declare i1 @IsGamepadButtonDown(i32, i32)

declare i1 @IsGamepadButtonReleased(i32, i32)

declare i1 @IsGamepadButtonUp(i32, i32)

declare i32 @GetGamepadButtonPressed()

declare i32 @GetGamepadAxisCount(i32)

declare float @GetGamepadAxisMovement(i32, i32)

declare i32 @SetGamepadMappings(ptr)

declare void @SetGamepadVibration(i32, float, float, float)

declare i1 @IsMouseButtonPressed(i32)

declare i1 @IsMouseButtonDown(i32)

declare i1 @IsMouseButtonReleased(i32)

declare i1 @IsMouseButtonUp(i32)

declare i32 @GetMouseX()

declare i32 @GetMouseY()

declare i64 @GetMousePosition()

declare i64 @GetMouseDelta()

declare void @SetMousePosition(i32, i32)

declare void @SetMouseOffset(i32, i32)

declare void @SetMouseScale(float, float)

declare float @GetMouseWheelMove()

declare i64 @GetMouseWheelMoveV()

declare void @SetMouseCursor(i32)

declare i32 @GetTouchX()

declare i32 @GetTouchY()

declare i64 @GetTouchPosition(i32)

declare i32 @GetTouchPointId(i32)

declare i32 @GetTouchPointCount()

declare void @SetGesturesEnabled(i32)

declare i1 @IsGestureDetected(i32)

declare i32 @GetGestureDetected()

declare float @GetGestureHoldDuration()

declare i64 @GetGestureDragVector()

declare float @GetGestureDragAngle()

declare i64 @GetGesturePinchVector()

declare float @GetGesturePinchAngle()

declare void @UpdateCamera(ptr, i32)

declare void @UpdateCameraPro(ptr, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, float)

declare void @SetShapesTexture(%_ZN6Raylib7TextureE, %_ZN6Raylib9RectangleE)

declare %_ZN6Raylib7TextureE @GetShapesTexture()

declare %_ZN6Raylib9RectangleE @GetShapesTextureRectangle()

declare void @DrawPixel(i32, i32, i32)

declare void @DrawPixelV(i64, i32)

declare void @DrawLine(i32, i32, i32, i32, i32)

declare void @DrawLineV(i64, i64, i32)

declare void @DrawLineEx(i64, i64, float, i32)

declare void @DrawLineStrip(ptr, i32, i32)

declare void @DrawLineBezier(i64, i64, float, i32)

declare void @DrawLineDashed(i64, i64, i32, i32, i32)

declare void @DrawCircle(i32, i32, float, i32)

declare void @DrawCircleV(i64, float, i32)

declare void @DrawCircleGradient(i64, float, i32, i32)

declare void @DrawCircleSector(i64, float, float, float, i32, i32)

declare void @DrawCircleSectorLines(i64, float, float, float, i32, i32)

declare void @DrawCircleLines(i32, i32, float, i32)

declare void @DrawCircleLinesV(i64, float, i32)

declare void @DrawEllipse(i32, i32, float, float, i32)

declare void @DrawEllipseV(i64, float, float, i32)

declare void @DrawEllipseLines(i32, i32, float, float, i32)

declare void @DrawEllipseLinesV(i64, float, float, i32)

declare void @DrawRing(i64, float, float, float, float, i32, i32)

declare void @DrawRingLines(i64, float, float, float, float, i32, i32)

declare void @DrawRectangle(i32, i32, i32, i32, i32)

declare void @DrawRectangleV(i64, i64, i32)

declare void @DrawRectangleRec(%_ZN6Raylib9RectangleE, i32)

declare void @DrawRectanglePro(%_ZN6Raylib9RectangleE, i64, float, i32)

declare void @DrawRectangleGradientV(i32, i32, i32, i32, i32, i32)

declare void @DrawRectangleGradientH(i32, i32, i32, i32, i32, i32)

declare void @DrawRectangleGradientEx(%_ZN6Raylib9RectangleE, i32, i32, i32, i32)

declare void @DrawRectangleLines(i32, i32, i32, i32, i32)

declare void @DrawRectangleLinesEx(%_ZN6Raylib9RectangleE, float, i32)

declare void @DrawRectangleRounded(%_ZN6Raylib9RectangleE, float, i32, i32)

declare void @DrawRectangleRoundedLines(%_ZN6Raylib9RectangleE, float, i32, i32)

declare void @DrawRectangleRoundedLinesEx(%_ZN6Raylib9RectangleE, float, i32, float, i32)

declare void @DrawTriangle(i64, i64, i64, i32)

declare void @DrawTriangleLines(i64, i64, i64, i32)

declare void @DrawTriangleFan(ptr, i32, i32)

declare void @DrawTriangleStrip(ptr, i32, i32)

declare void @DrawPoly(i64, i32, float, float, i32)

declare void @DrawPolyLines(i64, i32, float, float, i32)

declare void @DrawPolyLinesEx(i64, i32, float, float, float, i32)

declare void @DrawSplineLinear(ptr, i32, float, i32)

declare void @DrawSplineBasis(ptr, i32, float, i32)

declare void @DrawSplineCatmullRom(ptr, i32, float, i32)

declare void @DrawSplineBezierQuadratic(ptr, i32, float, i32)

declare void @DrawSplineBezierCubic(ptr, i32, float, i32)

declare void @DrawSplineSegmentLinear(i64, i64, float, i32)

declare void @DrawSplineSegmentBasis(i64, i64, i64, i64, float, i32)

declare void @DrawSplineSegmentCatmullRom(i64, i64, i64, i64, float, i32)

declare void @DrawSplineSegmentBezierQuadratic(i64, i64, i64, float, i32)

declare void @DrawSplineSegmentBezierCubic(i64, i64, i64, i64, float, i32)

declare i64 @GetSplinePointLinear(i64, i64, float)

declare i64 @GetSplinePointBasis(i64, i64, i64, i64, float)

declare i64 @GetSplinePointCatmullRom(i64, i64, i64, i64, float)

declare i64 @GetSplinePointBezierQuad(i64, i64, i64, float)

declare i64 @GetSplinePointBezierCubic(i64, i64, i64, i64, float)

declare i1 @CheckCollisionRecs(%_ZN6Raylib9RectangleE, %_ZN6Raylib9RectangleE)

declare i1 @CheckCollisionCircles(i64, float, i64, float)

declare i1 @CheckCollisionCircleRec(i64, float, %_ZN6Raylib9RectangleE)

declare i1 @CheckCollisionCircleLine(i64, float, i64, i64)

declare i1 @CheckCollisionPointRec(i64, %_ZN6Raylib9RectangleE)

declare i1 @CheckCollisionPointCircle(i64, i64, float)

declare i1 @CheckCollisionPointTriangle(i64, i64, i64, i64)

declare i1 @CheckCollisionPointLine(i64, i64, i64, i32)

declare i1 @CheckCollisionPointPoly(i64, ptr, i32)

declare i1 @CheckCollisionLines(i64, i64, i64, i64, ptr)

declare %_ZN6Raylib9RectangleE @GetCollisionRec(%_ZN6Raylib9RectangleE, %_ZN6Raylib9RectangleE)

declare %_ZN6Raylib5ImageE @LoadImage(ptr)

declare %_ZN6Raylib5ImageE @LoadImageRaw(ptr, i32, i32, i32, i32)

declare %_ZN6Raylib5ImageE @LoadImageAnim(ptr, ptr)

declare %_ZN6Raylib5ImageE @LoadImageAnimFromMemory(ptr, ptr, i32, ptr)

declare %_ZN6Raylib5ImageE @LoadImageFromMemory(ptr, ptr, i32)

declare %_ZN6Raylib5ImageE @LoadImageFromTexture(%_ZN6Raylib7TextureE)

declare %_ZN6Raylib5ImageE @LoadImageFromScreen()

declare i1 @IsImageValid(%_ZN6Raylib5ImageE)

declare void @UnloadImage(%_ZN6Raylib5ImageE)

declare i1 @ExportImage(%_ZN6Raylib5ImageE, ptr)

declare ptr @ExportImageToMemory(%_ZN6Raylib5ImageE, ptr, ptr)

declare i1 @ExportImageAsCode(%_ZN6Raylib5ImageE, ptr)

declare %_ZN6Raylib5ImageE @GenImageColor(i32, i32, i32)

declare %_ZN6Raylib5ImageE @GenImageGradientLinear(i32, i32, i32, i32, i32)

declare %_ZN6Raylib5ImageE @GenImageGradientRadial(i32, i32, float, i32, i32)

declare %_ZN6Raylib5ImageE @GenImageGradientSquare(i32, i32, float, i32, i32)

declare %_ZN6Raylib5ImageE @GenImageChecked(i32, i32, i32, i32, i32, i32)

declare %_ZN6Raylib5ImageE @GenImageWhiteNoise(i32, i32, float)

declare %_ZN6Raylib5ImageE @GenImagePerlinNoise(i32, i32, i32, i32, float)

declare %_ZN6Raylib5ImageE @GenImageCellular(i32, i32, i32)

declare %_ZN6Raylib5ImageE @GenImageText(i32, i32, ptr)

declare %_ZN6Raylib5ImageE @ImageCopy(%_ZN6Raylib5ImageE)

declare %_ZN6Raylib5ImageE @ImageFromImage(%_ZN6Raylib5ImageE, %_ZN6Raylib9RectangleE)

declare %_ZN6Raylib5ImageE @ImageFromChannel(%_ZN6Raylib5ImageE, i32)

declare %_ZN6Raylib5ImageE @ImageText(ptr, i32, i32)

declare %_ZN6Raylib5ImageE @ImageTextEx(%_ZN6Raylib4FontE, ptr, float, float, i32)

declare void @ImageFormat(ptr, i32)

declare void @ImageToPOT(ptr, i32)

declare void @ImageCrop(ptr, %_ZN6Raylib9RectangleE)

declare void @ImageAlphaCrop(ptr, float)

declare void @ImageAlphaClear(ptr, i32, float)

declare void @ImageAlphaMask(ptr, %_ZN6Raylib5ImageE)

declare void @ImageAlphaPremultiply(ptr)

declare void @ImageBlurGaussian(ptr, i32)

declare void @ImageKernelConvolution(ptr, ptr, i32)

declare void @ImageResize(ptr, i32, i32)

declare void @ImageResizeNN(ptr, i32, i32)

declare void @ImageResizeCanvas(ptr, i32, i32, i32, i32, i32)

declare void @ImageMipmaps(ptr)

declare void @ImageDither(ptr, i32, i32, i32, i32)

declare void @ImageFlipVertical(ptr)

declare void @ImageFlipHorizontal(ptr)

declare void @ImageRotate(ptr, i32)

declare void @ImageRotateCW(ptr)

declare void @ImageRotateCCW(ptr)

declare void @ImageColorTint(ptr, i32)

declare void @ImageColorInvert(ptr)

declare void @ImageColorGrayscale(ptr)

declare void @ImageColorContrast(ptr, float)

declare void @ImageColorBrightness(ptr, i32)

declare void @ImageColorReplace(ptr, i32, i32)

declare ptr @LoadImageColors(%_ZN6Raylib5ImageE)

declare ptr @LoadImagePalette(%_ZN6Raylib5ImageE, i32, ptr)

declare void @UnloadImageColors(ptr)

declare void @UnloadImagePalette(ptr)

declare %_ZN6Raylib9RectangleE @GetImageAlphaBorder(%_ZN6Raylib5ImageE, float)

declare i32 @GetImageColor(%_ZN6Raylib5ImageE, i32, i32)

declare void @ImageClearBackground(ptr, i32)

declare void @ImageDrawPixel(ptr, i32, i32, i32)

declare void @ImageDrawPixelV(ptr, i64, i32)

declare void @ImageDrawLine(ptr, i32, i32, i32, i32, i32)

declare void @ImageDrawLineV(ptr, i64, i64, i32)

declare void @ImageDrawLineEx(ptr, i64, i64, i32, i32)

declare void @ImageDrawCircle(ptr, i32, i32, i32, i32)

declare void @ImageDrawCircleV(ptr, i64, i32, i32)

declare void @ImageDrawCircleLines(ptr, i32, i32, i32, i32)

declare void @ImageDrawCircleLinesV(ptr, i64, i32, i32)

declare void @ImageDrawRectangle(ptr, i32, i32, i32, i32, i32)

declare void @ImageDrawRectangleV(ptr, i64, i64, i32)

declare void @ImageDrawRectangleRec(ptr, %_ZN6Raylib9RectangleE, i32)

declare void @ImageDrawRectangleLines(ptr, %_ZN6Raylib9RectangleE, i32, i32)

declare void @ImageDrawTriangle(ptr, i64, i64, i64, i32)

declare void @ImageDrawTriangleEx(ptr, i64, i64, i64, i32, i32, i32)

declare void @ImageDrawTriangleLines(ptr, i64, i64, i64, i32)

declare void @ImageDrawTriangleFan(ptr, ptr, i32, i32)

declare void @ImageDrawTriangleStrip(ptr, ptr, i32, i32)

declare void @ImageDraw(ptr, %_ZN6Raylib5ImageE, %_ZN6Raylib9RectangleE, %_ZN6Raylib9RectangleE, i32)

declare void @ImageDrawText(ptr, ptr, i32, i32, i32, i32)

declare void @ImageDrawTextEx(ptr, %_ZN6Raylib4FontE, ptr, i64, float, float, i32)

declare %_ZN6Raylib7TextureE @LoadTexture(ptr)

declare %_ZN6Raylib7TextureE @LoadTextureFromImage(%_ZN6Raylib5ImageE)

declare %_ZN6Raylib7TextureE @LoadTextureCubemap(%_ZN6Raylib5ImageE, i32)

declare %_ZN6Raylib13RenderTextureE @LoadRenderTexture(i32, i32)

declare i1 @IsTextureValid(%_ZN6Raylib7TextureE)

declare void @UnloadTexture(%_ZN6Raylib7TextureE)

declare i1 @IsRenderTextureValid(%_ZN6Raylib13RenderTextureE)

declare void @UnloadRenderTexture(%_ZN6Raylib13RenderTextureE)

declare void @UpdateTexture(%_ZN6Raylib7TextureE, ptr)

declare void @UpdateTextureRec(%_ZN6Raylib7TextureE, %_ZN6Raylib9RectangleE, ptr)

declare void @GenTextureMipmaps(ptr)

declare void @SetTextureFilter(%_ZN6Raylib7TextureE, i32)

declare void @SetTextureWrap(%_ZN6Raylib7TextureE, i32)

declare void @DrawTexture(%_ZN6Raylib7TextureE, i32, i32, i32)

declare void @DrawTextureV(%_ZN6Raylib7TextureE, i64, i32)

declare void @DrawTextureEx(%_ZN6Raylib7TextureE, i64, float, float, i32)

declare void @DrawTextureRec(%_ZN6Raylib7TextureE, %_ZN6Raylib9RectangleE, i64, i32)

declare void @DrawTexturePro(%_ZN6Raylib7TextureE, %_ZN6Raylib9RectangleE, %_ZN6Raylib9RectangleE, i64, float, i32)

declare void @DrawTextureNPatch(%_ZN6Raylib7TextureE, %_ZN6Raylib10NPatchInfoE, %_ZN6Raylib9RectangleE, i64, float, i32)

declare i1 @ColorIsEqual(i32, i32)

declare i32 @Fade(i32, float)

declare i32 @ColorToInt(i32)

declare %_ZN6Raylib7Vector4E @ColorNormalize(i32)

declare i32 @ColorFromNormalized(%_ZN6Raylib7Vector4E)

declare %_ZN6Raylib7Vector3E @ColorToHSV(i32)

declare i32 @ColorFromHSV(float, float, float)

declare i32 @ColorTint(i32, i32)

declare i32 @ColorBrightness(i32, float)

declare i32 @ColorContrast(i32, float)

declare i32 @ColorAlpha(i32, float)

declare i32 @ColorAlphaBlend(i32, i32, i32)

declare i32 @ColorLerp(i32, i32, float)

declare i32 @GetColor(i32)

declare i32 @GetPixelColor(ptr, i32)

declare void @SetPixelColor(ptr, i32, i32)

declare i32 @GetPixelDataSize(i32, i32, i32)

declare %_ZN6Raylib4FontE @GetFontDefault()

declare %_ZN6Raylib4FontE @LoadFont(ptr)

declare %_ZN6Raylib4FontE @LoadFontEx(ptr, i32, ptr, i32)

declare %_ZN6Raylib4FontE @LoadFontFromImage(%_ZN6Raylib5ImageE, i32, i32)

declare %_ZN6Raylib4FontE @LoadFontFromMemory(ptr, ptr, i32, i32, ptr, i32)

declare i1 @IsFontValid(%_ZN6Raylib4FontE)

declare ptr @LoadFontData(ptr, i32, i32, ptr, i32, i32, ptr)

declare %_ZN6Raylib5ImageE @GenImageFontAtlas(ptr, ptr, i32, i32, i32, i32)

declare void @UnloadFontData(ptr, i32)

declare void @UnloadFont(%_ZN6Raylib4FontE)

declare i1 @ExportFontAsCode(%_ZN6Raylib4FontE, ptr)

declare void @DrawFPS(i32, i32)

declare void @DrawText(ptr, i32, i32, i32, i32)

declare void @DrawTextEx(%_ZN6Raylib4FontE, ptr, i64, float, float, i32)

declare void @DrawTextPro(%_ZN6Raylib4FontE, ptr, i64, i64, float, float, float, i32)

declare void @DrawTextCodepoint(%_ZN6Raylib4FontE, i32, i64, float, i32)

declare void @DrawTextCodepoints(%_ZN6Raylib4FontE, ptr, i32, i64, float, float, i32)

declare void @SetTextLineSpacing(i32)

declare i32 @MeasureText(ptr, i32)

declare i64 @MeasureTextEx(%_ZN6Raylib4FontE, ptr, float, float)

declare i64 @MeasureTextCodepoints(%_ZN6Raylib4FontE, ptr, i32, float, float)

declare i32 @GetGlyphIndex(%_ZN6Raylib4FontE, i32)

declare %_ZN6Raylib9GlyphInfoE @GetGlyphInfo(%_ZN6Raylib4FontE, i32)

declare %_ZN6Raylib9RectangleE @GetGlyphAtlasRec(%_ZN6Raylib4FontE, i32)

declare ptr @LoadUTF8(ptr, i32)

declare void @UnloadUTF8(ptr)

declare ptr @LoadCodepoints(ptr, ptr)

declare void @UnloadCodepoints(ptr)

declare i32 @GetCodepointCount(ptr)

declare i32 @GetCodepoint(ptr, ptr)

declare i32 @GetCodepointNext(ptr, ptr)

declare i32 @GetCodepointPrevious(ptr, ptr)

declare ptr @CodepointToUTF8(i32, ptr)

declare ptr @LoadTextLines(ptr, ptr)

declare void @UnloadTextLines(ptr, i32)

declare i32 @TextCopy(ptr, ptr)

declare i1 @TextIsEqual(ptr, ptr)

declare i32 @TextLength(ptr)

declare ptr @TextFormat(ptr)

declare ptr @TextSubtext(ptr, i32, i32)

declare ptr @TextRemoveSpaces(ptr)

declare ptr @GetTextBetween(ptr, ptr, ptr)

declare ptr @TextReplace(ptr, ptr, ptr)

declare ptr @TextReplaceAlloc(ptr, ptr, ptr)

declare ptr @TextReplaceBetween(ptr, ptr, ptr, ptr)

declare ptr @TextReplaceBetweenAlloc(ptr, ptr, ptr, ptr)

declare ptr @TextInsert(ptr, ptr, i32)

declare ptr @TextInsertAlloc(ptr, ptr, i32)

declare ptr @TextJoin(ptr, i32, ptr)

declare ptr @TextSplit(ptr, i8, ptr)

declare void @TextAppend(ptr, ptr, ptr)

declare i32 @TextFindIndex(ptr, ptr)

declare ptr @TextToUpper(ptr)

declare ptr @TextToLower(ptr)

declare ptr @TextToPascal(ptr)

declare ptr @TextToSnake(ptr)

declare ptr @TextToCamel(ptr)

declare i32 @TextToInteger(ptr)

declare float @TextToFloat(ptr)

declare void @DrawLine3D(%_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, i32)

declare void @DrawPoint3D(%_ZN6Raylib7Vector3E, i32)

declare void @DrawCircle3D(%_ZN6Raylib7Vector3E, float, %_ZN6Raylib7Vector3E, float, i32)

declare void @DrawTriangle3D(%_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, i32)

declare void @DrawTriangleStrip3D(ptr, i32, i32)

declare void @DrawCube(%_ZN6Raylib7Vector3E, float, float, float, i32)

declare void @DrawCubeV(%_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, i32)

declare void @DrawCubeWires(%_ZN6Raylib7Vector3E, float, float, float, i32)

declare void @DrawCubeWiresV(%_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, i32)

declare void @DrawSphere(%_ZN6Raylib7Vector3E, float, i32)

declare void @DrawSphereEx(%_ZN6Raylib7Vector3E, float, i32, i32, i32)

declare void @DrawSphereWires(%_ZN6Raylib7Vector3E, float, i32, i32, i32)

declare void @DrawCylinder(%_ZN6Raylib7Vector3E, float, float, float, i32, i32)

declare void @DrawCylinderEx(%_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, float, float, i32, i32)

declare void @DrawCylinderWires(%_ZN6Raylib7Vector3E, float, float, float, i32, i32)

declare void @DrawCylinderWiresEx(%_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, float, float, i32, i32)

declare void @DrawCapsule(%_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, float, i32, i32, i32)

declare void @DrawCapsuleWires(%_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, float, i32, i32, i32)

declare void @DrawPlane(%_ZN6Raylib7Vector3E, i64, i32)

declare void @DrawRay(%_ZN6Raylib3RayE, i32)

declare void @DrawGrid(i32, float)

declare %_ZN6Raylib5ModelE @LoadModel(ptr)

declare %_ZN6Raylib5ModelE @LoadModelFromMesh(%_ZN6Raylib4MeshE)

declare i1 @IsModelValid(%_ZN6Raylib5ModelE)

declare void @UnloadModel(%_ZN6Raylib5ModelE)

declare %_ZN6Raylib11BoundingBoxE @GetModelBoundingBox(%_ZN6Raylib5ModelE)

declare void @DrawModel(%_ZN6Raylib5ModelE, %_ZN6Raylib7Vector3E, float, i32)

declare void @DrawModelEx(%_ZN6Raylib5ModelE, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, float, %_ZN6Raylib7Vector3E, i32)

declare void @DrawModelWires(%_ZN6Raylib5ModelE, %_ZN6Raylib7Vector3E, float, i32)

declare void @DrawModelWiresEx(%_ZN6Raylib5ModelE, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, float, %_ZN6Raylib7Vector3E, i32)

declare void @DrawBoundingBox(%_ZN6Raylib11BoundingBoxE, i32)

declare void @DrawBillboard(%_ZN6Raylib8Camera3DE, %_ZN6Raylib7TextureE, %_ZN6Raylib7Vector3E, float, i32)

declare void @DrawBillboardRec(%_ZN6Raylib8Camera3DE, %_ZN6Raylib7TextureE, %_ZN6Raylib9RectangleE, %_ZN6Raylib7Vector3E, i64, i32)

declare void @DrawBillboardPro(%_ZN6Raylib8Camera3DE, %_ZN6Raylib7TextureE, %_ZN6Raylib9RectangleE, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, i64, i64, float, i32)

declare void @UploadMesh(ptr, i1)

declare void @UpdateMeshBuffer(%_ZN6Raylib4MeshE, i32, ptr, i32, i32)

declare void @UnloadMesh(%_ZN6Raylib4MeshE)

declare void @DrawMesh(%_ZN6Raylib4MeshE, %_ZN6Raylib8MaterialE, %_ZN6Raylib6MatrixE)

declare void @DrawMeshInstanced(%_ZN6Raylib4MeshE, %_ZN6Raylib8MaterialE, ptr, i32)

declare %_ZN6Raylib11BoundingBoxE @GetMeshBoundingBox(%_ZN6Raylib4MeshE)

declare void @GenMeshTangents(ptr)

declare i1 @ExportMesh(%_ZN6Raylib4MeshE, ptr)

declare i1 @ExportMeshAsCode(%_ZN6Raylib4MeshE, ptr)

declare %_ZN6Raylib4MeshE @GenMeshPoly(i32, float)

declare %_ZN6Raylib4MeshE @GenMeshPlane(float, float, i32, i32)

declare %_ZN6Raylib4MeshE @GenMeshCube(float, float, float)

declare %_ZN6Raylib4MeshE @GenMeshSphere(float, i32, i32)

declare %_ZN6Raylib4MeshE @GenMeshHemiSphere(float, i32, i32)

declare %_ZN6Raylib4MeshE @GenMeshCylinder(float, float, i32)

declare %_ZN6Raylib4MeshE @GenMeshCone(float, float, i32)

declare %_ZN6Raylib4MeshE @GenMeshTorus(float, float, i32, i32)

declare %_ZN6Raylib4MeshE @GenMeshKnot(float, float, i32, i32)

declare %_ZN6Raylib4MeshE @GenMeshHeightmap(%_ZN6Raylib5ImageE, %_ZN6Raylib7Vector3E)

declare %_ZN6Raylib4MeshE @GenMeshCubicmap(%_ZN6Raylib5ImageE, %_ZN6Raylib7Vector3E)

declare ptr @LoadMaterials(ptr, ptr)

declare %_ZN6Raylib8MaterialE @LoadMaterialDefault()

declare i1 @IsMaterialValid(%_ZN6Raylib8MaterialE)

declare void @UnloadMaterial(%_ZN6Raylib8MaterialE)

declare void @SetMaterialTexture(ptr, i32, %_ZN6Raylib7TextureE)

declare void @SetModelMeshMaterial(ptr, i32, i32)

declare ptr @LoadModelAnimations(ptr, ptr)

declare void @UpdateModelAnimation(%_ZN6Raylib5ModelE, %_ZN6Raylib14ModelAnimationE, float)

declare void @UpdateModelAnimationEx(%_ZN6Raylib5ModelE, %_ZN6Raylib14ModelAnimationE, float, %_ZN6Raylib14ModelAnimationE, float, float)

declare void @UnloadModelAnimations(ptr, i32)

declare i1 @IsModelAnimationValid(%_ZN6Raylib5ModelE, %_ZN6Raylib14ModelAnimationE)

declare i1 @CheckCollisionSpheres(%_ZN6Raylib7Vector3E, float, %_ZN6Raylib7Vector3E, float)

declare i1 @CheckCollisionBoxes(%_ZN6Raylib11BoundingBoxE, %_ZN6Raylib11BoundingBoxE)

declare i1 @CheckCollisionBoxSphere(%_ZN6Raylib11BoundingBoxE, %_ZN6Raylib7Vector3E, float)

declare %_ZN6Raylib12RayCollisionE @GetRayCollisionSphere(%_ZN6Raylib3RayE, %_ZN6Raylib7Vector3E, float)

declare %_ZN6Raylib12RayCollisionE @GetRayCollisionBox(%_ZN6Raylib3RayE, %_ZN6Raylib11BoundingBoxE)

declare %_ZN6Raylib12RayCollisionE @GetRayCollisionMesh(%_ZN6Raylib3RayE, %_ZN6Raylib4MeshE, %_ZN6Raylib6MatrixE)

declare %_ZN6Raylib12RayCollisionE @GetRayCollisionTriangle(%_ZN6Raylib3RayE, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E)

declare %_ZN6Raylib12RayCollisionE @GetRayCollisionQuad(%_ZN6Raylib3RayE, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E, %_ZN6Raylib7Vector3E)

declare void @InitAudioDevice()

declare void @CloseAudioDevice()

declare i1 @IsAudioDeviceReady()

declare void @SetMasterVolume(float)

declare float @GetMasterVolume()

declare %_ZN6Raylib4WaveE @LoadWave(ptr)

declare %_ZN6Raylib4WaveE @LoadWaveFromMemory(ptr, ptr, i32)

declare i1 @IsWaveValid(%_ZN6Raylib4WaveE)

declare %_ZN6Raylib5SoundE @LoadSound(ptr)

declare %_ZN6Raylib5SoundE @LoadSoundFromWave(%_ZN6Raylib4WaveE)

declare %_ZN6Raylib5SoundE @LoadSoundAlias(%_ZN6Raylib5SoundE)

declare i1 @IsSoundValid(%_ZN6Raylib5SoundE)

declare void @UpdateSound(%_ZN6Raylib5SoundE, ptr, i32)

declare void @UnloadWave(%_ZN6Raylib4WaveE)

declare void @UnloadSound(%_ZN6Raylib5SoundE)

declare void @UnloadSoundAlias(%_ZN6Raylib5SoundE)

declare i1 @ExportWave(%_ZN6Raylib4WaveE, ptr)

declare i1 @ExportWaveAsCode(%_ZN6Raylib4WaveE, ptr)

declare void @PlaySound(%_ZN6Raylib5SoundE)

declare void @StopSound(%_ZN6Raylib5SoundE)

declare void @PauseSound(%_ZN6Raylib5SoundE)

declare void @ResumeSound(%_ZN6Raylib5SoundE)

declare i1 @IsSoundPlaying(%_ZN6Raylib5SoundE)

declare void @SetSoundVolume(%_ZN6Raylib5SoundE, float)

declare void @SetSoundPitch(%_ZN6Raylib5SoundE, float)

declare void @SetSoundPan(%_ZN6Raylib5SoundE, float)

declare %_ZN6Raylib4WaveE @WaveCopy(%_ZN6Raylib4WaveE)

declare void @WaveCrop(ptr, i32, i32)

declare void @WaveFormat(ptr, i32, i32, i32)

declare ptr @LoadWaveSamples(%_ZN6Raylib4WaveE)

declare void @UnloadWaveSamples(ptr)

declare %_ZN6Raylib5MusicE @LoadMusicStream(ptr)

declare %_ZN6Raylib5MusicE @LoadMusicStreamFromMemory(ptr, ptr, i32)

declare i1 @IsMusicValid(%_ZN6Raylib5MusicE)

declare void @UnloadMusicStream(%_ZN6Raylib5MusicE)

declare void @PlayMusicStream(%_ZN6Raylib5MusicE)

declare i1 @IsMusicStreamPlaying(%_ZN6Raylib5MusicE)

declare void @UpdateMusicStream(%_ZN6Raylib5MusicE)

declare void @StopMusicStream(%_ZN6Raylib5MusicE)

declare void @PauseMusicStream(%_ZN6Raylib5MusicE)

declare void @ResumeMusicStream(%_ZN6Raylib5MusicE)

declare void @SeekMusicStream(%_ZN6Raylib5MusicE, float)

declare void @SetMusicVolume(%_ZN6Raylib5MusicE, float)

declare void @SetMusicPitch(%_ZN6Raylib5MusicE, float)

declare void @SetMusicPan(%_ZN6Raylib5MusicE, float)

declare float @GetMusicTimeLength(%_ZN6Raylib5MusicE)

declare float @GetMusicTimePlayed(%_ZN6Raylib5MusicE)

declare %_ZN6Raylib11AudioStreamE @LoadAudioStream(i32, i32, i32)

declare i1 @IsAudioStreamValid(%_ZN6Raylib11AudioStreamE)

declare void @UnloadAudioStream(%_ZN6Raylib11AudioStreamE)

declare void @UpdateAudioStream(%_ZN6Raylib11AudioStreamE, ptr, i32)

declare i1 @IsAudioStreamProcessed(%_ZN6Raylib11AudioStreamE)

declare void @PlayAudioStream(%_ZN6Raylib11AudioStreamE)

declare void @PauseAudioStream(%_ZN6Raylib11AudioStreamE)

declare void @ResumeAudioStream(%_ZN6Raylib11AudioStreamE)

declare i1 @IsAudioStreamPlaying(%_ZN6Raylib11AudioStreamE)

declare void @StopAudioStream(%_ZN6Raylib11AudioStreamE)

declare void @SetAudioStreamVolume(%_ZN6Raylib11AudioStreamE, float)

declare void @SetAudioStreamPitch(%_ZN6Raylib11AudioStreamE, float)

declare void @SetAudioStreamPan(%_ZN6Raylib11AudioStreamE, float)

declare void @SetAudioStreamBufferSizeDefault(i32)

declare void @SetAudioStreamCallback(%_ZN6Raylib11AudioStreamE, ptr)

declare void @AttachAudioStreamProcessor(%_ZN6Raylib11AudioStreamE, ptr)

declare void @DetachAudioStreamProcessor(%_ZN6Raylib11AudioStreamE, ptr)

declare void @AttachAudioMixedProcessor(ptr)

declare void @DetachAudioMixedProcessor(ptr)

declare double @pow(double, double)

declare double @sqrt(double)

declare double @cbrt(double)

declare double @exp(double)

define i64 @"_Z12neighborhood6[]bool3int3int"(%"_Z6[]bool" %0, i64 %1, i64 %2) {
.alloca-block:
  %3 = alloca %"_Z6[]bool", align 8
  %4 = alloca i64, align 8
  %5 = alloca i64, align 8
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  store %"_Z6[]bool" %0, ptr %3, align 8
  store i64 %1, ptr %4, align 4
  store i64 %2, ptr %5, align 4
  %6 = load i64, ptr %5, align 4
  %7 = call i64 @_Zmi3int3int(i64 %6, i64 1)
  %8 = getelementptr inbounds nuw %"_Z6[]bool", ptr %3, i32 0, i32 0
  %9 = load ptr, ptr %8, align 8
  %10 = getelementptr inbounds i1, ptr %9, i64 %7
  %11 = load i1, ptr %10, align 1
  %12 = zext i1 %11 to i64
  %13 = load i64, ptr %5, align 4
  %14 = call i64 @_Zpl3int3int(i64 %13, i64 1)
  %15 = getelementptr inbounds nuw %"_Z6[]bool", ptr %3, i32 0, i32 0
  %16 = load ptr, ptr %15, align 8
  %17 = getelementptr inbounds i1, ptr %16, i64 %14
  %18 = load i1, ptr %17, align 1
  %19 = zext i1 %18 to i64
  %20 = call i64 @_Zpl3int3int(i64 %12, i64 %19)
  %21 = load i64, ptr %5, align 4
  %22 = load i64, ptr %4, align 4
  %23 = call i64 @_Zmi3int3int(i64 %21, i64 %22)
  %24 = call i64 @_Zmi3int3int(i64 %23, i64 1)
  %25 = getelementptr inbounds nuw %"_Z6[]bool", ptr %3, i32 0, i32 0
  %26 = load ptr, ptr %25, align 8
  %27 = getelementptr inbounds i1, ptr %26, i64 %24
  %28 = load i1, ptr %27, align 1
  %29 = zext i1 %28 to i64
  %30 = call i64 @_Zpl3int3int(i64 %20, i64 %29)
  %31 = load i64, ptr %5, align 4
  %32 = load i64, ptr %4, align 4
  %33 = call i64 @_Zmi3int3int(i64 %31, i64 %32)
  %34 = getelementptr inbounds nuw %"_Z6[]bool", ptr %3, i32 0, i32 0
  %35 = load ptr, ptr %34, align 8
  %36 = getelementptr inbounds i1, ptr %35, i64 %33
  %37 = load i1, ptr %36, align 1
  %38 = zext i1 %37 to i64
  %39 = call i64 @_Zpl3int3int(i64 %30, i64 %38)
  %40 = load i64, ptr %5, align 4
  %41 = load i64, ptr %4, align 4
  %42 = call i64 @_Zmi3int3int(i64 %40, i64 %41)
  %43 = call i64 @_Zpl3int3int(i64 %42, i64 1)
  %44 = getelementptr inbounds nuw %"_Z6[]bool", ptr %3, i32 0, i32 0
  %45 = load ptr, ptr %44, align 8
  %46 = getelementptr inbounds i1, ptr %45, i64 %43
  %47 = load i1, ptr %46, align 1
  %48 = zext i1 %47 to i64
  %49 = call i64 @_Zpl3int3int(i64 %39, i64 %48)
  %50 = load i64, ptr %5, align 4
  %51 = load i64, ptr %4, align 4
  %52 = call i64 @_Zpl3int3int(i64 %50, i64 %51)
  %53 = call i64 @_Zmi3int3int(i64 %52, i64 1)
  %54 = getelementptr inbounds nuw %"_Z6[]bool", ptr %3, i32 0, i32 0
  %55 = load ptr, ptr %54, align 8
  %56 = getelementptr inbounds i1, ptr %55, i64 %53
  %57 = load i1, ptr %56, align 1
  %58 = zext i1 %57 to i64
  %59 = call i64 @_Zpl3int3int(i64 %49, i64 %58)
  %60 = load i64, ptr %5, align 4
  %61 = load i64, ptr %4, align 4
  %62 = call i64 @_Zpl3int3int(i64 %60, i64 %61)
  %63 = getelementptr inbounds nuw %"_Z6[]bool", ptr %3, i32 0, i32 0
  %64 = load ptr, ptr %63, align 8
  %65 = getelementptr inbounds i1, ptr %64, i64 %62
  %66 = load i1, ptr %65, align 1
  %67 = zext i1 %66 to i64
  %68 = call i64 @_Zpl3int3int(i64 %59, i64 %67)
  %69 = load i64, ptr %5, align 4
  %70 = load i64, ptr %4, align 4
  %71 = call i64 @_Zpl3int3int(i64 %69, i64 %70)
  %72 = call i64 @_Zpl3int3int(i64 %71, i64 1)
  %73 = getelementptr inbounds nuw %"_Z6[]bool", ptr %3, i32 0, i32 0
  %74 = load ptr, ptr %73, align 8
  %75 = getelementptr inbounds i1, ptr %74, i64 %72
  %76 = load i1, ptr %75, align 1
  %77 = zext i1 %76 to i64
  %78 = call i64 @_Zpl3int3int(i64 %68, i64 %77)
  ret i64 %78
}

define void @_Z4main3intPP4byte(i64 %0, ptr %1) {
.alloca-block:
  %2 = alloca i64, align 8
  %3 = alloca ptr, align 8
  %4 = alloca %"_Z7[]*byte", align 8
  %5 = alloca %"_Z7[]*byte", align 8
  %6 = alloca i64, align 8
  %7 = alloca %"_Z6[]bool", align 8
  %8 = alloca %"_Z6[]bool", align 8
  %9 = alloca %"_Z6[]bool", align 8
  %10 = alloca %"_Z6[]bool", align 8
  %11 = alloca i64, align 8
  %12 = alloca i64, align 8
  %13 = alloca i64, align 8
  %14 = alloca i64, align 8
  %15 = alloca i64, align 8
  %16 = alloca %_ZN6Raylib5ColorE, align 8
  %17 = alloca i64, align 8
  %18 = alloca i64, align 8
  %19 = alloca i64, align 8
  %20 = alloca i64, align 8
  %21 = alloca i1, align 1
  %22 = alloca %_ZN6Raylib7Vector2E, align 8
  %23 = alloca %_ZN6Raylib7Vector2E, align 8
  %24 = alloca double, align 8
  %25 = alloca double, align 8
  %26 = alloca i64, align 8
  %27 = alloca i64, align 8
  %28 = alloca %"_Z6[]bool", align 8
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  store i64 %0, ptr %2, align 4
  store ptr %1, ptr %3, align 8
  %29 = getelementptr inbounds nuw %"_Z7[]*byte", ptr %4, i32 0, i32 0
  %30 = load ptr, ptr %3, align 8
  store ptr %30, ptr %29, align 8
  %31 = getelementptr inbounds nuw %"_Z7[]*byte", ptr %4, i32 0, i32 1
  %32 = load i64, ptr %2, align 4
  store i64 %32, ptr %31, align 4
  %33 = load %"_Z7[]*byte", ptr %4, align 8
  store %"_Z7[]*byte" %33, ptr %5, align 8
  store i64 50, ptr %6, align 4
  %34 = load i64, ptr %6, align 4
  %35 = load i64, ptr %6, align 4
  %36 = call i64 @_Zml3int3int(i64 %34, i64 %35)
  %37 = call ptr @calloc(i64 %36, i64 1)
  %38 = load i64, ptr %6, align 4
  %39 = load i64, ptr %6, align 4
  %40 = call i64 @_Zml3int3int(i64 %38, i64 %39)
  %41 = getelementptr inbounds nuw %"_Z6[]bool", ptr %7, i32 0, i32 0
  store ptr %37, ptr %41, align 8
  %42 = getelementptr inbounds nuw %"_Z6[]bool", ptr %7, i32 0, i32 1
  store i64 %40, ptr %42, align 4
  %43 = load %"_Z6[]bool", ptr %7, align 8
  store %"_Z6[]bool" %43, ptr %8, align 8
  %44 = load i64, ptr %6, align 4
  %45 = load i64, ptr %6, align 4
  %46 = call i64 @_Zml3int3int(i64 %44, i64 %45)
  %47 = call ptr @calloc(i64 %46, i64 1)
  %48 = load i64, ptr %6, align 4
  %49 = load i64, ptr %6, align 4
  %50 = call i64 @_Zml3int3int(i64 %48, i64 %49)
  %51 = getelementptr inbounds nuw %"_Z6[]bool", ptr %9, i32 0, i32 0
  store ptr %47, ptr %51, align 8
  %52 = getelementptr inbounds nuw %"_Z6[]bool", ptr %9, i32 0, i32 1
  store i64 %50, ptr %52, align 4
  %53 = load %"_Z6[]bool", ptr %9, align 8
  store %"_Z6[]bool" %53, ptr %10, align 8
  %54 = getelementptr inbounds nuw %"_Z7[]*byte", ptr %5, i32 0, i32 1
  %55 = load i64, ptr %54, align 4
  %56 = call i64 @_Zmi3int3int(i64 %55, i64 1)
  store i64 1, ptr %11, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.incr, %.entry-block
  %57 = load i64, ptr %11, align 4
  %58 = icmp slt i64 %57, %56
  br i1 %58, label %for.where, label %for.after

for.where:                                        ; preds = %for.cond
  %59 = load i64, ptr %11, align 4
  %60 = call i64 @_Zrm3int3int(i64 %59, i64 2)
  %61 = call i1 @_Zeq3int3int(i64 %60, i64 1)
  br i1 %61, label %for.body, label %for.incr

for.body:                                         ; preds = %for.where
  %62 = load i64, ptr %11, align 4
  %63 = getelementptr inbounds nuw %"_Z7[]*byte", ptr %5, i32 0, i32 0
  %64 = load ptr, ptr %63, align 8
  %65 = getelementptr inbounds ptr, ptr %64, i64 %62
  %66 = load ptr, ptr %65, align 8
  %67 = call i64 @atoi(ptr %66)
  %68 = load i64, ptr %6, align 4
  %69 = call i64 @_Zml3int3int(i64 %67, i64 %68)
  %70 = load i64, ptr %11, align 4
  %71 = call i64 @_Zpl3int3int(i64 %70, i64 1)
  %72 = getelementptr inbounds nuw %"_Z7[]*byte", ptr %5, i32 0, i32 0
  %73 = load ptr, ptr %72, align 8
  %74 = getelementptr inbounds ptr, ptr %73, i64 %71
  %75 = load ptr, ptr %74, align 8
  %76 = call i64 @atoi(ptr %75)
  %77 = call i64 @_Zpl3int3int(i64 %69, i64 %76)
  %78 = getelementptr inbounds nuw %"_Z6[]bool", ptr %10, i32 0, i32 0
  %79 = load ptr, ptr %78, align 8
  %80 = getelementptr inbounds i1, ptr %79, i64 %77
  store i1 true, ptr %80, align 1
  br label %for.incr

for.incr:                                         ; preds = %for.body, %for.where
  %81 = add i64 %57, 1
  store i64 %81, ptr %11, align 4
  br label %for.cond

for.after:                                        ; preds = %for.cond
  call void @InitWindow(i32 800, i32 800, ptr @0)
  call void @SetTargetFPS(i32 60)
  %82 = call i32 @GetRenderWidth()
  %83 = sext i32 %82 to i64
  %84 = load i64, ptr %6, align 4
  %85 = call i64 @_Zdv3int3int(i64 %83, i64 %84)
  store i64 %85, ptr %12, align 4
  %86 = call i32 @GetRenderHeight()
  %87 = sext i32 %86 to i64
  %88 = load i64, ptr %6, align 4
  %89 = call i64 @_Zdv3int3int(i64 %87, i64 %88)
  store i64 %89, ptr %13, align 4
  br label %.while-condition

.while-condition:                                 ; preds = %if.merge25, %for.after
  %90 = call i1 @WindowShouldClose()
  %91 = call i1 @_Znt4bool(i1 %90)
  br i1 %91, label %.while-body, label %.while-after

.while-body:                                      ; preds = %.while-condition
  call void @BeginDrawing()
  %92 = load i64, ptr %6, align 4
  store i64 0, ptr %14, align 4
  br label %for.cond1

.while-after:                                     ; preds = %.while-condition
  call void @CloseWindow()
  %93 = getelementptr inbounds nuw %"_Z6[]bool", ptr %10, i32 0, i32 0
  %94 = load ptr, ptr %93, align 8
  call void @free(ptr %94)
  %95 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %96 = load ptr, ptr %95, align 8
  call void @free(ptr %96)
  ret void

for.cond1:                                        ; preds = %for.incr3, %.while-body
  %97 = load i64, ptr %14, align 4
  %98 = icmp slt i64 %97, %92
  br i1 %98, label %for.body2, label %for.after4

for.body2:                                        ; preds = %for.cond1
  %99 = load i64, ptr %6, align 4
  store i64 0, ptr %15, align 4
  br label %for.cond5

for.incr3:                                        ; preds = %for.after8
  %100 = add i64 %97, 1
  store i64 %100, ptr %14, align 4
  br label %for.cond1

for.after4:                                       ; preds = %for.cond1
  call void @EndDrawing()
  %101 = load i64, ptr %6, align 4
  %102 = call i64 @_Zmi3int3int(i64 %101, i64 1)
  store i64 1, ptr %17, align 4
  br label %for.cond9

for.cond5:                                        ; preds = %for.incr7, %for.body2
  %103 = load i64, ptr %15, align 4
  %104 = icmp slt i64 %103, %99
  br i1 %104, label %for.body6, label %for.after8

for.body6:                                        ; preds = %for.cond5
  %105 = call %_ZN6Raylib5ColorE @_ZN6Raylib5Color3rgbE3int3int3int(i64 255, i64 215, i64 0)
  store %_ZN6Raylib5ColorE %105, ptr %16, align 1
  %106 = load i64, ptr %14, align 4
  %107 = load i64, ptr %6, align 4
  %108 = call i64 @_Zml3int3int(i64 %106, i64 %107)
  %109 = load i64, ptr %15, align 4
  %110 = call i64 @_Zpl3int3int(i64 %108, i64 %109)
  %111 = getelementptr inbounds nuw %"_Z6[]bool", ptr %10, i32 0, i32 0
  %112 = load ptr, ptr %111, align 8
  %113 = getelementptr inbounds i1, ptr %112, i64 %110
  %114 = load i1, ptr %113, align 1
  %115 = call i1 @_Znt4bool(i1 %114)
  br i1 %115, label %if.then, label %if.merge

for.incr7:                                        ; preds = %if.merge
  %116 = add i64 %103, 1
  store i64 %116, ptr %15, align 4
  br label %for.cond5

for.after8:                                       ; preds = %for.cond5
  br label %for.incr3

if.then:                                          ; preds = %for.body6
  %117 = call %_ZN6Raylib5ColorE @_ZN6Raylib5Color3rgbE3int3int3int(i64 0, i64 0, i64 0)
  store %_ZN6Raylib5ColorE %117, ptr %16, align 1
  br label %if.merge

if.merge:                                         ; preds = %if.then, %for.body6
  %118 = load i64, ptr %14, align 4
  %119 = load i64, ptr %12, align 4
  %120 = call i64 @_Zml3int3int(i64 %118, i64 %119)
  %121 = trunc i64 %120 to i32
  %122 = load i64, ptr %15, align 4
  %123 = load i64, ptr %13, align 4
  %124 = call i64 @_Zml3int3int(i64 %122, i64 %123)
  %125 = trunc i64 %124 to i32
  %126 = load i64, ptr %12, align 4
  %127 = trunc i64 %126 to i32
  %128 = load i64, ptr %13, align 4
  %129 = trunc i64 %128 to i32
  %130 = load %_ZN6Raylib5ColorE, ptr %16, align 1
  %131 = load i32, ptr %16, align 4
  call void @DrawRectangle(i32 %121, i32 %125, i32 %127, i32 %129, i32 %131)
  br label %for.incr7

for.cond9:                                        ; preds = %for.incr11, %for.after4
  %132 = load i64, ptr %17, align 4
  %133 = icmp slt i64 %132, %102
  br i1 %133, label %for.body10, label %for.after12

for.body10:                                       ; preds = %for.cond9
  %134 = load i64, ptr %6, align 4
  %135 = call i64 @_Zmi3int3int(i64 %134, i64 1)
  store i64 1, ptr %18, align 4
  br label %for.cond13

for.incr11:                                       ; preds = %for.after16
  %136 = add i64 %132, 1
  store i64 %136, ptr %17, align 4
  br label %for.cond9

for.after12:                                      ; preds = %for.cond9
  %137 = call i1 @IsMouseButtonDown(i32 0)
  br i1 %137, label %if.then24, label %if.merge25

for.cond13:                                       ; preds = %for.incr15, %for.body10
  %138 = load i64, ptr %18, align 4
  %139 = icmp slt i64 %138, %135
  br i1 %139, label %for.body14, label %for.after16

for.body14:                                       ; preds = %for.cond13
  %140 = load i64, ptr %17, align 4
  %141 = load i64, ptr %6, align 4
  %142 = call i64 @_Zml3int3int(i64 %140, i64 %141)
  %143 = load i64, ptr %18, align 4
  %144 = call i64 @_Zpl3int3int(i64 %142, i64 %143)
  store i64 %144, ptr %19, align 4
  %145 = load %"_Z6[]bool", ptr %10, align 8
  %146 = load i64, ptr %6, align 4
  %147 = load i64, ptr %19, align 4
  %148 = call i64 @"_Z12neighborhood6[]bool3int3int"(%"_Z6[]bool" %145, i64 %146, i64 %147)
  store i64 %148, ptr %20, align 4
  %149 = load i64, ptr %19, align 4
  %150 = getelementptr inbounds nuw %"_Z6[]bool", ptr %10, i32 0, i32 0
  %151 = load ptr, ptr %150, align 8
  %152 = getelementptr inbounds i1, ptr %151, i64 %149
  %153 = load i1, ptr %152, align 1
  store i1 %153, ptr %21, align 1
  %154 = load i64, ptr %20, align 4
  %155 = call i1 @_Zlt3int3int(i64 %154, i64 2)
  %156 = load i1, ptr %21, align 1
  %157 = call i1 @_Zaa4bool4bool(i1 %156, i1 %155)
  br i1 %157, label %if.then17, label %elif.condition

for.incr15:                                       ; preds = %if.merge23
  %158 = add i64 %138, 1
  store i64 %158, ptr %18, align 4
  br label %for.cond13

for.after16:                                      ; preds = %for.cond13
  br label %for.incr11

if.then17:                                        ; preds = %for.body14
  %159 = load i64, ptr %19, align 4
  %160 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %161 = load ptr, ptr %160, align 8
  %162 = getelementptr inbounds i1, ptr %161, i64 %159
  store i1 false, ptr %162, align 1
  br label %if.merge23

elif.condition:                                   ; preds = %for.body14
  %163 = load i64, ptr %20, align 4
  %164 = call i1 @_Zeq3int3int(i64 %163, i64 2)
  %165 = load i64, ptr %20, align 4
  %166 = call i1 @_Zeq3int3int(i64 %165, i64 3)
  %167 = call i1 @_Zoo4bool4bool(i1 %164, i1 %166)
  %168 = load i1, ptr %21, align 1
  %169 = call i1 @_Zaa4bool4bool(i1 %168, i1 %167)
  br i1 %169, label %if.then18, label %elif.condition19

if.then18:                                        ; preds = %elif.condition
  %170 = load i64, ptr %19, align 4
  %171 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %172 = load ptr, ptr %171, align 8
  %173 = getelementptr inbounds i1, ptr %172, i64 %170
  store i1 true, ptr %173, align 1
  br label %if.merge23

elif.condition19:                                 ; preds = %elif.condition
  %174 = load i64, ptr %20, align 4
  %175 = call i1 @_Zgt3int3int(i64 %174, i64 3)
  %176 = load i1, ptr %21, align 1
  %177 = call i1 @_Zaa4bool4bool(i1 %176, i1 %175)
  br i1 %177, label %if.then20, label %elif.condition21

if.then20:                                        ; preds = %elif.condition19
  %178 = load i64, ptr %19, align 4
  %179 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %180 = load ptr, ptr %179, align 8
  %181 = getelementptr inbounds i1, ptr %180, i64 %178
  store i1 false, ptr %181, align 1
  br label %if.merge23

elif.condition21:                                 ; preds = %elif.condition19
  %182 = load i1, ptr %21, align 1
  %183 = call i1 @_Znt4bool(i1 %182)
  %184 = load i64, ptr %20, align 4
  %185 = call i1 @_Zeq3int3int(i64 %184, i64 3)
  %186 = call i1 @_Zaa4bool4bool(i1 %183, i1 %185)
  br i1 %186, label %if.then22, label %if.merge23

if.then22:                                        ; preds = %elif.condition21
  %187 = load i64, ptr %19, align 4
  %188 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %189 = load ptr, ptr %188, align 8
  %190 = getelementptr inbounds i1, ptr %189, i64 %187
  store i1 true, ptr %190, align 1
  br label %if.merge23

if.merge23:                                       ; preds = %if.then22, %elif.condition21, %if.then20, %if.then18, %if.then17
  br label %for.incr15

if.then24:                                        ; preds = %for.after12
  %191 = call i64 @GetMousePosition()
  store i64 %191, ptr %22, align 4
  %192 = load %_ZN6Raylib7Vector2E, ptr %22, align 4
  store %_ZN6Raylib7Vector2E %192, ptr %23, align 4
  %193 = getelementptr inbounds nuw %_ZN6Raylib7Vector2E, ptr %23, i32 0, i32 0
  %194 = load float, ptr %193, align 4
  %195 = fpext float %194 to double
  %196 = call i32 @GetRenderWidth()
  %197 = sext i32 %196 to i64
  %198 = sitofp i64 %197 to double
  %199 = call double @_Zdv5float5float(double %195, double %198)
  store double %199, ptr %24, align 8
  %200 = getelementptr inbounds nuw %_ZN6Raylib7Vector2E, ptr %23, i32 0, i32 1
  %201 = load float, ptr %200, align 4
  %202 = fpext float %201 to double
  %203 = call i32 @GetRenderHeight()
  %204 = sext i32 %203 to i64
  %205 = sitofp i64 %204 to double
  %206 = call double @_Zdv5float5float(double %202, double %205)
  store double %206, ptr %25, align 8
  %207 = load i64, ptr %6, align 4
  %208 = sitofp i64 %207 to double
  %209 = load double, ptr %24, align 8
  %210 = call double @_Zml5float5float(double %209, double %208)
  %211 = fptosi double %210 to i64
  %212 = load i64, ptr %6, align 4
  %213 = call i64 @_Zmi3int3int(i64 %212, i64 1)
  %214 = call i64 @_ZN4Math5clampE3int3int3int(i64 0, i64 %211, i64 %213)
  store i64 %214, ptr %26, align 4
  %215 = load i64, ptr %6, align 4
  %216 = sitofp i64 %215 to double
  %217 = load double, ptr %25, align 8
  %218 = call double @_Zml5float5float(double %217, double %216)
  %219 = fptosi double %218 to i64
  %220 = load i64, ptr %6, align 4
  %221 = call i64 @_Zmi3int3int(i64 %220, i64 1)
  %222 = call i64 @_ZN4Math5clampE3int3int3int(i64 0, i64 %219, i64 %221)
  store i64 %222, ptr %27, align 4
  %223 = load i64, ptr %26, align 4
  %224 = load i64, ptr %6, align 4
  %225 = call i64 @_Zml3int3int(i64 %223, i64 %224)
  %226 = load i64, ptr %27, align 4
  %227 = call i64 @_Zpl3int3int(i64 %225, i64 %226)
  %228 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %229 = load ptr, ptr %228, align 8
  %230 = getelementptr inbounds i1, ptr %229, i64 %227
  store i1 true, ptr %230, align 1
  br label %if.merge25

if.merge25:                                       ; preds = %if.then24, %for.after12
  %231 = getelementptr inbounds nuw %"_Z6[]bool", ptr %10, i32 0, i32 0
  %232 = load ptr, ptr %231, align 8
  %233 = load i64, ptr %6, align 4
  %234 = call i64 @_Zml3int3int(i64 1, i64 %233)
  %235 = load i64, ptr %6, align 4
  %236 = call i64 @_Zml3int3int(i64 %234, i64 %235)
  call void @memset(ptr %232, i64 0, i64 %236)
  %237 = load %"_Z6[]bool", ptr %10, align 8
  store %"_Z6[]bool" %237, ptr %28, align 8
  %238 = load %"_Z6[]bool", ptr %8, align 8
  store %"_Z6[]bool" %238, ptr %10, align 8
  %239 = load %"_Z6[]bool", ptr %28, align 8
  store %"_Z6[]bool" %239, ptr %8, align 8
  br label %.while-condition
}

define %_ZN6Raylib5ColorE @_ZN6Raylib5Color3rgbE3int3int3int(i64 %0, i64 %1, i64 %2) {
.alloca-block:
  %3 = alloca i64, align 8
  %4 = alloca i64, align 8
  %5 = alloca i64, align 8
  %6 = alloca %_ZN6Raylib5ColorE, align 8
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  store i64 %0, ptr %3, align 4
  store i64 %1, ptr %4, align 4
  store i64 %2, ptr %5, align 4
  %7 = load i64, ptr %3, align 4
  %8 = trunc i64 %7 to i8
  %9 = load i64, ptr %4, align 4
  %10 = trunc i64 %9 to i8
  %11 = load i64, ptr %5, align 4
  %12 = trunc i64 %11 to i8
  %13 = getelementptr inbounds nuw %_ZN6Raylib5ColorE, ptr %6, i32 0, i32 0
  store i8 %8, ptr %13, align 1
  %14 = getelementptr inbounds nuw %_ZN6Raylib5ColorE, ptr %6, i32 0, i32 1
  store i8 %10, ptr %14, align 1
  %15 = getelementptr inbounds nuw %_ZN6Raylib5ColorE, ptr %6, i32 0, i32 2
  store i8 %12, ptr %15, align 1
  %16 = getelementptr inbounds nuw %_ZN6Raylib5ColorE, ptr %6, i32 0, i32 3
  store i8 -1, ptr %16, align 1
  %17 = load %_ZN6Raylib5ColorE, ptr %6, align 1
  ret %_ZN6Raylib5ColorE %17
}

define %_ZN6Raylib5ColorE @_ZN6Raylib5Color4rgbaE3int3int3int3int(i64 %0, i64 %1, i64 %2, i64 %3) {
.alloca-block:
  %4 = alloca i64, align 8
  %5 = alloca i64, align 8
  %6 = alloca i64, align 8
  %7 = alloca i64, align 8
  %8 = alloca %_ZN6Raylib5ColorE, align 8
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  store i64 %0, ptr %4, align 4
  store i64 %1, ptr %5, align 4
  store i64 %2, ptr %6, align 4
  store i64 %3, ptr %7, align 4
  %9 = load i64, ptr %4, align 4
  %10 = trunc i64 %9 to i8
  %11 = load i64, ptr %5, align 4
  %12 = trunc i64 %11 to i8
  %13 = load i64, ptr %6, align 4
  %14 = trunc i64 %13 to i8
  %15 = load i64, ptr %7, align 4
  %16 = trunc i64 %15 to i8
  %17 = getelementptr inbounds nuw %_ZN6Raylib5ColorE, ptr %8, i32 0, i32 0
  store i8 %10, ptr %17, align 1
  %18 = getelementptr inbounds nuw %_ZN6Raylib5ColorE, ptr %8, i32 0, i32 1
  store i8 %12, ptr %18, align 1
  %19 = getelementptr inbounds nuw %_ZN6Raylib5ColorE, ptr %8, i32 0, i32 2
  store i8 %14, ptr %19, align 1
  %20 = getelementptr inbounds nuw %_ZN6Raylib5ColorE, ptr %8, i32 0, i32 3
  store i8 %16, ptr %20, align 1
  %21 = load %_ZN6Raylib5ColorE, ptr %8, align 1
  ret %_ZN6Raylib5ColorE %21
}

define i64 @_ZN4Math5clampE3int3int3int(i64 %0, i64 %1, i64 %2) {
.alloca-block:
  %3 = alloca i64, align 8
  %4 = alloca i64, align 8
  %5 = alloca i64, align 8
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  store i64 %0, ptr %3, align 4
  store i64 %1, ptr %4, align 4
  store i64 %2, ptr %5, align 4
  %6 = load i64, ptr %4, align 4
  %7 = load i64, ptr %3, align 4
  %8 = call i1 @_Zlt3int3int(i64 %6, i64 %7)
  br i1 %8, label %if.then, label %elif.condition

if.then:                                          ; preds = %.entry-block
  %9 = load i64, ptr %3, align 4
  ret i64 %9

elif.condition:                                   ; preds = %.entry-block
  %10 = load i64, ptr %4, align 4
  %11 = load i64, ptr %5, align 4
  %12 = call i1 @_Zgt3int3int(i64 %10, i64 %11)
  br i1 %12, label %if.then1, label %else.body

if.then1:                                         ; preds = %elif.condition
  %13 = load i64, ptr %5, align 4
  ret i64 %13

else.body:                                        ; preds = %elif.condition
  %14 = load i64, ptr %4, align 4
  ret i64 %14

if.merge:                                         ; No predecessors!
  unreachable
}

define double @_ZN4Math5clampE5float5float5float(double %0, double %1, double %2) {
.alloca-block:
  %3 = alloca double, align 8
  %4 = alloca double, align 8
  %5 = alloca double, align 8
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  store double %0, ptr %3, align 8
  store double %1, ptr %4, align 8
  store double %2, ptr %5, align 8
  %6 = load double, ptr %4, align 8
  %7 = load double, ptr %3, align 8
  %8 = call i1 @_Zlt5float5float(double %6, double %7)
  br i1 %8, label %if.then, label %elif.condition

if.then:                                          ; preds = %.entry-block
  %9 = load double, ptr %3, align 8
  ret double %9

elif.condition:                                   ; preds = %.entry-block
  %10 = load double, ptr %4, align 8
  %11 = load double, ptr %5, align 8
  %12 = call i1 @_Zgt5float5float(double %10, double %11)
  br i1 %12, label %if.then1, label %else.body

if.then1:                                         ; preds = %elif.condition
  %13 = load double, ptr %5, align 8
  ret double %13

else.body:                                        ; preds = %elif.condition
  %14 = load double, ptr %4, align 8
  ret double %14

if.merge:                                         ; No predecessors!
  unreachable
}
