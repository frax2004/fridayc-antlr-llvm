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

declare i8 @_Zpl4byte(i8)

declare i8 @_Zpl4byte4byte(i8, i8)

declare ptr @_ZplP4void3int(ptr, i64)

declare i64 @_Zpl3int(i64)

declare i64 @_Zpl3int3int(i64, i64)

declare double @_Zpl5float(double)

declare double @_Zpl5float5float(double, double)

declare i8 @_Zmi4byte(i8)

declare i8 @_Zmi4byte4byte(i8, i8)

declare i64 @_ZmiP4voidP4void(ptr, ptr)

declare ptr @_ZmiP4void3int(ptr, i64)

declare i64 @_Zmi3int(i64)

declare i64 @_Zmi3int3int(i64, i64)

declare double @_Zmi5float(double)

declare double @_Zmi5float5float(double, double)

declare i8 @_Zml4byte4byte(i8, i8)

declare i64 @_Zml3int3int(i64, i64)

declare double @_Zml5float5float(double, double)

declare i8 @_Zdv4byte4byte(i8, i8)

declare i64 @_Zdv3int3int(i64, i64)

declare double @_Zdv5float5float(double, double)

declare i8 @_Zrm4byte4byte(i8, i8)

declare i64 @_Zrm3int3int(i64, i64)

declare double @_Zrm5float5float(double, double)

declare i1 @_Zeq4byte4byte(i8, i8)

declare i1 @_ZeqP4voidP4void(ptr, ptr)

declare i1 @_Zeq3int3int(i64, i64)

declare i1 @_Zeq4bool4bool(i1, i1)

declare i1 @_Zeq5float5float(double, double)

declare i1 @_Zne4byte4byte(i8, i8)

declare i1 @_ZneP4voidP4void(ptr, ptr)

declare i1 @_Zne3int3int(i64, i64)

declare i1 @_Zne4bool4bool(i1, i1)

declare i1 @_Zne5float5float(double, double)

declare i1 @_Zlt4byte4byte(i8, i8)

declare i1 @_ZltP4voidP4void(ptr, ptr)

declare i1 @_Zlt3int3int(i64, i64)

declare i1 @_Zlt5float5float(double, double)

declare i1 @_Zgt4byte4byte(i8, i8)

declare i1 @_ZgtP4voidP4void(ptr, ptr)

declare i1 @_Zgt3int3int(i64, i64)

declare i1 @_Zgt5float5float(double, double)

declare i1 @_Zle4byte4byte(i8, i8)

declare i1 @_ZleP4voidP4void(ptr, ptr)

declare i1 @_Zle3int3int(i64, i64)

declare i1 @_Zle5float5float(double, double)

declare i1 @_Zge4byte4byte(i8, i8)

declare i1 @_ZgeP4voidP4void(ptr, ptr)

declare i1 @_Zge3int3int(i64, i64)

declare i1 @_Zge5float5float(double, double)

declare i8 @_Zan4byte4byte(i8, i8)

declare i64 @_Zan3int3int(i64, i64)

declare i1 @_Zan4bool4bool(i1, i1)

declare i8 @_Zor4byte4byte(i8, i8)

declare i64 @_Zor3int3int(i64, i64)

declare i1 @_Zor4bool4bool(i1, i1)

declare i8 @_Zco4byte(i8)

declare i64 @_Zco3int(i64)

declare i1 @_Zco4bool(i1)

declare i64 @_Zpp3int(i64)

declare double @_Zpp5float(double)

declare i64 @_Zmm3int(i64)

declare double @_Zmm5float(double)

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

declare ptr @strcat(ptr, ptr)

declare void @memset(ptr, i64, i64)

declare ptr @memcpy(ptr, ptr, i64)

declare i64 @memcmp(ptr, ptr, i64)

declare double @pow(double, double)

declare double @sqrt(double)

declare double @cbrt(double)

declare double @exp(double)

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
  %16 = alloca i64, align 8
  %17 = alloca %_ZN6Raylib5ColorE, align 8
  %18 = alloca i64, align 8
  %19 = alloca i64, align 8
  %20 = alloca i64, align 8
  %21 = alloca i64, align 8
  %22 = alloca i1, align 1
  %23 = alloca %_ZN6Raylib7Vector2E, align 8
  %24 = alloca %_ZN6Raylib7Vector2E, align 8
  %25 = alloca double, align 8
  %26 = alloca double, align 8
  %27 = alloca i64, align 8
  %28 = alloca i64, align 8
  %29 = alloca %"_Z6[]bool", align 8
  br label %.entry-block

.entry-block:                                     ; preds = %.alloca-block
  store i64 %0, ptr %2, align 4
  store ptr %1, ptr %3, align 8
  %30 = getelementptr inbounds nuw %"_Z7[]*byte", ptr %4, i32 0, i32 0
  %31 = load ptr, ptr %3, align 8
  store ptr %31, ptr %30, align 8
  %32 = getelementptr inbounds nuw %"_Z7[]*byte", ptr %4, i32 0, i32 1
  %33 = load i64, ptr %2, align 4
  store i64 %33, ptr %32, align 4
  %34 = load %"_Z7[]*byte", ptr %4, align 8
  store %"_Z7[]*byte" %34, ptr %5, align 8
  store i64 50, ptr %6, align 4
  %35 = load i64, ptr %6, align 4
  %36 = load i64, ptr %6, align 4
  %37 = call i64 @_Zml3int3int(i64 %35, i64 %36)
  %38 = call ptr @calloc(i64 %37, i64 1)
  %39 = load i64, ptr %6, align 4
  %40 = load i64, ptr %6, align 4
  %41 = call i64 @_Zml3int3int(i64 %39, i64 %40)
  %42 = getelementptr inbounds nuw %"_Z6[]bool", ptr %7, i32 0, i32 0
  store ptr %38, ptr %42, align 8
  %43 = getelementptr inbounds nuw %"_Z6[]bool", ptr %7, i32 0, i32 1
  store i64 %41, ptr %43, align 4
  %44 = load %"_Z6[]bool", ptr %7, align 8
  store %"_Z6[]bool" %44, ptr %8, align 8
  %45 = load i64, ptr %6, align 4
  %46 = load i64, ptr %6, align 4
  %47 = call i64 @_Zml3int3int(i64 %45, i64 %46)
  %48 = call ptr @calloc(i64 %47, i64 1)
  %49 = load i64, ptr %6, align 4
  %50 = load i64, ptr %6, align 4
  %51 = call i64 @_Zml3int3int(i64 %49, i64 %50)
  %52 = getelementptr inbounds nuw %"_Z6[]bool", ptr %9, i32 0, i32 0
  store ptr %48, ptr %52, align 8
  %53 = getelementptr inbounds nuw %"_Z6[]bool", ptr %9, i32 0, i32 1
  store i64 %51, ptr %53, align 4
  %54 = load %"_Z6[]bool", ptr %9, align 8
  store %"_Z6[]bool" %54, ptr %10, align 8
  %55 = getelementptr inbounds nuw %"_Z7[]*byte", ptr %5, i32 0, i32 1
  %56 = load i64, ptr %55, align 4
  %57 = call i64 @_Zmi3int3int(i64 %56, i64 1)
  store i64 1, ptr %11, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.incr, %.entry-block
  %58 = load i64, ptr %11, align 4
  %59 = icmp slt i64 %58, %57
  br i1 %59, label %for.where, label %for.after

for.where:                                        ; preds = %for.cond
  %60 = load i64, ptr %11, align 4
  %61 = call i64 @_Zrm3int3int(i64 %60, i64 2)
  %62 = call i1 @_Zeq3int3int(i64 %61, i64 1)
  br i1 %62, label %for.body, label %for.incr

for.body:                                         ; preds = %for.where
  %63 = load i64, ptr %11, align 4
  %64 = getelementptr inbounds nuw %"_Z7[]*byte", ptr %5, i32 0, i32 0
  %65 = load ptr, ptr %64, align 8
  %66 = getelementptr inbounds ptr, ptr %65, i64 %63
  %67 = load ptr, ptr %66, align 8
  %68 = call i64 @atoi(ptr %67)
  %69 = load i64, ptr %6, align 4
  %70 = call i64 @_Zml3int3int(i64 %68, i64 %69)
  %71 = load i64, ptr %11, align 4
  %72 = call i64 @_Zpl3int3int(i64 %71, i64 1)
  %73 = getelementptr inbounds nuw %"_Z7[]*byte", ptr %5, i32 0, i32 0
  %74 = load ptr, ptr %73, align 8
  %75 = getelementptr inbounds ptr, ptr %74, i64 %72
  %76 = load ptr, ptr %75, align 8
  %77 = call i64 @atoi(ptr %76)
  %78 = call i64 @_Zpl3int3int(i64 %70, i64 %77)
  %79 = getelementptr inbounds nuw %"_Z6[]bool", ptr %10, i32 0, i32 0
  %80 = load ptr, ptr %79, align 8
  %81 = getelementptr inbounds i1, ptr %80, i64 %78
  store i1 true, ptr %81, align 1
  br label %for.incr

for.incr:                                         ; preds = %for.body, %for.where
  %82 = add i64 %58, 1
  store i64 %82, ptr %11, align 4
  br label %for.cond

for.after:                                        ; preds = %for.cond
  call void @InitWindow(i32 800, i32 800, ptr @0)
  call void @SetTargetFPS(i32 60)
  %83 = call i32 @GetRenderWidth()
  %84 = sext i32 %83 to i64
  %85 = load i64, ptr %6, align 4
  %86 = call i64 @_Zdv3int3int(i64 %84, i64 %85)
  store i64 %86, ptr %12, align 4
  %87 = call i32 @GetRenderHeight()
  %88 = sext i32 %87 to i64
  %89 = load i64, ptr %6, align 4
  %90 = call i64 @_Zdv3int3int(i64 %88, i64 %89)
  store i64 %90, ptr %13, align 4
  store i64 120, ptr %14, align 4
  br label %.while-condition

.while-condition:                                 ; preds = %if.merge25, %for.after
  %91 = call i1 @WindowShouldClose()
  %92 = call i1 @_Znt4bool(i1 %91)
  %93 = load i64, ptr %14, align 4
  %94 = call i1 @_Zgt3int3int(i64 %93, i64 0)
  %95 = call i1 @_Zaa4bool4bool(i1 %92, i1 %94)
  br i1 %95, label %.while-body, label %.while-after

.while-body:                                      ; preds = %.while-condition
  %96 = load i64, ptr %14, align 4
  %97 = call i64 @_Zmi3int3int(i64 %96, i64 1)
  store i64 %97, ptr %14, align 4
  call void @BeginDrawing()
  %98 = load i64, ptr %6, align 4
  store i64 0, ptr %15, align 4
  br label %for.cond1

.while-after:                                     ; preds = %.while-condition
  call void @CloseWindow()
  %99 = getelementptr inbounds nuw %"_Z6[]bool", ptr %10, i32 0, i32 0
  %100 = load ptr, ptr %99, align 8
  call void @free(ptr %100)
  %101 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %102 = load ptr, ptr %101, align 8
  call void @free(ptr %102)
  ret void

for.cond1:                                        ; preds = %for.incr3, %.while-body
  %103 = load i64, ptr %15, align 4
  %104 = icmp slt i64 %103, %98
  br i1 %104, label %for.body2, label %for.after4

for.body2:                                        ; preds = %for.cond1
  %105 = load i64, ptr %6, align 4
  store i64 0, ptr %16, align 4
  br label %for.cond5

for.incr3:                                        ; preds = %for.after8
  %106 = add i64 %103, 1
  store i64 %106, ptr %15, align 4
  br label %for.cond1

for.after4:                                       ; preds = %for.cond1
  call void @EndDrawing()
  %107 = load i64, ptr %6, align 4
  %108 = call i64 @_Zmi3int3int(i64 %107, i64 1)
  store i64 1, ptr %18, align 4
  br label %for.cond9

for.cond5:                                        ; preds = %for.incr7, %for.body2
  %109 = load i64, ptr %16, align 4
  %110 = icmp slt i64 %109, %105
  br i1 %110, label %for.body6, label %for.after8

for.body6:                                        ; preds = %for.cond5
  %111 = call %_ZN6Raylib5ColorE @_ZN6Raylib5Color3rgbE3int3int3int(i64 255, i64 215, i64 0)
  store %_ZN6Raylib5ColorE %111, ptr %17, align 1
  %112 = load i64, ptr %15, align 4
  %113 = load i64, ptr %6, align 4
  %114 = call i64 @_Zml3int3int(i64 %112, i64 %113)
  %115 = load i64, ptr %16, align 4
  %116 = call i64 @_Zpl3int3int(i64 %114, i64 %115)
  %117 = getelementptr inbounds nuw %"_Z6[]bool", ptr %10, i32 0, i32 0
  %118 = load ptr, ptr %117, align 8
  %119 = getelementptr inbounds i1, ptr %118, i64 %116
  %120 = load i1, ptr %119, align 1
  %121 = call i1 @_Znt4bool(i1 %120)
  br i1 %121, label %if.then, label %if.merge

for.incr7:                                        ; preds = %if.merge
  %122 = add i64 %109, 1
  store i64 %122, ptr %16, align 4
  br label %for.cond5

for.after8:                                       ; preds = %for.cond5
  br label %for.incr3

if.then:                                          ; preds = %for.body6
  %123 = call %_ZN6Raylib5ColorE @_ZN6Raylib5Color3rgbE3int3int3int(i64 0, i64 0, i64 0)
  store %_ZN6Raylib5ColorE %123, ptr %17, align 1
  br label %if.merge

if.merge:                                         ; preds = %if.then, %for.body6
  %124 = load i64, ptr %15, align 4
  %125 = load i64, ptr %12, align 4
  %126 = call i64 @_Zml3int3int(i64 %124, i64 %125)
  %127 = trunc i64 %126 to i32
  %128 = load i64, ptr %16, align 4
  %129 = load i64, ptr %13, align 4
  %130 = call i64 @_Zml3int3int(i64 %128, i64 %129)
  %131 = trunc i64 %130 to i32
  %132 = load i64, ptr %12, align 4
  %133 = trunc i64 %132 to i32
  %134 = load i64, ptr %13, align 4
  %135 = trunc i64 %134 to i32
  %136 = load %_ZN6Raylib5ColorE, ptr %17, align 1
  %137 = load i32, ptr %17, align 4
  call void @DrawRectangle(i32 %127, i32 %131, i32 %133, i32 %135, i32 %137)
  br label %for.incr7

for.cond9:                                        ; preds = %for.incr11, %for.after4
  %138 = load i64, ptr %18, align 4
  %139 = icmp slt i64 %138, %108
  br i1 %139, label %for.body10, label %for.after12

for.body10:                                       ; preds = %for.cond9
  %140 = load i64, ptr %6, align 4
  %141 = call i64 @_Zmi3int3int(i64 %140, i64 1)
  store i64 1, ptr %19, align 4
  br label %for.cond13

for.incr11:                                       ; preds = %for.after16
  %142 = add i64 %138, 1
  store i64 %142, ptr %18, align 4
  br label %for.cond9

for.after12:                                      ; preds = %for.cond9
  %143 = call i1 @IsMouseButtonDown(i32 0)
  br i1 %143, label %if.then24, label %if.merge25

for.cond13:                                       ; preds = %for.incr15, %for.body10
  %144 = load i64, ptr %19, align 4
  %145 = icmp slt i64 %144, %141
  br i1 %145, label %for.body14, label %for.after16

for.body14:                                       ; preds = %for.cond13
  %146 = load i64, ptr %18, align 4
  %147 = load i64, ptr %6, align 4
  %148 = call i64 @_Zml3int3int(i64 %146, i64 %147)
  %149 = load i64, ptr %19, align 4
  %150 = call i64 @_Zpl3int3int(i64 %148, i64 %149)
  store i64 %150, ptr %20, align 4
  %151 = load %"_Z6[]bool", ptr %10, align 8
  %152 = load i64, ptr %6, align 4
  %153 = load i64, ptr %20, align 4
  %154 = call i64 @"_Z12neighborhood6[]bool3int3int"(%"_Z6[]bool" %151, i64 %152, i64 %153)
  store i64 %154, ptr %21, align 4
  %155 = load i64, ptr %20, align 4
  %156 = getelementptr inbounds nuw %"_Z6[]bool", ptr %10, i32 0, i32 0
  %157 = load ptr, ptr %156, align 8
  %158 = getelementptr inbounds i1, ptr %157, i64 %155
  %159 = load i1, ptr %158, align 1
  store i1 %159, ptr %22, align 1
  %160 = load i64, ptr %21, align 4
  %161 = call i1 @_Zlt3int3int(i64 %160, i64 2)
  %162 = load i1, ptr %22, align 1
  %163 = call i1 @_Zaa4bool4bool(i1 %162, i1 %161)
  br i1 %163, label %if.then17, label %elif.condition

for.incr15:                                       ; preds = %if.merge23
  %164 = add i64 %144, 1
  store i64 %164, ptr %19, align 4
  br label %for.cond13

for.after16:                                      ; preds = %for.cond13
  br label %for.incr11

if.then17:                                        ; preds = %for.body14
  %165 = load i64, ptr %20, align 4
  %166 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %167 = load ptr, ptr %166, align 8
  %168 = getelementptr inbounds i1, ptr %167, i64 %165
  store i1 false, ptr %168, align 1
  br label %if.merge23

elif.condition:                                   ; preds = %for.body14
  %169 = load i64, ptr %21, align 4
  %170 = call i1 @_Zeq3int3int(i64 %169, i64 2)
  %171 = load i64, ptr %21, align 4
  %172 = call i1 @_Zeq3int3int(i64 %171, i64 3)
  %173 = call i1 @_Zoo4bool4bool(i1 %170, i1 %172)
  %174 = load i1, ptr %22, align 1
  %175 = call i1 @_Zaa4bool4bool(i1 %174, i1 %173)
  br i1 %175, label %if.then18, label %elif.condition19

if.then18:                                        ; preds = %elif.condition
  %176 = load i64, ptr %20, align 4
  %177 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %178 = load ptr, ptr %177, align 8
  %179 = getelementptr inbounds i1, ptr %178, i64 %176
  store i1 true, ptr %179, align 1
  br label %if.merge23

elif.condition19:                                 ; preds = %elif.condition
  %180 = load i64, ptr %21, align 4
  %181 = call i1 @_Zgt3int3int(i64 %180, i64 3)
  %182 = load i1, ptr %22, align 1
  %183 = call i1 @_Zaa4bool4bool(i1 %182, i1 %181)
  br i1 %183, label %if.then20, label %elif.condition21

if.then20:                                        ; preds = %elif.condition19
  %184 = load i64, ptr %20, align 4
  %185 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %186 = load ptr, ptr %185, align 8
  %187 = getelementptr inbounds i1, ptr %186, i64 %184
  store i1 false, ptr %187, align 1
  br label %if.merge23

elif.condition21:                                 ; preds = %elif.condition19
  %188 = load i1, ptr %22, align 1
  %189 = call i1 @_Znt4bool(i1 %188)
  %190 = load i64, ptr %21, align 4
  %191 = call i1 @_Zeq3int3int(i64 %190, i64 3)
  %192 = call i1 @_Zaa4bool4bool(i1 %189, i1 %191)
  br i1 %192, label %if.then22, label %if.merge23

if.then22:                                        ; preds = %elif.condition21
  %193 = load i64, ptr %20, align 4
  %194 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %195 = load ptr, ptr %194, align 8
  %196 = getelementptr inbounds i1, ptr %195, i64 %193
  store i1 true, ptr %196, align 1
  br label %if.merge23

if.merge23:                                       ; preds = %if.then22, %elif.condition21, %if.then20, %if.then18, %if.then17
  br label %for.incr15

if.then24:                                        ; preds = %for.after12
  %197 = call i64 @GetMousePosition()
  store i64 %197, ptr %23, align 4
  %198 = load %_ZN6Raylib7Vector2E, ptr %23, align 4
  store %_ZN6Raylib7Vector2E %198, ptr %24, align 4
  %199 = getelementptr inbounds nuw %_ZN6Raylib7Vector2E, ptr %24, i32 0, i32 0
  %200 = load float, ptr %199, align 4
  %201 = fpext float %200 to double
  %202 = call i32 @GetRenderWidth()
  %203 = sext i32 %202 to i64
  %204 = sitofp i64 %203 to double
  %205 = call double @_Zdv5float5float(double %201, double %204)
  store double %205, ptr %25, align 8
  %206 = getelementptr inbounds nuw %_ZN6Raylib7Vector2E, ptr %24, i32 0, i32 1
  %207 = load float, ptr %206, align 4
  %208 = fpext float %207 to double
  %209 = call i32 @GetRenderHeight()
  %210 = sext i32 %209 to i64
  %211 = sitofp i64 %210 to double
  %212 = call double @_Zdv5float5float(double %208, double %211)
  store double %212, ptr %26, align 8
  %213 = load i64, ptr %6, align 4
  %214 = sitofp i64 %213 to double
  %215 = load double, ptr %25, align 8
  %216 = call double @_Zml5float5float(double %215, double %214)
  %217 = fptosi double %216 to i64
  %218 = load i64, ptr %6, align 4
  %219 = call i64 @_Zmi3int3int(i64 %218, i64 1)
  %220 = call i64 @_ZN4Math5clampE3int3int3int(i64 0, i64 %217, i64 %219)
  store i64 %220, ptr %27, align 4
  %221 = load i64, ptr %6, align 4
  %222 = sitofp i64 %221 to double
  %223 = load double, ptr %26, align 8
  %224 = call double @_Zml5float5float(double %223, double %222)
  %225 = fptosi double %224 to i64
  %226 = load i64, ptr %6, align 4
  %227 = call i64 @_Zmi3int3int(i64 %226, i64 1)
  %228 = call i64 @_ZN4Math5clampE3int3int3int(i64 0, i64 %225, i64 %227)
  store i64 %228, ptr %28, align 4
  %229 = load i64, ptr %27, align 4
  %230 = load i64, ptr %6, align 4
  %231 = call i64 @_Zml3int3int(i64 %229, i64 %230)
  %232 = load i64, ptr %28, align 4
  %233 = call i64 @_Zpl3int3int(i64 %231, i64 %232)
  %234 = getelementptr inbounds nuw %"_Z6[]bool", ptr %8, i32 0, i32 0
  %235 = load ptr, ptr %234, align 8
  %236 = getelementptr inbounds i1, ptr %235, i64 %233
  store i1 true, ptr %236, align 1
  br label %if.merge25

if.merge25:                                       ; preds = %if.then24, %for.after12
  %237 = getelementptr inbounds nuw %"_Z6[]bool", ptr %10, i32 0, i32 0
  %238 = load ptr, ptr %237, align 8
  %239 = load i64, ptr %6, align 4
  %240 = call i64 @_Zml3int3int(i64 1, i64 %239)
  %241 = load i64, ptr %6, align 4
  %242 = call i64 @_Zml3int3int(i64 %240, i64 %241)
  call void @memset(ptr %238, i64 0, i64 %242)
  %243 = load %"_Z6[]bool", ptr %10, align 8
  store %"_Z6[]bool" %243, ptr %29, align 8
  %244 = load %"_Z6[]bool", ptr %8, align 8
  store %"_Z6[]bool" %244, ptr %10, align 8
  %245 = load %"_Z6[]bool", ptr %29, align 8
  store %"_Z6[]bool" %245, ptr %8, align 8
  br label %.while-condition
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
