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

  while(!WindowShouldClose()) {
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

int base = 3;
int exp = 4;
int res = 1;
while(exp > 0) {
  res *= base;
  exp -= 1;
}
printf("%d", res);

int numbers[] = {6, 7, 3, 8, 9};
int sum = 0;
for(int i = 0; i < sizeof(numbers)/sizeof(*numbers); i+= 1) {
  if(i%2 == 0) {
    sum += numbers[i];
  }
}
printf("%d", sum);

const int x = 5;
if(x < 0) {
  puts("Negative");
} else if(x == 0) {
  puts("Zero");
} else puts("Positive");

}



int int_compare   (int         lhs, int         rhs) { return lhs - rhs; }
int float_compare (float       lhs, float       rhs) { return (int)(lhs - rhs); }
int char_compare  (char        lhs, char        rhs) { return (int)(lhs - rhs); }
int string_compare(const char* lhs, const char* rhs) { return strcmp(lhs, rhs); }
