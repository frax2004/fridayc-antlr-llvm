#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define CELLS 50

int neighborhood(const bool* grid, const int linidx) {
  return grid[linidx-1] + grid[linidx+1]
  + grid[linidx-CELLS-1] + grid[linidx-CELLS] + grid[linidx-CELLS+1]
  + grid[linidx+CELLS-1] + grid[linidx+CELLS] + grid[linidx+CELLS+1];
}

int main(int argc, const char** argv) {
  bool* front_grid = calloc(CELLS*CELLS, sizeof(bool));
  bool* back_grid = calloc(CELLS*CELLS, sizeof(bool));

  for(int i = 1; i < argc-1; i += 2) 
    back_grid[atoi(argv[i])*CELLS + atoi(argv[i+1])] = true;

  InitWindow(800, 800, "C - GameOfLife");
  SetTargetFPS(60);
  
  const int cell_w = GetRenderWidth()/CELLS;
  const int cell_h = GetRenderHeight()/CELLS;

  int iter = 120;
  while(!WindowShouldClose() && iter --> 0) {
    BeginDrawing();

    for(int i = 0; i < CELLS; ++i)
      for(int j = 0; j < CELLS; ++j)
        if(back_grid[i*CELLS+j])
          DrawRectangle(i * cell_w, j * cell_h, cell_w, cell_h, (Color) {255, 215, 0, 255});
        else DrawRectangle(i * cell_w, j * cell_h, cell_w, cell_h, (Color) {0, 0, 0, 255});

    EndDrawing();

    for(int i = 1; i < CELLS-1; ++i)
      for(int j = 1; j < CELLS-1; ++j) {
        const int idx = i*CELLS+j;
        const int n = neighborhood(back_grid, idx);
        bool self_alive = back_grid[idx];
        if(self_alive && n < 2) front_grid[idx] = false;
        else if(self_alive && (n == 2 || n == 3)) front_grid[idx] = true;
        else if(self_alive && n > 3) front_grid[idx] = false;
        else if(!self_alive && n == 3) front_grid[idx] = true;
      }
    
    memset(back_grid, 0, sizeof(bool)*CELLS*CELLS);
    bool* tmp_grid = back_grid;
    back_grid = front_grid;
    front_grid = tmp_grid;
  }

  free(back_grid);
  free(front_grid);
  CloseWindow();
}
